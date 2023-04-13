#include "iic.h"

extern void printf(const char* fmt, ...);
/*
 * 函数名 ： delay_us
 * 函数功能：延时函数
 * 函数参数：无
 * 函数返回值：无
 * */
void delay_us(void)
{
	unsigned int i = 2000;
	while(i--);
}
/*
 * 函数名 ： i2c_init
 * 函数功能： i2C总线引脚的初始化， 通用输出，推挽输出，输出速度，
 * 函数参数：无
 * 函数返回值：无
 * */
void i2c_init(void)
{
 	// 使能GPIOF端口的时钟
	RCC->MP_AHB4ENSETR |= (0x1 << 5);
	// 设置PF14，PF15引脚为通用的输出功能
	GPIOF->MODER &= (~(0xF << 28));
	GPIOF->MODER |= (0x5 << 28);
	// 设置PF14, PF15引脚为推挽输出
	GPIOF->OTYPER &= (~(0x3 << 14));
	// 设置PF14, PF15引脚为高速输出
	GPIOF->OSPEEDR |= (0xF << 28);
	// 设置PF14, PF15引脚的禁止上拉和下拉
	GPIOF->PUPDR &= (~(0xF << 28));
	// 空闲状态SDA和SCL拉高 
	I2C_SCL_H;
	I2C_SDA_H;
}



/*
 * 函数名：i2c_start
 * 函数功能：模拟i2c开始信号的时序
 * 函数参数：无
 * 函数返回值：无
 * */
void i2c_start(void)
{
	/*
	 * 开始信号：时钟在高电平期间，数据线从高到低的变化
	 *     --------
	 * SCL         \
	 *              --------
	 *     ----
	 * SDA     \
	 *          --------
	 * */	
	 //1.设置SDA为输出模式
	 SET_SDA_OUT;

	 //当SCL拉高，数据线SDA从拉高到低
	 //2. SCL拉高
	 I2C_SCL_H;
	 delay_us();
	 //3. SDA拉高
	 I2C_SDA_H;
	 delay_us();
	 //4.SDA拉低
	 I2C_SDA_L;
	 //5.SCL拉低，总线处于占用状态
	 I2C_SCL_L;

}

/*
 * 函数名：i2c_stop
 * 函数功能：模拟i2c停止信号的时序
 * 函数参数：无
 * 函数返回值：无
 * */

void i2c_stop(void)
{
	/*
	 * 停止信号 ： 时钟在高电平期间，数据线从低到高的变化 
	 *             ----------
	 * SCL        /
	 *    --------
	 *    ---         -------
	 * SDA   X       /
	 *    --- -------
	 * */
	//1.设置SDA为输出模式   主机向数据线写数据
	SET_SDA_OUT;

	//2.SCL拉低
	I2C_SCL_L;
	delay_us();

	//3.SDA拉低
	I2C_SDA_L;
	delay_us();
	//4.SCL拉高
	I2C_SCL_H;
	delay_us();

	//5.SDA拉高
	I2C_SDA_H;
	delay_us();

}

/*
 * 函数名： i2c_write_byte
 * 函数功能：主机向i2c总线上的从设备写8bits数据
 * 函数参数：dat : 等待发送的字节数据
 * 函数返回值： 无
 * */

void i2c_write_byte(unsigned char dat)
{
	/*
	 * 数据信号：时钟在低电平期间，发送器向数据线上写入数据
	 * 			时钟在高电平期间，接收器从数据线上读取数据 
	 *      ----          --------
	 * 	SCL     \        /        \
	 *           --------          --------
	 *      -------- ------------------ ---
	 * 	SDA         X                  X
	 *      -------- ------------------ ---
	 *
	 *      先发送高位在发送低位 
	 * */
	
	//1.设置SDA为输出模式
	SET_SDA_OUT;
	//for循环  串行传输，只能一位一位发送
	//内容: SCL拉低   先发送高位，再发送低位  左移
	//取出最高位
	unsigned int i;
	for(i = 0;i<8;i++)
	{
		//2. SCL拉低，向数据线写入数据
		I2C_SCL_L;
		delay_us();
		if(dat&0x80) //3. 先发送高位，再发送低位
		{
			I2C_SDA_H;//4. 向数据线写入高电平
		} else
		{
			I2C_SDA_L;//5. 向数据线写入低电平
		}
		delay_us();
		//6. SCL拉高，接收器从数据线读取数据
		I2C_SCL_H;
		delay_us();
		delay_us();
		dat<<=1;
	}
	

}

/*
 * 函数名：i2c_read_byte
 * 函数功能： 主机从i2c总线上的从设备读8bits数据, 
 *          主机发送一个应答或者非应答信号
 * 函数参数： 0 ： 应答信号   1 ： 非应答信号
 * 函数返回值：读到的有效数据
 *
 * */
unsigned char i2c_read_byte(unsigned char ack)
{
	/*
	 * 数据信号：时钟在低电平期间，发送器向数据线上写入数据
	 * 			时钟在高电平期间，接收器从数据线上读取数据 
	 *      ----          --------
	 * 	SCL     \        /        \
	 *           --------          --------
	 *      -------- ------------------ ---
	 * 	SDA         X                  X
	 *      -------- ------------------ ---
	 *
	 *      先接收高位， 在接收低位 
	 * */
	
	unsigned int i;
	//1.设置SDA数据线为输入模式
	SET_SDA_IN;
	unsigned char data;
	//for循环内容: SCL拉高 读取数据 如何将读到的8位数据进行返回
	for(i=0;i<8;i++)
	{
		I2C_SCL_L; //将SCL拉低，保证从机向数据线上写入数据完成
		delay_us();
		delay_us();
		//拉高SCL  主机可以向从机读取数据
		I2C_SCL_H;
		delay_us();
		data<<1; //将data左移
		if(I2C_SDA_READ) //从数据线上读取数据
		{
			data |=1;
		} else
		{
			data|=0;
		}
		delay_us()
	}
		//判断应答信号   应答: 0   非应答: 1
		if(!ack)
		{
			i2c_ack(); //主机给从机返回应答信号
		} else
		{
			i2c_nack(); //主机给从机返回非应答信号
		}


}
/*
 * 函数名： i2c_wait_ack
 * 函数功能： 主机作为发送器时，等待接收器返回的应答信号
 * 函数参数：无
 * 函数返回值：
 *					0：接收到的应答信号
 *                  1：接收到的非应答信号
 * */
unsigned char i2c_wait_ack(void)
{
	/*
	 * 主机发送一个字节之后，从机给主机返回一个应答信号
	 *
	 *                   -----------
	 * SCL              /   M:读    \
	 *     -------------             --------
	 *     --- ---- --------------------
	 * SDA    X    X
	 *     ---      --------------------
	 *     主  释   从机    主机
	 *     机  放   向数据  读数据线
	 *         总   线写    上的数据
	 *         线   数据
	 * */	
	
	//1.SCL拉低 
	I2C_SCL_L;
	delay_us();
	//2.SDA拉高，释放总线   主机释放总线给从机
	I2C_SDA_H;
	delay_us();
	//3.设置数据线为输入模式
	SET_SDA_IN;
	delay_us();
	I2C_SCL_H; //4. SCL拉高，总线数据保持温度
	delay_us();
	if(I2C_SDA_READ())
	{
		return 1; //5.返回非应答信号
	}
	I2C_SCL_L; //7.SCL拉低，总线处于占用状态
	return 0; //6. 返回应答信号


	//主机读取数据线上的数据
} 
/*
 * 函数名： iic_ack
 * 函数功能： 主机作为接收器时，给发送器发送应答信号
 * 函数参数：无
 * 函数返回值：无
 * */
void i2c_ack(void)
{
	/*            --------
	 * SCL       /        \
	 *    -------          ------
	 *    ---
	 * SDA   X 
	 *    --- -------------
	 *
	*/
	//1. 设置SDA为输出模式
	SET_SDA_OUT;

	//2.SCL拉低
	I2C_SCL_L;
	delay_us();

	 //3.SDA拉低
	 I2C_SDA_L;
	 delay_us();

	 //4. SCL拉高
	 I2C_SCL_H;
	 delay_us();
	 delay_us();

	 //5.SCL拉低，总线处于占用状态
	 I2C_SCL_L;
}
/*
 * 函数名： iic_nack
 * 函数功能： 主机作为接收器时，给发送器发送非应答信号
 * 函数参数：无
 * 函数返回值：无
 * */
void i2c_nack(void)
{
	/*            --------
	 * SCL       /        \
	 *    -------          ------
	 *    --- ---------------
	 * SDA   X 
	 *    --- 
	 * */
	//1. 设置SDA为输出模式
	SET_SDA_OUT;

	//2.SCL拉低
	I2C_SCL_L;
	delay_us();

	 //3.SDA拉高
	 I2C_SDA_H;
	 delay_us();

	 //4. SCL拉高
	 I2C_SCL_H;
	 delay_us();
	 delay_us();

	 //5.SCL拉低，总线处于占用状态
	 I2C_SCL_L;	
}



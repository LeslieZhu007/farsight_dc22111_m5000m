#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

int do_insert(sqlite3 *db);
int do_delete(sqlite3 *db);
int do_update(sqlite3 *db);
int do_select(sqlite3 *db);
int do_select_1(sqlite3 *db);



#endif
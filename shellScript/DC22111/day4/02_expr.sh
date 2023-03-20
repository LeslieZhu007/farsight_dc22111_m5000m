#!/bin/bash 
string1=hello
string2=world
string3=hel
expr match $string1 $string2
expr match $string1 $string3
expr substr $string1 2 4
expr index $string1 lo
expr index $string1 w
expr index $string1 o
expr index $string1 l
expr index $string1 le
expr length $string1 
expr length $(expr substr $string1 2 4)

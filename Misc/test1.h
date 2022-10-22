#ifndef TEST1_H
#define TEST1_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct test1
{
	char _name[20];
	int id;	
}TEST;

int WriteToFile(TEST *);
int ReadFromFile(TEST *);

#endif
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct signUp{
	long int phno;
	int _id;
	char name[20];
	char addr[50];
	char gender;
}SIGNUP;

typedef struct login{
	int _id;
	char uName[20];
	char uPasswd[20];
}LOGIN;


int signUp(SIGNUP *, int);
int login(LOGIN *);

int signUpWrite(SIGNUP *);
int signUpRecs();
int signUpRead(SIGNUP *);

int loginWrite(LOGIN *);
int loginRead(LOGIN *);


#endif
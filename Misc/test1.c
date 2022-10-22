#include "test1.h"

int WriteToFile(TEST *t)
{
	FILE *fp;
	fp = fopen("test1.dat","a+");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	fwrite(t, sizeof(TEST),1,fp);

	fclose(fp);
}


int ReadFromFile(TEST *t)
{
	FILE *fp;
	fp = fopen("test1.dat","r");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	while(fread(t, sizeof(TEST),1,fp))
		printf("\nDetails\nName: %s\nID: %d\n",t->_name,t->id);
	fclose(fp);
}


#include "test1.h"

int main(int argc, char*argv[])
{
	TEST t1,t2;
	/*
	strcpy(t1._name,argv[1]);
	t1.id = atoi(argv[2]);

	WriteToFile(&t1);
	*/
	
	
	ReadFromFile(&t2);
	/*
	printf("\nDetails\nName: %s\nID: %d\n",t2._name,t2.id);

	ReadFromFile(&t2);

	printf("\nDetails\nName: %s\nID: %d\n",t2._name,t2.id);
	*/
	return 0;

}
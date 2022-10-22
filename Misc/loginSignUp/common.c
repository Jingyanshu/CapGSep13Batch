#include <common.h>

int signUp(SIGNUP *sn, int _id)
{
	system("clear");
	printf("\n\t=============SIGNUP=============\n");
	printf("\n\tEnter the details of the User\n");
	printf("\n\tName: ");
	scanf("%s",sn->name);
	printf("\n\tAddress: ");
	scanf("%s",sn->addr);
	getchar();
	printf("\n\tGender(M/F/O): ");
	scanf("%c",&sn->gender);
	printf("\n\tPhno: ");
	scanf("%ld",&sn->phno);
	sn->_id = _id;
	LOGIN *ln;
	ln->_id = _id;
	printf("\n\tUser Name: ");
	scanf("%s", ln->uName);
	printf("\n\tPassword: ");
	scanf("%s",ln->uPasswd);

	/*
	After validating all the flds write to the file/db
	*/
	signUpWrite(sn);
	loginWrite(ln);
}


int signUpWrite(SIGNUP *sn)
{
	FILE *fp;
	fp = fopen("Users.dat","a+");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	fwrite(sn, sizeof(SIGNUP),1,fp);

	fclose(fp);
}


int signUpRecs()
{
	FILE *fp;
	SIGNUP *sn;
	int recCount=0;
	fp = fopen("Users.dat","r");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		return 0;
	}

	while(fread(sn, sizeof(SIGNUP),1,fp))
		recCount++;

	fclose(fp);

	return recCount;
}


int login(LOGIN *ln)
{
	int flag=0;
	system("clear");
	printf("\n\t=============LOGIN=============\n");
	printf("\n\tLogin: ");
	scanf("%s", ln->uName);
	printf("\n\tPassword: ");
	scanf("%s", ln->uPasswd);

	if((strcmp(ln->uName, "Admin")==0) && (strcmp(ln->uPasswd,"admin123")==0))
		return 2;
	else
		flag = loginRead(ln);
	
	if(flag == 1)
		return 1;
	else
		return 0;
}

int loginWrite(LOGIN *ln)
{
	FILE *fp;
	fp = fopen("login.dat","a+");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	fwrite(ln, sizeof(LOGIN),1,fp);

	fclose(fp);
}


int loginRead(LOGIN *ln)
{
	FILE *fp;
	LOGIN *tln;
	int flag = 0;
	fp = fopen("login.dat","r");
	if(fp == NULL)
	{
		printf("Unable to open the file");
		exit(EXIT_FAILURE);
	}

	while(fread(tln, sizeof(LOGIN),1,fp))
	{
		if((strcmp(ln->uName, tln->uName)==0) && (strcmp(ln->uPasswd,tln->uPasswd)==0))
		{
			flag = 1;
			break;
		}	
	}

	fclose(fp);

	return flag;
}	
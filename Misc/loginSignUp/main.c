#include <common.h>
#include <main.h>

int main()
{
	int ch;
	int id;
	SIGNUP sn;
	LOGIN ln;
	
	while(1){
		system("clear");
		printf("%s", WelcomeMsg);
		printf("%s", MainMenu);
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				system("clear");
				printf("\ncase 1 is executed\n");
				if((id = signUpRecs())==0)
					signUp(&sn, 0+1);
				else
					signUp(&sn, id+1);
				break;
			case 2:
				system("clear");
				printf("\ncase 2 is executed\n");
				switch(login(&ln))
				{
					case 0:
						printf("\nCheck credentials\n");
						system("clear");
						break;
					case 2:
						printf("%s",AdminMenu);
						scanf("%d", &ch);
						break;
					case 1:
						printf("%s", EmpMenu);
						scanf("%d", &ch);
						break;
					default:
						printf("\nSomething Went Wrong\n");
				}

				break;
			case 3:
				printf("\ncase 3 is executed\n");
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("\ndefault case is executed\n");
				break;
		}
	}

	return 0;
}
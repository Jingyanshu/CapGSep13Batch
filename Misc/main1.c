#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int main()
{
	FILE *fp;
	char buff[1024];
	char *token;
	/*fp = fopen("inventory.csv", "a+");
	fprintf(fp, "%d, %s, %d, %f\n", 1001, "Parle G", 100, 10.0);
	fprintf(fp, "%d, %s, %d, %f\n", 1002, "Good Day", 100, 15.0);
	fprintf(fp, "%d, %s, %d, %f\n", 1003, "prod1", 50, 20.0);
	fprintf(fp, "%d, %s, %d, %f\n", 1004, "prod2", 60, 35.50);

	fclose(fp);
	*/
	fp = fopen("inventory.csv", "r");
	/*fgets(buff, 1024, fp);
	printf("%s", buff);
	*/
	while(fgets(buff, 1024, fp))
	{
		printf("%s", buff);
		

		token = strtok(buff,",");
		
		while( token != NULL ) {
			token = trimwhitespace(token);
	      printf( "\n%s\n", token );
	    
	      token = strtok(NULL, ",");
	   }
	}

	// fprintf(fp, "%d, %s, %d, %f\n", 1001, "Parle G", 100, 10.0);
	// fprintf(fp, "%d, %s, %d, %f\n", 1002, "Good Day", 100, 15.0);
	// fprintf(fp, "%d, %s, %d, %f\n", 1003, "prod1", 50, 20.0);
	// fprintf(fp, "%d, %s, %d, %f\n", 1004, "prod2", 60, 35.50);

	fclose(fp);

	return 0;
}
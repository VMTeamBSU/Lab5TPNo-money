#include "../../include/Authorization.h"
#include "string.h"
int ValidateUser(char* login, char* password)
{
	if (strcmp(login, "admin") == 0 && strcmp(password, "1111")==0)
	{
		return  1;
	}
	else
	{
		return -1;
	}
}
int FindUser(char* login)
{
	if(strcmp("admin", login)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


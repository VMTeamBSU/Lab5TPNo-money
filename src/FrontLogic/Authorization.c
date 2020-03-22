#include "../../include/Authorization.h"

#include "../../BackEndLogic/sqlite3.h"
#include "string.h"
int ValidateUser(char* login, char* password)
{
	sqlite3* pedp;
	sqlite3_open("dsd", &pedp);
	if (strcmp(login, "admin") == 0 && strcmp(password, "1111")==0)
	{
		return  1;
	}
	else
	{
		return -1;
	}
}

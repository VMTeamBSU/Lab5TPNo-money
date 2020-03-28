#include "../../include/Authorization.h"
#include "../../lib/sqlite3/sqlite3.h"
#include "string.h"
#include "../../include/request.h"
#include "../../include/BDfunctions.h"
#include <stdlib.h>
#include <stdio.h>

int ValidateUser(char* login, char* password)
{

	InitDataBase();
	//if (strcmp(login, "admin") == 0 && strcmp(password, "1111")==0)
	//{
	//	return  1;
	//}
	//else
	//{
	//	return -1;
	//}
	
	char requestBuffer[500];
	sprintf(requestBuffer,
		"Select login, password from mainLogin where login  = '%s' AND password = '%s';",
		login, password);

	if (Validation(requestBuffer) == 0)
		return 0;
	else
		return 1;
	
}
int FindUser(char* login)
{
	/*if(strcmp("admin", login)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}*/

	char requestBuffer[500];
	sprintf(requestBuffer,
		"Select login from mainLogin where login  = '%s';",
		login);

	if (Validation(requestBuffer) == 0)
		return 0;
	else
		return 1;
}

int FindById(int id)
{
	char requestBuffer[500];
	sprintf(requestBuffer,
		"Select login from mainLogin where id  = %d;",
		id);

	if (Validation(requestBuffer) == 0)
		return 0;
	else
		return 1;
}


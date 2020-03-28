#include "../../include/SessionController.h"

#include <stdlib.h>

#include "../../include/BDfunctions.h"
#include <string.h>
struct User CurrentUser;

struct User GetCurrentUser(char* login)
{
	char*** result;
	int rowsCount = 0;
	int columnsCount = 0;
	char surname[30];
	char** columnsNames = NULL;

	result = GetUserInfo(login, &columnsNames, &rowsCount, &columnsCount);

	
	struct User user;
	user.id =atoi( result[0][0]);

	if(strcmp(result[0][1],"member")==0)
	{
		user.privilege = member;
	}
	else
	{
		if(strcmp(result[0][1], "admin")==0)
		{
			user.privilege = admin;
		}
	}
	
	strcpy(user.login, login);
	
	return  user;
}



void InitSession(char* login)
{
	CurrentUser = GetCurrentUser(login);
}


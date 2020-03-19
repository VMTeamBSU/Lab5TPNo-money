#include "../include/SessionController.h"

struct User CurrentUser;

struct User GetCurrentUser(char* login)
{
	struct User user;
	user.id = 0;	
	user.privilege = admin;
	return  user;
}

int CheckPermission(struct User user, int commandId)
{
	return 1;
}


int ExecuteCommand(struct command* command)
{
	int a;
	if(CheckPermission(CurrentUser,command->id)==-1)
	{
		return -1;
	}

	command->function();
}

void Init(char* login)
{
	CurrentUser = GetCurrentUser(login);
}


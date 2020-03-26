#include "../../include/SessionController.h"
#include <string.h>
struct User CurrentUser;

struct User GetCurrentUser(char* login)
{
	//TODO implement this to make it work with database
	struct User user;
	user.id = 0;	
	user.privilege = admin;
	strcpy(user.login, login);
	strcpy(user.surname, "Adminov");
	
	return  user;
}

int CheckPermission(struct User user, int commandId)
{
	return 1;
}



int ExecuteCommand(struct command* command)
{
	command->function();
}

void Init(char* login)
{
	CurrentUser = GetCurrentUser(login);
}


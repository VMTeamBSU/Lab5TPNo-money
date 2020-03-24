#include "User.h"
#include "Command.h"

extern struct User CurrentUser;
extern int ExecuteCommand(struct command* command);
struct User GetCurrentUser(char* login);
int CheckPermission(struct User user,int commandId);
void InitDataBase(char* login);

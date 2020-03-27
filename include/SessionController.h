//Author: Ivan Shishlyannikov

//Description: SessionController handles all info of current session

#include "User.h"

//Current user in session
extern struct User CurrentUser;

//Get current user by login
struct User GetCurrentUser(char* login);

//All initialization should be done here
void InitSession(char* login);

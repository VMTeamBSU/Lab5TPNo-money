
#pragma once
enum privilegeLevel
{
	admin,
	commando,
	member
};

struct User
{
	int id;
	enum privilegeLevel privilege;
	char login[30];
	char surname[30];
};

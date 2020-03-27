#include "../../include/Registration.h"
#include "../../include/request.h"
#include <stdio.h>

int RegisterMember(char* login, char* password, char* surname, int experience, char* dateOfBirth,char* position, char* commanderID)
{
	char requestBuffer[500];
	sprintf(requestBuffer,
			"INSERT INTO mainLogin(login, password) VALUES ('%s', '%s'); ",
			login, password);
	InsertData(requestBuffer);

	sprintf(requestBuffer,
		"INSERT INTO statusSurname(status, surname) VALUES ('member', '%s' ); ",
		surname);
	InsertData(requestBuffer);

	sprintf(requestBuffer,
		"INSERT INTO crew(position, experiens, date_of_birth, surname) VALUES('%s', '%d', '%s', '%s');",
		position, experience, dateOfBirth, surname);
	InsertData(requestBuffer);

	return 1;
}

int RegisterCommando(char* login, char* password, char* surname, int experience, char* dateOfBirth, char* position)
{
	return 1;
}

int RegisterAdmin(char* login, char* password)
{
	return 1;
}

int RegisterFlight(char* date, char* helicopterName, int weightOfGoods, int numberOfPeople, int duration, int price, int isSpecial)
{
	return 1;
}

int RegisterHelicopter(char* name, char* creationDate, char* repairDate, int capacity, int flyingResources)
{
	return 1;
}

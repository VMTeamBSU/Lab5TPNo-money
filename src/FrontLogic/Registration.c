#include "../../include/Registration.h"
#include "../../include/request.h"
#include <stdio.h>
#include <time.h>

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
	char requestBuffer[500];
	sprintf(requestBuffer,
		"INSERT INTO mainLogin(login, password) VALUES ('%s', '%s'); ",
		login, password);
	InsertData(requestBuffer);

	sprintf(requestBuffer,
		"INSERT INTO statusSurname(status) VALUES ('admin')");
	InsertData(requestBuffer);
	return 1;
}

int RegisterFlight(char* date, int helicopterID, int weightOfGoods, int numberOfPeople, int duration, int price, int isSpecial)
{
	char requestBuffer[500];

	sprintf(requestBuffer,
		"SELECT (helicopter.flying_resourse - %d)FROM helicopter WHERE helicopter.ID = %d", 
		duration, helicopterID);

	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	
	if (Result[0][1] >= 0)
	{
		char* text;
		if (isSpecial == 1)
			text = "yes";
		else
			text = "no";


		sprintf(requestBuffer,
			"INSERT INTO flights(date, ID_helicopter, weight_of_goods, num_of_people, duration, price, special) VALUES ('%s', '%d', '%d', '%d', '%d', '%d', '%s'); ",
			date, helicopterID, weightOfGoods, numberOfPeople, duration, price, text);
		InsertData(requestBuffer);

	
		return 1;
	}
	
		//Edited by IVan ( no need to repair if flying resource is not zero)
	if (Result[0][1] == 0) {
		struct tm* ptr;
		time_t lt;
		lt = time(NULL);

		ptr = localtime(time(NULL));


		sprintf(requestBuffer,
			"UPDATE helicopter SET flying_resourse = 1000 AND date_of_repair = %s-%s-%s WHERE helicopter.ID = %d",
			ptr->tm_year, ptr->tm_mon, ptr->tm_mday, duration, helicopterID);
		InsertData(requestBuffer);
	}

	return 0;
}

int RegisterHelicopter(char* name, char* creationDate, char* repairDate, int capacity, int flyingResources)
{

	char requestBuffer[500];
	sprintf(requestBuffer,
		"INSERT INTO helicopter(name, data_of_creation, Ñapacity, date_of_repair, flying_resourse) VALUES ('%s', '%s', '%d', '%s', '%d');",
		name, creationDate, capacity, repairDate, flyingResources);
	InsertData(requestBuffer);

	return 1;
}


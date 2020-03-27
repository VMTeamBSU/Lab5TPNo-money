#include <stdlib.h>
#include <stdio.h>
#include "../../include/request.h"
#include "../../include/BDfunctions.h"
#pragma warning(disable:4996)


char*** CrewMemberInformation(char* surname, char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT * FROM flights WHERE ID_helicopter = (SELECT ID_helicopter FROM commander INNER JOIN crew ON commander.ID = crew.ID_commander WHERE crew.surname = '%s');",
		surname);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}


char*** GetFlightInformation(int special, char*** columnName, int* rowCount, int* columnCount)
{
	char* text;
	if (special == 1)
		text = "yes";
	else
		text = "no";

	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT count(ID_helicopter), sum(weight_of_goods), sum(price) from flights where flights.special = '%s';",
		text);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}



char*** DateHelicopterInformation(char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT count(flights.date), sum(weight_of_goods), sum(num_of_people) FROM flights WHERE flights.date >= '%s' AND flights.date <= '%s'; ",
		firstDate, secondDate);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** HelicopterFlyDurationAndFlyingResourse(int helicopterId, char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT sum(duration), (flying_resourse - sum(duration)) FROM helicopter INNER JOIN flights ON flights.ID_helicopter = helicopter.ID WHERE ID_helicopter = %d; ",
		helicopterId);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** MaxflughtsCrewInfo(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT crew.*, SUM(price) FROM crew, flights INNER JOIN commander On commander.id = crew.ID_commander WHERE commander.id_helicopter = (SELECT id_helicopter FROM flights GROUP By id_helicopter ORDER BY COUNT(id_helicopter) DESC LIMIT 1) GROUP BY crew.ID";
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** MaxEarnedMoneyCrewInfo(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT crew.*, SUM(price) FROM crew, flights INNER JOIN commander On commander.id = crew.ID_commander WHERE commander.id_helicopter = (SELECT id_helicopter FROM flights GROUP By id_helicopter ORDER BY SUM(price) DESC LIMIT 1) GROUP BY crew.ID";
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** ShowAllHelicopters(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT * FROM helicopter;";
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** ShowAllCrewMembers(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT * FROM crew;";
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** ShowAllFlights(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT * FROM flights;";
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

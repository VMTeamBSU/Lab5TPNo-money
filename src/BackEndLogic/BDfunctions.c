#include <stdlib.h>
#include <stdio.h>
#include "../../include/request.h"
#include "../../include/BDfunctions.h"


char*** CrewMemberInformation(int id, char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT * FROM flights WHERE ID_helicopter = (SELECT ID_helicopter FROM helicopter INNER JOIN crew ON helicopter.ID = crew.ID_helicopter WHERE crew.ID = %d);",
		id);
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

char*** MaxflightsCrewInfo(char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000] = "SELECT crew.*, SUM(price) FROM crew, flights INNER JOIN helicopter On helicopter.id = crew.ID_helicopter WHERE helicopter.id = (SELECT id_helicopter FROM flights GROUP By id_helicopter ORDER BY COUNT(id_helicopter) DESC LIMIT 1) GROUP BY crew.ID";
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
	char requestBuffer[1000] = "SELECT crew.*, SUM(price) FROM crew, flights INNER JOIN helicopter On helicopter.id = crew.ID_helicopter WHERE helicopter.id = (SELECT id_helicopter FROM flights GROUP By id_helicopter ORDER BY SUM(price) DESC LIMIT 1) GROUP BY crew.ID;";
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

char*** IncomeOfCrewMember(int crewID, char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount)
{
	//TODO make divider automatic
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT sum(price), special FROM flights, crew INNER JOIN helicopter ON helicopter.id = flights.ID_helicopter AND crew.ID_helicopter = helicopter.ID WHERE crew.ID = '%d' AND flights.date >= '%s' AND flights.date <= '%s';",
		crewID, firstDate, secondDate);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

char*** IncomeOfAllCrewMembers(char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount)
{
	//TODO make divider automatic, add tranzaction (not here)
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT crew.ID, sum(price), special FROM flights, crew INNER JOIN helicopter ON helicopter.id = flights.ID_helicopter AND crew.ID_helicopter = helicopter.ID WHERE flights.date >= '%s' AND flights.date <= '%s' GROUP BY crew.ID;",
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

char*** IncomeOfCrewMemberForSpecificFlight(int isSpecial, int crewID, char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount)
{
	char* text;
	int divider = 1;
	if (isSpecial == 1) {
		text = "yes";
		divider = 10;
	}
	else
	{
		text = "no";
		divider = 5;
	}
	
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT sum(price)/%d, special FROM flights, crew INNER JOIN helicopter ON helicopter.ID = flights.ID_helicopter AND crew.ID_helicopter = helicopter.ID WHERE crew.ID = '%d' AND flights.special = '%s' AND flights.date >= '%s' AND flights.date <= '%s';",
		divider,	crewID, text, firstDate, secondDate);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}


char*** GetUserInfo(char* login, char*** columnName, int* rowCount, int* columnCount)
{
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"Select mainLogin.ID,status from mainLogin, LoginStatus where LoginStatus.ID = mainLogin.ID and login  = '%s';",login);
	
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	
	return Result;
}

int DeleteFlightById(int id)
{
	char requestBuffer[500];
	sprintf(requestBuffer,
		"BEGIN TRANSACTION; DELETE FROM flights WHERE ID = = %d; COMMIT;",
		id);

	if (Validation(requestBuffer) == 0)
		return 0;
	else
		return 1;
}

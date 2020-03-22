#include <stdlib.h>
#include <stdio.h>
#include "sqlite3.h"
#include <Windows.h>
#include "../../include/request.h"
#pragma warning(disable:4996)
struct sqlite3* db;


void CrewMemberInformation(char* text)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT * FROM flights WHERE ID_helicopter = (SELECT ID_helicopter FROM commander INNER JOIN crew ON commander.ID = crew.ID_commander WHERE crew.surname = '%s');",
		text);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	int c;
}

void SpecialOrNotInformation(char* text)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT count(ID_helicopter), sum(weight_of_goods), sum(price) from flights where flights.special = '%s'; ",
		text);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	int c;
}


int main()
{
	int run = 1;
	//int openResult = sqlite3_open("MyStudents.db", &db);
	int openResult = sqlite3_open("AirCab.db", &db);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (openResult)
	{
		printf("Cant open db\n");
	}

	while (run)
	{
		printf("SUGGESTED OPTIONS:\n");
		printf("Special flights INF: 1\n");
		printf("Usual flights INF: 2\n");
		printf("Crew member INF: 8\n");
		printf("Exit: 0\n");

		int command;
		scanf("%d", &command);

		switch (command)
		{
			
		case 8: {
			printf("Test func\n");

			printf("Insert requered ccrew memder: \n");
			char id[50];
			//int id;
			scanf("%s", &id);
			CrewMemberInformation(id);
			break;
		}
		case 1: {
			printf("Special flights INF\n");
			char* s = "yes";
			SpecialOrNotInformation(s);
			break;
		}
		case 2: {
			printf("Usual flights INF\n");
			char* s = "no";
			SpecialOrNotInformation(s);
			break;
		}
		case 0:
		{
			run = 0;
			break;

		}

		default:
		{
			printf(" Incorrect option!!!!\n");
			continue;
		}
		}

	}

}
#include "../../include/request.h"
#include "../../lib/sqlite3/sqlite3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
struct sqlite3* db;

int MainCounter = 0;
int CurrentRow = 0;
char*** MatrixResponce;
char** RequestColumnName;
int openResult;

void Init()
{
	if (db == NULL)
		openResult = sqlite3_open("../../DataBase/AirCab.db", &db);
}

static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	int i;

	RequestColumnName = (char**)calloc(argc, sizeof(char*));

	for (int i = 0; i < argc; i++)
	{
		RequestColumnName[i] = (char*)calloc(50, sizeof(char));
		strcpy(RequestColumnName[i], azColName[i]);
	}

	for (i = 0; i < argc; i++)
	{
		strcpy(MatrixResponce[CurrentRow][i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	CurrentRow++;
	return 0;
}

void MyInitFunc(int rows, int columns)
{
	MatrixResponce = (char***)calloc(rows, sizeof(char**));
	for (int i = 0; i < rows; ++i)
	{
		MatrixResponce[i] = (char**)calloc(columns, sizeof(char*));
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			MatrixResponce[i][j] = (char*)calloc(30, sizeof(char));
		}
	}
}

void MyDInit()
{
	MatrixResponce = NULL;
	RequestColumnName = NULL;
	MainCounter = 0;
	CurrentRow = 0;
}

char*** GetResult(char* RequestBuffer, int *aColumn, int *aRow, char*** aColumnName)
{
	
	sqlite3_stmt* pStmt;

	if (sqlite3_prepare_v2(db, RequestBuffer, -1, &pStmt, 0) == SQLITE_OK)
	{
		while (sqlite3_step(pStmt) == SQLITE_ROW)
		{
			MainCounter++;
		}
	}

	if (sqlite3_prepare_v2(db, RequestBuffer, -1, &pStmt, 0) == SQLITE_OK)
	{
		char* errorMsg = 0;

		int rows = MainCounter, columns = sqlite3_column_count(pStmt);


		MyInitFunc(rows, columns);


		if (sqlite3_exec(db, RequestBuffer, callback, 0, &errorMsg) != SQLITE_OK) {
			printf(errorMsg);
		}

		char*** ResultMatrix = MatrixResponce;
		*aRow = rows;
		*aColumn = columns;
		*aColumnName = RequestColumnName;
		MyDInit();

		return ResultMatrix;
	}
	else
	{
		return -1;
	}

}


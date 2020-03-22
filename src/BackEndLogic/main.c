#include <stdlib.h>
#include <stdio.h>
#include "../../lib/sqlite3/sqlite3.h"
#include <Windows.h>
#include "../../include/request.h"
#pragma warning(disable:4996)

//surname: ������� ����� �������, �� ������� �������� ������.
//columnName: ������, ������� �������� �������� �������� �� ������� ������.
//rowCount: ����������, ������� �������� ���������� � ���������� ����� � �������-������.
//columnCount: ����������, ������� �������� ���������� � ���������� ������� � �������-������.
//Result: ���� ������ ���������� �������, ���������� �������-����� �� ������ �� �������(��� ����� �������), � ��� �������� � ����������� �� ������ (*).
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

//Special: ���� Special = 1, �� �� ������� ��������� � �����������, ���� Special = 0, �� �� ������� ���������� � ������� �������.
//columnName: ������, ������� �������� �������� �������� �� ������� ������.
//rowCount: ����������, ������� �������� ���������� � ���������� ����� � �������-������.
//columnCount: ����������, ������� �������� ���������� � ���������� ������� � �������-������.
//Result: ���� ������ ���������� �������, ���������� �������-����� �� ������ �� ���� ����������, ����������� ������� ����� ��� ���������, � ����� ���������� ������, ����� ����� ������������ ������, ����� ����� ������������ �����;
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

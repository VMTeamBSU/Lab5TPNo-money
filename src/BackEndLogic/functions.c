#include <stdlib.h>
#include <stdio.h>
#include "../../include/request.h"
#pragma warning(disable:4996)

//surname: ������� ����� �������, �� ������� �������� ������.
//columnName: ������, ������� �������� �������� �������� �� ������� ������.
//rowCount: ����������, ������� �������� ���������� � ���������� ����� � �������-������.
//columnCount: ����������, ������� �������� ���������� � ���������� ������� � �������-������.
//Result: ���� ������ ���������� �������, ���������� �������-����� �� ������ �� �������(��� ����� �������), � ��� �������� � ����������� �� ������ (*).
//������� �������� ������ ��� ����������� ��������
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

//Special: åñëè Special = 1, òî ìû ïîëó÷èì èíôðìàöèþ î ñïåöâûëåòàõ, åñëè Special = 0, òî ìû ïîëó÷èì èíôîðìàöèþ î îáû÷íûõ âûëåòàõ.
//columnName: ìàññèâ, êîòîðûé ñîäåðæèò íàçâàíèÿ ñòîëáöîâ ïî ïîðÿäêó âûâîäà.
//rowCount: ïåðåìåííàÿ, êîòîðàÿ ñîäåðæèò èíôîðìàöèþ î êîëè÷åñòâå ðÿäîâ â òàáëèöå-îòâåòå.
//columnCount: ïåðåìåííàÿ, êîòîðàÿ ñîäåðæèò èíôîðìàöèþ î êîëè÷åñòâå êîëîíîê â òàáëèöå-îòâåòå.
//Result: íàøà ôóêöèÿ âîçâðàùàåò ìàòðèöó, ñîäåðæàùàÿ òàáëèöó-îòâåò íà çàïðîñ ïî âñåì âåðòîëåòàì, âûïîëíÿâøèì îáû÷íûå ðåéñû èëè ñïåöðåéñû, – îáùåå êîëè÷åñòâî ðåéñîâ, îáùàÿ ìàññà ïåðåâåçåííûõ ãðóçîâ, îáùàÿ ñóììà çàðàáîòàííûõ äåíåã;
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


//date: � �������� �������� ��������� ��������� ������ date(���� �� ������� �� ����� ���������� ���������� � �������). date ������ ���� � ������� "yyyy-mm-dd";
//columnName: ������, ������� �������� �������� �������� �� ������� ������;
//rowCount: ����������, ������� �������� ���������� � ���������� ����� � �������-������;
//columnCount: ����������, ������� �������� ���������� � ���������� ������� � �������-������;
//Result: ���� ������ ���������� �������, ���������� �������-����� �� ������ �� ������� ��������� �� ������������ ����, �� ������ ��������: ���������� ���� ������� � ���� ����, ��������� ��� ���� ������������ ������ �� ���� ����, ��������� ���������� ����� �� ���� ����. �� �������� �������������;
//������: date = '2020-02-10', Result[0][0] = 1, Result[0][1] = 3, Result[0][3] = 1;
//������� �������� ������ ��� ����������� ��������
char*** DateHelicopterInformation(char* date, char*** columnName, int* rowCount, int* columnCount)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT count(flights.date), sum(weight_of_goods), sum(num_of_people) FROM flights WHERE flights.date = '%s'; ",
		date);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, &ColumnName);
	*rowCount = row;
	*columnCount = column;
	*columnName = ColumnName;

	return Result;
}

//helicopterId: ����������, ������� �������� ID ���������.
//columnName: ������, ������� �������� �������� �������� �� ������� ������;
//rowCount: ����������, ������� �������� ���������� � ���������� ����� � �������-������;
//columnCount: ����������, ������� �������� ���������� � ���������� ������� � �������-������;
//Result: ���� ������ ���������� �������, ���������� �������-����� �� ������ �� ������� ���������: ����� ���������� �����, ������� ��� �������� ����������������� �������, � ������ ������� �������(*);
//������: ID = 1, Result[0][0] = 9(��� �����, ����������� � ������), Result[0][1] = 1086(������ ������ ����� ��� �����, ����������� � ������);
//������� �������� ������ ��� ����������� ��������
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

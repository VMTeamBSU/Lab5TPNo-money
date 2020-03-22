#include <stdlib.h>
#include <stdio.h>
#include "../include/request.h"
#pragma warning(disable:4996)

//surname: фамили€ члена экипажа, по которой делаетс€ запрос.
//columnName: массив, который содержит названи€ столбцов по пор€дку вывода.
//rowCount: переменна€, котора€ содержит информацию о количестве р€дов в таблице-ответе.
//columnCount: переменна€, котора€ содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукци€ возвращает матрица, содержаща€ таблицу-ответ на запрос по экипажу(или члену экипажа), Ц все сведени€ о выполненных им рейсах (*).
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

//Special: если Special = 1, то мы получим инфрмацию о спецвылетах, если Special = 0, то мы получим информацию о обычных вылетах.
//columnName: массив, который содержит названи€ столбцов по пор€дку вывода.
//rowCount: переменна€, котора€ содержит информацию о количестве р€дов в таблице-ответе.
//columnCount: переменна€, котора€ содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукци€ возвращает матрицу, содержаща€ таблицу-ответ на запрос по всем вертолетам, выполн€вшим обычные рейсы или спецрейсы, Ц общее количество рейсов, обща€ масса перевезенных грузов, обща€ сумма заработанных денег;
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

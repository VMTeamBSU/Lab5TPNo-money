#include <stdlib.h>
#include <stdio.h>
#include "../../include/request.h"
#pragma warning(disable:4996)

//surname: фамилия члена экипажа, по которой делается запрос.
//columnName: массив, который содержит названия столбцов по порядку вывода.
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе.
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукция возвращает матрица, содержащая таблицу-ответ на запрос по экипажу(или члену экипажа), – все сведения о выполненных им рейсах (*).
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
//columnName: массив, который содержит названия столбцов по порядку вывода.
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе.
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукция возвращает матрицу, содержащая таблицу-ответ на запрос по всем вертолетам, выполнявшим обычные рейсы или спецрейсы, – общее количество рейсов, общая масса перевезенных грузов, общая сумма заработанных денег;
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


//date: в качестве входного параметра выступает строка date(дата за которую мы хотим посмотреть информацию о полетах). date должна быть в формате "yyyy-mm-dd";
//columnName: массив, который содержит названия столбцов по порядку вывода;
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе;
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе;
//Result: наша фукция возвращает матрицу, содержащая таблицу-ответ на запрос по каждому вертолету за определенную дату, на выходе получаем: количество всех полетов в этот день, суммарное вес всех перевезенных грузов за этот день, суммарное количество людей за этот день. По столюцам соответсвенно;
//Пример: date = '2020-02-10', Result[0][0] = 1, Result[0][1] = 3, Result[0][3] = 1; 
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
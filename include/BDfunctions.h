#pragma once

//surname: фамилия члена экипажа, по которой делается запрос.
//columnName: массив, который содержит названия столбцов по порядку вывода.
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе.
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукция возвращает матрица, содержащая таблицу-ответ на запрос по экипажу(или члену экипажа), – все сведения о выполненных им рейсах (*).
char*** CrewMemberInformation(int id, char*** columnName, int* rowCount, int* columnCount);

//Special: если Special = 1, то мы получим инфрмацию о спецвылетах, если Special = 0, то мы получим информацию о обычных вылетах.
//columnName: массив, который содержит названия столбцов по порядку вывода.
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе.
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе.
//Result: наша фукция возвращает матрицу, содержащая таблицу-ответ на запрос по всем вертолетам, выполнявшим обычные рейсы или спецрейсы, – общее количество рейсов, общая масса перевезенных грузов, общая сумма заработанных денег;
char*** GetFlightInformation(int special, char*** columnName, int* rowCount, int* columnCount);

//firstDate, secondDate: в качестве входного параметра выступает строка date(период за которую мы хотим посмотреть информацию о полетах). date должна быть в формате "yyyy-mm-dd";
//columnName: массив, который содержит названия столбцов по порядку вывода;
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе;
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе;
//Result: наша фукция возвращает матрицу, содержащая таблицу-ответ на запрос по каждому вертолету за определенную дату, на выходе получаем: количество всех полетов в этот день, суммарное вес всех перевезенных грузов за этот день, суммарное количество людей за этот день. По столюцам соответсвенно;
//Пример: firstDate = '2020-02-10' secondDate = '2020-02-10', Result[0][0] = 1, Result[0][1] = 3, Result[0][3] = 1; 
char*** DateHelicopterInformation(char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount);

//helicopterId: переменная, которая содержит ID вертолета.
//columnName: массив, который содержит названия столбцов по порядку вывода;
//rowCount: переменная, которая содержит информацию о количестве рядов в таблице-ответе;
//columnCount: переменная, которая содержит информацию о количестве колонок в таблице-ответе;
//Result: наша фукция возвращает матрицу, содержащая таблицу-ответ на запрос по каждому вертолету: общее количество часов, которые они налетали послекапитального ремонта, и ресурс летного времени(*);
//Пример: ID = 1, Result[0][0] = 9(все время, проведенное в рейсах), Result[0][1] = 1086(летный ресурс минус все время, проведенное в рейсах); 
//Функция доступна только для коммандиров экипажей
char*** HelicopterFlyDurationAndFlyingResourse(int helicopterId, char*** columnName, int* rowCount, int* columnCount);

//Функция, которая выводит всю информацию об экипаже, который выполнил больше всех полетов и общее количество заработанных денег этого экипажа;
//Пример вывода: Result[0][0] = 7, Result[0][1] = 'second pilot', Result[0][2] = 833 и тд;  
char*** MaxflightsCrewInfo(char*** columnName, int* rowCount, int* columnCount);

//Функция, которая выводит всю информацию об экипаже, который заработал больше всех денег;
//Пример вывода: Result[0][0] = 7, Result[0][1] = 'second pilot', Result[0][2] = 833 и тд;  
char*** MaxEarnedMoneyCrewInfo(char*** columnName, int* rowCount, int* columnCount);

//Функция выводит всю таблицу Helicopters
char*** ShowAllHelicopters(char*** columnName, int* rowCount, int* columnCount);

//Функция выводит всю таблицу crew
char*** ShowAllCrewMembers(char*** columnName, int* rowCount, int* columnCount);

//Функция выводит всю таблицу flights
char*** ShowAllFlights(char*** columnName, int* rowCount, int* columnCount);

//firstDate, secondDate: в качестве входного параметра выступает строка date(период за которую мы хотим посмотреть информацию о полетах). date должна быть в формате "yyyy-mm-dd";
//crewID: ID человека, зарплату которого мы хотим узнать
//Выводит количесвто денег за рейс и показывает какой был рейс(special, usual). Соответсвенно зп считается в зависимоти от рейса.
char*** IncomeOfCrewMember(int crewID, char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount);

char*** IncomeOfAllCrewMembers(char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount);

//за указанный период определяет количество денег,
//начисленных указанному летчику за указанный рейс(сы) или спецрейс(сы)
char*** IncomeOfCrewMemberForSpecificFlight(int isSpecial, int crewID, char* firstDate, char* secondDate, char*** columnName, int* rowCount, int* columnCount);

char*** GetUserInfo(char* login, char*** columnName, int* rowCount, int* columnCount);

int DeleteFlightById(int id);
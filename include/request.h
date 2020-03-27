#pragma once

extern int MainCounter;
extern int CurrentRow;
extern char*** MatrixResponce;
void InitDataBase();
char*** GetResult(char* RequestBuffer, int *aColumn, int *aRow, char*** aColumnName);
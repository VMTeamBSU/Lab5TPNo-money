#pragma once

extern int MainCounter;
extern int CurrentRow;
extern char*** MatrixResponce;

char*** GetResult(char* RequestBuffer, int *aColumn, int *aRow, char*** aColumnName);

int InsertData(char* RequesInsertBuffer);
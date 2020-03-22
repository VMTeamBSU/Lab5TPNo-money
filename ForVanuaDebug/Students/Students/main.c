#include <stdlib.h>
#include <stdio.h>
#include "sqlite3.h"
#include "Windows.h"
#include "request.h"
#pragma warning(disable:4996)
struct sqlite3* db;



static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) 
	{
		printf(" %s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		
	}
	printf("\n");

	return 0;

}



void TestValueById(char* text)
{
	char requestBuffer[1000];
	sprintf(requestBuffer,
		"SELECT * FROM flights WHERE ID_helicopter = (SELECT ID_helicopter FROM commander INNER JOIN crew ON commander.ID = crew.ID_commander WHERE crew.surname = '%s');",
		text);
	char** ColumnName = NULL;
	int row = 0;
	int column = 0;
	char*** Result = GetResult(requestBuffer, &column, &row, ColumnName);
	int c;
}

void PrintValueById(int id)
{
	char requestBuffer[60];
	sprintf(requestBuffer, "SELECT * from Students where id=%d;", id);
	char* errorMsg=0;
	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg) != SQLITE_OK) {
		printf(errorMsg);
	}
}

void PrintValueByFieldPattern(char* field, char* pattern)
{
	char requestBuffer[150];
	char* errorMsg = 0;
	sprintf(requestBuffer, "SELECT * from Students where %s like '%s';",field,pattern );
	if(sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg) != SQLITE_OK)
	{
		printf(errorMsg);
	}
}

void AddStudent(char** argv)
{
	char requestBuffer[1000];
	char* errorMsg = 0;
	sprintf(requestBuffer,
		"insert into Students (id, name, surname, patronymic, sex, nation, height, weight, dateOfBirth, phoneNumber, address, course, groupNum, avarageGrade, specialization, vuz_id) values 		(%d, '%s','%s','%s', '%s', '%s', %d, %d, '%s', %d, '%s', %d, %d, %f, '%s', %d)",
		atoi(argv[0]), argv[1], argv[2], argv[3], argv[4], argv[5], atoi(argv[6]), atoi(argv[7]), argv[8], atoi(argv[9]),
		argv[10], atoi(argv[11]), atoi(argv[12]), atof(argv[13]), argv[14], atoi(argv[15]));

	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg) != SQLITE_OK)
	{
		printf(errorMsg);
	}
}

void PrintValueByvuz(char* vuz)
{
	char requestBuffer[200];
	char* errorMsg = 0;
	sprintf(requestBuffer, "SELECT * from Students INNER JOIN vuz ON vuz.id=Students.vuz_id AND vuz.vuz_name='%s';", vuz);

	if(sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg) != SQLITE_OK)
	{
		printf(errorMsg);
	}
}

void DeleteValueById(int id)
{
	char requestBuffer[200];
	char* errorMsg = 0;
	sprintf(requestBuffer, "DELETE from Students where id=%d;", id);

	if (sqlite3_exec(db, requestBuffer, callback, 0, &errorMsg) != SQLITE_OK)
	{
		printf(errorMsg);
	}
}

void PrintImnationById(int id,FILE* outFile)
{
	char requestBuffer[200];
	char* errorMsg = 0;
	sprintf(requestBuffer, "SELECT picture from Students where id=%d;", id);

	

	sqlite3_stmt* pStmt;
	sqlite3_prepare_v2(db, requestBuffer, -1, &pStmt, 0);

	int rc = sqlite3_step(pStmt);

	int bytes = 0;


	if (rc == SQLITE_ROW) {

		bytes = sqlite3_column_bytes(pStmt, 0);
	}

	fwrite(sqlite3_column_blob(pStmt, 0), bytes, 1, outFile);
	fclose(outFile);
	sqlite3_finalize(pStmt);
}

int main()
{
	int run = 1;
	//int openResult = sqlite3_open("MyStudents.db", &db);
	int openResult = sqlite3_open("AirCab.db", &db);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if(openResult)
	{
		printf("Cant open db\n");
	}

	while (run)
	{
		printf("SUGGESTED OPTIONS:\n");
		printf("Print value by id: 1\n");
		printf("Print value by field pattern: 2\n");
		printf("Print value by vuz: 3\n");
		printf("Add Student: 4\n");
		printf("Print all: 5\n");
		printf("Delete by index: 6\n");
		printf("Load image by index: 7\n");
		printf("Test block 8\n");
		printf("Exit: 0\n");

		int command;
		scanf("%d", &command);
		
			switch (command)
			{
			  case 1:
			  {
			  
			  	printf("  Insert required id \n");
			  	int id;
			  	scanf("%d", &id);
			  	PrintValueById(id);
			  	break;
			  
			  }
			  
			  case 2:
			  {
			  	printf("  Insert required field name \n");
			  	char field[30];
			  	scanf("%s", &field);
			  
			  	printf("  Insert required pattern \n");
			  	char pattern[30];
			  	scanf("%s", &pattern);
			  
			  	PrintValueByFieldPattern(field, pattern);
			  	break;
			  }
			  case 3:
			  {
				printf("  Insert required vuz name \n");
				char vuz[100];
				scanf(" %[^\n]s", &vuz);
				PrintValueByvuz(vuz);
				break;
			  }
			  case 4:
				  {
				  char id[5];
				  char name[30];
				  char surname[30];
				  char adress[50];
				  char patronymic[30];
				  char nation[30];
				  char phoneNumber[30];
				  char specialization[30];
				  char vuz_id[30];
				  char height[3];
				  char weight[3];
				  char sex[5];
				  char dateOfBirth[30];
				  char course[10];
				  char groupNum[10];
				  char avarageGrade[10];
				  
				  printf("Enter Id:");
				  scanf("%s", &id);
				  printf("Enter name:" );
				  scanf("%s", &name);
				  printf("Enter surname:");
				  scanf("%s", &surname);				  
				  printf("Enter patronymic:");
				  scanf("%s", &patronymic);
				  printf("Enter sex:");
				  scanf("%s", &sex);
				  printf("Enter nation:");
				  scanf("%s", &nation);
				  printf("Enter height:");
				  scanf("%s", &height);
				  printf("Enter weight:");
				  scanf("%s", &weight);
				  printf("Enter dateOfBirth:");
				  scanf("%s", &dateOfBirth);
				  printf("Enter adress:");
				  scanf("%s", &adress);				  
				  printf("Enter phoneNumber:");
				  scanf("%s", &phoneNumber);
				  printf("Enter specialization:");
				  scanf("%s", &specialization);
				  printf("Enter vuz_id:");
				  scanf("%s", &vuz_id);
				  printf("Enter avarageGrade:");
				  scanf("%s", &avarageGrade);
				  printf("Enter course:");
				  scanf("%s", &course);

				  char* argv[16];
				  argv[0] = id;
				  argv[1] = name;
				  argv[2] = surname;
				  argv[3] = patronymic;
				  argv[4] = sex;
				  argv[5] = nation;
				  argv[6] = height;
				  argv[7] = weight;
				  argv[8] = dateOfBirth;
				  argv[9] = phoneNumber;
				  argv[10] = adress;	
				  argv[11] = course;
				  argv[12] = groupNum;
				  argv[13] = avarageGrade;
				  argv[14] = specialization;
				  argv[15] = vuz_id;		


				  AddStudent(argv);
			  		
				  break;
				  }

			  case 5:
				  {
				  PrintValueByFieldPattern("name", "%%");
				  break;
				  }
			  case 6:
				  {
				  int id;
				  printf("Insert id\n");
				  scanf("%d", &id);
				  DeleteValueById(id);
			  		break;
				  }
			  case 7:
				  {
				  int id;
				  printf("Insert id\n");
				  scanf("%d", &id);
				  char path[50];
					  printf("Insert path\n");
					  scanf("%s", &path);
				  FILE* outFile = fopen(path, "wb");
				  PrintImnationById(id,outFile);
			  		break;
				  }
			  case 8: {
				  printf("Test func\n");

				  printf("  Insert required id \n");
				  char id[50];
				  //int id;
				  scanf("%s", &id);
				  TestValueById(id);
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
#include "../../include/UIController.h"
#include <stdio.h>
#include "../../include/Authorization.h"
#include "../../include/Registration.h"
#include "string.h"
#include "../../include/SessionController.h"
#include "../../include/BDfunctions.h"
#include "stdlib.h"

int timesToType;


int GetInteger()
{
	int result = 0;
	char input[30];
	while (fgets(input, sizeof(input), stdin))
	{
		if (IsValidNumber(input) == 1 && sscanf(input, "%d", &result) == 1)
		{
			break;
		}
		if (input[0] != '\n') {
			printf("Invalid input!\n");
		}
	}
	return result;
}

int IsValidNumber(char* string)
{
	for (int i = 0; i < strlen(string)-1; i++)
	{
		//ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
		//Checking for negative sign "-" could be added: ASCII value 45.
		if (string[i] < 48 || string[i] > 57)
			return 0;
	}

	return 1;
}

void UiControllerInit()
{
	timesToType = 3;
}

int TryLogin(char* login,char* password)
{
	timesToType--;
	if(timesToType<0)
	{
		return -2;
	}
	if (ValidateUser(login, password) == 1)
	{
		return 1;

	}
	else
	{
		return -1;
	}

}

void HandleAuthorization()
{
	system("CLS");
	int flag = 1;

	while (flag==1)
	{
		char login[30];
		char password[30];
		printf("Insert login\n");
		scanf("%s", login);
		printf("Insert password\n");
		scanf("%s", password);
		int result = TryLogin(login, password);
		if (result ==1)
		{
			printf("Loged in successfully!\n\n");
			CurrentUser = GetCurrentUser(login);
			HandleMainMenu();
			break;
		}
		if(result== -2)
		{
			printf("No more times left\n ");
			break;
		}
		else
		{
			printf("Incorrect login or password!\n\n");
		}
	}
}

void HandleMainMenu()
{
	
	while (1)
	{


		system("CLS");
		printf("Oh, you are in main menu.\n ");
		printf("Choose option \n");
		printf("Crew member information :1\n");
		printf("Flights information :2\n");
		printf("Helicopters information :3\n");

		int option = GetInteger();
		

		switch (option)
		{
		case  1:
		{
			HandleCrewMemberInfo();
			break;
		}
		case  2:
			{
			HandleFlightsInfo();
				break;
			}
		case 3:
			{
			HandleHelicopterInfo();
				break;
			}
		default:
			{
			printf("Invalid option!\n");
				break;
			}

		}
	}
	
	
}

void HandleRegistration()
{
	system("CLS");
	int stop = 1;
	char password[30];
	char passwordRepeat[30];
	char login[30];

	while (stop==1)
	{
		printf(" Enter your login: \n");

		scanf("%s", &login);
		if(FindUser(login)==1)
		{
			printf("Login is already taken \n:");
			continue;
		}
		else
		{
			int stopPass = 1;
				while (stopPass == 1) {
					printf("Insert password \n");
					scanf("%s", &password);
					printf("Insert password again\n");
					scanf("%s", &passwordRepeat);
					if(strcmp(password,passwordRepeat)!=0)
					{
						printf("Password not matching! Try again\n");
						continue;
					}
					else
					{
						RegisterUser(login, password);
						printf("User registered successfully!\n");
						CurrentUser = GetCurrentUser(login);
						HandleMainMenu();
						stop = 0;
						break;
					}


				}

			break;
		}
	}
}

void HandleStartWindow()
{
	system("CLS");
	printf("Welcome everybody!\n");
	printf("Select option\n");
	printf("Login: 1\n");
	printf("Register: 2\n");
	printf("Exit: 3\n");

	int option = GetInteger();

	
	
		
	
	
	int stop = 1;
	while (stop == 1)
	{
		switch (option)
		{
		case 1:
		{
			HandleAuthorization();
			stop = 0;
			break;
		}
		case 2:
		{
			HandleRegistration();
			stop = 0;
			break;
		}
		case 3:
		{
			stop = 0;
			break;
		}
		default:
		{
			printf("Incorrect option");
			break;
		}
		}
	}
}

void HandleCrewMemberInfo()
{
	int stop = 1;
	while (stop==1) {
		system("CLS");

		char*** result;
		int rowsCount = 0;
		int columnsCount = 0;
		char surname[30];
		char** columnsNames = NULL;


		if (CurrentUser.privilege == member) {
			strcpy(surname, CurrentUser.login);
		}
		else
		{
			printf("Insert member's surname, or print all to print all members\n");
			scanf("%s", &surname);
		}

		result = CrewMemberInformation(surname, &columnsNames, &rowsCount, &columnsCount);

		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);
		printf("\nDo you want to exit? yes/no\n");
		if (GetYesNo() == 1)
		{
			stop = 0;
		}
	}

	
}

void HandleFlightsInfo()
{
	int stop = 1;
	while (stop==1)
	{
	system("CLS");

	char*** result;
	int rowsCount = 0;
	int columnsCount = 0;
	char surname[30];
	char** columnsNames = NULL;
	int command=0;
	int isSpecial = 0;

	


		printf("Choose option:\n");

		printf("1. Special flights\n");
		printf("2. Normal flights\n");

		command = GetInteger();

		switch (command)
		{
		case 1:
		{
			isSpecial = 1;
			break;
		}
		case 2:
		{
			isSpecial = 0;
			break;
		}
		default:
		{
			printf("Invalid option!\n");
			break;
		}
		}



		result = GetFlightInformation(isSpecial, &columnsNames, &rowsCount, &columnsCount);

		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);
		char a[30];
		printf("\nDo you want to exit? yes/no\n");
		printf("\nDo you want to exit? yes/no\n");
		if (GetYesNo() == 1)
		{
			stop = 0;
		}
		
	}
}

void PrintMatrix(char*** matrix,char** columnsNames,int rawsCount,int columnsCount)
{
	for (int i = 0; i < rawsCount ; ++i)
	{
		for (int j = 0; j < columnsCount; ++j)
		{
			printf(" %s = %s\n", columnsNames[j], matrix[i][j] ? matrix[i][j] : "No information found");
		}
		printf("------------------------------------------------\n");
	}
}

//TODO find helicopters by surname
void HandleHelicopterInfo()
{
	int stop = 1;
	while (stop==1)
	{
		system("CLS");

		char*** result;
		int rowsCount = 0;
		int columnsCount = 0;
		char surname[30];
		char** columnsNames = NULL;
		int id = 0;

		printf("Choose option:\n");


		if (CurrentUser.privilege != member)
		{
			printf("Insert helicopter's id\n");
			id = GetInteger();
		}



		result = HelicopterFlyDurationAndFlyingResourse(id, &columnsNames, &rowsCount, &columnsCount);

		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);
		char a[30];
		
		printf("\nDo you want to exit? yes/no\n");
		if(GetYesNo()==1)
		{
			stop = 0;
		}
	}

}

int GetYesNo()
{
	char input[30];
	while (1)
	{


		scanf("%s", &input);
		if (strcmpi(input, "yes") == 0)
		{
			return 1;
			break;
		}
		else
		{
			if (strcmpi(input, "no") != 0)
			{
				printf("Incorrect answer! type yes/no\n");
			}
			else
			{
				return 0;
			}
		}
	}
}





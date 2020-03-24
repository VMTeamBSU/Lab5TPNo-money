#include "../../include/UIController.h"
#include <stdio.h>
#include "../../include/Authorization.h"
#include "../../include/Registration.h"
#include "string.h"

int timesToType;

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
	printf("Oh, you are in main menu.\n ");
}

void HandleRegistration()
{
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
						HandleMainMenu();
						break;
					}

					
				}
				
			break;
		}
	}
}



void HandleStartWindow()
{
	printf("Welcome everybody!\n");
	printf("Select option\n");
	printf("Login: 1\n");
	printf("Register: 2\n");
	printf("Exit: 3\n");

	int option;
	scanf("%d", &option);
	int stop = 1;
	while (stop == 1)
	{


		switch (option)
		{
		case 1:
		{
			HandleAuthorization();
			break;
		}
		case 2:
		{
			HandleRegistration();
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

#include "../../include/UIController.h"
#include <stdio.h>
#include "../../include/Authorization.h"

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
	
}



void HandleStartWindow()
{
	printf("Welcome everybody!\n");
	printf("Select option\n");
	printf("Login: 1\n");
	printf("Register: 2\n");

	int option;
	scanf("%d", &option);

	switch (option)
	{
	case 1:
		{
		HandleAuthorization();
		}
	case 2:
		{
		HandleRegistration();
		}
	default:
		{
		printf("Incorrect option");
		}
	}
}

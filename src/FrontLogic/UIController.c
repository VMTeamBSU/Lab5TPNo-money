#include "../../include/UIController.h"

#include <ctype.h>
#include <stdio.h>

#include <string.h>

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

char* GetDate()
{
	fflush(stdin);
	char input[30];
	static char* data;
	
	data = (char*)calloc(30, sizeof(char));
	
	while (fgets(input, sizeof(input), stdin))
	{
		fflush(stdin);
		if (strlen(input) == 11 && isdigit(input[0]) && isdigit(input[1]) && isdigit(input[2]) && isdigit(input[3]) && input[4] == '.'
			&& isdigit(input[5]) && isdigit(input[6]) && input[7] == '.' && isdigit(input[8]) && isdigit(input[9]))
		{
			sscanf(input, "%s", data);
			return data;
		}
		else
		{
			if(input[0]!='\n')
			printf("Invalid date input (yyyy.mm.dd)\n");
		}
	}
}


int GetEnter()
{
	char input[30];
	char charEater[30];
	/*char c;
	
	while ((c = getchar()) != '\n' && c != EOF)
	{
		
	}*/

	fflush(stdin);
	while (fgets(input, sizeof(input), stdin))
	{
		if (input[0] == '\n') {
			sscanf(input, "%s", &charEater);
			return 1;
		}
	}
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
			InitSession(login);
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
		printf("1. Crew member information\n");
		printf("2. Flights information\n");
		printf("3. Helicopters information\n");
		printf("4. Registration\n");
		printf("5. Remove flight\n");
		printf("6. Show crew rating\n");
		printf("7. Show crew income info\n");
		printf("8. Exit\n");

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
		case 4:
			{
			HandleRegistration();
			break;
			}
		case 5:
			{
			if (CurrentUser.privilege == admin) {
				HandleDeleteFlight();
			}
			else
			{
				printf("You do not have permissions to remove flights");
			}
				break;
			}
		case 6:
			{
			HandleTopRating();
				break;
			}
		case 7:
			{
			HandleMoneyInfo();
				break;
			}
		case 8:
			{
				return;
			}
		default:
			{
			printf("Invalid option!\n");
				break;
			}

		}
	}
	
	
}

void HandleRegistrationNewUser()
{
	system("CLS");
	int option;

	printf("1. Register admin\n");
	printf("2. Register commando\n");
	printf("3. Register member\n");

	option = GetInteger();

	switch (option)
	{
	case 1:
	{
		HandleRegistrationAdmin();
		break;
	}
	case 2:
	{
		HandleRegistrationCommando();
		break;
	}
	case 3:
	{
		HandleRegistrationMember();
		break;
	}
	}
	printf("Press enter to continue...\n");
}

void HandleRegistration()
{
	system("CLS");
	int option;

	printf("1. Register helicopter\n");
	printf("2. Register flight\n");
	printf("3. Register new user\n");

	option = GetInteger();

	switch (option)
	{
	case 1:
		{
			
		
		if (CurrentUser.privilege != member) {
			HandleRegistrationHelicopter();
		}
		else
		{
			printf("You do not have permissions to register new flights\n");
		}
			break;
		}
		
	case 2:
	{
		if (CurrentUser.privilege != member) {
			HandleRegisterFlight();
		}
		else
		{
			printf("You do not have permissions to register new flights\n");
		}
		break;
	}
	case 3:
	{
		if (CurrentUser.privilege == admin) {
			HandleRegistrationNewUser();
		}
		else
		{
			printf("You do not have permissions to register new users\n");
		}
		break;
	}
	}
	printf("Press enter to continue...\n");
}

void HandleRegistrationHelicopter()
{
	system("CLS");
	int stop = 1;
	char* dateOfRepair;
	char name[30];
	char* dateOfCreation;
	int capacity;
	int resources;

	printf("Enter name:\n");
	scanf(" %[^\n]", &name);
	printf("Enter date of creation:\n");
	dateOfCreation = GetDate();
	printf("Enter date of repair:\n");
	dateOfRepair = GetDate();
	printf("Enter capacity \n");
	capacity = GetInteger();
	printf("Enter flying resources amount\n");
	resources = GetInteger();

	RegisterHelicopter(name, dateOfCreation, dateOfRepair, capacity, resources);
	printf("Registered successfully! press enter to continue... \n");
	GetEnter();
}

void HandleRegistrationMember()
{
	system("CLS");
	int stop = 1;
	char password[30];
	char passwordRepeat[30];
	char login[30];
	char surname[30];
	char* dateOfBirth;
	char commanderSurname[30];
	char position[30];
	int experience;

	while (stop == 1)
	{
		printf(" Enter login: \n");
		scanf("%s", &login);

		if (FindUser(login) == 1)
		{
			printf("Login is already taken \n:");
			continue;
		}
		else
		{
			printf(" Enter surname: \n");
			scanf("%s", &surname);

			printf(" Enter date of birth (yyyy.mm.dd): \n");
			dateOfBirth = GetDate();

			printf("Enter experience: \n");
			experience = GetInteger();

			printf(" Enter commander's surname: \n");
			scanf("%s", &commanderSurname);

			int stopPass = 1;
			while (stopPass == 1) {
				printf("Insert password \n");
				scanf("%s", &password);
				printf("Insert password again\n");
				scanf("%s", &passwordRepeat);
				if (strcmp(password, passwordRepeat) != 0)
				{
					printf("Password not matching! Try again\n");
					continue;
				}
				else
				{
					RegisterMember(login, password, surname, experience, dateOfBirth, position, commanderSurname);
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

void HandleRegistrationCommando()
{
	system("CLS");
	int stop = 1;
	char password[30];
	char passwordRepeat[30];
	char login[30];
	char surname[30];
	char* dateOfBirth;
	char position[30];
	int experience;

	while (stop == 1)
	{
		printf(" Enter login: \n");
		scanf("%s", &login);

		if (FindUser(login) == 1)
		{
			printf("Login is already taken \n:");
			continue;
		}
		else
		{
			printf(" Enter surname: \n");
			scanf("%s", &surname);

			printf(" Enter date of birth (yyyy.mm.dd): \n");
			dateOfBirth = GetDate();

			printf("Enter experience: \n");
			experience = GetInteger();

			int stopPass = 1;
			while (stopPass == 1) {
				printf("Insert password \n");
				scanf("%s", &password);
				printf("Insert password again\n");
				scanf("%s", &passwordRepeat);
				if (strcmp(password, passwordRepeat) != 0)
				{
					printf("Password not matching! Try again\n");
					continue;
				}
				else
				{
					RegisterCommando(login, password, surname, experience, dateOfBirth, position);
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

void HandleRegistrationAdmin()
{
	system("CLS");
	int stop = 1;
	char password[30];
	char passwordRepeat[30];
	char login[30];

	while (stop == 1)
	{
		printf(" Enter login: \n");
		scanf("%s", &login);

		if (FindUser(login) == 1)
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
				if (strcmp(password, passwordRepeat) != 0)
				{
					printf("Password not matching! Try again\n");
					continue;
				}
				else
				{
					RegisterAdmin(login, password);
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

void HandleRegisterFlight()
{
	char* date;
	char helicopterName[30];
	int weightOfGoods;
	int numberOfPeople;
	int duration;
	int price;
	int isSpecial;

	printf("enter date (yyyy.mm.dd):\n");
	date = GetDate();
	printf("enter helicopter's name:\n");
	scanf(" %[^\n]", &helicopterName);
	printf("enter weight of goods:\n");
	weightOfGoods = GetInteger();
	printf("enter number of people:\n");
	numberOfPeople = GetInteger();
	printf("enter flight duration:\n");
	duration = GetInteger();
	printf("enter price:\n");
	price = GetInteger();
	printf("enter if flight is special (yes/no) :\n");
	if(GetYesNo()==1)
	{
		isSpecial = 1;
	}
	else
	{
		isSpecial = 0;
	}

	if(RegisterFlight(date,helicopterName, weightOfGoods, numberOfPeople, duration, price,isSpecial)!=1)
	{
		printf("Registration failed!Not enough flying resources\n");
	}
	else {
		printf("Registration done successfully!\n");
	}
	
	printf("Press enter to continue...\n");
	GetEnter();
	

	
}

void HandleStartWindow()
{
	system("CLS");
	printf("Welcome everybody!\n");
	printf("Select option\n");
	printf("1. Login\n");
	printf("2. Exit\n");
	
	int stop = 1;
	while (stop == 1)
	{
		int option = GetInteger();
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
			printf("Insert member's surname, or print \"all\" to print all members\n");
			scanf("%s", &surname);
		}

		if(strcmp(surname,"all")==0)
		{
			result = ShowAllCrewMembers(&columnsNames, &rowsCount, &columnsCount);
		}
		else {
			result = CrewMemberInformation(surname, &columnsNames, &rowsCount, &columnsCount);
		}
		
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
	int isSpecial = -1;

	


		printf("Choose option:\n");

		printf("1. Special flights report\n");
		printf("2. Normal flights report\n");
		printf("3. All flights list\n");
		printf("4. Report of flights during period\n");
		printf("5. exit\n");

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
		case 3:
		{
			isSpecial = -1;
				break;
		}
		case 4:
		{

			HandleFlightsInfoByDate();
			break;
		}
		case 5:
			{
			stop = 0;
			break;
			}
		default:
		{
			printf("Invalid option!\n");
			break;
		}
		}
	if (stop=0)
	{
		break;
	}

		if(isSpecial==-1)
		{
			result = ShowAllFlights(&columnsNames, &rowsCount, &columnsCount);
		}
		else {
			result = GetFlightInformation(isSpecial, &columnsNames, &rowsCount, &columnsCount);
			strcpy(columnsNames[0], "number of flights");
		}
		
		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);
		printf("\nPress enter to continue\n");
		GetEnter();
		
	}
}

void PrintMatrix(char*** matrix,char** columnsNames,int rowsCount,int columnsCount)
{
	for (int i = 0; i < rowsCount ; ++i)
	{
		for (int j = 0; j < columnsCount; ++j)
		{
			
			printf(" %s = %s\n", columnsNames[j], matrix[i][j] && strcmp(matrix[i][j],"NULL")!=0 ? matrix[i][j] : "No information found");
		}
		printf("------------------------------------------------\n");
	}
}

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
			printf("Insert helicopter's id \n");
			id = GetInteger();
		}
		/*else
		{
			id = CurrentUser.id;
		}*/

		result = HelicopterFlyDurationAndFlyingResourse(id, &columnsNames, &rowsCount, &columnsCount);

		strcpy(columnsNames[1], "fly resource remaining");
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

void HandleDeleteFlight()
{
	while (1)
	{


		char*** result;
		int rowsCount = 0;
		int columnsCount = 0;
		char** columnsNames = NULL;
		int id = 0;



		result = ShowAllFlights(&columnsNames, &rowsCount, &columnsCount);

		PrintMatrix(result, columnsNames, rowsCount, columnsCount);

		printf("-------------------------------------\n");
		printf("Enter flights id\n");
		id = GetInteger();
		//TODO delete here....
		
		printf("Deleted successfully!Do you want to exit?\n");
		if(GetYesNo()==1)
		{
			break;
		}
		
		
	}
	
}

void HandleTopRating()
{
	char*** result;
	int rowsCount = 0;
	int columnsCount = 0;
	char** columnsNames = NULL;

	result = MaxflughtsCrewInfo(&columnsNames, &rowsCount, &columnsCount);

	printf("Crew with max flight's count\n");
	PrintMatrix(result, columnsNames, rowsCount, columnsCount);

	result = MaxEarnedMoneyCrewInfo(&columnsNames, &rowsCount, &columnsCount);

	printf("Crew, earned highest amount of money\n");
	PrintMatrix(result, columnsNames, rowsCount, columnsCount);

	printf("Print enter to continue...\n");
	GetEnter();
	

	
}

void HandleFlightsInfoByDate()
{
	int stop = 1;
	while (stop == 1)
	{
		system("CLS");

		char*** result;
		int rowsCount = 0;
		int columnsCount = 0;
		char surname[30];
		char** columnsNames = NULL;
		char* date1;
		char* date2;
		
		int id = 0;

		printf("Choose option:\n");


		if (CurrentUser.privilege != member)
		{
			printf("Insert start date (yyyy.mm.dd)\n");
			date1 = GetDate();
			printf("Insert last date (yyyy.mm.dd)\n");
			date2 = GetDate();
		}

		result = DateHelicopterInformation(date1,date2, &columnsNames, &rowsCount, &columnsCount);

		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);

		printf("\nDo you want to continue? yes/no\n");
		if (GetYesNo() == 0)
		{
			break;
		}
	}
}

void HandleMoneyInfo()
{

	int stop = 1;
	while (stop == 1)
	{
		system("CLS");

		char*** result;
		int rowsCount = 0;
		int columnsCount = 0;
		char surname[30];
		char** columnsNames = NULL;
		char* date1;
		char* date2;
		int id;
		int special = -1;
		int option;


		if (CurrentUser.privilege != member)
		{
			printf("print member's id\n");
			id = GetInteger();

		}
		else {
			id = CurrentUser.id;
		}


		printf("Insert start date (yyyy.mm.dd)\n");
		date1 = GetDate();
		printf("Insert last date (yyyy.mm.dd)\n");
		date2 = GetDate();

		system("CLS");
		printf("Choose option\n");
		printf("1. special flights\n");
		printf("2. normal flights\n");
		printf("3. all flights\n");

		option = GetInteger();

		int stop = 1;
		while (stop==1)
		{


			switch (option)
			{
			case 1:
			{
				result = IncomeOfCrewMemberForSpecificFlight(1, id, date1, date2, &columnsNames, &rowsCount, &columnsCount);
				stop = 0;
				break;
			}
			case 2:
			{
				
				result = IncomeOfCrewMemberForSpecificFlight(0, id, date1, date2, &columnsNames, &rowsCount, &columnsCount);
				stop = 0;
				break;
			}
			case 3:
			{				
				result = IncomeOfCrewMember( id, date1, date2, &columnsNames, &rowsCount, &columnsCount);
				stop = 0;
				break;
			}
			default:
			{
				printf("invalid option!\n");
				break;
			}
			}
		}
		
		
		/*result=*/

		printf("result:\n-----------------------------------\n");
		PrintMatrix(result, columnsNames, rowsCount, columnsCount);

		printf("\nDo you want to continue? yes/no\n");
		if (GetYesNo() == 0)
		{
			break;
		}
	}
}




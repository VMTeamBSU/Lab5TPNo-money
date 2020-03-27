//Author: Ivan Shishlyannikov

//Description: This interface describes  whole UI behaviour

#pragma once

//handles dialog for flight registration
void HandleRegisterFlight();

//handles authorization dialog  
void HandleAuthorization();

//handles registration dialog 
void HandleRegistration();

//handles dialog of registration of new crew member 
void HandleRegistrationMember();

//handles dialog of registration of new helicopter 
void HandleRegistrationHelicopter();

//handles dialog of registration of new commando 
void HandleRegistrationCommando();

void HandleRegistrationAdmin();

//handles main menu dialog 
void HandleMainMenu();

//handles dialog of menu of registration of new users (members and commanders) 
void HandleRegistrationNewUser();

//handles first window user will see at the start of application run 
void HandleStartWindow();

//whole UI initialization should be done here. 
void UiControllerInit();

//handles members info dialog
void HandleCrewMemberInfo();

//handles flights info dialog
void HandleFlightsInfo();

//handles helicopters info dialog
void HandleHelicopterInfo();

//handles dialog of flights info by date
void HandleFlightsInfoByDate();

//handles dialog of flights remove
void HandleDeleteFlight();

//handles dialog of top crew ratings
void HandleTopRating();

//handles dialog of info about crews salary
void HandleMoneyInfo();

//Gets yes/no input from user
//returns 1 if "yes", 0 if "no"
int GetYesNo();

//Gets integer input from user
//returns entered int value
int GetInteger();

//Gets date input from user
//returns date in format (yyyy.mm.dd)
char* GetDate();

//Checks if string is valid number equivalent
//returns 1 if "true", 0 if "false"
int IsValidNumber(char* string);

//Prints given matrix
//matrix: matrix to print
//columnNames: matrix column names
//rowsCount: number of rows in matrix
//columnCount: number of columns in matrix
void PrintMatrix(char*** matrix, char** columnsNames, int rowsCount, int columnsCount);

//Tries to login
//returns 1 if login and password areValid, 0 if not valid, 2 if user reached types limit
int TryLogin(char* login, char* password);
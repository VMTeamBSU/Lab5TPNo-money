
void DisplayData();
void HandleAuthorization();
void HandleRegistration();
void HandleMainMenu();
void HandleStartWindow();
void UiControllerInit();
void HandleCrewMemberInfo();
void HandleFlightsInfo();
void HandleHelicopterInfo();
void HandleFlightsInfoByDate();
int GetYesNo();
int GetInteger();
int IsValidNumber(char* string);
void PrintMatrix(char*** matrix, char** columnsNames, int rawsCount, int columnsCount);
int TryLogin(char* login, char* password);
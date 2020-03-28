
int RegisterMember(char* login, char* password, char* surname, int experience, char* dateOfBirth, char* position, char* commanderName);
int RegisterCommando(char* login, char* password, char* surname, int experience, char* dateOfBirth, char* position);
int RegisterAdmin(char* login, char* password);
int RegisterHelicopter(char* name, char* creationDate, char* repairDate, int capacity, int flyingResources);
int RegisterFlight(char* date, int helicopterID, int weightOfGoods, int numberOfPeople, int duration, int price, int isSpecial);
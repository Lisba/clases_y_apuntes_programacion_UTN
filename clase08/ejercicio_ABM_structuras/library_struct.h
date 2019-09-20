typedef struct
{
    char name[20];
    char lastName[20];
    int file;
    int state;
} ePerson;

void menu(void);
ePerson addPerson (void);
void addPersonsList(ePerson personList[], int lenght);
void modifyPerson (ePerson personList[], int length);
void showOnePerson(ePerson onePerson);
void showPersonList(ePerson personList[], int length);
void sortPeopleByLastName(ePerson personList[], int lengh);
void erasePerson(ePerson personList[], int length);

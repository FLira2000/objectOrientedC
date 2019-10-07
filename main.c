#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* FirstName;
    char* LastName;
    char* (*ConcatBothNames)(char *, char *);
}Person;

Person* createPerson(){
    Person *p = malloc(sizeof(Person));
    p->FirstName = NULL;
    p->LastName = NULL;

    char* concatBothNames(char* First, char* Last){
        char* temp;
        strcpy(temp, "");
        strcat(temp, First);
        strcat(temp, " ");
        strcat(temp, Last);
        return temp;
    }
    
    p->ConcatBothNames = concatBothNames;
    return p;
}

int main(){
    Person *p = createPerson();
    p->FirstName = "Fabio";
    p->LastName = "Lira";

    printf("Bem vindo, %s!", p->ConcatBothNames(p->FirstName, p->LastName));
    return 0;
}
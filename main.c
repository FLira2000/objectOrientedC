#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* concatBothNames(char* First, char* Last){
    char* temp;
    strcpy(temp, "");
    strcat(temp, First);
    strcat(temp, " ");
    strcat(temp, Last);
    return temp;
}

typedef struct {
    char* FirstName;
    char* LastName;
    char* (*ConcatBothNames)(char *, char *);
}Person;

Person* createPerson(){
    Person *p = malloc(sizeof(Person));
    p->ConcatBothNames = &concatBothNames;
    return p;
}

int main(){
    Person *p = createPerson();
    p->FirstName = "Fabio";
    p->LastName = "Lira";

    printf("Bem vindo, %s!", p->ConcatBothNames(p->FirstName, p->LastName));
    return 0;
}
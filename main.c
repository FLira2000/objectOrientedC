#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
    void* self;
    char* firstName;
    char* lastName;
    char* (*fullName)(struct p*);
}Person;

char* concatBothNames(Person *p){
    char* temp;
    strcpy(temp, "");
    strcat(temp, p->firstName);
    strcat(temp, " ");
    strcat(temp, p->lastName);
    return temp;
}

Person* createPerson(){
    Person *p = malloc(sizeof(Person));
    p->firstName = NULL;
    p->lastName= NULL;
    p->self = p;
    
    p->fullName = &concatBothNames;
    return p;
}

int main(){
    Person *p = createPerson();
    p->firstName = "Fabio";
    p->lastName = "Lira";

    printf("Bem vindo, %s!", p->fullName(p->self));
    return 0;
}
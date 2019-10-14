#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
    void* self;
    char* FirstName;
    char* LastName;
    char* (*ConcatBothNames)(struct p*);
}Person;

Person* createPerson(){
    Person *p = malloc(sizeof(Person));
    p->FirstName = NULL;
    p->LastName = NULL;
    p->self = p;

    char* concatBothNames(Person *p){
        char* temp;
        strcpy(temp, "");
        strcat(temp, p->FirstName);
        strcat(temp, " ");
        strcat(temp, p->LastName);
        return temp;
    }
    
    p->ConcatBothNames = &concatBothNames;
    return p;
}

int main(){
    Person *p = createPerson();
    p->FirstName = "Fabio";
    p->LastName = "Lira";

    printf("Bem vindo, %s!", p->ConcatBothNames(p->self));
    return 0;
}
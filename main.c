#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CURRENTYEAR 2019
typedef struct p {
    int age;
    char* firstName;
    char* lastName;
    void* self;
    void (*setAge)(struct p*, int);
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

void setAge(Person *p, int birthYear){
    p->age = 2019 - birthYear;
}

Person* createPerson(){
    Person *p = (Person*) malloc(sizeof(Person));
    p->firstName = NULL;
    p->lastName= NULL;
    p->self = p;
    
    p->fullName = &concatBothNames;
    p->setAge = &setAge;
    return p;
}

int main(){
    Person *p = createPerson();
    p->firstName = "Fabio";
    p->lastName = "Lira";
    ///p->setAge(p->self, 2000);
    p->age = 18; //For some reason, this isn't working. /*TODO*/
    printf("Bem vindo, %s! \n", p->fullName(p->self));
    printf("Voce tem %d anos.", p->age);
    return 0;
}
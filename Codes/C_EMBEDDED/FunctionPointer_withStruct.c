#include <stdio.h>

typedef struct Person
{
    char name[10];
    int age;
    void (*print) (struct Person *p);
}Person;

void printName(Person *pn){
    printf("%s\n",pn->name);
}
void printAll(Person *pl){
    printf("%s\n",pl->name);
    printf("%d\n",pl->age);
}


int main(){
    Person p1 = {"yuchuanwei", 26, printName};
    Person p2 = {"tangshijia", 23, printAll};
    p1.print(&p1);
    p2.print(&p2);
    return 0;
}
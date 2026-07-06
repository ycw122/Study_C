#include <stdio.h>

/* 这里使用typedef 创建新类型的结构体时为什么还要加上结构体标签？(第一个Person)?
    因为结构体内部变量使用了结构体本身，如果不加标签编译器无法识别内部定义的结构体变量。
    末尾的Person就是创建新类型的结构体，那么就可以使用Person p来定义结构体变量了。
    链表定义结构体时和这个类型相同。
 */
typedef struct Person
{
    char name[10];
    int age;
    void (*print)(struct Person *p);
} Person;

void printName(Person *pn)
{
    printf("%s\n", pn->name);
}
void printAll(Person *pl)
{
    printf("%s\n", pl->name);
    printf("%d\n", pl->age);
}

int main()
{
    Person p1 = {"yuchuanwei", 26, printName};
    Person p2 = {"tangshijia", 23, printAll};
    p1.print(&p1);
    p2.print(&p2);
    return 0;
}
#include <stdio.h>
#include <iostream>

inline int fun1()
{
    printf("fun1");
    throw 100;
    printf("fun1");
    return 0;
}

void fun2() 
{
    printf("fun2");
    fun1();
    printf("fun2");
}

void fun3() 
{
    printf("fun3");
    try
    {
    fun2();
    }
    catch(int i)
    {
        printf("exception%d",i);
    }
    printf("fun3");
}

int main(int argc, char **argv)
{
    fun3();
	printf("hello world\n");
	return 0;
}

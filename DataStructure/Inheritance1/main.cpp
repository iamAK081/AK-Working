#include <stdio.h>
#include<iostream>

class Base
{
public:
    void fun()
    {
        
    }
    void fun(int n)
    {
        std::cout<<n;
    }
};

class Dervied : public Base{
public:
    void fun()
    {
        
    }
};
int main(int argc, char **argv)
{
    Dervied d;
    d.Base::fun(5);
	printf("hello world\n");
	return 0;
}

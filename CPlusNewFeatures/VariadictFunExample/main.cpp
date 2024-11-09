#include <stdio.h>
#include <iostream>
using namespace std;

void outprint()
{
    cout<<"To handle variadic function, this function is required";
}

template<typename T,typename... Types>
void outprint(T arg1,Types... arg2)
{
    cout<<arg1;
    outprint(arg2...);
}

int main(int argc, char **argv)
{
   
    outprint("hello",12345);
	printf("hello world\n");
	return 0;
}

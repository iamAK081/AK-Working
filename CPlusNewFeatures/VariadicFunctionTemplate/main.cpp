#include <stdio.h>
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
    cout<<"Iam Empty function";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template<typename T,typename... Types>
void print(T arg1,Types... arg2)
{
    cout<<arg1;
    print(arg2...);
}

int main(int argc, char **argv)
{
    print(1,2,3,"Hai");
	printf("hello world\n");
	return 0;
}

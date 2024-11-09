#include <stdio.h>
#include <iostream>
using namespace std;

//constexpr int add(int a, int b) { return a + b;}

constexpr int fib(int n) { return (n <=1) ? n : fib(n-1) + fib(n-2); }
constexpr int fact(int n) { return (n <=1) ? 1 : fact(n-1) * n; }

int main(int argc, char **argv)
{
    //constexpr int b = add(10,20);
    cout<<fib(30);
	printf("hello world\n");
	return 0;
}

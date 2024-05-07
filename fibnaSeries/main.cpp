#include <stdio.h>
#include <iostream>
using namespace std;

int fib(int n)
{
    if( n == 0 || n == 1)
        return 1;
        
    return fib(n-2) + fib(n-1);
}

//without recursive
int fibWithOutRec(int n)
{
    int cur = 0, pre = 1;
    for(int i = 0; i < n; i++)
    {
        cur = i + pre;
        pre = cur;
        
    }
    
    return cur;
}
int main(int argc, char **argv)
{
    std::cout<<fibWithOutRec(5);
	printf("hello world\n");
	return 0;
}

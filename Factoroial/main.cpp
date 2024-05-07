#include <stdio.h>
#include <iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;
    else
    {
           return fact(n-1) * n; 
    }
}

int factwithout(int n)
{
    if(n==0)
        return 1;
    
    int prv = 1;int cur = 0;
    for(int i = 1; i < n; i++)
    {
        cur = i * prv;
        prv = cur;
    }
    return cur;
}
int main(int argc, char **argv)
{
    int fa = factwithout(5);
    std::cout<<fa;
	printf("hello world\n");
	return 0;
}

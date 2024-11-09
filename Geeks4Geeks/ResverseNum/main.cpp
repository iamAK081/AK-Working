#include <stdio.h>
#include <iostream>
using namespace std;

void revnum(int num)
{
    int r = 0;
    while(num)
    {
        int t = num % 10;
        r= r * 10 + t;
        num = num / 10;        
    }
    
    cout<<r;
}

int main(int argc, char **argv)
{
    int num = 1234;
    revnum(num);
	printf("hello world\n");
	return 0;
}

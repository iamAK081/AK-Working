#include <iostream>
using namespace std;

void TowerOfHannai(int n,int a,int b,int c)
{
    if(n>0)
    {
        TowerOfHannai(n-1,a,c,b);
        cout<<"Move A to C using B\n";
        TowerOfHannai(n-1,b,a,c);
    }
  
}
int main(int argc, char **argv)
{
    int a=1,b=2,c=3;
    TowerOfHannai(3,a,b,c);
    std::cout << "Hello World" << std::endl;
    return 0;
}

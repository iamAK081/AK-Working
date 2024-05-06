#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    int a[5] = {1,2,3,4,5};
    int b[4] = {2,3,6,7};
    int c[5];
    int i = 0,j=0,k=0;
    //intersection only matching element coping to the third array
    
    while(i < 5 && j < 4)
    {
        if(a[i] < b[j])
            i++;
        else if(b[j] < a[i])
            j++;
        else if(a[i] == b[j])
        {
            c[k++] = a[i++];
            j++;
        }
    }
    
    for(int l = 0; l <k; l++)
        cout<<c[l];
	printf("hello world\n");
	return 0;
}

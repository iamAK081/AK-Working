#include <stdio.h>
#include<iostream>

//method1
int main1(int argc, char **argv)
{
    int a[] = {1,2,3,4,6,7,8,9};
    int sum = 0;
    int n = 9;
    for(int i = 0; i < 8; i++)
    {
        sum += a[i];
    }
    int l = (n*(n+1)/2);
    int re = l - sum;
    std::cout<<"missing Element is :"<<re;
	printf("hello world\n");
	return 0;
}

int main1()
{
    int a[] = {1,2,3,4,6,7,8,9};
    int l = a[0];
    int diff = l - 0;
    for(int i = 0; i < 8; i++)
    {
        if(a[i]-i != diff)
        {
            std::cout<<"Missing Element found : " << i + diff;
            break;
        }
    }
    
}

//mulple missing 
//method1
int MulpleMissing()
{
    int missing[10];
    int k = 0;

    int a[] = {1,2,3,4,6,7,8,9,10,13,16};
    int n = sizeof(a) / sizeof(int);
    int diff = a[0] - 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i]-i != diff)
        {
            while(diff < a[i] - i)
            {
                missing[k++] = diff + i;
            diff++;
            }
        }         
    }
    
    std::cout<<"Missing Element in the array:"<<std::endl;
    for(int l = 0 ;l < k; l++)
        std::cout<<missing[l]<<std::endl;
    
}

int main()
{
    int a[] = {1,2,3,4,6,7,8,9,10,13,16};
    int n = sizeof(a) / sizeof(int);
    int m[n];
    for(int i = 0; i < n; i++)
    {
        m[i] = 0;
    }
    
    for(int j = 0; j < n;j++)
    {
        int idx = a[j];
        m[idx] = 1;        
    }
    
    for(int i = 0; i < n; i++)
    {
        if(m[i] != 1)
            std::cout<<m[i];
    }
    
    
    return 0;
}
#include <stdio.h>
#include<iostream>
#include<cstring>
using namespace std;


//find duplicate using hasing method

void DuplicateHashMethod(int array[],int n)
{
    
    int m = array[n-1] + 1;
    int hash[m];
    for(int j = 0; j <m ; j++)
        hash[j] = 0;
    
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(hash[array[i]] == 0)
            hash[array[i]] = array[i];
       //hash[array[i]]++;
    }
    

    int l = 0;
    for(int j = 0; j <n ; j++)
    {
        if(hash[j] != 0)
            array[l++] = hash[j];

      /*  if(hash[j] > 1)
        {
            cout<<"\n\nDuplicate no is"<<(j) <<"No of times:"<<hash[j];
        }*/
    }
    
     for(int j = 0; j <l ; j++)
         cout<<array[j];
    
}
void coutNoDuplicate(int array[],int n)
{
    int lastduplicate = 0;
    
    int count = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(lastduplicate == array[i])
            count++;
            
        if(array[i] == array[i+1] && array[i] != lastduplicate)
        {
            lastduplicate = array[i];
            int j = i +1;
            
            while(array[i] == array[j])
                j++;
            count = j - i;
            cout<<"\n No of Count for "<<array[i] <<"No of times" <<count;
            i = j-1;
        }
       
    }
    
}

int LastDuplicate(int array[],int n)
{
    int lastduplicate = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(array[i] == array[i+1] && array[i] != lastduplicate)
        {
            lastduplicate = array[i];
        }
    }
    
    return lastduplicate;
}
int main(int argc, char **argv)
{
    int array[10]= {1,2,3,4,4,5,6,8,8,8};
   // std::cout<<LastDuplicate(array,10);
   // coutNoDuplicate(array,10);
    DuplicateHashMethod(array,10);
	//printf("hello world\n");
	return 0;
}

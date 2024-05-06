#include <stdio.h>
#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int c;
    c = *b;
    *b = *a;
    *a = c;
}
void reverseArray(int Array[],int n)
{
    for(int i=0, j = n -1;i<j; i++,j--)
    {
        swap(&Array[i],&Array[j]);
    }
    
   

}

void circlurArray(int Array[],int n)
{
    int l = n;
    
    while(1)
    {
        int c = Array[0];
        for(int i = 0; i < n; i++)
        {      
            Array[i] = Array[i+1];
        
        }
        Array[n] =c;
        
         for(int i=0; i < n; i++)
        {
            std::cout<<Array[i];
        }
        std::cout<<endl;
    }
}

void MergeArray(int *a, int *b, int *c,int m, int n)
{
    int i = 0, j = 0, k = 0;
   // int m = sizeof(a) / sizeof(a[0]);
   // int n = sizeof(b) / sizeof(b[0]);
    
    while(i < m && j < n)
    {
       if(a[i] < b[j])
        {
            c[k++] = a[i++];
            std::cout<<c[k-1];
        }
        else
        {
            c[k++] = b[j++];
            std::cout<<c[k-1];
        }
    }
    
    for(;i<m;i++)
    {
        c[k++] = a[i];
    }
    
     for(;j<n;j++)
    {
        c[k++] = a[j];
    }
    
    for(int l = 0; l < m+ n; l++)
        std::cout<<c[l];
}

int main(int argc, char **argv)
{
  //  int A[] = {1,2,3,4,0,};
   // reverseArray(A,4);
  //  circlurArray(A,4);
    int A[4] = {1,2,3,4};
    int B[3] = {2,5,6};
    int C[7];
    
   
    MergeArray(A,B,C,4,3);
	printf("hello world\n");
	return 0;
}

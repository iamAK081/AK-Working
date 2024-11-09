#include <stdio.h>
#include<iostream>
using namespace std;

#define SIZE 10

//(h(x) + f(i)) % 10

int Hash(int key)
{
    return key % 10; // h(x) = x%10;
}

int prob(int H[],int key)
{
    int index = Hash(key);
    int i = 0;
     while(H[(i+1) % 10] != 0)
         i++;
    return (i+1) %10;
}

int search(int H[],int key)
{
    int index = Hash(key);
    int i = 0;
    while(H[(index+i) %10] != key)
        i++;
        return (index+i) % 10;
}

void Insert(int H[],int key)
{
    int index = Hash(key);
    while(H[index] != 0)
    {
        index = prob(H,key);
    }
    //H[index] = key;
}


int main(int argc, char **argv)
{
    int HT[SIZE];
    Insert(HT,5);
    Insert(HT,6);
	printf("hello world\n");
	return 0;
}

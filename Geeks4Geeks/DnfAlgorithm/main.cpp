#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void dnfSort(int arr[], int n) 
{
    int l =0, m =0, h = n-1;
    while(m <= h)
    {
        switch(arr[m])
        {
            case 0:
            swap(arr[m],arr[l]);
            m++;
            l++;
            break;
            
            case 1:
            m++;
            break;
            
            case 2:
            swap(arr[m],arr[h]);
            h = h-1;
            break;
        }
        
    }
}


int main() {
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    dnfSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
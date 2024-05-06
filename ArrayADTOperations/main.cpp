#include <stdio.h>
#include<iostream>
using namespace std;

struct Array
{
    int *A; // array data
    int size; // size of the array
    int len; // len of the array    
};

Array arr;

void Add(int x)
{
    if(arr.len < arr.size)
    {
        arr.A[arr.len] = x;
        arr.len++;
    }
}

void Insert(int x,int ind)
{
    if(ind < arr.size)
    {
        for(int i = arr.len; i > ind; i--)
        {
            arr.A[i] = arr.A[i-1];            
        }
        arr.A[ind-1] = x;
        arr.len++;
    }
}

void Delete(int ind)
{
    ind = ind -1;
    if(ind < arr.size)
    {
        for(int i = ind; i < arr.len; i++)
        {
            arr.A[i] = arr.A[i + 1];
        }
        arr.len--;
    }
}

void swap(int *a, int *b) 
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}
int LinearSearch(int x)
{
    for(int i = 0; i < arr.len; i++)
    {
        if(arr.A[i] == x)
        {
            swap(arr.A[i],arr.A[i-1]);
            return i;
        }
        
    }
    
    return 0;
}

int BinarySearch(int x)
{
    int l = 0,mid = 0;
    int h = arr.len -1;
    
    
    while(l <= h)
    {
        int mid = (l + h) / 2;
        
        if(arr.A[mid] == x)
            return mid;
        if(arr.A[mid] > x)
            h = mid -1;
        else
            l = mid +1;
        
    }
    
    
}

void Display()
{
    for(int i = 0; i<arr.len; i++)
    {
        cout<<"The numbers are:"<<arr.A[i]<<endl;
    }
}

int GetIndexValue(int index)
{
    if(index >= 0 && index < arr.len)
    {
        return arr.A[index];
    }
}

int MaxInArray()
{
    int max = arr.A[0];
    for(int i = 0; i < arr.len; i++)
    {
        if(arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    
    return max;
}

int MinInArray()
{
    int min = arr.A[0];
    for(int i = 0; i < arr.len; i++)
    {
        if(min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    
    return min;
}


int main(int argc, char **argv)
{
    arr.size = 10;
    arr.A = new int[arr.size];
    arr.len = 0;
    
    while(1)
    {
        cout<<"\nEnter the below operation to perform: \n \
        1.Add(x) \n \
        2.Insert(x,i) \n \
        3.Delete(ind) \n \
        4.LinearSearch(x) \n \
        5.Display()\n \
        11.exit \n\n";
    
        int opt;
        cin>>opt;
    
        switch(opt)
        {
            case 1:
            {
                cout<<"\n\nEnter the number to add in the array";
                int x;
                cin>>x;
                Add(x);
            }
            break;
            
            case 2:
            {
                int x;
                cout<<"\n Enter the number to insert:";
                cin>>x;
                cout<<"\n Enter the index to insert";
                int i;
                cin>>i;
            
                Insert(x,i);
            
            }
            break;
            
            case 3:
            {
                int ind;
                cout<<"\nEnter the index to be deleted from Arry:";
                cin>>ind;
                Delete(ind);
            }
            break;
            
             case 4:
            {
                int ind;
                cout<<"\nEnter the number to search in the Arry:";
                cin>>ind;
                int st = LinearSearch(ind);
                if(st != 0)
                    cout<<"\nThe index of the element is :"<<st<<endl;
                else
                    cout<<"\n The given nunber is not availble in the array\n";
            }
            break;
            
            case 5:
                Display();
            break;
        
            case 11:
            break;                
        
        }
    }
    
	
	return 0;
}

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
}*first=nullptr;

void createLinkedList(int array[],int n)
{
    struct Node* t, *last;
    first = (struct Node*) malloc (sizeof(struct Node));
    first->data = array[0];
    first->next = nullptr;
    last = first;
    
    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc (sizeof(struct Node));
        t->data = array[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

int findMax(struct Node* first)
{
    int max = 0;
    
    struct Node* temp = first;
    while(temp != nullptr)
    {
        if(max < temp->data)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    
    return max;
}

void insertSort(int data,struct Node** head)
{
    struct Node*p = *head,*q;
    
    struct Node* t = new Node();
    t->data = data;
    t->next = nullptr;
    
    while(p != nullptr && data < p->data)
    {
        q = p;
        p = p->next;
    }
    
    if(p == first)
    {
        t->next = p;
        first = t;
        
    }
    else
    {
        t->next = q->next;
        q->next = t;
     }
}

void InsertNew(struct Node* first,int data)
{
    Node* t = first;
    Node* q = nullptr;
    
    Node* p = (struct Node*) malloc (sizeof(struct Node));
    p->data = data;
    p->next = nullptr;
    
    if(t == nullptr)
    {
        t = p;
        first = t;
        
    }
    else if(t == first)
    {
        p->next = first;
        first = p;
        
    }
    else
    {    
       while(t && t->data < data)
       {
           q = t;
           t = t->next;           
       }
      p->next = q->next;
      q->next = t;
  
    }   
   
    
}

void Display(struct Node* p)
{
        
    while(p != nullptr)
    {
        cout<<p->data;
        p = p->next;
    }
}

void reverseList(struct Node** head)
{
    struct Node* p = *head;
    struct Node *q = nullptr; struct Node *next = nullptr;
    while(p != nullptr)
    {
        next = p->next;
        q = p;
        p = p->next;
    }
    
    struct Node* temp = q;
    while(temp != nullptr)
    {
        std::cout<<temp->data;
        temp = temp->next;
    }
}

int main(int argc, char **argv)
{
  //  int array[] {1,2,3,4,5};
  //  createLinkedList(array,5);
  //  Display(first);
 //   cout<<"\n";
    InsertNew(first,6);
    Display(first);
     InsertNew(first,5);
     reverseList(&first);
   int max = findMax(first);
   cout<<"\n"<<max;
   
	printf("hello world\n");
	return 0;
}

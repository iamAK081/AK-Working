#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
}*first = nullptr;

void create_linked_list(int A[],int n)
{
    int i = 0;
    struct Node *t = nullptr;
    struct Node *last = nullptr;
    
    //create first element
    first = (struct Node*) malloc (sizeof(struct Node));
    first->data = A[0];
    first->next = nullptr;
    last = first;
    
    for(i = 1; i < n; i++)
    {
        struct Node* t = (struct Node*) malloc (sizeof(struct Node));
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}


void display_linked_list()
{
    struct Node* temp = first;
    
    while(temp != nullptr)
    {
        cout<<temp->data <<endl;
        temp = temp->next;
    }
}
int main(int argc, char **argv)
{
    int A[] = {2,3,4,5,6};
    create_linked_list(A,5);
    
    display_linked_list();
	printf("hello world\n");
	return 0;
}

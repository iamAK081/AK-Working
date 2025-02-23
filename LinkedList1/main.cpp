#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
}*first;

void createList(struct Node** head,int d)
{
    struct Node* cur = *head;
    
    struct Node* temp = new Node();
    temp->data = d;
    temp->next = nullptr;
    
    if(*head == nullptr)
    {
        *head = temp;
    }
    else
    {
        struct Node* q = nullptr;
        while(cur != nullptr && cur->data < d)
        {
            q = cur;
            cur = cur->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
    
}

void Display(struct Node* first)
{
    struct Node* t = first;
    while(t != nullptr)
    {
        std::cout<<t->data;
        t = t->next;
    }
}

void reverse(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = nullptr;
    struct Node* r = nullptr;
    
    while(p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}


int main(int argc, char **argv)
{
    createList(&first,1);
    createList(&first,2);
    createList(&first,3);
    createList(&first,10);
    createList(&first,20);
    createList(&first,6);
    Display(first);
    std::cout<<"\n";
    reverse(first);
    Display(first);
    
	printf("hello world\n");
	return 0;
}

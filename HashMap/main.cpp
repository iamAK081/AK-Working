#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
    struct Node* next;
    int data;
    
}*first=nullptr;

void create(struct Node** h,int data)
{
    struct Node* p = *h,*q,*n;
    
    n = new Node();
    n->data = data;
    n->next = nullptr;
    
    if(p == nullptr)
    {
        *h = n;
    }
    else
    {
        while(p != nullptr && p->data < data)
        {
            q = p;
            p = p->next;
        }
        if(first == p)
        {
            p->next = first;
            first = p;
        }
        else
        {
            n->next = q->next;
            q->next = n;
        }
        q->next = n;
        n->next = p;
       // *h = q;
    }
}

void display(struct Node* h)
{
    struct Node* p = h;
    while(p != nullptr)
    {
        std::cout<<p->data<<"->";
        p = p->next;
    }
}

int main(int argc, char **argv)
{
    
    create(&first,10);
    create(&first,20);
    create(&first,5);
    display(first);
	printf("hello world\n");
	return 0;
}

#include<iostream>
using namespace std;
struct node
{
    int data;
    int freq;
    struct node* left;
    struct node* right;
    struct node* link;
}*ptr;

struct heapnode
{
    int size;
    struct node *heap;
}*h;

void insert_heap(struct node *n,int pos)
{
    int k=2;
    if(pos==1)
    {

        n->link = h->heap;
        h->heap = n;
    }
    /*else if(pos == h->size+1)
    {
        ptr = h->heap;
        while(ptr->link !=NULL)
        {
            ptr = ptr->link;
        }
        cout<<"Ejerhg";
        ptr->link=n;
        n->link=NULL;
    }*/
    else
    {
        ptr = h->heap;
        while(k!=pos)
        {
            ptr = ptr->link;
            k++;
        }
        n->link =  ptr->link;
        ptr->link = n;
    }
}
void insert_end(struct node *n)
{
    ptr = h->heap;
    while(ptr->link !=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = n;
    n->link =NULL;
}

void create_node(int data,int freq)
{
    h = new heapnode;
    struct node* n = new node;
    n->data = data;
    n->freq = freq;
    h->heap = n;
    n->left = NULL;
    n->right = NULL;
    n->link = NULL;

}
void insert_node(int dat,int frq)
{   
    struct node* n = new node;
    n->data = dat;
    n->freq = frq;
    n->right = NULL;
    n->left = NULL;
    n->link = NULL;
    ptr = h->heap;
    while(ptr->link !=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link = n;
    n->link = NULL;
}
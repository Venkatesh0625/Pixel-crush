#include<iostream>
#include <cstdlib>
#include<stdint.h>
#include<iomanip>
#include<queue>
using namespace std;

struct node
{
    uint8_t data;
    unsigned int freq;
    node *left,*right;
}*ptr;

struct heap
{
    unsigned int size;
    struct node **array;
}*h;

heap* create_heap()
{
    struct heap* n;
    n=new heap;
    n->size=0;
}

node* create_node(uint8_t data,unsigned int freq)
{
    struct node *temp=new node;
    temp=new node;
    temp->data = data;
    temp->freq = freq;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void swap_node(struct node *a,struct node *b)
{
    struct node *t;
    t=a; a=b; b=t;
}

void heapify(struct heap *h,int idx)
{
    int x=idx,y=idx+1;
    int k=0,j;
    int freq_sum=(h->array[x]->freq + h->array[y]->freq);
    struct node *n=create_node(0,freq_sum);
    n->left=h->array[x];
    n->right=h->array[y];
    for(int i=idx+2;i<h->size;i++)
    {
            if(h->array[i]->freq >= n->freq)
            {
                for(int j=idx+2;j<=i;j++)
                    h->array[j-1]=h->array[j];
                h->array[i]=n;
                k=1;
                break;
        	}

    }
    if(k==0)
        	{
        		for(j=idx+2;j<h->size;j++)
                    h->array[j-1]=h->array[j];
                h->array[j-1]=n;
            }
    cout<<h->array[idx]->data<<"\t"<<h->array[idx]->freq<<endl;
}

struct node* tree()
{
    for(int k=0;k < (h->size)-1;k++)
        heapify(h,k);
    return h->array[h->size-1];
}

void print(node *root, int space=1)
{
	int count =1;
    if (root == NULL)
        return;
    space += count;
    print(root->right, space);
    cout<<endl;
    for (int i = count; i < space; i++)
        cout<<" ";
    cout<<setw(3)<<root->freq<<"|"<<"\n\n";
    print(root->left, space);
}


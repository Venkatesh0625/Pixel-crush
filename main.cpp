#include<iostream>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include "Load_bmp.cpp"
#include "sort.cpp"
#include "huffmann.cpp"
#include "traverse.cpp"
using namespace std;
#define Max_Pix 256
int **freq;
char binary[32000];
char encode[4000];
struct file_info
{
    char data;
    unsigned int freq;
};



int main()
{
    int height=0,width=0;
    int k=0,i=0,j=0;
    struct node *root;
    FILE *file;
    struct file_info info;

    //The 2 dimensional Array which Store Image pIxels.
    int** image;
    image = load_bmp(height,width);

    //The 1 dimensional Array which stores the frequency of the correspoding pixels(index refers to pixels here).

    //Allocating 256 Integer size using new keyword
    freq = new int*[256];
    for(int i=0;i<Max_Pix;i++)
        freq[i] = new int[2];

    //Assigning initially with 0.
    for(int i=0;i<Max_Pix;i++)
    {
        freq[i][1]=0;
        freq[i][0]=i;
    }

    //Counting the Number of Pixels.
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            freq[image[i][j]][1]++;

    //Sorting the Frequencies
    sort(freq,Max_Pix);

    h = new heap;

    //Finding Number of Non zero elements to determine size
    for(i=0;i<Max_Pix;i++)
        if(freq[i][1] !=0)
            h->size++;

    //Allocating heap memory
    h->array = new node*[h->size];

    //Assigning Values to the array of the heap
    for(i=0;i<Max_Pix;i++)
        if(freq[i][1] !=0)
        {
            h->array[k]=create_node(freq[i][0],freq[i][1]);
            k++;
        }
    
    //Storing the Frequency Data to file for Reuse
    file = fopen("E:/Freq_Data.txt","w");
    for(int i=0;i<Max_Pix;i++)
        if(freq[i][1] !=0)
        {
            info.data = freq[i][0];
            info.freq = freq[i][1];
            fwrite(&info,sizeof(file_info),1,file);
            cout<<"1";
        }
    fclose(file);
    
    //Creating Tree
    root = tree();

    traverse(root,0);

    binaryfy(image,binary,height,width);
    cout<<binary;
    cout<<endl<<endl<<endl<<(strlen(binary)/8);
    cout<<endl<<sum;
    
    
    file=fopen("E:/Huffmann_encode.txt","wb");
    char ch;
    k=0;
    int l=0,m=0;
    for(int i=0;i<strlen(binary)/8;i++)
    {
        int sum=0;
        for(int j=0;j<8;j++)
        {
            sum+=((binary[k]-48)*pow(2,7-j));
            k++;
        }
        ch=(char)sum;
        putc(ch,file);
        l++;
    }
    cout<<endl<<ch<<endl<<"dgb";
    fclose(file);

    cout<<endl<<l;
    l=0;
    
    
    file=fopen("E:/Huffmann_encode.txt","rb");
    cout<<endl;
    //cout<<endl<<ch<<endl;
    while(!feof(file))
    {
        ch=getc(file);
        cout<<ch;
        l++;
    }
    l--;
    cout<<"\n\n\n"<<sum/8;
    cout<<endl<<l;
}

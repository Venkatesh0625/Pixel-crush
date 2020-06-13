#include<iostream>

void sort(int** arr,int size)
{
    int t;
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
            if(arr[i][1]>arr[j][1])
            { 
                t=arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=t;
                t=arr[i][0];
                arr[i][0]=arr[j][0];
                arr[j][0]=t;
            }
}
void print(int** arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i][0]<<"\t"<<arr[i][1]<<endl;
    }
}
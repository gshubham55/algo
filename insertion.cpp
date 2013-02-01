#include<iostream>
#include<stdio.h>
using namespace std;

void insertion(int a[],int n)
{
     for ( int i=1;i<n;i++)
     {
         int pos=i;
         int val=a[i];
         for ( int j=i;j>0;j--)
         {
             if ( a[j]<a[j-1])
             {
                  int temp=a[j];
                  a[j]=a[j-1];
                  a[j-1]=temp;
             }
             else if( a[j]>a[j-1]) break;
         }
     }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for ( int i=0;i<n;i++) cin>>a[i];
    insertion(a,n);
    cout<<endl;
    for ( int i=0;i<n;i++) cout<<a[i]<<endl;
 //   system("pause");
}

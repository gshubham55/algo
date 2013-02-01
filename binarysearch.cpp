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
     //cout<<"done"<<endl;
}

int bs(int a[],int n, int num)
{
    insertion(a,n);
    int check=0;
    int l=0,r=n-1,mid,br=0;
    for (;;)
    {
        if(r-l==1) br=1;
        mid=(l+r)/2;

        if (num>a[mid]) l=mid;
        else if(num<a[mid]) r=mid;
        else
        {
             check =1;
             break;
        }
        if(br==1) break;
    }
    return check;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for ( int i=0;i<n;i++) cin>>a[i];
    int num;
    cin>>num;
    int ans=bs(a,n,num);
    if ( ans==0) cout<<"Number doesn't exist in the array\n";
    else cout<<"Number exists in the array\n";
//    system("pause");
}

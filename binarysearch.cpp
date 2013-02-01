#include<iostream>
#include<stdio.h>
using namespace std;
void merge( int a[], int l, int mid, int r);
void mergesort ( int a[], int l,int r)
{
     if (r>l)
     {
             int mid=(l+r)/2;
             mergesort(a,l,mid);
             mergesort(a,mid+1,r);
             merge(a,l,mid,r);
     }
}
void merge( int a[], int l, int mid, int r)
{
     int x[mid-l+2],y[r-mid+1];
     x[mid-l+1]=2147483647;
     y[r-mid]=2147483647;
     for( int i=0;i<mid-l+1;i++) x[i]=a[l+i];
     for( int i=0;i<r-mid;i++) y[i]=a[mid+1+i];
     int c=0,d=0;
     for( int i=l;i<=r;i++)
       {
              if((x[c]<=y[d]))
              {
                           a[i]=x[c];
                           c++;
              }
              else
              {
                           a[i]=y[d];
                           d++;
              }
       }
}

int bs(int a[],int n, int num)
{
    mergesort(a,0,n-1);
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
 //   system("pause");
}

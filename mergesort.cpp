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
int main()
{
    int n;
    cin>>n;
    int a[n];
    for ( int i=0;i<n;i++) cin>>a[i];
    mergesort(a,0,n-1);
    cout<<endl;
    for ( int i=0;i<n;i++) cout<<a[i]<<endl;
    system("pause");
}

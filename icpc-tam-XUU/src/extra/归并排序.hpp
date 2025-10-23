#include<bits/stdc++.h>
using namespace std;
int n,temp[1000001],a[1000001];
void merge_sort(int l,int r)
{
    if(l==r)
    return;
    int mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,c=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j])
        temp[++c]=a[i++];
        else
        temp[++c]=a[j++];
    }
    while(i<=mid)
    temp[++c]=a[i++];
    while(j<=r)
    temp[++c]=a[j++];
    for(int i=1;i<=c;i++)
    {
        a[l++]=temp[i];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    merge_sort(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
    system("pause");
    return 0;
}
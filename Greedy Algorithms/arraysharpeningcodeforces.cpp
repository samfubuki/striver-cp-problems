#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int prefixend=-1,suffixend=n;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<i)
        {
            break;
        }
        prefixend=i;
    }
    for(int i=(n-1);i>=0;i--)
    {
        if(arr[i]<(n-1)-i)
        {
            break;
        }
       suffixend=i;
    }
    if(suffixend<=prefixend)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
 return 0;
}

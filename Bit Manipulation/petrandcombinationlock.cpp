#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool p = false;
    for(int i=0;i<=((1<<n)-1);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                sum=sum+arr[j];
                sum%=360;
            }
            else
            {
                sum=sum-arr[j];
                sum%=360;
            }
        }
        if(sum%360==0)
        {
            p=true;
        }
    }
    if(p)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
 return 0;
}

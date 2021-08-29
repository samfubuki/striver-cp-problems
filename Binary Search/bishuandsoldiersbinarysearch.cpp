#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin>>n;

    int a[n];ll sum[n],s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        s+=a[i];
        sum[i]=s;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;

        if(x>=sum[n-1])
        {
            cout<<n<<" "<<sum[n-1]<<endl;
        }
        else
        {
            int ind=upper_bound(a,a+n,x)-a;
            cout<<ind<<" "<<sum[ind-1]<<endl;
        }
    }

    return 0;
}

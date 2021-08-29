#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int res=1,p=3;
        while(res<n)
        {
            res=res+p;
            p*=3;
        }
        while(p)
        {
            if((res-p)>=n)
            {
                res=res-p;
            }
            p/=3;
        }
        cout<<res<<endl;
    }
 return 0;
}

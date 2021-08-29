#include<bits/stdc++.h>'
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0,r=n,m,k=0;
    long long int cost=0;
    while(l<=r)
    {
        m=(l+r)/2;
        vector<long long int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]+(i+1)*m);
        }
        sort(v.begin(),v.end());
        long long int c=0;
        for(int i=0;i<m;i++)
        {
            c+=v[i];
        }
        if(c<=s)
        {
            k=m;
            cost=c;
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
  cout<<k<<" "<<cost<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int cnt=0;
    vector<int> removedelements(n,false);
    for(int i=0;i<n;i++)
    {
        if(!removedelements[i])
        {
            cnt++;
            if(binary_search(v.begin(),v.end(), k*1LL*v[i]))
               {
                  int index = lower_bound(v.begin(), v.end(),k*1LL*v[i]) - v.begin();
                  removedelements[index]=true;
               }
        }

    }
   cout<<cnt;
   return 0;

}

#include<bits/stdc++.h>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;
void countwarriors(const vector<long long int> &a, const vector<long long int> &b)
{
    vector<long long int> c(a.size());
    partial_sum(a.begin(),a.end(),c.begin());
    long long int d=0;
    for(auto arrows:b)
    {
        d+=arrows;
        if(d>=c.back())
        {
            d=0;
        }
        auto it = lower_bound(c.begin(),c.end(),d);
        cout<<distance(it,c.end())-(*it==d)<<endl;
    }
}
int main()
{
    long long int n,q;
    cin>>n>>q;
    vector<long long int> a(n);
    vector<long long int> b(q);
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long int i=0;i<q;i++)
    {
        cin>>b[i];
    }
    countwarriors(a,b);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long int n = 1e5+2;
long long int tree[4*n],a[n];

void build(long long int node, long long int st, long long int en)
{
        if(st==en)
        {
            tree[node]=a[st];
            return;
        }
      long long int mid = (st+en)/2;
      build(2*node,st,en);
      build(2*node+1,mid+1,en);
      tree[node] = max(tree[2*node],tree[2*node+1]);
}
long long int query(long long int node, long long int st, long long int en, long long int l, long long int r)
{
    if(st>r || en<l)
    {
        return INT_MIN;
    }
    if(l<=st && en<=r)
    {
        return tree[node];
    }
    long long int mid = (st+en)/2;
    long long int q1 = query(2*node,st,mid,l,r);
    long long int q2 = query(2*node+1,mid+1,en,l,r);
    return max(q1,q2);
}
void update(long long int node, long long int st, long long int en, long long int idx, long long int val)
{
    if(st==en)
    {
        a[st]=val;
        tree[node]=val;
        return;
    }
    long long int mid = (st+en)/2;
    if(idx<=mid)
    {
        update(2*node,st,mid,idx,val);
    }
    else
    {
        update(2*node+1,mid+1,en,idx,val);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int main()
{
    long long int n;
    cin>>n;
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    while(1)
    {
        long long int type;
        cin>>type;
        if(type==-1)
        {
            break;
        }
        if(type==1)
        {
            long long int l,r;
            cin>>l>>r;
            long long int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;

        }
        else if(type==2)
        {
            long long int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
            cout<<query(1,0,n-1,0,n-1)<<endl;
        }
    }
    return 0;
}

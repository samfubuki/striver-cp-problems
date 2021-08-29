#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   long long int n,p,x,r;
    cin>>n>>p;
    long long int a[p+1];
    for(int i=0;i<=p;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>x>>r;
        //left end of range
        if(x-r>=0)
        {
            a[x-r]++;
        }
        else
        {
            a[0]++;
        }
        //right end of range
        if(x+r+1<=p)
        {
            a[x+r+1]--;
        }

    }
    for(int i=1;i<=p;i++)
    {
        a[i]+=a[i-1];
    }
    long long int cnt=0,ans=INT_MIN;
    for(int i=0;i<=p;i++)
    {
        cnt=0;
        while(a[i]!=1 && i<=p)
        {
            cnt++;
            i++;
        }
      ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
unsigned long long int ff(long long int n)
{
    unsigned long long int p,i,j,cnt=0;
    do{
        n=n/2;
        cnt++;

    }while(n!=0);
 return cnt;
}
int main()
{
    unsigned long long int a,b,pp,i,j,res,temp;
    cin>>a>>b;
    unsigned long long int len1,len2;
    res=0;
    len1 = ff(a);
    len2 = ff(b);
    for(i=len1;i<=len2;i++)
    {
        pp = (1ll<<(i))-1;
        for(j=0;j<i-1;j++)
        {
            temp=pp-(1ll<<j);
            if(temp>=a && temp<=b)
            {
                res++;
            }
        }
    }
    cout<<res<<endl;
return 0;
}

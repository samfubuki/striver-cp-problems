#include<bits/stdc++.h>
using namespace std;
int pattern[1000005];
string p;
void kmp()
{
    int now;
    pattern[0]=now=-1;
    for(int i=1;i<p.length();i++)
    {
        while(now!=-1 && p[i]!=p[now+1])
        {
            now=pattern[now];
        }
        if(p[i]==p[now+1])
        {
           now++;
           pattern[i]=now;
        }
        else
        {
            pattern[i]=-1;
        }

    }
}
int main()
{
    cin>>p;
    kmp();
    int len = p.length();
    int maxi = pattern[len-1];
    int found = pattern[maxi];
    if(maxi==-1)
    {
        found=-1;
    }
    for(int i=1;i<(len-1);i++)
    {
        if(pattern[i]==maxi)
        {
            found=maxi;
        }
    }
    if(found==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        cout<<p.substr(0,found+1)<<endl;
    }
 return 0;
}

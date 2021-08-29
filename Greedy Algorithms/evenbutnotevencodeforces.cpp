#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        cin>>s;
        int odd=0;
        for(int i=0;i<n;i++)
        {
            if((s[i]-'0')%2!=0)
            {
                odd++;
            }
        }
        if(odd<2)
        {
            cout<<"-1"<<endl;

        }
        else
        {
            int total=0;
            for(int i=0;i<n;i++)
            {
                if((s[i]-'0')%2!=0)
                {
                    cout<<s[i];
                    total++;
                }
                if(total==2)
                {
                    break;
                }
            }
            cout<<endl;
        }
    }
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string,int> mp;
    int t;
    cin>>t;
    while(t--)
    {

        string s;
        cin>>s;
        mp[s]++;
        int cnt = mp[s];
        if(cnt==1)
        {
            cout<<"OK"<<endl;
            continue;
        }
        cout<<s<<cnt-1<<endl;
    }
 return 0;
}

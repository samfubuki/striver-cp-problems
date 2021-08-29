#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int maxele=0,cnt=0;
	    for(int i=0;s[i]!='\0';i++)
	    {
	      if(s[i]=='1')
	      {
	          cnt++;
	          maxele = max(maxele,cnt);
	      }
	      else
	      {
	          maxele = max(maxele,cnt);
	          cnt=0;
	      }
	    }
	    if((count(s.begin(),s.end(),'1')==maxele) && (maxele>=1))
	    {
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}


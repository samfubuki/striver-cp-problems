#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int cnt1=0,cnt2=0;
		for(int i=0;s[i]!='\0';i++)
		{
         if(s[i]=='S' && s[i+1]=='U' && s[i+2]=='V' && s[i+3]=='O' && s[i+4]=='J' && s[i+5]=='I' && s[i+6]=='T')
		 {
			 cnt1++;
		 }
		 else if(s[i]=='S' && s[i+1]=='U' && s[i+2]=='V' && s[i+3]=='O')
		 {
			 cnt2++;
		 }

		}
     cout<<"SUVO = "<<cnt2<<", SUVOJIT = "<<cnt1<<endl;
	}
 return 0;
}


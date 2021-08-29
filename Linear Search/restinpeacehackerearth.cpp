#include<bits/stdc++.h>
using namespace std;
int main()
{
		int n;
		cin>>n;
		string s1 = "The streak lives still in our heart!";
		string s2 = "The streak is broken!";
		while(n--)
		{
			int t,cnt=0;
			cin>>t;
            int k=t;
			while(k!=0)
			{
				int x = k%100;
				if(x==21)
				{
					cnt++;
				}
				k=k/10;
			}
			if(cnt>0 || (t%21)==0)
			{
				cout<<s2<<endl;
			}
			else
			{
				cout<<s1<<endl;
			}
		}
return 0;
}

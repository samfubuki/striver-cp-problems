#include<bits/stdc++.h>
using namespace std;
int sie[1000010] , ans[1000010];
void sieve()
{
	int i,j;
	sie[0]=sie[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(sie[i]==0)
		{
			int c=1;
			for(j=i+i;j<=1000000;j+=i)
			{
				if(sie[j]==0)
				{
					c++;
				}
		     sie[j]=1;
			}
		  ans[i]=c;
		}
	}
}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
		long long int x;
		cin>>x;
        cout<<ans[x]<<endl;
	}
 return 0;
}

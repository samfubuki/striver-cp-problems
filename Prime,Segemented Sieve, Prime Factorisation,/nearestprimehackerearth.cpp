#include<bits/stdc++.h>
using namespace std;
bool isprime[1000005];
void sieve()
{
	memset(isprime,true,sizeof(isprime));
    int maxn = 1000005;
	for(int i=2;i*i<maxn;i++)
	{
		if(isprime[i]==true)
		{
			for(int j=i*i;j<maxn;j+=i)
			{
             isprime[j]=false;
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
     int i,j,n;
	sieve();
	while(t--)
	{
		scanf("%d",&n);
        for(i=n,j=n;i>1||j<1000005;i--,j++)
		{
			if(isprime[i])
			{
				printf("%d",i);
				break;
			}
			else if(isprime[j])
			{
				printf("%d",j);
				break;
			}
		}
     cout<<"\n";
	}
 return 0;
}

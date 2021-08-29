#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans = 0;
		int freq[1001] = {0};
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
            freq[arr[i]]++;
		}
		for(int i=1;i<1001;i++)
		{
			for(int j=i;j<1001;j++)
			{
				int square,cube;
				square = sqrt(i+j);
				cube = cbrt(i+j);
				if((i+j)==square*square || (i+j)==cube*cube*cube)
				{
					if(i==j)
					{
						ans = ans + freq[i]*(freq[i]-1)/2;
					}
					else
					{
						ans = ans + freq[i]*freq[j];
					}
				}

			}
		}
	cout<<ans<<endl;
	}
return 0;
}


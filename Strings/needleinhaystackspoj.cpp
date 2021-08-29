#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int dp[1000001];
long long int inv[1000001];

long long int power(long long int a , long long int n)
{
	long long int result = 1;

	while(n)
	{
		if(n & 1)
        {
         result = (result * a) % mod;
        }

		n >>= 1;
		a = (a * a) % mod;
	}

	return result;
}


void init(string input_string)
{
	long long int p = 31;
	long long int p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);


	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];

		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);

		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}

long long int getHash(string key)
{
	long long int value = 0;
	long long int p = 31;
	long long int p_power = 1;

	for(char ch : key)
	{
		value = (value + (ch - 'a' + 1)*p_power) % mod;
		p_power = (p_power * p) % mod;
	}

	return value;
}

long long int substringHash(int L , int R)
{
	int result = dp[R];

	if(L > 0) result = (result - dp[L-1] + mod) % mod;

	result = (result * inv[L]) % mod;

	return result;
}

int main()
{
	string haystack , needle;
	int n , L , R , answer;
	bool flag = false;

	while(cin>>n)
	{
		cin>>needle;
		cin>>haystack;

		long long int needleHash = getHash(needle);

		init(haystack);

		for(L=0 , R=needle.size()-1; R < haystack.size(); L++ , R++)
		{
			if(needleHash == substringHash(L , R))
			cout<<L<<endl;
		}

		cout<<endl;
	}
 return 0;
}

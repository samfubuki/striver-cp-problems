#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m,a,b,res=0;
int main()
{
  cin>>n;
  m=n;
  while(n--)
  {
	  cin>>a;
      q.push(a);
  }
  while(m-- && !q.empty())
  {
	  cin>>a;
	  b = q.front();
	  while(!q.empty() && b!=a)
	  {
		  q.pop();
		  q.push(b);
		  res++;
		  b = q.front();
	  }
	q.pop();
	res++;
  }
 cout<<res;
 return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	map<char,int> mp;
	for(int i=0;i<str.length();i++)
	{
		mp[str[i]]++;
	}
	auto maxchar = '$';
	int maxcnt = 0;
	for(auto itr:mp)
	{
      if(itr.second>maxcnt)
	  {
		  maxchar = itr.first;
		  maxcnt = itr.second;
	  }
	  else if(itr.second==maxcnt)
	  {
		  if(maxchar>itr.first)
		  {
			  maxchar = itr.first;
			  maxcnt = itr.second;
		  }
	  }
	}
  cout<<maxchar<<" "<<maxcnt;
  return 0;

}


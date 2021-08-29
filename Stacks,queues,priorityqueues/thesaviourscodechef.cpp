#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      char str[1000001];
      cin>>str;
      stack<char> st;
      int len = strlen(str);
      for(int i=len-1;i>=0;i--)
      {
          if(str[i]=='*')
          {
              if(!st.empty())
              {
                  st.pop();
              }
              if(!st.empty())
              {
                  st.pop();
              }
          }
          else
          {
              st.push(str[i]);
          }
      }
      if(st.empty())
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

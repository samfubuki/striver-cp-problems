#include<bits/stdc++.h>
using namespace std;
long long int k;
string s,w;
bool isgood(char ch)
{
    return w[ch-'a']=='1';
}
struct Node {
   Node *next[30];
};
int main()
{
   Node *head = new Node();
   cin>>s;
   cin>>w;
   cin>>k;
   long long int ans=0;
   for(int i=0;i<s.size();i++)
   {
       int cnt=0;
       Node *p = head;
       for(int j=i;j<s.size();j++)
       {
           if(!isgood(s[j]))
           {
               cnt++;
           }
           int c = s[j]-'a';
           if(cnt>k)
           {
               break;
           }
           if(p->next[c]==NULL)
           {
               p->next[c]=new Node();
               ans++;//
           }
          p=p->next[c];
       }

   }
   cout<<ans<<endl;
  return 0;
   }


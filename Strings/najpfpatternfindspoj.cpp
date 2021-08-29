#include<bits/stdc++.h>
using namespace std;
int prefix_table[1000005];
void construct_table(string st)
{
    int i,j,k,n,c,sz=st.size();
    j=0;
    for(int i=1;i<sz;)
    {
      if(st[i]==st[j])
      {
          prefix_table[i]=j+1,j++,i++;
      }
      else if(j)
      {
          j=prefix_table[j-1];
      }
      else
      {
          prefix_table[i]=0,i++;
      }
    }
}
void kmp(string st, string pattern)
{
   int i,j,flag=0,szst=st.size(),szpt=pattern.size();
   vector<int> vc;
   i=j=0;
   while(1)
   {
       if(i==szst)
       {
           break;
       }
       if(st[i]==pattern[j])
       {
           i++,j++;
       }
       else if(j)
       {
           j=prefix_table[j-1];
       }
       else
       {
           i++;
       }
       if(j==szpt)
       {
           vc.push_back(i-j+1);
       }

   }
   if(vc.empty())
   {
       cout<<"Not Found"<<endl;
   }
   else
   {
       cout<<vc.size()<<endl;
       for(int i=0;i<vc.size();i++)
       {
           cout<<vc[i]<<" ";
       }
       cout<<endl;
   }
}
int main()
{
    int t;
    int id=1;
    string st,pattern;
    cin>>t;
    while(t--)
    {
        if(id!=1)
        {
            cout<<endl;
        }
        cin>>st>>pattern;
        construct_table(pattern);
        kmp(st,pattern);
        id++;

    }
 return 0;
}

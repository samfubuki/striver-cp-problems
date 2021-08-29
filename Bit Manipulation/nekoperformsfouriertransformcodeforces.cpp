#include<bits/stdc++.h>
using namespace std;
vector<int> ops;
bool ok(int x)
{
  return !((x+1) & x);
}
void opA(int& x)
{
  int p;
  for (int i=0; (1<<i)<=x; ++i)
    if (!((x>>i) & 1)) {
      p = i;
    }
  ops.push_back(p + 1);
  x ^= (1<<(p+1)) - 1;
}
void opB(int& x)
{
  ++x;
}
int main()
{
  int x,step=0;
  cin>>x;
  while(!ok(x))
  {
    step++;
    opA(x);
    if(ok(x))
    {
        break;
    }
    step++;
    opB(x);
  }
  cout<<step<<endl;
  for(auto x:ops)
  {
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}

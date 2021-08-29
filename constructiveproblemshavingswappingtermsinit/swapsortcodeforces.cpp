#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (auto &x : arr)
		cin >> x;
    vector<pair<int,int> > v;
    int cnt=0;
    int i,j,min_idx;
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
              min_idx = j;
        // Swap the found minimum element with the first element
        cnt++;
        v.push_back({min_idx,i});
        swap(arr[min_idx], arr[i]);

    }
    cout<<cnt<<endl;
    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
 return 0;

}


#include<iostream>
typedef long long ll;
using namespace std;
int T, N;
int arr[101][101];
ll dig1[205][202]={0}, dig2[205][202]={0};

pair<int,int> dig1_idx(pair<int,int> pt)
{
    pair<int,int> res;
    if(pt.first>=pt.second)
        return {N-1-(pt.first-pt.second),pt.second};
    else return {N-1 + pt.second-pt.first,pt.first};
}

pair<int,int> dig2_idx(pair<int,int> pt)
{
    if(N-1-pt.first<=pt.second) return {2*N -2 - pt.first - pt.second,N-1-pt.second};
    else return {2*N -2 - pt.first - pt.second,pt.first};
}

void compute_diagnols()
{
    int dig1_cnt=0;
    for(int i=N-1; i>=0; i--)
    {
        for(int j=0; j<N-i; j++)
            dig1[dig1_cnt][j+1]=arr[i+j][j]+ dig1[dig1_cnt][j];
        dig1_cnt++;
    }
    for(int j=1; j<N; j++)
    {
        for(int i=0; i<N-j; i++)
            dig1[dig1_cnt][i+1]=arr[i][i+j] + dig1[dig1_cnt][i];
        dig1_cnt++;
    }

    int dig2_cnt=0;

    for(int i=N-1; i>=0; i--)
    {
        for(int j=0; j<N-i; j++)
            dig2[dig2_cnt][j+1]=arr[i+j][N-1-j]+dig2[dig2_cnt][j];
        dig2_cnt++;
    }
    for(int j=N-2; j>=0; j--)
    {
        for(int i=0; i<=j; i++)
            dig2[dig2_cnt][i+1]=arr[i][j-i]+dig2[dig2_cnt][i];
        dig2_cnt++;
    }
}

ll solve()
{
    compute_diagnols();
    ll answer=arr[0][0];
    ll temp;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            ll temp=arr[i][j];
            answer=max(answer,temp);
            int max_side=min(min(i,j),min(N-i-1,N-j-1));
            for(int side=1; side<=max_side; side++)
            {
                pair<int,int> l={i,j-side}, r={i,j+side};
                pair<int,int> t={i-side,j}, b={i+side, j};
                temp+=arr[l.first][l.second]+arr[r.first][r.second]+arr[t.first][t.second] + arr[b.first][b.second];
                pair<int,int> dig1_b=dig1_idx(b), dig1_r=dig1_idx(r);
                pair<int,int> dig2_b=dig2_idx(b), dig2_l=dig2_idx(l);
                temp+=dig1[dig1_b.first][dig1_b.second]+dig1[dig1_r.first][dig1_r.second]+ dig2[dig2_b.first][dig2_b.second]+ dig2[dig2_l.first][dig2_l.second];
                temp-=dig1[dig1_b.first][dig1_b.second-side+1]+dig1[dig1_r.first][dig1_r.second-side+1]+ dig2[dig2_b.first][dig2_b.second-side+1]+ dig2[dig2_l.first][dig2_l.second-side+1];
                answer=max(temp,answer);
            }
        }
    return answer;
}

int main()
    cin >> T;
    while(T--)
    {
        cin>>N;
        for(int i =0; i<N; i++) for(int j=0; j<N; j++) cin>>arr[i][j];
        cout<<solve()<<"\n";
    }
    return 0;
}

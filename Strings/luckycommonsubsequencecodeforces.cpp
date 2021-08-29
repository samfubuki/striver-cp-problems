#include<bits/stdc++.h>
using namespace std;
struct pos {
   int x,y,z;
} pre[111][111][111],  tail;
char a[111],b[111],c[111];
int dp[111][111][111];
int f[111];
void failedmatch(char *p, int *f)
{
    f[0]=0;
    f[1]=0;
    for(int i=1;p[i];i++)
    {
        int j = f[i];
        while(j && p[i]!=p[j])
        {
            j=f[j];
        }
        if(p[i]==p[j])
        {
            f[i+1]=j+1;
        }
        else
        {
            f[i+1]=0;
        }
    }
}
void dfs(pos t)
{
    if(!t.x && !t.y && !t.z)
    {
        return;
    }
    pos q = pre[t.x][t.y][t.z];
    int i=q.x,j=q.y,k=q.z;
    dfs(q);
    if(dp[i][j][k]+1==dp[t.x][t.y][t.z])
    {
        printf("%c",a[i]);
    }
}
int main()
{
   scanf("%s%s%s",a,b,c);
   failedmatch(c,f);
   memset(dp,0,sizeof(dp));
   int len1 = strlen(a), len2 = strlen(b), len3 = strlen(c);
   for(int i=0;i<len1;i++)
   {
       for(int j=0;j<len2;j++)
       {
           for(int k=0;k<len3;k++)
           {
               if(dp[i+1][j][k]<dp[i][j][k])
               {
                   dp[i+1][j][k] = dp[i][j][k];
                   pre[i+1][j][k].x=i;
                   pre[i+1][j][k].y=j;
                   pre[i+1][j][k].z=k;
               }
               if(dp[i][j+1][k]<dp[i][j][k])
               {
                   dp[i][j+1][k]=dp[i][j][k];
                   pre[i][j+1][k].x=i;
                   pre[i][j+1][k].y=j;
                   pre[i][j+1][k].z=k;
               }
               if(a[i]==b[j])
               {
                   int w = k;

               while(w && a[i]!=c[w])
               {
                   w=f[w];
               }
               if(a[i]==c[w])
               {
                   w++;
               }
               else
               {
                   w=0;
               }
               if(dp[i+1][j+1][w]<dp[i][j][k]+1)
               {
                   dp[i+1][j+1][w]=dp[i][j][k]+1;
                   pre[i+1][j+1][w].x=i;
                   pre[i+1][j+1][w].y=j;
                   pre[i+1][j+1][w].z=k;
               }
           }
       }
   }
   }
   int maxlength = 0;
   for(int i=0;i<=len1;i++)
   {
       for(int j=0;j<=len2;j++)
       {
           for(int k=0;k<len3;k++)
           {
               if(dp[i][j][k]>maxlength)
               {
                   maxlength = dp[i][j][k];
                   tail.x=i;
                   tail.y=j;
                   tail.z=k;
               }
           }
       }
   }
   if(maxlength==0)
   {
       printf("0\n");
   }
   dfs(tail);
 return 0;
}

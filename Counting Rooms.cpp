#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,int n,int m, string s[])
{
   if(i<0 || j<0 || i>=n || j>=m)return;
   if(s[i][j]!= '.')return;
   s[i][j]='*';
   dfs(i,j-1,n,m,s);
   dfs(i,j+1,n,m,s);
   dfs(i-1,j,n,m,s);
   dfs(i+1,j,n,m,s);
}
int main()
{
    int n,m,i,j,cnt=0;
    cin>>n>>m;
    string s[n+1];
    for(i=0;i<n;i++)
    {
      cin>>s[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
 
            if(s[i][j]=='.'){dfs(i,j,n,m,s);
            cnt++;}
        }
    }
    cout<<cnt<<endl;
 
}

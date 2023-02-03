/*
Problem Name: Tree Diameter
Problem Link: https://cses.fi/problemset/task/1131
Author: Israt Jahan
*/
#include<bits/stdc++.h>
#define N 200005
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
using namespace std;
 
vector<int>adj[N];
int deg[N]={0};
vector<bool>vis(N,false);
 
int n;
int mx1;
int sum=0;
void dfs(int node,int dis=0)
{
    vis[node]=true;
    if(dis>=sum)
    {
        sum=dis;
        mx1=node;
    }
    for(auto v: adj[node])
    {
       if(!vis[v])
            dfs(v,dis+1);
    }
    return;
}
int main()
{
   int m,k;
 
   cin>>n;
 
   for(int i=2;i<=n;i++)
   {
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
   }
   dfs(1);
   sum=0;
   //cout<<mx1<<endl;
   for(int i=1;i<=n;i++)vis[i]=false;
   dfs(mx1);
   cout<<sum<<endl;
 
}

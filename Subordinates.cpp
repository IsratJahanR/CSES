/*
Problem Name: Subordinates
Problem Link: https://cses.fi/problemset/task/1674
Author: Israt Jahan
*/
#include<bits/stdc++.h>
#define N 2000005
#define pii pair<int,int>
#define vii vector<pii>
#define ll long long
using namespace std;
 
vector<int>adj[N];
int deg[N]={0};
vector<bool>vis(N,false);
 
int n;
void dfs(int node)
{
    vis[node]=true;
 
    for(auto v: adj[node])
    {
        if(!vis[v])dfs(v);
        deg[node]+=deg[v]+1;
        //cout<<node<<" "<<deg[node]<<endl;
 
    }
    //deg[node]++;
    return;
}
int main()
{
   int m,k;
 
   cin>>n;
 
   for(int i=2;i<=n;i++)
   {
       int a;
       cin>>a;
       adj[a].push_back(i);
   }
   for(int i=1;i<=n;i++)
   {
       if(!vis[i])dfs(i);
   }
   for(int i=1;i<=n;i++)cout<<deg[i]<<" ";
 
 
}

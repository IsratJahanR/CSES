/*
Problem Name: Shortest Routes II
Problem Link: https://cses.fi/problemset/task/1672
Author: Israt Jahan
*/
///Approach:Floyd Warshall Algorithm: All Pair Shortest Path
#include<bits/stdc++.h>
#define ll long long
#define INF 1e18
const int N = 505;
using namespace std;
ll dis[N][N];
int main()
{
    ll i,j,k,n,e,u,v,w,q;
    cin>>n>>e>>q;
    for(i=1;i<=n;i++)
       {
            for(j=1;j<=n;j++)
            {
                if(i==j)dis[i][j]=0;
                else dis[i][j]=INF;
            }
       }
    for(ll i=1;i<=e;i++)
    {
        cin>>u>>v>>w;
        dis[u][v]=min(dis[u][v],w);
        dis[v][u]=min(dis[v][u],w);
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
              dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(dis[x][y]==INF)cout<<-1<<endl;
        else cout<<dis[x][y]<<endl;
    }

}


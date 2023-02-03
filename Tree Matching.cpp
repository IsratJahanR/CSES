#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pii pair<int,int>
#define vii vector<pii>
#define pll pair<ll,ll>
#define vll vector<pll>
#define inf 1e10
 
using namespace std;
 
vector<int>adj[N];
vector<int>vis(N,0);
vector<bool>isCount(N,false);
int ans=0;
void dfs(int node,int par)
{
    vis[node]=1;
    //cout<<node<<endl;
    for(auto v:adj[node])
    {
       if(v==par)continue;
       if(vis[v]==0)dfs(v,node);
 
 
    }
 
    vis[node]=2;
    if(!isCount[par] && !isCount[node] && node>1)
    {
            //cout<<node<<" "<<par<<endl;
            isCount[par]=true;
            isCount[node]=true;
            ans++;
            //cout<<ans<<endl;
    }
 
    //cout<<node<<endl;
   // return;
 
}
int main()
{
    int t,tc=1; //cin>>t;
    while(tc--)
    {
       int n,m,p;
       cin>>n;
       for(int i=1;i<n;i++)
       {
           int u,v;
           cin>>u>>v;;
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       //cout<<n<<endl;
       dfs(1,0);
       cout<<ans<<endl;
 
 
    }
 
 
 
}

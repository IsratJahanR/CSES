#include<bits/stdc++.h>
using namespace std;
 
int n,m;
bool vis[100002]={false};
vector<int>adj[100002];
void dfs(int vertex)
{
   vis[vertex]=true;
   for(auto v: adj[vertex])
   {
       if(!vis[v])dfs(v);
   }
}
 
int main()
{
   cin>>n>>m;
    int x,y;
   for(int i=0;i<m;i++)
   {
 
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
   }
   vector<int>v;
   for(int i=1;i<=n;i++)
   {
 
      if(!vis[i]){
           v.push_back(i);
            dfs(i);
 
      }
   }
   if(v.size()==1)
   {
       cout<<0<<endl;
       return 0;
   }
   cout<<v.size()-1<<endl;
   for(int i=0;i<v.size()-1;i++)
   {
       cout<<v[i]<<" "<<v[i+1]<<endl;
   }
 
 
 
}

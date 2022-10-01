///Print Cycle in a graph:


#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>adj[N];
vector<bool>vis(N,false);
bool isCycle=false;
int l=-1;

int dir[N];
bool dfs(int node,int par=-1)
{
   vis[node]=true;
   //cout<<node<<endl;
   for(auto child:adj[node])
   {
       if(child==par)continue;
       if(vis[child])
       {
           if(!isCycle){
                isCycle=true;
           dir[child]=node;
           }
           if(l==-1)l=child;
           return true;
       }
       else
       {
         if(!isCycle)dir[child] = node;
         isCycle = dfs(child,node);
       }
   }
   return isCycle;
}

int main()
{
    int n,e,u,v;
    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                vector<int>ans;
                ans.push_back(l);
                ans.push_back(dir[l]);
                int x=dir[l];
                while(x!=l)
                {

                    x=dir[x];
                    ans.push_back(x);
                }

                cout<<ans.size()<<endl;
                for(int j=0;j<ans.size();j++)cout<<ans[j]<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

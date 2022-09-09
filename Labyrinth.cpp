#include<bits/stdc++.h>
using namespace std;
 
int n,m;
int vis[1002][1002];
int dir[1002][1002];
char ch[1001][1002];
int dx[] ={-1,1,0,0};
int dy[] ={0,0,-1,1};
string stepDir="UDLR";
 
int sx,sy,ex,ey;
 
bool isValid(int x,int y)
{
   if(x<0 || x>=m || y<0 || y>=n)return false;
 
   if(vis[x][y])return false ;
 
   //if(ch[x][y]=='#')return false ;
 
   return true;
 
}
void bfs(int i,int j)
{
    queue<pair<int,int>>Q;
    Q.push({i,j});
    vis[i][j]=true;
 
    while(!Q.empty())
    {
        int x= Q.front().first;
        int y= Q.front().second;
 
        Q.pop();
 
        if(x==ex && y==ey)break;
 
        for(int k=0;k<4;k++)
        {
           int newX=x+dx[k];
           int newY=y+dy[k];
 
           if(isValid(newX,newY) && ch[newX][newY]!='#')
              {
                  //cout<<newX<<" "<<newY<<" "<<k<<endl;
 
                  Q.push({newX,newY});
                  dir[newX][newY]=k;
                  vis[newX][newY]=true;
 
              }
        }
 
    }
 
    if(vis[ex][ey])
    {
        cout<<"YES"<<endl;
        vector<int>v;
 
        while(1)
        {
            if(ex==sx && ey==sy)break;
            int p=dir[ex][ey];
            //cout<<p<<" ";
            v.push_back(p);
            ex-=dx[p];
            ey-=dy[p];
        }
        cout<<v.size()<<endl;
        reverse(v.begin(),v.end());
        for(auto it: v)
        {
            //cout<<it<<" ";
            cout<<stepDir[it];
        }
        cout<<endl;
 
 
 
    }
    else cout<<"NO"<<endl;
 
 
 
}
int main()
{
   cin>>m>>n;
   for(int i=0;i<m;i++)
   {
       for(int j = 0;j<n; j++){
            cin>>ch[i][j];
            if(ch[i][j]=='A')
            {
                sx=i;
                sy=j;
            }
            else if(ch[i][j]=='B')
            {
                ex=i;
                ey=j;
            }
       }
   }
   //cout<<sx<<sy<<ex<<ey<<endl;
   bfs(sx,sy);
 
 
 
 
}

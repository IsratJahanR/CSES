#include<bits/stdc++.h>
#define N 200005
#define pb push_back
#define ll long long
#define vi vector<int>
 
#define pii pair<int,int>
#define vsi vector<set<pii>>
#define vii vector<pii>
#define pll pair<ll,ll>
#define vll vector<pll>
#define inf 1e10
#define floop(i,n) for(ll i=1;i<=n;i++)
 
using namespace std;
 
vi adj[N];
vi vis(N);
vi v;
vi dis(N);
vi par(N);
vector<int> z_algo(string s)
{
    vector<int>ans;
    int n=s.size();
    vector<int>z(n,0);
    int i=1,l=0,r=0;
    while(i<n)
    {
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])z[i]++;
        if(i+z[i]-1>r)
        {
            r=i+z[i]-1;
            l=i;
        }
        i++;
 
    }
    return z;
}
int cnt(string s,int l,int r)
{
    while(l>=0 && r<s.size() && s[l]==s[r])l--,r++;
    return r-l-1;
}
 
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>z;
    z=z_algo(s);
    //cout<<1<<" ";
    int tmp=0;
    for(int i=0;i<n;i++)
    {
        //cout<<z[i]+i<<endl;
        if(z[i]+i==n)cout<<i<<" ";
 
    }
   // if(tmp<=s.size())cout<<tmp;
    cout<<n<<endl;
}

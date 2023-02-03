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
vector<int> kmp(string s)
{
    vector<int>ans;
    int n=s.size();
    vector<int>lps(n,0);
    int i=1,idx=0;
    while(i<n)
    {
        if(s[i]==s[idx])
        {
            lps[i]=idx+1;
            idx++;
            i++;
 
        }
        else
        {
            if(idx)idx=lps[idx-1];
            else lps[i]=idx,i++;
        }
    }
    return lps;
}
 
 
int main()
{
    string s;
    cin>>s;
    vector<int>ans,v;
    v = kmp(s);
 
    int j = v[s.size()-1];
    while(j>0){
        ans.pb(j);
        j = v[j-1];
    }
    sort(ans.begin(),ans.end());
    //cout<<ans.size()<<endl;
    for(auto a:ans)cout<<a<<" ";
    cout<<endl;
 
 
}

#include<bits/stdc++.h>
#define N 200005
#define mod 1000000007
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
//vector<string>s;
//ll s[100002][100002];
//ll dp[100002][100002];
 
ll dp[1000002];
 
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int wt=0;wt<=target;wt++)
        {
            ll tmp=wt-coins[i];
            if(tmp>=0){
                dp[wt]+=dp[tmp];
                dp[wt]%=mod;
            }
        }
    }
    cout<<dp[target]<<endl;
 
 
}

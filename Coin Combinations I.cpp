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
 
int dp[1000004];
ll fun(vector<int>& coins, int amount)
{
 
    if(amount==0){
            //cout<<"yes"<<endl;
            return 1;
 
    }
    if(amount<0){
 
            return 0;
    }
    if(dp[amount]!=-1){
            //cout<<dp[amount]<<endl;
            return dp[amount];
    }
    ll ans=0;
 
    for(auto c: coins)
    {
        ans+=fun(coins,amount-c)%mod;
 
    }
    return dp[amount]=ans%mod;
}
int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    memset(dp,-1,sizeof(dp));
    ll ans=fun(coins,amount);
    cout<<dp[amount]<<endl;
 
 
}

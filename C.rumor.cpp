#include<iostream>
#include<string>
using ll=long long;
using namespace std;
#include<sstream>
ll mod=1e9+7;
#include<bits/stdc++.h>
#define ya  cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;
#define pb push_back
#define fast_cin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(bi) bi.begin(),bi.end()
vector<int>bi[100005];
vector<bool>b(100005,0);
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/
ll cnt;
ll dfs(ll source,ll wt[])
{
    b[source]=1;
    if(cnt>wt[source])cnt=wt[source];
    for(ll y :bi[source])
    {
        if(b[y]==0)
        {
            dfs(y,wt);
        }
    }
    return cnt;
}
int main()
{
   ll i,j,xx,m,n;
   ll x,v,sum=0;
   ll y;
    cin>>m>>n;
    ll wt[m+5];
    for(i=1; i<=m; i++)
    {
        cin>>x;
        wt[i]=x;
    }
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        bi[x].pb(y);
        bi[y].pb(x);
    }
    for(i=1; i<=m; i++)
    {
       if(b[i]==0)
       {
           cnt=INT_MAX;
           ll v=dfs(i,wt);
           //cout<<v<<endl;
           sum+=v;
       }
    }
    cout<<sum<<endl;

}
 
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
ll MAX =2e5+5;
vector<ll>bi[200005];
vector<bool>b(MAX);
vector<ll>dis(MAX);
  vector<ll>sub(MAX);
void dfs(int source)
{
  b[source]=1;
  sub[source]=1;
  for(auto it :bi[source])
  {
      if(b[it]==0)
      {
          dis[it]+=(dis[source]+1);
          dfs(it);
          sub[source]+=sub[it];
          //cout<<source<<" " <<sub[source]<<endl;
      }
  }
}
int main()
{
  ll n,k,i,j,u,v;
  cin>>n>>k;
  for(i=0;i<n-1;i++)
  {
      cin>>u>>v;
      bi[u].pb(v);
      bi[v].pb(u);
  }
  dfs(1);
  vector<ll>c;
  for(i=1;i<=n;i++)
  {
    c.pb(dis[i]-(sub[i]-1));
    //cout<<c[i-1]<<endl;
  }
  sort(all(c),greater<int>());
  ll sum=i=0;
  while(k--)
  {
    sum+=c[i];
    i++;
  }
  cout<<sum<<endl;
}
 
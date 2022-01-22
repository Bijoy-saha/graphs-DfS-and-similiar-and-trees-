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
vector<ll>bi[200009];
vector<bool>b(200009,0);
vector<ll>dis(200009);
vector<ll>color(200009);
bool flag ;
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/
void dfs(ll source)
{
    if(bi[source].size()!=2)
    {
        flag=false;
    }
    b[source]=1;
    for(auto it: bi[source])
    {
        if(b[it]==0)
        {
            dfs(it);
        }

    }
}
int main()
{
    fast_cin;
    ll n,m,i,j,x,y,t,u,v;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        bi[u].pb(v);
        bi[v].pb(u);
    }
    ll sum=0;
    for(i=1; i<=n; i++)
    {
        if(b[i]==0)
        {
            flag=true;
            dfs(i);
            if(flag==true)
                sum++;
        }
    }
    cout<<sum<<endl;
}
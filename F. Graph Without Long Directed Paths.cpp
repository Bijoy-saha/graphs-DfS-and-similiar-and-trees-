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
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/
void dfs(ll source)
{
    ll y1=1;
    for(auto it: bi[source])
    {
        if(b[it]==1)
        {
            if(color[it]==color[source])
            {
                no
                exit(0);
            }
        }
        if(b[it]==0)
        {
            b[it]=1;
            color[it]=(1-color[source]);
            dfs(it);
        }
    }
}
int main()
{
    ll n,m,i,j,x,y,t,u,v;
    vector<pair<ll,ll>>vp;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        vp.pb({u,v});
        bi[u].pb(v);
        bi[v].pb(u);
    }
    color[1]=1;
    b[1]=1;
    dfs(1);
        ya
        for(i=0; i<m; i++)
        {
            if(color[vp[i].second]==1)
                cout<<0;
            else
                cout<<1;
            //cout<<vp[i].first<< " "<<vp[i].second<<endl;
        }

    return 0;
}
 
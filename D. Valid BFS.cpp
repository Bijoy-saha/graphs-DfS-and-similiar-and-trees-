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
vector<ll>ts;
vector<ll>dis(200009);
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/

vector<ll>tr(200009);
ll bfs(ll source)
{
    b[source]=1;
    dis[source]=0;
    queue<ll>qq;
    qq.push(source);
    while(!qq.empty())
    {
        ll f=qq.front();
        qq.pop();
        for(ll i=0; i<bi[f].size(); i++)
        {
            if(b[bi[f][i]]==0)
            {
                b[bi[f][i]]=1;
                dis[bi[f][i]]=dis[f]+1;
                qq.push(bi[f][i]);
                tr[bi[f][i]]=f;
                //cout<<dis[bi[f][i]]<<endl;
            }
        }
    }
}
int main()
{
    ll x,y,i,j,m;
    ll n;
    cin>>n;
    vector<ll>xy;
    for(i=0; i<n-1; i++)
    {
        cin>>x>>y;
        bi[x].pb(y);
        bi[y].pb(x);
    }
    cin>>x;
    if(x!=1)
    {
        no
        return 0;
    }
    bfs(1);
    queue<ll>q;
    q.push(1);
    ll chk =1;
    j=0;
    m=0;
    for(i=1; i<n; i++)
    {
        cin>>x;
        j++;
        if(dis[x]==dis[chk]+1&&tr[x]==chk)
        {
            if(bi[x].size()>1)
            q.push(x);
        }
        else
        {
            no
            //cout<<x<<" "<<tr[x]<<" "<<chk<<endl;
            return 0;
        }

            if(j==bi[chk].size()-1&&chk!=1)
            {
                j=0;
                q.pop();
                chk=q.front();
            }else if(j==bi[chk].size()&&chk==1)
            {
             j=0;
                q.pop();
                chk=q.front();
            }

    }
    ya
    return 0;
}
 
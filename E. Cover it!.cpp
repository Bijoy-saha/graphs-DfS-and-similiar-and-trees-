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
vector<int>bi[200009];
vector<int>b(200009);
vector<int>dis(200009);
vector<int>color(200009);
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/
ll inf=1e9;
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(auto it:bi[v])
        {
            if(b[it]==0)
            {
                b[it]=1;
                dis[it]=(dis[v]+1);
                q.push(it);
            }
        }
    }
}
int main()
{
    fast_cin;
    int  n,m,i,j,x,y,t,u,v;
    vector<int>vc,bc;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1; i<=n; i++)
        {
            b[i]=0;
            color[i]=1;
            bi[i].clear();
            dis[i]=0;
        }
        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            bi[u].pb(v);
            bi[v].pb(u);
        }
        b[1]=1;
        dis[1]=1;
        bfs(1);
        for(i=1; i<=n; i++)
        {
            if(dis[i]%2==0)
            {
                vc.pb(i);
            }
            else
            {
                bc.pb(i);
            }
        }
        if(vc.size()<=bc.size())
        {
            cout<<vc.size()<<endl;
            for(i=0; i<vc.size(); i++)
            {
                cout<<vc[i]<<endl;
            }
        }
        else
        {
            cout<<bc.size()<<endl;
            for(i=0; i<bc.size(); i++)
            {
                cout<<bc[i]<<endl;
            }
        }
        vc.clear();
        bc.clear();
    }
}
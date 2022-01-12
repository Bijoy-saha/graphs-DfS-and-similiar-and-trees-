#include<iostream>
#include<string>
using ll=long long;
using namespace std;
#include<sstream>
ll mod=1e9+7;
#include<bits/stdc++.h>
#include<iomanip>
#define ya  cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;
#define pb push_back
#define fast_cin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(bi) bi.begin(),bi.end()
vector<int>bi[200009];
vector<bool>b(200009,0);
vector<int>dis(200009);
vector<int>color;
vector<double>prb(200009);
bool flag ;
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/

double sum=0;
int cnt=0;
void dfs(int source)
{
   int sources=source;
    if(bi[sources].size()==1)
    {
       cnt++;
       color.pb(sources);
       //cout<<sources<<endl;
    }
    b[sources]=1;
    for(auto it: bi[sources])
    {
        if(b[it]==0)
        {
            dis[it]=dis[sources]+1;
            if(sources==1)
            prb[it]=(prb[sources]/(bi[sources].size()+0.0));
            else
            {
                prb[it]=(prb[sources]/(bi[sources].size()-1.0));
            }
            //cout<<it<<" " <<prb[it]<<endl;
            dfs(it);
        }

    }
}
int main()
{
    fast_cin;
    int n,m,i,j,x,y,t,u,v;
    cin>>n;
    for(i=0; i<n-1; i++)
    {
        cin>>u>>v;
        bi[u].pb(v);
        bi[v].pb(u);
    }
    prb[1]=1;
    dis[1]=0;
    dfs(1);
    for(i=0;i<cnt;i++)
    {
        sum+=(dis[color[i]]*prb[color[i]]);
        //cout<<dis[color[i]]<<" " <<prb[color[i]]<<endl;
        //cout<<sum<<endl;
    }
    cout<<setprecision(12)<<sum<<endl;

}
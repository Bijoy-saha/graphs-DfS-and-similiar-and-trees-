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
/*bool cmp(pair<ll, ll>& a,
         pair<ll, ll>& b)
{
    return a.second > b.second;
}*/
int i,j,sum=0,x,y,t,m,n,cnt;
vector<int>bi[100009];
vector<int>dis(100009);
vector<bool>b(100009);
void dfs(int source,int cnt)
{
    if(dis[source]>0)
        cnt++;
    else
        cnt=0;
    if(cnt>m)
        return;
    if(bi[source].size()==1&&source!=1)
    {
        sum++;
    }
    for(int y:bi[source])
    {
        if(b[y]==0)
        {
            b[y]=1;
            dfs(y,cnt);
            //ya
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        dis[i]=x;
    }
    for(int i=0; i<n-1; i++)
    {

        int x,y;
        cin>>x>>y;
        bi[x].pb(y);
        bi[y].pb(x);

    }
    b[1]=1;
    dfs(1,0);
    cout<<sum;
    return 0;
}

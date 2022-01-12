#include<iostream>
#include<string>
using ll=long long;
#include <utility>
using namespace std;
#include<sstream>
ll mod=1e9+7;
#define filein freopen("input.txt","r",stdin)
#define fileout  freopen("output.txt","w",stdout)
#include<bits/stdc++.h>
#define ya  cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;
#define pb push_back
#define lst bi.back()
#define fast_cin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(bi) bi.begin(),bi.end()
#define printv(bi) for(i=0;i<bi.size();i++)cout<<bi[i]<<' ';cout<<endl;
#define see(x) cout<<x<<endl;
ll inf=1e16;
//iterateinaset for(auto it:s){cout<<it<<endl;}
//for searching a key:
//[auto it=mp.find(x);
//if(it!=mp.end())]
//for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
//bool cmp(pair<ll, ll>& a,
//         pair<ll, ll>& b)
//{
//    return a.second > b.second;
//}
//saauuo nijar diya  kissu hbena
/*ll myXOR(ll x, ll y)
{
   return (x | y) & (~x | ~y);
}*/
vector<ll>bi[200009];
map<pair<ll,ll>,ll>mp,mp1,mp2;
//map<ll,ll>mp;
vector<bool>b(200009,0);
vector<ll>dis(200009);
ll val=0;
ll vv=0;
void dfs(ll sources)
{
    ll source =sources;
    b[source]=1;
    for(auto it:bi[source])
    {
        if(b[it]==0)
        {
            if(mp1[ {source,it}]==1)
            {
              if(mp2[{source,it}]==1)
                {
                    //
                }else
                {
                   mp[{source,it}]=val++;
                   mp2[{source,it}]==1;
                }
            }
            else
            {
                if(mp2[{it,source}]==1)
                {
                    //
                }else
                {
                   mp[{it,source}]=val++;
                   mp2[{it,source}]==1;
                }

            }
            //cout<<source<<' '<<it<<' '<<val-1<<endl;
            dfs(it);

        }
    }
}
int main()
{
    fast_cin;
    ll x,n,i,y,j,t,xx=0;
    cin>>n;
    vector<pair<ll,ll>>vp;
    for(i=0; i<n-1; i++)
    {
        cin>>x>>y;
        mp1[ {x,y}]=1;
        vp.pb({x,y});
        bi[x].pb(y);
        bi[y].pb(x);
    }
    for(i=1; i<=n; i++)
    {
        if(bi[i].size()>2)
        {
            for(j=0; j<3; j++)
            {
                if(mp1[{i,bi[i][j]}]==1){
                        mp2[{i,bi[i][j]}]=1;
                mp[{i,bi[i][j]}]=val;
                }
                else
                {

                    mp2[{bi[i][j],i}]=1;
                 mp[{bi[i][j],i}]=val;
                }
//                cout<<i<<' ' <<bi[i][j]<<' '<<val<<endl;
//                cout<<mp[{i,bi[i][j]}]<<endl;
                val++;
            }
            break;
        }
    }
    dfs(1);
    //cout<<vp.size()<<endl;
    for(auto it=vp.begin(); it!=vp.end(); it++)
    {
//        cout<<it->first<<' ' <<it->second<<endl;
        y=it->second;
        x=it->first;
//        cout<<x<<' '<<y<<endl;
        cout<<mp[ {x,y}]<<endl;
    }

}


 
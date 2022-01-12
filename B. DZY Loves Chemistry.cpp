#include<iostream>
#include<string>
using ll=long long;
#include <utility>
using namespace std;
#include<sstream>
#include<numeric>
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
ll inf=1e10;
inline ll lcm(ll a,ll b)
{
    ll    y=(a*b)/__gcd(a,b);
    return y;
}
//iterateinaset for(auto it:s){cout<<it<<endl;}
//for searching a key:
//[auto it=mp.find(x);if(it!=mp.end())]
//for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
//*____________________________*
//bool cmp(pair<ll, ll>& a,
//         pair<ll, ll>& b)
//{
//    return a.second > b.second;
//}
//*______________________________*
ll myXOR(ll x, ll y)
{
    return (x | y) & (~x | ~y);
}
//*____________________________
vector<ll>b(100);
vector<ll>vc[100];
ll cal=1;
ll z=0;
ll one=1;
ll tw=2;
ll dfs(ll source)
{
   // b[source]=1;
   for(auto it:vc[source])
   {
       if(b[it]==z)
       {
           b[it]=one;
           cal=cal*tw;
           dfs(it);
       }
   }

    return cal;
}
int main()
{
    fast_cin;
    ll x,n,i,k,y,j=0,t,m;
    cin>>n>>k;
    for(i=0; i<k; i++)
    {
        cin>>x>>y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    ll sum=0;
    for(i=1; i<=n; i++)
    {
        if(vc[i].size()>sum)
        {
            sum=vc[i].size();
            x=i;
        }
    }
    if(k==0){cout<<1<<endl;
    return 0;
    }
    b[x]=1;
    dfs(x);
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            b[i]=1;
            dfs(i);
        }
    }
    see(cal)

}
 
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 300010
using namespace std;

ll t,n,k,x,y,r,c,minm,f,ans,deg[N],a[N];
vector<ll> g[N];

ll dfs(ll u,ll p)
{
    ll ret=LONG_LONG_MAX;
    vector<ll> s;
    for(ll v: g[u])
    {
        if(v!=p) 
        {
            c=dfs(v,u);
            ret=min(ret,1+c);
            s.push_back(c);
        }
    }
    sort(s.begin(),s.end());
    if(s.size()>=2)
    {
        minm=min(minm,1+s[0]+s[1]);
    }
    return (ret==LONG_LONG_MAX?1:ret);
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k; FOR(i,1,n+1) cin>>a[i],deg[i]=0,g[i].clear();
        minm=LONG_LONG_MAX; ans=0;
        FOR(i,1,n)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            deg[x]++,deg[y]++;
        }
        sort(a+1,a+n+1,greater<>());
        FOR(i,1,n+1)
        {
            if(deg[i]==1)
            {
                r=i;
                break;
            }
        }
        c=dfs(r,-1); 
        minm=min(minm,c); f=k/(2*minm);
        FOR(i,1,1+minm) 
        {
            ans+=2*f*a[i];
        }
        f=k-(f*2*minm);
        if(f==2)
        {
            ans+=a[1]+a[2];
        }
        else
        {
            FOR(i,1,1+f/2) ans+=a[i];
            FOR(i,1,1+(f+1)/2) ans+=a[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}

#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007
#define endl '\n'

ll poww(ll a, ll b)
{
    if(b==0)
        return 1;
    ll ans=poww(a,b/2);
    if(b%2==0)
        return (ans*ans)%mod;
    return (((ans*ans)%mod)*a)%mod;
}

void DFS(vector<int> tree[], int u, bool visited[], pl ans[], bool isprime[])
{
    visited[u]=1;
    ll val1=0,val2=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(visited[v])
            continue;
        DFS(tree,v,visited,ans,isprime);
        if(ans[v].first>0)
            val1+=ans[v].first;
        if(ans[v].second>0)
            val2+=ans[v].second;
    }
    if(isprime[u])
    {
        ans[u].first=val1+1;
        ans[u].second=max(0ll,val2-1);
    }
    else
    {
        ans[u].first=max(0ll,val1-1);
        ans[u].second=val2+1;
    }
}

void DFS2(vector<int> tree[], int u, bool visited[], pl ans[], ll finans[], bool isprime[])
{
    visited[u]=1;
    ll val1=0,val2=0;
    bool flag1=0,flag2=0;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(visited[v])
        {
            if(ans[v].first>0)
            {
                flag1=1;
                ans[v].first-=ans[u].first;
            }
            if(ans[v].second>0)
            {
                flag2=1;
                ans[v].second-=ans[u].second;
            }
        }
    }
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(ans[v].first>0)
            val1+=ans[v].first;
        if(ans[v].second>0)
            val2+=ans[v].second;
    }
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(visited[v])
        {
            if(flag1==1)
            {
                ans[v].first+=ans[u].first;
            }
            if(flag2==1)
            {
                ans[v].second+=ans[u].second;
            }
        }
    }    
    // cout<<u<<" "<<val1<<" "<<val2<<endl;
    if(isprime[u])
    {
        finans[u]=max(val1+1,val2-1);
        ans[u].first=val1+1;
        ans[u].second=max(val2-1,0ll);
    }
    else
    {
        finans[u]=max(val1-1,val2+1);
        ans[u].first=max(val1-1,0ll);
        ans[u].second=val2+1;
    }   

    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(visited[v])
            continue;
        DFS2(tree,v,visited,ans,finans,isprime);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    ll arr[n];
    bool seive[200005];
    for(int i=0;i<=200004;i++)
        seive[i]=1;
    seive[0]=0;
    seive[1]=0;
    for(int i=2;i<=sqrt(200004);i++)
    {
        if(seive[i]==0)
            continue;
        for(int j=i*i;j<=200004;j+=i)
            seive[j]=0;
    }
    bool isprime[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        isprime[i]=seive[arr[i]];
    }
    vector<int> tree[n];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    pl ans[n];
    for(int i=0;i<n;i++)
        ans[i]={0,0};
    bool visited[n]={0};
    DFS(tree,0,visited,ans,isprime);
    bool visited2[n]={0};
    ll finans[n]={0};
    DFS2(tree,0,visited2,ans,finans,isprime);
    for(int i=0;i<n;i++)
        cout<<finans[i]<<" ";

    return 0;
}

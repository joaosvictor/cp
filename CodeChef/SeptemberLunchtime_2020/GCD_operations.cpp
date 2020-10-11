// https://www.codechef.com/LTIME88B
#include<bits/stdc++.h>
#define endl "\n"
typedef long long int ll;
#define MOD 1000000007
#define mp make_pair
#define pll pair<ll,ll>
#define pb push_back
#define max_XOR(a,b) (1 << int(log2(a ^ b) + 1)) - 1
#define vl vector<ll>
#define inf ll(1e18)
#define all(v) (v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define nrep(i,a,b) for(long long int i=a;i>=b;i--)
#define ceil(a,b) a/b+((a%b ==0 )?0:1)
using namespace std;

const ll sz=100005;

int main()
{
	fast;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll ar[n];
		bool f=1;
		rep(i,0,n)
		{
		    cin>>ar[i];
		    if(!(__gcd(ar[i],i+1)==ar[i] or __gcd(ar[i],i+1)==i+1 or ar[i]==1))
		    {
		        f=0;
		    }
		}
		if(f)
		{
		    cout<<"YES\n";
		}
		else
		{
		    cout<<"NO\n";
		}
	}
}

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<int64_t,int64_t> Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    return os << "]";
}
template<class T> istream& operator>>(istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator << (ostream& os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, ordered_set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R>> ostream& operator<<(ostream &os, unordered_map<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}
template<class L, class R, class chash = std::hash<R> > ostream& operator<<(ostream &os, gp_hash_table<L,R,chash> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";
    return os<<"}";
}

#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l,long long r){
    uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
inline int64_t random_long(){
    uniform_int_distribution<int64_t> generator(LLONG_MIN,LLONG_MAX);
    return generator(rng);
}


/*/---------------------------Defines----------------------/*/
typedef vector<int> vi;
typedef pair<int,int> pii;

#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(v) (v).begin(),(v).end()

const int mod=1e9+7;

ll binpow(int a,int b,int m){
	ll ret = 1, mul = a;

	while(b){
		if (b&1){
			ret = (ret * mul)%m;
		}
		b >>= 1;
		mul = (mul * mul) %m;
	}

	return ret;
}

struct ex_gcd{ ll x,y,d;
	ex_gcd(ll x,ll y,ll d): x(x),y(y),d(d){}  };
ex_gcd gcd(ll a,ll b){if(b==0) return ex_gcd(1,0,a); 
	ex_gcd c=gcd(b,a%b);
	return ex_gcd(c.y,c.x-(a/b)*c.y,c.d); }


pair<ll,ll> CRT(vector<ll>& rem,vector<ll>& mods){
	ll lcm=mods[0]; ll ans=rem[0];
	for(int i=1;i<mods.size();++i){
		ex_gcd curr=gcd(lcm,mods[i]);
		// n1*((a2-a1)/d) % (n2/d)
		if ((ans-rem[i])%curr.d!=0) return {-1,-1};
		ans=ans+(((curr.x*(rem[i]-ans)/curr.d))%(mods[i]/curr.d))*lcm;
		lcm=(lcm*(mods[i]/curr.d)); ans%=lcm;
		if (ans<0) ans+=lcm; }
	return {ans,lcm}; 
}

const int N = 1e7 + 10;
int pr[N],phi_n[N];

void preprocess(){
	for(int i = 2; i < N; ++i){
		pr[i] = i;
		phi_n[i] = i - 1;
	}

	for(int i = 2; i < N; ++i){
		if (pr[i] == i){
			for(ll j = i * 1ll * i; j < N; j += i){
				pr[j] = min(pr[j],i);
			}
		}
		else{
			phi_n[i] = (phi_n[i / pr[i]]);
			if (pr[i / pr[i]] == pr[i]){
				phi_n[i] *= pr[i];
			}
			else{
				phi_n[i] *= (pr[i] - 1);
			}
		}
		
	}
}
inline ll F(int n,int m);

inline ll G(int n,int m){
	// M is prime^k !!!!
	if (n == 0){
		return 1;
	}
	if (n == 1){
		return (m == 2) ? 0 : 2;
	}

	

	

	if (n == 2){
		return 3%m;
	}

	if (n == 3){
		return 7 % m;
	}

	if (n == 4){
		return 127 % m;
	}

	if (n == 5){
		return (binpow(2,127,m) + m - 1)%m;
	}


	// G(n-1,m) > 2*m here
	if (m == 1){
		return 0;
	}

	if ((m&(m-1)) == 0){
		return m - 1;
	}
	ll phi = 1;
	ll M = m;

	if (M < N){
		phi = phi_n[M];
	}
	else{
		for(ll i = 2; i *i <= M; ++i){
			bool f = true;
			while ((M % i) == 0){
				if (f){
					phi *= (i - 1);
					f = false;
				}
				else phi *= i;

				M /= i;

				}
		}

		if (M > 1) phi *= M-1;
	}
	

	// n - 1>= 5  so adding phi is okay
	ll X = F(n - 1, phi);

	return (binpow(2,X + phi,m) + m - 1)%m;

}

inline ll F(int n,int m){
	if (m == 1){
		return 0;
	}
	vector<ll> rem,mods;

	if (m < N){
		while(m > 1){
			ll x = pr[m];
			ll ph = 1;
			while( pr[m] == x){
				m /= x;
				ph *= x;
			}

			mods.push_back(ph);
			rem.push_back(G(n,ph));
		}
	}
	else{
		for(ll i = 2; i*i <= m; ++i){
			ll ph = 1;
			while((m%i) == 0){
				m /= i;
				ph *= i;
			}
			if (ph > 1){
				mods.push_back(ph);
				rem.push_back(G(n,ph));	
			}
		}

		if (m > 1){
			mods.push_back(m);
			rem.push_back(G(n,m));
		}
	}
	

	


	return CRT(rem,mods).first;
}

void solve(){
	int n,m;
	cin >> n >> m;
	cout << F(n,m) % m << endl;


}
int main(){
    // Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
    // Or use gp_hash_table<X,null_type>
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed<<setprecision(25);
    cerr<<fixed<<setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int t=1;
    preprocess();

    // pre();
    cin>>t;
    while(t--) {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;     
}

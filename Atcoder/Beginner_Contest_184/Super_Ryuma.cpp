#include <bits//stdc++.h>
using namespace std;
 
// MACROS
#define int                     long long
#define mp                      make_pair
#define pb                      push_back
#define MAX                     1e9
#define MIN                     -1e9
#define PI                      3.1415926535897932384626433832795
#define mod                     1000000007
#define set(x)                  memset(x, 0, sizeof(x))
#define clr(x)                  memset(x, -1, sizeof(x))
#define ff                      first
#define ss                      second
#define rep(i,n)                for(int i=0;i<(n);i++)
#define FOR(i,a,b)              for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)             for(int i=(a);i>=(b);i--)
#define test()                  int t;cin>>t;while(t--)
#define endl                    "\n"
 
 
typedef priority_queue<int>     maxHeap;
typedef priority_queue<int,     vector<int>, greater<int>> minHeap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<pii>             vpii;
typedef vector<vi>              vvi;
typedef map<int, int>            mpii;
typedef set<int>                seti;
typedef multiset<int>           mseti;


 
 }
 
 
const int T2 = 105; const int T3 = 1005; const int T4 = 10005; const int T5 = 100005;
 
 
bool check(int a, int b, int c, int d) {
    if (a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3)
        return true;
    return false;
}
 
 
int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c)
           { swap(a, c); swap(b, d);}
        if (a == c && b == d) {
            cout << 0;
            return 0;
        }
        if (check(a, b, c, d)) {
            cout << 1;
            return 0;
        }
        if ((a + b) % 2 == ( c + d) % 2 ) {
            cout << 2;
            return 0;
        }
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int x = c + i, y = d + j;
                if (check(a, b, x, y)) {
                    cout << 2;
                    return 0;
                }
            }
        }
        int x = c, y = d;
         if (check(a, b, x+3, y)) {
                    cout << 2;
                    return 0;
                }
         if (check(a, b, x-3, y)) {
                    cout << 2;
                    return 0;
                }
                 if (check(a, b, x, y+3)) {
                    cout << 2;
                    return 0;
                }
                 if (check(a, b, x, y-3)) {
                    cout << 2;
                    return 0;
                }        
        cout << 3;
 
 
 
    }
    return 0;
 
}

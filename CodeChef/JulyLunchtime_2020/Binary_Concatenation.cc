#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <iomanip>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string.h>
#define ll long long
#define mod 1000000007
using namespace std;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int bsearch(ll n){
    int l = 1, u = 10000000, res = -1;
    while(l <= u){
        // int mid = (l + u) / 2;
        // if(pref[mid] == n) return mid;
        // else if(pref[mid] < n){
        //     res = mid;
        //     l = mid + 1;
        // }
        // else u = mid - 1;
    }
    return res;
}

bool is_strictly_increasing(vector<int> arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i-1]) return false;
    }
    return true;
}

bool is_strictly_decreasing(vector<int> arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]) return false;
    }
    return true;
}

#define MAXN 200005
int n;
vector<int> arr(MAXN);

ll f(int i, int j){
    int mbit1 = -1, mbit2 = -1;
    for(int bit = 0; bit < 32; bit++){
        if(((1 << bit) & arr[i]) > 0) mbit1 = bit;
        if(((1 << bit) & arr[j]) > 0) mbit2 = bit;
    }
    ll res1 = (ll)arr[i], res2 = (ll)arr[j];
    for(int bit = 0; bit < 32; bit++){
        if(((1 << bit) & arr[j]) > 0){
            ll new_bit = mbit1 + bit + 1;
            res1 += ((ll)1 << new_bit);
        }
        if(((1 << bit) & arr[i]) > 0){
            ll new_bit = mbit2 + bit + 1;
            res2 += ((ll)1 << new_bit);
        }
    }
    return max(res1, res2) - min(res1, res2);
}



void modBigNumber(string num, long long m){
    vector<int> vec; 
    // long long mod = 0;
    for (int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        // mod = mod * 10 + digit; 
        // int quo = mod / m; 
        // vec.push_back(quo);
        // mod = mod % m;         
    }
    cout << "\nRemainder : " << mod << "\n";
    cout << "Quotient : ";
    bool zeroflag = 0; 
    for (int i = 0; i < vec.size(); i++) { 
        if (vec[i] == 0 && zeroflag == 0) 
            continue; 
        zeroflag = 1; 
        cout << vec[i]; 
    } 
    return;
}

void phi_1_to_n(int n){
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main(){
    int t;
    cin >> t;
    int times = t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > arr[maxi]){
                maxi = i;
            }
        }
        if(n <= 1000 && times <= 100){
            ll res = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++) res = max(res, f(i, j));
            }
            cout << res << endl;
            continue;
        }
        ll res = 0;
        for(int i = 0; i < n; i++) res = max(res, f(i, maxi));
        cout << res << endl;
    }
}

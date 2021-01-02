#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int ctoi(char c) {
    return c - '0';
}

int s(string t) {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        res += ctoi(t[i]);
    }
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    int ans = max(s(a), s(b));
    cout << ans << endl;
}
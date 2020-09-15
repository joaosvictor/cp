#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <queue>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    using hash_t = uint64_t;

    int N;
    cin >> N;
    vector<hash_t> hash_values(N + 1);

    for (int i = 0; i <= N; i++)
        hash_values[i] = rng();

    vector<int> freq(N + 1, 0);
    vector<queue<int>> indices(N + 1);
    vector<hash_t> hashes(N + 1, 0);
    unordered_map<hash_t, int> hash_freq;
    hash_freq[hashes[0]]++;
    int64_t answer = 0;
    int start = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (indices[a].size() >= 3) {
            int remove = indices[a].front(); indices[a].pop();

            while (start <= remove) {
                hash_freq[hashes[start]]--;
                start++;
            }
        }

        int before = freq[a];
        freq[a] = (freq[a] + 1) % 3;
        hashes[i + 1] = hashes[i] + (freq[a] - before) * hash_values[a];
        answer += hash_freq[hashes[i + 1]];
        hash_freq[hashes[i + 1]]++;
        indices[a].push(i);
    }

    cout << answer << '\n';
}

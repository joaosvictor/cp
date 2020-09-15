// give wi
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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

struct segment {
    int minimum, index;

    segment(int _minimum = numeric_limits<int>::max(), int _index = -1) : minimum(_minimum), index(_index) {}

    void join(const segment &other) {
        if (other.minimum < minimum) {
            minimum = other.minimum;
            index = other.index;
        }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};
//step 1
int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = false;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};
//step 2

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    int64_t L, R;
    cin >> N >> M >> L >> R;
    vector<array<int, 4>> solution(N + 1, {-1, -1, -1, -1});

    auto &&get_y_range = [&](int x) -> array<int64_t, 2> {
        int64_t y_low = max(INT64_C(1), (L + x - 1) / x);
        int64_t y_high = min(int64_t(M), R / x);
        return {y_low, y_high};
    };

    basic_seg_tree tree(M + 1);
    vector<segment> initial(M + 1);

    for (int i = 1; i <= M; i++)
        initial[i] = segment(INF, i);

    tree.build(initial);

    for (int f = M; f > 0; f--) {
        for (int x = f; x <= N; x += f) {
            array<int64_t, 2> y_range = get_y_range(x);

            if (y_range[0] <= y_range[1]) {
                segment seg = tree.query(y_range[0], y_range[1] + 1);
                assert(seg.minimum > f);

                if (seg.minimum <= int64_t(f) * N / x) {
                    int y = seg.index;
                    int yf = seg.minimum;
                    solution[x] = {x, y, x / f * yf, y / yf * f};
                }
            }
        }

        for (int y = f; y <= M; y += f)
            tree.update(y, segment(f, y));
    }

    for (int x = 1; x <= N; x++)
        if (solution[x][0] < 0)
            cout << -1 << '\n';
        else
            cout << solution[x][0] << ' ' << solution[x][1] << ' ' << solution[x][2] << ' ' << solution[x][3] << '\n';
}//tr

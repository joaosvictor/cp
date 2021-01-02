#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using II = pair<int, int>;

void top_sort(Graph &graph, int u, vector<bool> &seen,
        vector<int> &order)
{
    seen.at(u) = true;
    for (int v : graph.at(u)) {
        if (seen.at(v))
            continue;
        top_sort(graph, v, seen, order);
    }
    order.push_back(u);
}

void dfs(Graph &graph, int u, vector<int64_t> &y_vec,
        vector<bool> &seen, vector<int64_t> &c_vec)
{
    seen.at(u) = true;
    c_vec.at(u) += y_vec.at(u);
    for (int v : graph.at(u)) {
        if (seen.at(v))
            continue;
        c_vec.at(v) += c_vec.at(u);
        dfs(graph, v, y_vec, seen, c_vec);
    }
}

int main()
{
    int N;
    cin >> N;
    Graph graph(N);
    vector<II> edge_vec(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
        edge_vec.at(i) = {a, b};
    }
    vector<int> order;
    vector<bool> seen(N, false);
    top_sort(graph, 0, seen, order);
    reverse(order.begin(), order.end());
    vector<int> rank(N);
    for (int i = 0; i < N; ++i)
        rank.at(order.at(i)) = i;
    int Q;
    cin >> Q;
    vector<int> t_vec(Q), e_vec(Q);
    vector<int64_t> x_vec(Q);
    for (int i = 0; i < Q; ++i) {
        int e;
        cin >> t_vec.at(i) >> e >> x_vec.at(i);
        --e;
        e_vec.at(i) = e;
    }
    vector<int64_t> y_vec(N, 0);
    for (int i = 0; i < Q; ++i) {
        int t = t_vec.at(i), e = e_vec.at(i);
        int64_t x = x_vec.at(i);
        int a = edge_vec.at(e).first, b = edge_vec.at(e).second;
        if (t == 1) {
            if (rank.at(a) > rank.at(b)) {
                y_vec.at(a) += x;
            } else {
                y_vec.at(b) -= x;
                y_vec.at(0) += x;
            }
        }
        if (t == 2) {
            if (rank.at(b) > rank.at(a)) {
                y_vec.at(b) += x;
            } else {
                y_vec.at(a) -= x;
                y_vec.at(0) += x;
            }
        }
    }
    vector<int64_t> c_vec(N, 0);
    for (int i = 0; i < N; ++i)
        seen.at(i) = false;
    dfs(graph, 0, y_vec, seen, c_vec);
    for (int i = 0; i < N; ++i)
        cout << c_vec.at(i) << endl;
}

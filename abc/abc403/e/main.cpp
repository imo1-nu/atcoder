#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

struct trie {
    using ar = array<int, 26>;
    vector<ar> pos;
    ar def;
    int now_size;
    vector<pair<bool, int>> nodes;
    trie() = default;
    trie(int len) {
        pos.reserve(len + 1);
        nodes.reserve(len + 1);
        def.fill(-1);
        now_size = 0;
        make_node();
    }

    int make_node() {
        pos.push_back(def);
        nodes.push_back({false, 0});
        return now_size++;
    }

    void query(int t, string &s) {
        int now = 0;
        for (char c : s) {
            int d = c - 'a';
            int &nxt = pos[now][d];
            if (nxt == -1) nxt = make_node();
            now = nxt;
            if (nodes[now].first) return;
        }
        if (t == 1) {
            nodes[now].first = true;
            plus(s, -nodes[now].second);
        }
        else {
            plus(s, 1);
        }
    }

    void plus(string &s, int cnt) {
        int now = 0;
        nodes[now].second += cnt;
        for (char c : s) {
            int d = c - 'a';
            int &nxt = pos[now][d];
            now = nxt;
            nodes[now].second += cnt;
        }
    }

    int answer() {
        return nodes[0].second;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    trie T(500000);
    while (Q--) {
        int t;
        string s;
        cin >> t >> s;
        T.query(t, s);
        cout << T.answer() << '\n';
    }
}

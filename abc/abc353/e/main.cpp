#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie {
    using ar = array<int, 26>;
    vector<ar> pos;
    ar def;
    int now_size;
    ll ans;
    vector<int> cnt;
    trie() = default;
    trie(int len) {
        pos.reserve(len + 1);
        cnt.reserve(len + 1);
        def.fill(-1);
        now_size = ans = 0;
        make_node();
    }

    int make_node() {
        pos.push_back(def);
        cnt.push_back(0);
        return now_size++;
    }

    void add(string &s) {
        int now = 0;
        for (char c : s) {
            int d = c - 'a';
            int &nxt = pos[now][d];
            if (nxt == -1) nxt = make_node();
            now = nxt;
            ans += cnt[now]++;
        }
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    trie t(300000);
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        t.add(s);
    }
    cout << t.ans << endl;
}

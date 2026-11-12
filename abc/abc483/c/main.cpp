#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// https://github.com/imo1-nu/atcoder/tree/main/lib

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N);
    vector<vector<int>> second(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++;
        second[a].push_back(b);
    }

    set<pair<int, int>> S;
    for (int i = 0; i < N; i++) S.insert({cnt[i], -i});

    for (int i = 0; i < N; i++) {
        for (auto to : second[i]) {
            S.erase({cnt[i], -i});
            S.erase({cnt[to], -to});
            cnt[i]--;
            cnt[to]++;
            S.insert({cnt[i], -i});
            S.insert({cnt[to], -to});
        }

        cout << -(*S.rbegin()).second + 1 << endl;

        for (auto to : second[i]) {
            S.erase({cnt[i], -i});
            S.erase({cnt[to], -to});
            cnt[i]++;
            cnt[to]--;
            S.insert({cnt[i], -i});
            S.insert({cnt[to], -to});
        }
    }
}

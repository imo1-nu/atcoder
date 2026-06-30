#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> H(N), L(N);
    for (int i = 0; i < N; i++) cin >> H[i] >> L[i];

    int Q;
    cin >> Q;
    vector<pair<int, int>> query(Q);
    for (int i = 0; i < Q; i++) {
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    multiset<int> S;
    for (int i = 0; i < N; i++) {
        pq.push({L[i], i});
        S.insert(H[i]);
    }

    vector<int> ans(Q);
    for (auto q : query) {
        while (!pq.empty()) {
            auto p = pq.top();
            if (p.first > q.first) break;
            pq.pop();
            S.erase(S.find(H[p.second]));
        }
        ans[q.second] = *S.rbegin();
    }

    for (int a : ans) cout << a << endl;
}

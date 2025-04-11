#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), W(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    vector<set<pair<int, int>>> box(N);
    for (int i = 0; i < N; i++) {
        box[A[i]].insert({W[i], i});
    }
    vector<int> order(N);
    int idx = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (auto [w, j] : box[i]) {
            order[idx] = i;
            idx++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += abs(order[i] - i);
    }

    for (int i = N - 1; i >= 0; i--) {
        if (order[i] > i) {
            while ()
        }
    }
}

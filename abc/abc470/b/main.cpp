#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        cnt[c - 1]++;
    }
    int mx = 0;
    for (auto c : cnt) mx = max(mx, c);
    cout << N - mx << endl;
}

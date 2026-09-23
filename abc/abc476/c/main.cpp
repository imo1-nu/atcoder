#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    map<int, int> mp;
    mp[-A[0]]++;
    mp[-A[1]]++;
    for (int i = 2; i < N; i++) {
        mp[-A[i]]++;
        int cnt = 0;
        for (auto [k, v] : mp) {
            cnt += v;
            if (cnt >= 3) {
                cout << -k << endl;
                break;
            }
        }
    }
}

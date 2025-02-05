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
    for (int i = 0; i < N; i++) cin >> A[i];
    multiset<int> S;
    for (int i = 0; i < N; i++) {
        auto it = S.lower_bound(A[i]);
        if (it != S.begin()) S.erase(--it);
        S.insert(A[i]);
    }
    cout << S.size() << endl;
}

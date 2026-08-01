#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N), Q(N);
    for (auto& p : P) cin >> p;
    for (auto& q : Q) cin >> q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) A[i] = i + 1;
    int p, q;
    int cnt = 0;
    do {
        if (A == P) p = cnt;
        if (A == Q) q = cnt;
        cnt++;
    } while (next_permutation(A.begin(), A.end()));

    cout << max(0, q - p - 1) << endl;;
}

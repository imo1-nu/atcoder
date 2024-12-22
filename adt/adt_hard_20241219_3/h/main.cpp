#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N), C(M), D(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < M; ++i) cin >> C[i];
    for (int i = 0; i < M; ++i) cin >> D[i];

    vector<tuple<int, int, int>> obj;
    for (int i = 0; i < N; ++i) {
        obj.emplace_back(A[i], B[i], 0);
    }
    for (int i = 0; i < M; ++i) {
        obj.emplace_back(C[i], D[i], 1);
    }
    sort(obj.rbegin(), obj.rend());

    multiset<int> box;
    for (auto [a, b, c] : obj) {
        if (c == 1) {
            box.insert(b);
            continue;
        }
        auto it = box.lower_bound(b);
        if (it == box.end()) {
            cout << "No" << endl;
            return 0;
        }
        box.erase(it);
    }
    cout << "Yes" << endl;
}

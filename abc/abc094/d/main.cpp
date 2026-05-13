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
    sort(A.begin(), A.end());

    int l = A[N - 1];
    int r = A[0];
    for (auto a : A) {
        if (abs(l - r * 2) > abs(l - a * 2)) r = a;
    }
    cout << l << ' ' << r << endl;
}

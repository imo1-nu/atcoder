#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    cin >> X;
    cout << A[X - 1] << endl;
}

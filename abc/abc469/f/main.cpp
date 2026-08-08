#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto& a : A) cin >> a;
    sort(A.begin(), A.end());
    atcoder::dsu uf(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

        }
    }
}
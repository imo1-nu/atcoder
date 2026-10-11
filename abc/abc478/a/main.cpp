#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cout << M / N + (i < M % N) << endl;
    }
}

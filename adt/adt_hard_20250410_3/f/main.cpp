#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), inv(N, -1);
    int root = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != -1) inv[A[i] - 1] = i;
        else root = i;
    }
    int v = root;
    while (v != -1) {
        cout << v + 1 << " ";
        v = inv[v];
    }
    cout << endl;
}

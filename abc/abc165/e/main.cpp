#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; true; i++) {
        if (i >= M - i + 1) break;
        cout << i << ' ' << M - i + 1 << endl;
    }
    for (int i = 1; true; i++) {
        if (M + i >= M * 2 - i + 2) break;
        cout << M + i << ' ' << M * 2 - i + 2 << endl;
    }
}

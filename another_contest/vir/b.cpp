#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += max(0, A[i] - 10);
    }
    cout << ans << endl;
}

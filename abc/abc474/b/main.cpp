#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N);
    for (auto& p : P) cin >> p;

    for (int i = 1; i < N; i += 10) {
        for (int j = i; j <= min(i + 9, N); j++) {
            if (P[j-1] < i || P[j-1] > min(i + 9, N)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}

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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool ans = false;
    int m = N % 4;
    vector<int> even, odd;
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            if (i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        }
    }

    if (m == 0) {
        ans = true;
    }
    else if (m == 1 || m == 3) {
        if (even.size() + odd.size() > 0) {
            ans = true;
        }
    }
    else {
        if (even.size() > 0 && odd.size() > 0) {
            ans = true;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

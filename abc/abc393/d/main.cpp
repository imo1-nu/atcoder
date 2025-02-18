#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            A.push_back(i - cnt);
            cnt++;
        }
    }
    sort(A.begin(), A.end());

    int mid = A[A.size() / 2];
    ll ans = 0;
    for (int i = 0; i < (int)A.size(); i++) {
        ans += abs(A[i] - mid);
    }
    cout << ans << endl;
}

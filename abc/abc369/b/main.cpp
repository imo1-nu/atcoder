#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    vector<char> S(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> S[i];
    }
    
    int l = -1, r = -1;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            if (l != -1) ans += abs(A[i] - l);
            l = A[i];
        }
        else {
            if (r != -1) ans += abs(r - A[i]);
            r = A[i];
        }
    }
    cout << ans << endl;
}

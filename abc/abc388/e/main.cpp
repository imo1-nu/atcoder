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
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    multiset<int> S;
    for (int i = 0; i < N / 2; i++) {
        S.insert(A[i]);
    }

    int ans = 0;
    for (int i = N / 2; i < N; i++) {
        if (S.size() == 0) continue;
        int mn = *S.begin();
        if (mn * 2 <= A[i]) {
            S.erase(S.begin());
            ans++;
        }
    }
    cout << ans << endl;
}

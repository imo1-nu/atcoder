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
    vector<int> q(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> q[i] >> r[i];
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t, d;
        cin >> t >> d;
        t--;
        if (d % q[t] <= r[t]) {
            cout << d - (d % q[t]) + r[t] << endl;
        }
        else {
            cout << d - (d % q[t]) + q[t] + r[t]<< endl;
        }
    }
}

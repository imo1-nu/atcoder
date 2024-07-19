#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N, cnt;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];

    cnt = 0;
    vector<ll> s;

    for (ll i = 0; i < N; i++) {
        s.push_back(A[i]);
        cnt++;
        if (cnt == 1) continue;
        while (s[cnt - 1] == s[cnt - 2]) {
            s[cnt - 2]++;
            s.pop_back();
            cnt--;
            if (cnt == 1) break;;
        }
    }
    cout << cnt << endl;
}

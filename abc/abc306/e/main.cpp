#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    multiset<int> S1, S2;
    for (int i = 0; i < K; i++) S1.insert(0);
    for (int i = K; i <= N; i++) S2.insert(0);

    ll sum = 0;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;
        int a = A[x];
        A[x] = y;
        if (S1.count(a)) {
            S1.erase(S1.find(a));
            S1.insert(y);
            sum += y - a;
        }
        else {
            S2.erase(S2.find(a));
            S2.insert(y);
        }
        int mn = *S1.begin();
        int mx = *S2.rbegin();
        if (mn < mx) {
            S1.erase(S1.find(mn));
            S2.erase(S2.find(mx));
            S1.insert(mx);
            S2.insert(mn);
            sum += mx - mn;
        }
        cout << sum << '\n';
    }
}

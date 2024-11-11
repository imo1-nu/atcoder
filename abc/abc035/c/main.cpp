#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<bool> rev(N + 1, false);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        rev[l - 1] = !rev[l - 1];
        rev[r] = !rev[r];
    }

    vector<bool> ans(N + 1, false);
    for (int i = 1; i <= N; i++) {
        ans[i] = rev[i - 1] ^ ans[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        if (ans[i]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

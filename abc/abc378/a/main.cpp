#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> A(4);
    for (int i = 0; i < 4; ++i) {
        int a;
        cin >> a;
        A[a - 1]++;
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        while (A[i] > 1) {
            A[i] -= 2;
            ans++;
        }
    }
    cout << ans << endl;
}

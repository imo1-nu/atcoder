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
    
    vector<int> sq;
    vector<int> f(N + 1);
    for (int i = 1; i * i <= N; ++i) {
        sq.push_back(i * i);
        int x = i * i;
        for (int j = x; j <= N; j += x) {
            f[j] = x;
        }
    }

   vector<int> cnt(N + 1);
    for (int i = 1; i <= N; ++i) {
        cnt[i / f[i]]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += cnt[i] * cnt[i];
    }
    cout << ans << endl;
}

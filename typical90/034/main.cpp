#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> mp;
    int ans = 0;
    int l = 0, r = 1;
    while (r <= N) {
        mp[A[r - 1]]++;
        while (mp.size() > K) {
            mp[A[l]]--;
            if (mp[A[l]] == 0) mp.erase(A[l]);
            l++;
        }
        ans = max(ans, r - l);
        r++;
    }
    cout << ans << endl;
}

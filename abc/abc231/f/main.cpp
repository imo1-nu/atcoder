#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

void compression(vector<int> &v) {
    map<int, int> mp;
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 0; i < (int)tmp.size(); i++) mp[tmp[i]] = i;
    for (auto &x : v) x = mp[x];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    compression(B);
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) P[i] = {-A[i], B[i]};
    sort(P.begin(), P.end());

    ll ans = 0;
    atcoder::fenwick_tree<int> fw(N);
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        while (i + 1 < N && P[i] == P[i + 1]) {
            i++;
            cnt++;
        }
        int b = P[i].second;
        fw.add(b, cnt);
        ans += (ll)cnt * fw.sum(0, b + 1);
    }
    cout << ans << '\n';
}

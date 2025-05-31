#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

map<int, int> compression(vector<int> &v) {
    map<int, int> mp;
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 0; i < (int)tmp.size(); i++) mp[tmp[i]] = i;
    return mp;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    auto idx = compression(A);
    atcoder::fenwick_tree<int> fw(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += fw.sum(idx[A[i]], N);
        fw.add(idx[A[i]], 1);
        if (i < 2) continue;
        if (A[i] < A[i - 1] && A[i - 1] < A[i - 2]) {
            ans -= 3;
            swap(A[i], A[i - 2]);
        }
        if (A[i - 1] < A[i] && A[i] < A[i - 2]) {
            ans -= 1;
            swap(A[i], A[i - 2]);
        }
        if (A[i] < A[i - 2] && A[i - 2] < A[i - 1]) {
            ans -= 1;
            swap(A[i], A[i - 2]);
        }
    }
    cout << ans << endl;
}

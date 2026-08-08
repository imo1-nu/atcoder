#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    vector<vector<int>> nums(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        nums[A[i]].push_back(i);
        nums[B[i]].push_back(i);
    }

    vector<int> cnt1(N), cnt2(M + 1);
    for (int i = 0; i < N; i++) {
        cnt1[i] = nums[i].size();
        cnt2[cnt1[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (auto j : nums[i]) {
            int target = A[j];
            if (target == i) target = B[j];
            cnt2[cnt1[target]]--;
            cnt1[target]--;
            cnt2[cnt1[target]]++;
        }
        
        ans += cnt2[M - cnt1[i]];
        if (cnt1[i] * 2 == M) ans--;

        for (auto j : nums[i]) {
            int target = A[j];
            if (target == i) target = B[j];
            cnt2[cnt1[target]]--;
            cnt1[target]++;
            cnt2[cnt1[target]]++;
        }
    }
    cout << ans / 2 << endl;
}

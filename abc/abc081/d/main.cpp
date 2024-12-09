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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int absMaxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (abs(A[i]) > abs(A[absMaxIdx])) absMaxIdx = i;
    }

    queue<pair<int, int>> ans;
    for (int i = 0; i < N; i++) {
        if (i == absMaxIdx) continue;
        A[i] += A[absMaxIdx];
        ans.push({absMaxIdx + 1, i + 1});
    }

    if (A[absMaxIdx] >= 0) {
        for (int i = 1; i < N; i++) {
            ans.push({i, i + 1});
        }
    }
    else {
        for (int i = N; i > 1; i--) {
            ans.push({i, i - 1});
        }
    }

    cout << ans.size() << endl;
    while (!ans.empty()) {
        auto [a, b] = ans.front();
        ans.pop();
        cout << a << " " << b << endl;
    }
}

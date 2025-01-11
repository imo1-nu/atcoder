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

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        A[i] += pq.size();
        pq.push(A[i] + i);
        ans[i] = max(0, A[i] - (N - i - 1));
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i];
        cout << (i == N - 1 ? '\n' : ' ');
    }
}

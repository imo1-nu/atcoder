#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> jobs(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }
    sort(jobs.rbegin(), jobs.rend());

    int ans = 0;
    priority_queue<int> pq;
    for (int d = 1; d <= M; d++) {
        while (!jobs.empty() && jobs.back().first <= d) {
            pq.push(jobs.back().second);
            jobs.pop_back();
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}

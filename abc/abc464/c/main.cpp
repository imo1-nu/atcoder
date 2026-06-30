#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(N), D(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> D[i] >> B[i];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) pq.push({D[i], i});
    map<int, int> mp;
    for (int i = 0; i < N; i++) mp[A[i]]++;

    for (int j = 1; j <= M; j++) {
        while (!pq.empty() && pq.top().first <= j) {
            int i = pq.top().second;
            pq.pop();
            mp[A[i]]--;
            if (mp[A[i]] == 0) mp.erase(A[i]);
            mp[B[i]]++;
        }
        cout << mp.size() << endl;
    }
}

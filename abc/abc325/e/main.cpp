#include <bits/stdc++.h>
using namespace std;

const long long INF = 3000000000000000000;

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<vector<int>> D(N, vector<int>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> D[i][j];
    vector<int> d(N, INF);
    d[0] = 0;
    vector<priority_queue<long long, vector<long long>, greater<long long>>> pq(N - 1);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) pq[i].push(D[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
    }
}

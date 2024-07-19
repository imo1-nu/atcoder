#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];

    int ans = N;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++) A[P[i]] = i;

    vector<vector<int>> B(N + 1, vector<int> (5, 0));


    for (int i = 2; i <= N - K + 1; i++) {
        
    }

    cout << ans << endl;
}

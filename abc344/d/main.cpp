#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string T;
    int N;
    cin >> T >> N;
    vector<int> A(N);
    vector<vector<string>> S(N, vector<string>(10));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++) cin >> S[i][j];
    }
    vector<int> dp(T.length(), T.length() + 1);
    dp[0] = 0;
    for (int i = 1; i < T.length(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < N;)
        }
    }
}

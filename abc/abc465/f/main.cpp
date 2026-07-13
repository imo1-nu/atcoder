#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> V(N);
    for (int i = 0; i < N; i++) cin >> S[i] >> V[i];

    vector<vector<vector<vector<vector<vector<int>>>>>> A(10, vector<vector<vector<vector<vector<int>>>>>(10, vector<vector<vector<vector<int>>>>(10, vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(10))))));
    for (int i = 0; i < N; i++) A[S[i][0]-'0'][S[i][1]-'0'][S[i][2]-'0'][S[i][3]-'0'][S[i][4]-'0'][S[i][5]-'0'] += V[i];
    vector<vector<vector<vector<vector<vector<int>>>>>> B(11, vector<vector<vector<vector<vector<int>>>>>(11, vector<vector<vector<vector<int>>>>(11, vector<vector<vector<int>>>(11, vector<vector<int>>(11, vector<int>(11))))));
    

    int Q;
    cin >> Q;
    while (Q--) {
        string x, y;
        cin >> x >> y;
    }
}

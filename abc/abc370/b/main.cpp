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
    vector<vector<int>> A(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> A[i][j];
        }
    }
    int now = 1;
    for (int i = 1; i <= N; i++) {
        if (now > i) now = A[now][i];
        else now = A[i][now];
    }
    cout << now << endl;
}

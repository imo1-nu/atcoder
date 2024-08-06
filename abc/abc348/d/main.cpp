#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W;
vector<string> B;

bool check (int x, int y, int dr)
{
    if (dr == 0 && x > 0 && B[x - 1][y] != '#') return true;
    if (dr == 1 && y < W - 1 && B[x][y + 1] != '#') return true;
    if (dr == 2 && x < H - 1 && B[x + 1][y] != '#') return true;
    if (dr == 3 && y > 0 && B[x][y - 1] != '#') return true;
    return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    B = A;
    int N, x, y;
    cin >> N;
    vector<vector<int>> E(H, vector<int>(W, 0));
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cin >> E[x][y];
    }

    pair<int, int> S, T;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == 'S') {
                S.first = i;
                S.second = j;
            }
            if (A[i][j] == 'T') {
                T.first = i;
                T.second = j;
            }
        }
    }

    vector<vector<int>> dp(H, vector<int>(W, -1));
    pair<int, int> cr = S;
    dp[cr.first][cr.second] = E[cr.first][cr.second];

    while (1) {
        
    }
}

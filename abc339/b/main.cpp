#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W, N, dir = 3;
    pair<int, int> p = make_pair(0, 0);
    cin >> H >> W >> N;
    vector<vector<char>> A(H, vector<char>(W, '.'));
    for (int i = 0; i < N; i++) {
        if (A[p.first][p.second] == '.') {
            dir = (dir + 1) % 4;
            A[p.first][p.second] = '#';
        }
        else {
            dir = (dir + 3) % 4;
            A[p.first][p.second] = '.';
        }

        if (dir == 0) p.second = (p.second + 1) % W;
        if (dir == 1) p.first = (p.first + 1) % H;
        if (dir == 2) p.second = (p.second + W - 1) % W;
        if (dir == 3) p.first = (p.first + H - 1) % H;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cout << A[i][j];
        cout << endl;
    }
}

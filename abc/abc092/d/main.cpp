#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;

    vector<string> grid(100, string(100, '#'));
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 100; j++) {
            grid[i][j] = '.';
        }
    }

    A--; B--;
    for (int i = 0; i < B; i++) {
        grid[i / 50 * 2][i % 50 * 2] = '#';
    }
    for (int i = 0; i < A; i++) {
        grid[51 + i / 50 * 2][i % 50 * 2] = '.';
    }

    cout << "100 100" << endl;
    for (int i = 0; i < 100; i++) {
        cout << grid[i] << endl;
    }
}

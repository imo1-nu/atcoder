#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<char>> s(729, vector<char>(729, '#'));

int func(int i, int j, int k) {
    if (k == 0) return 0;
    int l = 1;
    for (int x = 0; x < k; x++) {
        l *= 3;
    }

    for (int x = i + l / 3; x < i + l / 3 * 2; x++) {
        for (int y = j + l / 3; y < j + l / 3 * 2; y++) {
            s[x][y] = '.';
        }
    }    
    
    func(i, j, k - 1);
    func(i + l / 3, j, k - 1);
    func(i + l / 3 * 2, j, k - 1);

    func(i, j + l / 3, k - 1);
    func(i + l / 3 * 2, j + l / 3, k - 1);

    func(i, j + l / 3 * 2, k - 1);
    func(i + l / 3, j + l / 3 * 2, k - 1);
    func(i + l / 3 * 2, j + l / 3 * 2, k - 1);
    return 0;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int l = 1;
    for (int i = 0; i < n; i++) {
        l *= 3;
    }
    
    func(0, 0, n);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }

    //cout << l << endl;
    
    
}

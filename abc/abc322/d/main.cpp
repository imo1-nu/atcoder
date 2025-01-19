#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<vector<char>>> P(3, vector<vector<char>>(4, vector<char>(4)));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> P[i][j][k];
            }
        }
    }

    auto rotate = [&](vector<vector<char>> &p) {
        vector<vector<char>> q(4, vector<char>(4));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                q[j][3 - i] = p[i][j];
            }
        }
        return q;
    };

    auto check = [&](vector<vector<char>> &x) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (3 <= i && i < 7 && 3 <= j && j < 7) {
                    if (x[i][j] == '.') return false;
                }
                else if (x[i][j] == '#') {
                    return false;
                }
            }
        }
        return true;
    };

    vector<int> rot(2);
    vector<int> I(3), J(3);
    for (rot[0] = 0; rot[0] < 4; rot[0]++) {
        for (rot[1] = 0; rot[1] < 4; rot[1]++) {
            for (I[0] = 0; I[0] < 7; I[0]++) {
                for (J[0] = 0; J[0] < 7; J[0]++) {
                    for (I[1] = 0; I[1] < 7; I[1]++) {
                        for (J[1] = 0; J[1] < 7; J[1]++) {
                            for (I[2] = 0; I[2] < 7; I[2]++) {
                                for (J[2] = 0; J[2] < 7; J[2]++) {
                                    vector<vector<char>> x(10, vector<char>(10, '.'));
                                    bool ok = true;
                                    for (int i = 0; i < 3; i++) {
                                        for (int j = 0; j < 4; j++) {
                                            for (int k = 0; k < 4; k++) {
                                                if (P[i][j][k] == '#') {
                                                    if (x[I[i] + j][J[i] + k] == '#') ok = false;
                                                    x[I[i] + j][J[i] + k] = '#';
                                                }
                                            }
                                        }
                                    }
                                    if (ok && check(x)) {
                                        cout << "Yes" << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            P[1] = rotate(P[1]);
        }
        P[0] = rotate(P[0]);
    }
    cout << "No" << endl;
}

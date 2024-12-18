#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<string> resize(vector<string> S) {
    int sx = 0, sy = 0;
    int tx = S.size(), ty = S[0].size();

    while (1) {
        bool flag = false;
        for (int j = 0; j < ty; ++j) {
            if (S[sx][j] == '#') flag = true;
        }
        if (flag) break;
        ++sx;
    }

    while (1) {
        bool flag = false;
        for (int j = 0; j < ty; ++j) {
            if (S[tx - 1][j] == '#') flag = true;
        }
        if (flag) break;
        --tx;
    }

    while (1) {
        bool flag = false;
        for (int i = sx; i < tx; ++i) {
            if (S[i][sy] == '#') flag = true;
        }
        if (flag) break;
        ++sy;
    }

    while (1) {
        bool flag = false;
        for (int i = sx; i < tx; ++i) {
            if (S[i][ty - 1] == '#') flag = true;
        }
        if (flag) break;
        --ty;
    }

    vector<string> res;
    for (int i = sx; i < tx; ++i) {
        string s;
        for (int j = sy; j < ty; ++j) {
            s.push_back(S[i][j]);
        }
        res.push_back(s);
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int Ha, Wa, Hb, Wb, Hx, Wx;
    vector<string> A, B, X;
    cin >> Ha >> Wa;
    for (int i = 0; i < Ha; ++i) {
        string s;
        cin >> s;
        A.push_back(s);
    }
    cin >> Hb >> Wb;
    for (int i = 0; i < Hb; ++i) {
        string s;
        cin >> s;
        B.push_back(s);
    }
    cin >> Hx >> Wx;
    for (int i = 0; i < Hx; ++i) {
        string s;
        cin >> s;
        X.push_back(s);
    }

    A = resize(A);
    B = resize(B);
    X = resize(X);
    Ha = A.size();
    Wa = A[0].size();
    Hb = B.size();
    Wb = B[0].size();
    Hx = X.size();
    Wx = X[0].size();
    
    for (int i = 0; i < Hx - Ha + 1; ++i) {
        for (int j = 0; j < Wx - Wa + 1; ++j) {
            for (int k = 0; k < Hx - Hb + 1; ++k) {
                for (int l = 0; l < Wx - Wb + 1; ++l) {
                    vector<string> Y(Hx, string(Wx, '.'));
                    for (int x = 0; x < Ha; ++x) {
                        for (int y = 0; y < Wa; ++y) {
                            if (A[x][y] == '#') Y[i + x][j + y] = A[x][y];
                        }
                    }
                    for (int x = 0; x < Hb; ++x) {
                        for (int y = 0; y < Wb; ++y) {
                            if (B[x][y] == '#') Y[k + x][l + y] = B[x][y];
                        }
                    }

                    bool flag = true;
                    for (int x = 0; x < Hx; ++x) {
                        for (int y = 0; y < Wx; ++y) {
                            if (X[x][y] != Y[x][y]) flag = false;
                        }
                    }
                    if (flag) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}

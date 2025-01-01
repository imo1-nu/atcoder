#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<vector<int>> A(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    auto check = [&](set<int> s) {
        if (s.count(0) && s.count(1) && s.count(2)) return true;
        if (s.count(3) && s.count(4) && s.count(5)) return true;
        if (s.count(6) && s.count(7) && s.count(8)) return true;
        if (s.count(0) && s.count(3) && s.count(6)) return true;
        if (s.count(1) && s.count(4) && s.count(7)) return true;
        if (s.count(2) && s.count(5) && s.count(8)) return true;
        if (s.count(0) && s.count(4) && s.count(8)) return true;
        if (s.count(2) && s.count(4) && s.count(6)) return true;
        return false;
    };

    function<bool(set<int>, set<int>)> dfs = [&](set<int> s, set<int> t) -> bool {
        if (check(s)) return true;
        if (check(t)) return false;
        if (s.size() == 5) {
            ll sumA = 0, sumB = 0;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (s.count(i * 3 + j)) sumA += A[i][j];
                    else sumB += A[i][j];
                }
            }
            return sumA > sumB;
        }

        bool res;
        if (s.size() == t.size()) {
            res = false;
            for (int i = 0; i < 9; ++i) {
                if (!s.count(i) && !t.count(i)) {
                    set<int> s2 = s;
                    s2.insert(i);
                    res |= dfs(s2, t);
                }
            }
        }
        else {
            res = true;
            for (int i = 0; i < 9; ++i) {
                if (!s.count(i) && !t.count(i)) {
                    set<int> t2 = t;
                    t2.insert(i);
                    res &= dfs(s, t2);
                }
            }
        }
        return res;
    };

    set<int> s, t;
    if (dfs(s, t)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<pair<char, int>> encode(const string& str) {
    int N = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < N;) {
        int r = l + 1;
        for (; r < N && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

string decode(const vector<pair<char, int>>& code) {
    string ret;
    for (auto [c, cnt] : code) {
        ret += string(cnt, c);
    }
    return ret;
}

bool canmove(int x, vector<int> X) {
    set<int> st;
    st.insert(0);
    for (int i = 0; i < (int)X.size(); i++) {
        set<int> nxt;
        for (int j : st) {
            nxt.insert(j + X[i]);
            nxt.insert(j - X[i]);
        }
        st = nxt;
    }
    return st.count(x);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    vector<pair<char, int>> code = encode(s);
    vector<int> dx, dy;
    int cnt = 0;
    for (int i = 0; i < (int)code.size(); i++) {
        if (code[i].first == 'T') {
            cnt += code[i].second;
            continue;
        }

        if (cnt == 0) {
            x -= code[i].second;
        }
        else if (cnt % 2 == 0) {
            dx.push_back(code[i].second);
        }
        else if (cnt % 2 == 1) {
            dy.push_back(code[i].second);
        }
    }

    bool ans = canmove(x, dx) && canmove(y, dy);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    vector<pair<char, int>> code = encode(S);
    bool ans = false;
    if (code.size() == 3 && code[0].first == '1' && code[1].first == '/' && code[2].first == '2' && code[0].second == code[2].second && code[1].second == 1) {
        ans = true;
    }
    if (code.size() == 1 && code[0].first == '/') {
        ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

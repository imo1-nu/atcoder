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
    int ans = 1;
    for (int i = 0; i < (int)code.size(); i++) {
        if (code[i].first == '/' && code[i].second == 1) {
            int l = 0, r = 0;
            if (i > 0 && code[i - 1].first == '1') {
                l = code[i - 1].second;
            }
            if (i + 1 < (int)code.size() && code[i + 1].first == '2') {
                r = code[i + 1].second;
            }
            int len = 2 * min(l, r) + 1;
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
}

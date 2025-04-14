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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            if (i - 1 >= 0 && S[i - 1] == '?') S[i - 1] = '.';
            if (i + 1 < N && S[i + 1] == '?') S[i + 1] = '.';
        }
    }
    vector<pair<char, int>> code = encode(S);
    int cnto = 0;
    int cntq = 0;
    for (auto [c, cnt] : code) {
        if (c == 'o') cnto += cnt;
        else if (c == '?') cntq += (cnt + 1) / 2;
    }

    string T = S;
    if (K - cnto == 0) {
        for (auto& t : T) {
            if (t == '?') t = '.';
        }
    }
    if (cnto + cntq == K) {
        int i = 0;
        for (auto [c, cnt] : code) {
            if (c == '?' && cnt % 2 == 1) {
                for (int j = 0; j < cnt; j++) {
                    if (j % 2 == 0) T[i + j] = 'o';
                    else T[i + j] = '.';
                }
            }
            i += cnt;
        }
    }
    cout << T << endl;
}

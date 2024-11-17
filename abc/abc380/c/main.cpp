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
    
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S = '0' + S + '0';

    int cnt = 0;
    vector<pair<char, int>> code = encode(S);
    for (int i = 0; i < (int)code.size(); i++) {
        if (code[i].first == '1') {
            cnt++;
        }
        if (cnt == K) {
            swap(code[i], code[i - 1]);
            break;
        }
    }
    cout << decode(code).substr(1, N) << endl;
}

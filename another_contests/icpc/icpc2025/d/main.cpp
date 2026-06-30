#include <bits/stdc++.h>

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
    while (1) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        vector<string> C(N);
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        vector<vector<pair<char, int>>> RLE(N);
        for (int i = 0; i < N; i++) {
            RLE[i] = encode(C[i]);
        }

        int ans = 0;
        int flag = 0;
        int ans2 = -1;
        int ans3 = -1;

        for (int i = 1; i < N; i++) {
            bool onazi = true;
            bool gyaku = true;
            for (int j = 0; j < M; j++) {
                if (C[i][j] == C[0][j]) gyaku = false;
                else onazi = false;
            }
            if (onazi == false && gyaku == false) {
                ans3 = 1;
                break;
            }
        }

        for (int i = 0; i < N; i++) {
            if (RLE[i].size() >= 3) {
                if (flag != 0 && flag != 1) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
                flag = 1;
                ans2 = max({ans2, RLE[i][0].second, RLE[i].back().second});
                for (int j = 1; j < RLE[i].size() - 1; j++) {
                    if (ans == 0) ans = RLE[i][j].second;
                    else if (ans != RLE[i][j].second) {
                        ans = -1;
                        ans3 = 1;
                        break;
                    }
                }
            }

            if (RLE[i].size() <= 2) {
                if (RLE[i].size() == 2) ans2 = max({ans2, RLE[i][0].second, RLE[i][1].second});
                if (RLE[i].size() == 1) ans2 = max(ans2, M);
                if (flag != 0 && flag != 2) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
                flag = 2;
                if (i == 0) continue;
                bool onazi = true;
                bool gyaku = true;
                for (int j = 0; j < M; j++) {
                    if (C[i][j] == C[i - 1][j]) gyaku = false;
                    else onazi = false;
                }
                if (onazi == false && gyaku == false) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
            }
        }

        flag = 0;
        vector<string> D;
        for (int i = 0; i < M; i++) {
            string s = "";
            for (int j = 0; j < N; j++) {
                s += C[j][i];
            }
            D.push_back(s);
        }

        for (int i = 1; i < M; i++) {
            bool onazi = true;
            bool gyaku = true;
            for (int j = 0; j < N; j++) {
                if (D[i][j] == D[0][j]) gyaku = false;
                else onazi = false;
            }
            if (onazi == false && gyaku == false) {
                ans3 = 1;
                break;
            }
        }
        vector<vector<pair<char, int>>> R(M);
        for (int i = 0; i < M; i++) {
            R[i] = encode(D[i]);
        }
        for (int i = 0; i < M; i++) {
            if (R[i].size() >= 3) {
                if (flag != 0 && flag != 1) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
                flag = 1;
                ans2 = max({ans2, R[i][0].second, R[i].back().second});
                for (int j = 1; j < R[i].size() - 1; j++) {
                    if (ans == 0) ans = R[i][j].second;
                    else if (ans != R[i][j].second) {
                        ans = -1;
                        ans3 = 1;
                        break;
                    }
                }
            }

            if (R[i].size() <= 2) {
                if (R[i].size() == 2) ans2 = max({ans2, R[i][0].second, R[i][1].second});
                if (R[i].size() == 1) ans2 = max(ans2, N);
                if (flag != 0 && flag != 2) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
                flag = 2;
                if (i == 0) continue;
                bool onazi = true;
                bool gyaku = true;
                for (int j = 0; j < N; j++) {
                    if (D[i][j] == D[i - 1][j]) gyaku = false;
                    else onazi = false;
                }
                if (onazi == false && gyaku == false) {
                    ans = -1;
                    ans3 = 1;
                    break;
                }
            }
        }
        if (ans != 0 && ans < ans2) {
            ans = -1;
        }
        if (ans3 == 1) ans = -1;
        cout << ans << endl;
    }
}
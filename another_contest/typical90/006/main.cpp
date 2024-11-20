#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> calc_next(const string &S) { //next[i][c] : Sのi文字目以降で，文字cが出現する最小の添字（存在しない場合はN）
    int N = S.size();
    vector<vector<int>> res(N + 1, vector<int>(26, N));
    for (int i = N - 1; i >= 0; i--) {
        res[i] = res[i + 1];
        res[i][S[i] - 'a'] = i;
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    string S;
    cin >> N >> K >> S;

    auto next = calc_next(S);
    string ans;

    int j = -1;
    for (int i = 0; i < K; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            int k = next[j + 1][c - 'a'];

            if (N - k >= K - i) {
                ans += c;
                j = k;
                break;
            }
        }
    }
    
    cout << ans << endl;
}

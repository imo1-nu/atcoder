#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    int n = 16 - N + 1;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
        n -= S[i].length();
    }
    sort(S.begin(), S.end());
    set<string> T;
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        T.insert(s);
    }

    function<void(int, int, string)> dfs = [&](int cur, int remain, string ans) {
        if (remain < 0) return;

        if (cur == N) {
            if (ans.length() >= 3 && !T.count(ans)) {
                cout << ans << endl;
                exit(0);
            }
            return;
        }

        if (ans.length() > 0 && ans.back() != '_') {
            dfs(cur, remain, ans + '_');
        }
        else {
            dfs(cur + 1, remain, ans + S[cur]);
            if (ans.length() > 0) dfs(cur, remain - 1, ans + '_');
        }
    };

    do {
        dfs(0, n, "");
    } while (next_permutation(S.begin(), S.end()));
    cout << -1 << endl;
}

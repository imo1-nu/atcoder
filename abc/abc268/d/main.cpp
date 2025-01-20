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
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    set<string> T;
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        T.insert(t);
    }
    sort(S.begin(), S.end());


    function<void(string ans, int cur, int cnt)> dfs = [&](string ans, int cur, int cnt) {
        if (cur == N) {
            if (!T.count(ans) && 3 <= ans.length() && ans.length() <= 16) {
                cout << ans << endl;
                exit(0);
            }
            return;
        }

        if (cnt == 0) dfs(ans + S[cur], cur + 1, cnt + 1);
        else {
            for (int i = 1; ans.length() + i + S[cur].length() <= 16; i++) {
                string add(i, '_');
                dfs(ans + add + S[cur], cur + 1, cnt + 1);
            }
        }
    };

    do {
        dfs("", 0, 0);
    } while (next_permutation(S.begin(), S.end()));
    cout << -1 << endl;
}

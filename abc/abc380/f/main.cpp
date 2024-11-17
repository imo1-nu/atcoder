#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N, M, L;
int A[13], Pow3[13];
vector<vector<bool>> used;
vector<vector<bool>> dp;

int get(int x, int i) {
    return x / Pow3[i] % 3;
}

bool dfs(int turn, int state) {
    if (!used[turn][state]) {
        for (int i = 0; i < N + M + L; i++) {
            if (get(state, i) == turn) {
                int s2 = state - Pow3[i] * turn + Pow3[i] * 2;
                if (!dfs(turn ^ 1, s2)) {
                    dp[turn][state] = true;
                }
                for (int j = 0; j < N + M + L; j++) {
                    if (A[j] < A[i] && get(state, j) == 2) {
                        int s3 = s2 - Pow3[j] * 2 + Pow3[j] * turn;
                        if (!dfs(turn ^ 1, s3)) {
                            dp[turn][state] = true;
                        }
                    }
                }
            }
        }
        used[turn][state] = true;
    }
    return dp[turn][state];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> L;
    for (int i = 0; i < N + M + L; i++) {
        cin >> A[i];
    }

    int S = N + M + L;
    Pow3[0] = 1;
    for (int i = 1; i <= S; i++) {
        Pow3[i] = Pow3[i - 1] * 3;
    }

    used.assign(2, vector<bool>(Pow3[S], false));
    dp.assign(2, vector<bool>(Pow3[S], false));

    int state = 0;
    for (int i = N; i < N + M; i++) {
        state += Pow3[i];
    }
    for (int i = N + M; i < S; i++) {
        state += Pow3[i] * 2;
    }

    if (dfs(0, state)) {
        cout << "Takahashi" << endl;
    }
    else {
        cout << "Aoki" << endl;
    }

    return 0;
}
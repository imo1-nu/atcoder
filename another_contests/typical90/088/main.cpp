#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N, Q;
int A[10007], X[10007], Y[10007];

int c[10007];
vector<int> G[10007];
vector<int> vec;
vector<vector<int>> Answer[10007];
bool flag = false;

void dfs(int pos, int dep) {
    if (flag) return;
    if (pos == N + 1) {
        Answer[dep].push_back(vec);
        if (Answer[dep].size() == 2) flag = true;
        return;
    }

    dfs(pos + 1, dep);
    
    if (c[pos] == 0) {
        vec.push_back(pos);
        for (int i : G[pos]) {
            c[i]++;
        }
        dfs(pos + 1, dep + A[pos]);
        for (int i : G[pos]) {
            c[i]--;
        }
        vec.pop_back();
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= Q; i++) {
        cin >> X[i] >> Y[i];
        G[X[i]].push_back(Y[i]);
    }

    dfs(1, 0);

    for (int i = 0; i <= 10000; i++) {
        if (Answer[i].size() <= 1) continue;
        
        cout << Answer[i][0].size() << endl;
        for (int j : Answer[i][0]) {
            cout << j;
            if (j != Answer[i][0].back()) cout << " ";
        }
        cout << endl;

        cout << Answer[i][1].size() << endl;
        for (int j : Answer[i][1]) {
            cout << j;
            if (j != Answer[i][1].back()) cout << " ";
        }
        cout << endl;

        break;
    }
}

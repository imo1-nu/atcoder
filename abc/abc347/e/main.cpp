#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    set<int> S;
    vector<int> Add(Q);
    vector<vector<int>> change(N);
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        x--;
        if (S.count(x)) {
            change[x].push_back(i);
            S.erase(x);
        }
        else {
            change[x].push_back(i);
            S.insert(x);
        }
        Add[i] = S.size();
    }

    for (int i = 0; i < N; i++) {
        if (S.count(i)) {
            change[i].push_back(Q);
        }
    }

    vector<ll> B(Q + 1);
    for (int i = 1; i <= Q; i++) {
        B[i] = B[i - 1] + Add[i - 1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)change[i].size(); j += 2) {
            int idx1 = change[i][j];
            int idx2 = change[i][j + 1];
            A[i] += B[idx2] - B[idx1];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}

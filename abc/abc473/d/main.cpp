#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;

    int sum = 0;
    vector<int> v;
    vector<vector<int>> answers;
    function<void()> dfs = [&]() {
        if ((int)v.size() == N - 1) {
            v.push_back(K - sum);
            answers.push_back(v);
            v.pop_back();
            return;
        }
        for (int i = (K - sum) / (N - v.size()); i >= 0; i--) {
            int add = i * (N - v.size());
            if (sum + add > K) break;
            sum += add;
            v.push_back(i);
            dfs();
            sum -= add;
            v.pop_back();
        }
        return;
    };
    dfs();

    for (auto& ans : answers) reverse(ans.begin(), ans.end());
    sort(answers.begin(), answers.end());
    for (auto ans : answers) {
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
}

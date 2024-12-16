#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> score(5);
    string S = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        cin >> score[i];
    }

    vector<pair<int, string>> ans;
    for (int i = 1; i < (1 << 5); ++i) {
        int sum = 0;
        string s;
        for (int j = 0; j < 5; ++j) {
            if (i >> j & 1) {
                sum += score[j];
                s += S[j];
            }
        }
        ans.emplace_back(-sum, s);
    }
    sort(ans.begin(), ans.end());
    for (auto [sum, s] : ans) {
        cout << s << endl;
    }
}

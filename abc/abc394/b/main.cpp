#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), [](const string& a, const string& b) {
        return a.size() < b.size();
    });
    for (auto s : S) {
        cout << s;
    }
    cout << endl;
}

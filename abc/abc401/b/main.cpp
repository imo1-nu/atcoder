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
    string state = "logout";
    int ans = 0;
    for (auto s : S) {
        if (s == "login" || s == "logout") {
            state = s;
        }
        else if (s == "private" && state == "logout") {
            ans++;
        }
    }
    cout << ans << endl;
}

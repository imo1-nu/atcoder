#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        if (mp.find(S[i]) == mp.end()) {
            cout << i + 1 << endl;
            mp[S[i]] = 1;
        }
    }
    
}

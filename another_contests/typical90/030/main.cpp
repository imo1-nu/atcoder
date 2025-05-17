#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> cnt(N + 1);
    vector<int> ans(9);
    for (int i = 2; i <= N; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= N; j += i) {
                cnt[j]++;
            }
        }
        ans[cnt[i]]++;
        
    }
    int ANS = 0;
    for (int i = K; i <= 8; i++) {
        ANS += ans[i];
    }
    cout << ANS << endl;
}

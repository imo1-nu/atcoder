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
    vector<bool> is_prime(55556, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < 55556; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < 55556; j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> ans;
    for (int i = 2; i < 55556; i++) {
        if (is_prime[i] && i % 5 == 1) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

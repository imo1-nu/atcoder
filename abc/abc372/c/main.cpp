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
    string S;
    cin >> S;
    int ans = 0;
    vector<bool> ABC(N - 2);
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            ABC[i] = true;
            ABC[i + 1] = true;
            ABC[i + 2] = true;
            ans++;
        }
    }

    for (int i = 0; i < Q; i++) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        if (ABC[x]) {
            ans--;
            if (S[x] == 'A') {
                ABC[x] = false;
                ABC[x + 1] = false;
                ABC[x + 2] = false;
            }
            if (S[x] == 'B') {
                ABC[x - 1] = false;
                ABC[x] = false;
                ABC[x + 1] = false;
            }
            if (S[x] == 'C') {
                ABC[x - 2] = false;
                ABC[x - 1] = false;
                ABC[x] = false;
            }
        }

        S[x] = c;
        if (x < N - 2) {
            if (S[x] == 'A' && S[x + 1] == 'B' && S[x + 2] == 'C') {
                ABC[x] = true;
                ABC[x + 1] = true;
                ABC[x + 2] = true;
                ans++;
            }
        }
        if (x > 0 && x < N - 1) {
            if (S[x - 1] == 'A' && S[x] == 'B' && S[x + 1] == 'C') {
                ABC[x - 1] = true;
                ABC[x] = true;
                ABC[x + 1] = true;
                ans++;
            }
        }
        if (x > 1) {
            if (S[x - 2] == 'A' && S[x - 1] == 'B' && S[x] == 'C') {
                ABC[x - 2] = true;
                ABC[x - 1] = true;
                ABC[x] = true;
                ans++;
            }
        }
        cout << ans << endl;
    }
}

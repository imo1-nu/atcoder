#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<ll> A;

    for (int i = 0; i < (1 << N); i++) {
        bitset<20> bs(i);
        int cnt = 0;
        int j;
        for (j = N - 1; j >= 0; j--) {
            if (bs.test(j)) cnt++;
            else cnt--;
            if (cnt > 0) break;
        }
        if (j < 0 && cnt == 0) {
            for (j = N - 1; j >= 0; j--) {
                if (bs.test(j)) cout << ")";
                else cout << "(";
            }
            cout << endl;
        }
    }
}

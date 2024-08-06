#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q);
    vector<int> ex(N, true);
    int ans = N;
    for (int i = 0; i < Q; i++) {
        cin >> T[i];
        if (ex[T[i]-1] == true) {
            ex[T[i]-1] = false;
            ans--;
        }
        else {
            ex[T[i]-1] = true;
            ans++;
        }


    }

    cout << ans << endl;
}

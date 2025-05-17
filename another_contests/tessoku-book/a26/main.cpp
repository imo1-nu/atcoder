#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }
    
    vector<bool> h(3e5 + 1, true);
    int i = 2;
    int max = 3e5;
    while (i <= max) {
        if (h[i] == false) {
            i++;
            continue;
        }
        int j = 2;
        while (i * j <= max) {
            h[i * j] = false;
            j++;
        }
        i++;
    }

    for (int i = 0; i < q; i++) {
        if (h[x[i]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}

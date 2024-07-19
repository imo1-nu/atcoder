#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    bool ans = false;
    for (int i = 0; i < n; i++) {
        int c = k - p[i];
        if(binary_search(q.begin(), q.end(), k - p[i])) {
            ans = true;
            break;
        }
    }
    
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}

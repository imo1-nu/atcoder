#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    vector<ll> A = {0};
    int top = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l;
            cin >> l;
            A.push_back(A.back() + l);
        }
        else if (t == 2) {
            top++;
        }
        else if (t == 3) {
            int k;
            cin >> k;
            cout << A[top + k - 1] - A[top] << endl;
        }
    }
}

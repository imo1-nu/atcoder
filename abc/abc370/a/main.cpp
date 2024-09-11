#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int L, R;
    cin >> L >> R;
    if (L == 1 && R == 0) {
        cout << "Yes" << endl;
    }
    else if (L == 0 && R == 1) {
        cout << "No" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
}

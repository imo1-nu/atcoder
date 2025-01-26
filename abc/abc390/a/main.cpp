#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> A(5), B;
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    B = A;
    sort(B.begin(), B.end());

    for (int i = 0; i < 4; i++) {
        vector<int> C = A;
        swap(C[i], C[i + 1]);
        if (C == B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}

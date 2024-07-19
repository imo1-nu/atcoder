#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<int> A(100);
    int i = 0;
    for (i = 0; 1; i++) {
        cin >> A[i];
        if (A[i] == 0) break;
    }
    for (int j = i; j > -1; j--) cout << A[j] << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<int> A = {0, 1, 1, 1};
    int a, b;
    cin >> a >> b; 
    A[a] = 0;
    A[b] = 0;
    if (a == b) cout << -1 << endl;
    else {
        int i;
        for (i = 0; A[i] == 0; i++) {}
        cout << i << endl;
    }
}

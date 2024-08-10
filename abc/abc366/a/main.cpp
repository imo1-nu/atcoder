#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, T, A;
    cin >> N >> T >> A;
    bool ans = false;
    if (T > N / 2 || A > N / 2) {
        ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
}

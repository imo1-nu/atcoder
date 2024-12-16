#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    char c1, c2;
    cin >> N >> c1 >> c2;
    string S;
    cin >> S;

    for (int i = 0; i < N; ++i) {
        if (S[i] != c1) S[i] = c2;
    }
    cout << S << endl;
}

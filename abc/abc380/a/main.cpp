#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    if (N == "122333") {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

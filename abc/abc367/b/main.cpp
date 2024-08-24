#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string X;
    cin >> X;
    while (X[X.length()-1] == '0'){
        X.pop_back();
    }
    if (X[X.length()-1] == '.') X.pop_back();
    cout << X << endl;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int R, G, B;
    cin >> R >> G >> B;
    string C;
    cin >> C;
    if (C == "Red") cout << min(G, B) << '\n';
    else if (C == "Green") cout << min(R, B) << '\n';
    else cout << min(R, G) << '\n';
}

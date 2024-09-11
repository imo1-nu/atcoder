#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;

    map<int, int> mp;
    mp[A + 2 * (B - A)]++;
    if ((A - B + 100) % 2 == 0) mp[(A + B) / 2]++;
    mp[2 * A - B]++;
    cout << mp.size() << endl;
}

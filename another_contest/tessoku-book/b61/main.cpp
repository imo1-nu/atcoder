#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> fr(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        fr[a].push_back(b);
        fr[b].push_back(a);
    }
    
    int Max = 0, MaxNum = 0;
    for (int i = 1; i <= n; i++) {
        int size = fr[i].size();
        if (Max < size) {
            Max = size;
            MaxNum = i;
        }
    }
    cout << MaxNum << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;

    for (int i = 0; i < N; i++) {
        int max = 0, mnum = i;
        for (int j = 0; j < N; j++) {
            int a = pow(p[j].first - p[i].first, 2) + pow(p[j].second - p[i].second, 2);
            if (a > max) {
                max = a;
                mnum = j + 1;
            }
        }
        cout << mnum << endl;
    }
}

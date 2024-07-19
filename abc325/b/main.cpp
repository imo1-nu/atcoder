#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> W(N), X(N);
    for (int i = 0; i < N; i++) cin >> W[i] >> X[i];
    vector<int> num(24, 0);
    for (int i = 0; i < N; i++) num[X[i]] += W[i];
    vector<int> ans(24, 0);
    int max = 0;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 9; j++) {
            ans[i] += num[(i + j) % 24];
        }
        if (ans[i] > max) max = ans[i];
    }
    cout << max << endl;
}

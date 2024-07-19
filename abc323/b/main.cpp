#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, cnt;
    cin >> N;
    vector<string> S(N);
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; i++) cin >> S.at(i);
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) if (S[i][j] == 'o') cnt++;
        p.at(i) = make_pair(-cnt, i);
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < N; i++) {
        cout << p.at(i).second + 1;
        if (i == N - 1) cout << endl;
        else cout << ' ';
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, i = 1, j;
    cin >> N >> M;
    vector<int> A(M);
    for (j = 0; j < M; j++) cin >> A.at(j);
    for (j = 0; j < M; j++, i++) {
        for (1; i <= N; i++) {
            cout << A.at(j) - i << endl;
            if (A.at(j) - i == 0) break;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int check(string T, string S) {
    for (int i = 0; i < T.length() && i < S.length(); i++) {
        if (T[i] != S[i]) {
            if (T.substr(i + 1, T.length() - i - 1) == S.substr(i, S.length() - i)) return 1;
            else if (T.substr(i, T.length() - i) == S.substr(i + 1, S.length() - i - 1)) return 1;
            else if (T.substr(i + 1, T.length() - i - 1) == S.substr(i + 1, S.length() - i - 1)) return 1;
            else return 0;
        }
    }
    return 1;
}

int main()
{
    int N;
    string T1;
    cin >> N >> T1;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<int> A;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (check(T1, S[i])) {
            A.push_back(i + 1);
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << A[i];
        if (i != cnt - 1) cout << ' ';
    }
    cout << endl;
}

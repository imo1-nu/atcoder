#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> A(26, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - i; j++) {
            if (S[i] != S[i + j]) {
                if (j > A[S[i] - 'a']) A[S[i] - 'a'] = j;
                i = i + j - 1;
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 26; i++) cnt += A[i];

    cout << cnt << endl;
}

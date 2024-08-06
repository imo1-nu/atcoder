#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    long long A[N];
    for (int i = 0; i < N; i++) A[i] = S[i] - '0';
    
    int cnt = 0;
    do {
        long long a = 0;
        for (int i = 0; i < N - 1; i++) {
            a += A[i];
            a *= 10;
        }
        a += A[N - 1];

        long long l = 1, r = 10000000, m;
        while (l + 1 != r) {
            m = (l + r) / 2;
            if (m * m > a) r = m;
            else l = m;
        }
        if (a == l * l) cnt++;
    } while (next_permutation(A, A + N));

    cout << cnt << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long ten[19];
    long long a = 1;
    for (long long i = 0; i <= 18; i++) {
        ten[i] = a;
        a *= 10;
    }

    long long N, max = 1;
    cin >> N;
    priority_queue<long long> pq;
    for (long long i = 1; i * i * i <= N; i++) {
        long long L, j;
        a = i * i * i;
        for (L = 1; a >= ten[L]; L++);
        for (j = 0; j < L / 2; j++) {
            //cout << (a / ten[L - 1 - j]) % ten[1] << ' ' << (a / ten[j]) % ten[1] << endl;
            if ((a / ten[j]) % ten[1] != (a / ten[L - 1 - j]) % ten[1]) break;
        }
        if (j == L / 2) max = a;
    }
    cout << max << endl;
}

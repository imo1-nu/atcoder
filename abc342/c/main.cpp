#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<queue<char>> C(26); //C[i]はi番目のアルファベットになるグループ
    for (int i = 0; i < 26; i++) C[i].push('a' + i);

    for (int i = 0; i < Q; i++) {
        char c, d;
        cin >> c >> d;
        if (c == d) continue;
        while (!C[int(c - 'a')].empty()) {
            C[int(d - 'a')].push(C[int(c - 'a')].front());
            C[int(c - 'a')].pop();
        }
    }

    vector<char> A(26);
    for (int i = 0; i < 26; i++) {
        while (!C[i].empty()) {
            A[int(C[i].front() - 'a')] = 'a' + i;
            C[i].pop();
        }
    }

    for (int i = 0; i < S.length(); i++) {
        S[i] = A[S[i] - 'a'];
    }
    cout << S << endl;
}

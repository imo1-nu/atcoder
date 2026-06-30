#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        string S, T;
        cin >> S >> T;
        int acnt = 0, bcnt = 0;
        int acnt1 = 0, bcnt1 = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'a') acnt++;
            else bcnt++;
            if (T[i] == 'a') acnt1++;
            else bcnt1++;
        }

        if (acnt != acnt1) {
            cout << "no" << endl;
            continue;
        }

        int type = 0;
        string ans = "";
        for (int i = N - 1; i >= 0; i--) {
            if (S[i] == T[i]) continue;
            if (type == 0) {
                int idx = 0;
                if (T[i] == 'a') {
                    for (int j = 0; j < N; j++) {
                        if (S[j] == 'a') {
                            idx = j;
                            break;
                        }
                    }
                    int cnt = 0;
                    for (int j = idx; j <= i; j++) {
                        if (S[j] == 'b') cnt++;
                        for (int j = 0; j <= cnt; j++) {
                            ans += "A";
                        }
                    }
                    type = 2;
                    acnt--;
                }
                else {
                    for (int j = 0; j < N; j++) {
                        if (S[j] == 'b') {
                            idx = j;
                            break;
                        }
                    }
                    int cnt = 0;
                    for (int j = idx; j <= i; j++) {
                        if (S[j] == 'a') cnt++;
                        for (int j = 0; j <= cnt; j++) {
                            ans += "B";
                        }
                    }
                    type = 1;
                    bcnt--;
                }
            }
            
            if (T[i] == 'a') {
                if (type == 1) {
                    for (int j = 0; j <= acnt; j++) {
                        ans += "B";
                    }
                }
                acnt--;
                type = 2;
            }

            if (T[i] == 'b') {
                if (type == 2) {
                    for (int j = 0; j <= bcnt; j++) {
                        ans += "A";
                    }
                }
                bcnt--;
                type = 1;
            }
        }
        cout << "yes" << endl << ans << endl;
    }
}
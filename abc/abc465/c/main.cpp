#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    string S;
    cin >> N >> S;

    deque<int> dq;
    bool rev = false;
    for (int i = 0; i < N; i++) {
        if (rev) dq.push_front(i + 1);
        else dq.push_back(i + 1);
        if (S[i] == 'o') rev ^= true;
    }

    while (!dq.empty()) {
        if (rev) {
            cout << dq.back() << ' ';
            dq.pop_back();
        }
        else {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
    }
    cout << endl;
}

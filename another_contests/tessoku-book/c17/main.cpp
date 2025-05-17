#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;
    vector<char> a(Q);
    vector<string> X(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i];
        if (a[i] == 'A' || a[i] == 'B') cin >> X[i];
    }    
    
    deque<string> deq1, deq2;
    for (int i = 0; i < Q; i++) {
        if (a[i] == 'A') deq2.push_back(X[i]);
        if (a[i] == 'B') deq1.push_back(X[i]);
        if (a[i] == 'C') deq1.pop_front();
        if (a[i] == 'D') cout << deq1.front() << endl;

        if ((int)deq1.size() - (int)deq2.size() < 0) {
            deq1.push_back(deq2.front());
            deq2.pop_front();
        }
        if ((int)deq1.size() - (int)deq2.size() > 1) {
            deq2.push_front(deq1.back());
            deq1.pop_back();
        }
    }
}

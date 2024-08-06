#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> c(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> c[i][0] >> c[i][1];
        c[i][2] = i + 1;
    }

    sort(c.rbegin(), c.rend());

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(c[0][2]);
    int min = c[0][1];
    for (int i = 1; i < N; i++) {
        if (min > c[i][1]) {
            q.push(c[i][2]);
            min = c[i][1];
        }
    }

    cout << q.size() << endl;

    while(q.size() > 1) {
        cout << q.top() << ' ';
        q.pop();
    }
    
    cout << q.top() << endl;
    
    
}

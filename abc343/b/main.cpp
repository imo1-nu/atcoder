#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        queue<int> q;
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a == 1) q.push(j + 1);
        }
        while (!q.empty()) {
            cout << q.front();
            q.pop();
            if (!q.empty()) cout << ' ';
        }
        cout << endl;
    }
}

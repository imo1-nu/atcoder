#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> G(100000);

void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex) {
    if (dist > maxDist) {
        maxDist = dist;
        maxVertex = current;
    }
    for (auto to : G[current]) {
        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}

int getTreeDiameter() {
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end;
    end = 0;
    maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    return maxDist;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    int ans = getTreeDiameter() + 1;
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void bfs(map<string, int> &d, string s) { //G, distを用意する
    //初期条件
    d[s] = 0;
    queue<string> q;
    q.push(s);

    while (!q.empty()) {
        string v = q.front();
        q.pop();
        int p;
        for (int i = 0; i <= n; i++) {
            if (v[i] == '.' && v[i + 1] == '.') {
                p = i;
            }
        }
        
        for (int i = 0; i <= n; i++) {
            if (v[i] == '.' || v[i + 1] == '.') continue;
            string nv = v;
            nv[p] = v[i];
            nv[p + 1] = v[i + 1];
            nv[i] = '.';
            nv[i + 1] = '.';
            if (d.count(nv) == 0) {
                d[nv] = d[v] + 1;
                q.push(nv);
            }
        }
    }
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s, t;
    cin >> n >> s >> t;
    s += "..";
    t += "..";
    map<string, int> d;
    bfs(d, s);
    if (d.count(t) == 1) cout << d[t] << endl;
    else cout << -1 << endl;
}

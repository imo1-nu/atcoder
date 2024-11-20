#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> par;
    vector<int> size;
    
    UnionFind(int N) : par(N), size(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (size[rx] < size[ry]) {
            par[rx] = ry;
            size[ry] += size[rx];
        }
        else {
            par[ry] = rx;
            size[rx] += size[ry];
        }
    }
    
    bool same(int x, int y) {
        if (root(x) == root(y)) return true;
        return false;
    }
};

vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
vector<int> dy = {-1, 1, 0, 0, -1, 1, 1, -1};
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> H >> W >> Q;
    vector<vector<int>> q(Q, vector<int>(5));
    for (int i = 0; i < Q; i++) {
        cin >> q[i][0];
        if (q[i][0] == 1) cin >> q[i][1] >> q[i][2];
        else cin >> q[i][1] >> q[i][2] >> q[i][3] >> q[i][4];
    }

    UnionFind uf(H * W);
    vector<vector<bool>> red(H, vector<bool>(W, false));
    for (int i = 0; i < Q; i++) {
        if (q[i][0] == 1) {
            int r = q[i][1] - 1, c = q[i][2] - 1;
            red[r][c] = true;
            for (int j = 0; j < 4; j++) {
                int nr = r + dx[j], nc = c + dy[j];
                if (canmove(nr, nc) && red[nr][nc]) uf.unite(r * W + c, nr * W + nc);
            }
        }
        else {
            int ra = q[i][1] - 1, ca = q[i][2] - 1;
            int rb = q[i][3] - 1, cb = q[i][4] - 1;
            if (red[ra][ca] && red[rb][cb] && uf.same(ra * W + ca, rb * W + cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N = 50;
int K = 400;
int L = 20;
int A[401], B[401];
int C[51][51], D[51][51];
int ans[401];
vector<int> G[401];

struct UnionFind {
    vector<int> par;
    vector<int> size;
    
    UnionFind(int N) : par(N), size(N) {
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }
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

bool visited[401];
void dfs(int pos) {
    visited[pos] = true;
    for (int next : G[pos]) {
        if (ans[next] == ans[pos] && !visited[next]) {
            dfs(next);
        }
    }
}

double get_score() {
    for (int i = 1; i <= K; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= L; i++) {
        int pos = -1;
        for (int j = 1; j <= K; j++) {
            if (ans[j] == i) pos = j;
        }
        if (pos == -1) return 0.0;
        dfs(pos);
    }
    for (int i = 1; i <= K; i++) {
        if (!visited[i]) return 0.0;
    }
    
    int p[21], q[21];
    for (int i = 1; i <= L; i++) {
        p[i] = 0;
        q[i] = 0;
    }
    for (int i = 1; i <= K; i++) {
        p[ans[i]] += A[i];
        q[ans[i]] += B[i];
    }
    int pmax = *max_element(p + 1, p + L + 1);
    int pmin = *min_element(p + 1, p + L + 1);
    int qmax = *max_element(q + 1, q + L + 1);
    int qmin = *min_element(q + 1, q + L + 1);
    return min(double(pmin) / pmax, double(qmin) / qmax);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> K >> L;
    for (int i = 1; i <= K; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> C[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != N && C[i][j] != 0 && C[i + 1][j] != 0 && C[i][j] != C[i + 1][j]) {
                G[C[i][j]].push_back(C[i + 1][j]);
                G[C[i + 1][j]].push_back(C[i][j]);
            }
            if (j != N && C[i][j] != 0 && C[i][j + 1] != 0 && C[i][j] != C[i][j + 1]) {
                G[C[i][j]].push_back(C[i][j + 1]);
                G[C[i][j + 1]].push_back(C[i][j]);
            }
        }
    }
    
    for (int i = 1; i <= K; i++) {
        sort(G[i].begin(), G[i].end());
        G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    }
    
    for (int i = 1; i <= K; i++) {
        visited[i] = false;
    }

    UnionFind uf(K + 1);
    for (int i = 1; i <= K - L; i++) {
        int min_size = 1e9;
        int vertex1 = -1;
        int vertex2 = -1;
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k < (int)G[j].size(); k++) {
                int v = G[j][k];
                if (uf.same(j, v)) continue;

                int size1 = uf.size[uf.root(j)];
                int size2 = uf.size[uf.root(v)];
                if (min_size > size1 + size2) {
                    min_size = size1 + size2;
                    vertex1 = j;
                    vertex2 = v;
                }
            }
        }
        uf.unite(vertex1, vertex2);
    }
    
    vector<int> roots;
    for (int i = 1; i <= K; i++) {
        roots.push_back(uf.root(i));
    }

    sort(roots.begin(), roots.end());
    roots.erase(unique(roots.begin(), roots.end()), roots.end());
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < (int)roots.size(); j++) {
            if (uf.root(i) == roots[j]) {
                ans[i] = j + 1;
            }
        }
    }
    
    double TIME_LIMIT = 0.95;
    int ti = clock();
    double current_score = get_score();
    while (double(clock() - ti) / CLOCKS_PER_SEC < TIME_LIMIT) {
        int v = 0;
        int x = 0;
        do {
            v = 1 + rand() % K;
            x = ans[G[v][rand() % (int)G[v].size()]];
        } while (ans[v] == ans[x]);

        int old_x = ans[v];

        ans[v] = x;
        double new_score = get_score();

        double rand_value = double(rand() + 0.5) / (RAND_MAX + 1.0);
        double temp = 0.0040 - 0.0039 * (double(clock() - ti) / CLOCKS_PER_SEC / TIME_LIMIT);
        if (new_score != 0.0 && rand_value < exp((new_score - current_score) / temp)) {
            current_score = new_score;
        }
        else {
            ans[v] = old_x;
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << ans[i] << endl;
    }
}

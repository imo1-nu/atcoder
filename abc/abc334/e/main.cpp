#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

using mint = atcoder::modint998244353;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int H, W;

bool canmove(int x, int y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    atcoder::dsu d(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (!canmove(ni, nj)) continue;
                if (S[ni][nj] == '.') continue;
                d.merge(i * W + j, ni * W + nj);
            }
        }
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));
    mint gnum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') continue;
            int id = d.leader(i * W + j);
            if (used[id / W][id % W]) continue;
            used[id / W][id % W] = true;
            gnum += mint(1);
        }
    }

    mint ans = 0;
    mint cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            set<int> st;
            cnt += mint(1);
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (!canmove(ni, nj)) continue;
                if (S[ni][nj] == '.') continue;
                int id = d.leader(ni * W + nj);
                st.insert(id);
            }
            mint tmp = gnum + 1 - (int)st.size();
            ans += tmp;
        }
    }

    ans /= cnt;
    cout << ans.val() << endl;
}

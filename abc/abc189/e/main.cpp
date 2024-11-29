#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<vector<int>> mat_mal(vector<vector<int>> &A, vector<vector<int>> &B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            for (int j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<int> mat_vec_mal(vector<vector<int>> &A, vector<int> &B) {
    int N = A.size();
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i] += A[i][j] * B[j];
        }
    }
    return C;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }
    int M;
    cin >> M;
    vector<int> op(M), p(M);
    for (int i = 0; i < M; i++) {
        cin >> op[i];
        if (op[i] == 3 || op[i] == 4) {
            cin >> p[i];
        }
    }

    vector<vector<int>> rot1 = {{0, -1}, {1, 0}};
    vector<vector<int>> rot2 = {{0, 1}, {-1, 0}};
    vector<vector<int>> move3 = {{-1, 0}, {0, 1}};
    vector<vector<int>> move4 = {{1, 0}, {0, -1}};
    vector<vector<vector<int>>> mat(M + 1, vector<vector<int>>(2, vector<int>(2)));
    vector<vector<int>> plus(M + 1, vector<int>(2));
    mat[0] = {{1, 0}, {0, 1}};
    plus[0] = {0, 0};
    for (int i = 0; i < M; i++) {
        if (op[i] == 1) {
            mat[i + 1] = mat_mal(rot1, mat[i]);
            plus[i + 1] = mat_vec_mal(rot1, plus[i]);
        }
        else if (op[i] == 2) {
            mat[i + 1] = mat_mal(rot2, mat[i]);
            plus[i + 1] = mat_vec_mal(rot2, plus[i]);
        }
        else if (op[i] == 3) {
            mat[i + 1] = mat_mal(move3, mat[i]);
            plus[i + 1] = mat_vec_mal(move3, plus[i]);
            plus[i + 1][0] -= 2 * p[i];
        }
        else {
            mat[i + 1] = mat_mal(move4, mat[i]);
            plus[i + 1] = mat_vec_mal(move4, plus[i]);
            plus[i + 1][1] -= 2 * p[i];
        }
    }

    int Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        B--;
        vector<int> ans = mat_vec_mal(mat[A], {X[B], Y[B]});
        ans[0] += plus[A][0];
        ans[1] += plus[A][1];
        cout << ans[0] << " " << ans[1] << endl;
    }
}

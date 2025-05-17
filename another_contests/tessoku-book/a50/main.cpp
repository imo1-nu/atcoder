#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N = 100;
int Q = 1000;
int A[100][100], B[100][100];
int X[1000], Y[1000], H[1000];

int RandInt(int L, int R) {
    return L + rand() % (R - L + 1);
}

int Randouble() {
    return (double)rand() / RAND_MAX;
}

int GetScore() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ret += abs(A[i][j] - B[i][j]);
        }
    }
    return 200000000 - ret;
}

void Change(int t, int x, int y, int h) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[j][i] -= max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
        }
    }
    
    X[t] = x;
    Y[t] = y;
    H[t] = h;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[j][i] += max(0, H[t] - abs(X[t] - i) - abs(Y[t] - j));
        }
    }
}

int Hrange(int Score) {
    if (Score < 199500000) return 14;
    if (Score < 199900000) return 7;
    return 1;
}

void Yakinamashi() {
    int TIMELIMIT = 5.95 * CLOCKS_PER_SEC;
    int CurrentScore = GetScore();
    int ti = clock();

    while (clock() - ti < TIMELIMIT) {
        int t = RandInt(0, Q - 1);
        int x = X[t], nx = x + RandInt(-9, 9);
        int y = Y[t], ny = y + RandInt(-9, 9);
        int dH = Hrange(CurrentScore);
        int h = H[t], nh = h + RandInt(-dH, dH);
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || nh < 1 || nh > N) {
            continue;
        }

        Change(t, nx, ny, nh);
        int NewScore = GetScore();

        double TEMP = 180.0 - 179.0 * (clock() - ti) / TIMELIMIT;
        double PROB = exp(min(0.0, 1.0 * (NewScore - CurrentScore) / TEMP));

        if (Randouble() < PROB) {
            CurrentScore = NewScore;
        } else {
            Change(t, x, y, h);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < Q; i++) {
        X[i] = rand() % N;
        Y[i] = rand() % N;
        H[i] = 1;
        B[Y[i]][X[i]]++;
    }

    Yakinamashi();

    cout << Q << endl;
    for (int i = 0; i < Q; i++) {
        cout << X[i] << " " << Y[i] << " " << H[i] << endl;
    }
}

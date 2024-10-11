#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define WIDTH 10000

struct State {
    int score;
    int X[20];
    char LastMove;
    int LastPos;
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    vector<int> P(T), Q(T), R(T);
    for (int i = 0; i < T; ++i) {
        cin >> P[i] >> Q[i] >> R[i];
        P[i]--; Q[i]--; R[i]--;
    }

    vector<vector<State>> Beam(T + 1);
    State s;
    s.score = 20;
    for (int i = 0; i < 20; i++) {
        s.X[i] = 0;
    }
    Beam[0].push_back(s);

    for (int i = 0; i < T; i++) {
        vector<State> Candidate;
        for (int j = 0; j < Beam[i].size(); j++) {
            State SousaA = Beam[i][j];
            SousaA.LastMove = 'A';
            SousaA.LastPos = j;
            SousaA.X[P[i]]++;
            SousaA.X[Q[i]]++;
            SousaA.X[R[i]]++;
            for (int k = 0; k < 20; k++) {
                if (SousaA.X[k] == 0) {
                    SousaA.score++;
                }
            }
            
            State SousaB = Beam[i][j];
            SousaB.LastMove = 'B';
            SousaB.LastPos = j;
            SousaB.X[P[i]]++;
            SousaB.X[Q[i]]++;
            SousaB.X[R[i]]++;
            for (int k = 0; k < 20; k++) {
                if (SousaB.X[k] == 0) {
                    SousaB.score++;
                }
            }

            Candidate.push_back(SousaA);
            Candidate.push_back(SousaB);
        }

        sort(Candidate.begin(), Candidate.end(), [](const State &a, const State &b) {
            return a.score > b.score;
        });
        
        int Num = min(WIDTH, (int)Candidate.size());
        for (int j = 0; j < Num; j++) {
            Beam[i + 1].push_back(Candidate[j]);
        }
    }
    
    int CurrentPos = 0;
    vector<char> Ans(T + 1); 
    for (int i = T; i >= 1; i++) {
        Ans[i] = Beam[i][CurrentPos].LastMove;
        CurrentPos = Beam[i][CurrentPos].LastPos;
    }
    
    for (int i = 1; i <= T; i++) {
        cout << Ans[i] << endl;
    }
}

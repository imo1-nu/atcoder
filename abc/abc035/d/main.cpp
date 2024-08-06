#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 200000

struct Edge {
    int to; //行き先
    int cost; //辺の長さ
};
using Graph = vector<vector<Edge>>;
using P = pair<vector<int>::iterator, int>;

struct myHeap { //Aを管理するためのヒープ
    vector<P> heap; //d[v]のアドレスとvのペアを管理
    int size = 0; //ヒープの要素数
    vector<int> possion; //ヒープ内部でのvの添字を管理
    myHeap(int N) : heap(N), possion(N, -1) {} 

    P top() { //先頭要素取り出し
        return heap[0];
    }

    bool empty() { //ヒープが空かどうかの確認
        if (size == 0) return true;
        return false;
    }

    bool greater(int i, int j) { //ヒープの要素の大小関係の定義
        if (max(i, j) >= size || max(i, j) == 0) return false;
        if (*heap[i].first > *heap[j].first || *heap[i].first == *heap[j].first && heap[i].second > heap[j].second) return true;
        else return false;
    }

    void remake(int i) { //heap[i]に変化があったときヒープを再構成
        int j = (i - 1) / 2; //iの親
        if (greater(j, i)) { //heap[j] > heap[i]の場合
            swap(heap[i], heap[j]);
            possion[heap[i].second] = i;
            possion[heap[j].second] = j;
            remake(j); //さらに上と比較
        }

        int k = 2 * i + 1; //iの左の子 
        if (k < size) {
            if (greater(k, k + 1)) k++; //左の子と右の子の小さい方がk
            if (greater(i, k)) { //heap[i] > heap[k]の場合
                swap(heap[i], heap[k]);
                possion[heap[i].second] = i;
                possion[heap[k].second] = k;
                remake(k); //さらに下と比較
            }
        }
    }

    void push(P p) { //ヒープに要素を追加し再構成
        heap[size] = p;
        possion[heap[size].second] = size;
        remake(++size - 1);
    }

    void pop() { //ヒープの先頭要素を取り出し再構成
        heap[0] = heap[--size];
        if (size > 0) {
            possion[heap[0].second] = 0;
            remake(0);
        }
    }
};

void shortest_pass_2(Graph T, vector<int>::iterator d, int s) {
    myHeap A(MAXN);
    vector<bool> B(MAXN, false); //iが発見済みの頂点であればB[i] == true
    d[s] = 0;
    A.push(make_pair(d + s, s));
    B[s] = true;

    while (!A.empty()) {
        P p = A.top(); //Aの中の頂点のうちd[v]が最小になるものを取り出す
        A.pop();
        int v = p.second;

        for (auto &e : T[v]) { //T[v]に属する頂点e.toに対して操作を行う
            if (B[e.to]) { //e.toが発見済みの場合
                if (d[e.to] > d[v] + e.cost) { //すでに見つかっている経路より今回見つかった経路の方が短いとき
                    d[e.to] = d[v] + e.cost;
                    A.remake(A.possion[e.to]);
                }
            }
            else { //e.toが未発見であるとき
                d[e.to] = d[v] + e.cost;
                A.push(make_pair(d + e.to, e.to));
                B[e.to] = true;
            }
        }
    }
}

int main() {
    string line, s;
    Graph T(MAXN); //G[v]にvから出ていく辺の情報を格納
    vector<int> d(MAXN, -1); //開始点からの最短距離を格納．-1は到達できないことを示す
    set<int> V; //頂点集合．Ο(mlogn)で計算できる（頂点の数:n，辺の数:m）

    while (!cin.eof()) {
        getline(cin, line); //入力文字列を取得しlineに格納
        stringstream line2(line); //stringstream型にする

        int from, to, cost;
        for (int i = 0; getline(line2, s, ',') && i < 3; i++) { // stringstream型の入力文字列を','で分割しsに格納
            if ( i == 0 ) {
                from = stoi(s); //出発点,到達点,長さの形式で辺が与えられる
                V.insert(from);
            }
            else if ( i == 1 ) {
                to = stoi(s);
                V.insert(to);
            }
            else cost = stoi(s);
        }

        Edge e;
        e.to = to;
        e.cost = cost;
        T[from].push_back(e); //グラフの情報を格納
    }

    int start = 0; //開始点を0に設定
    shortest_pass_2(T, d.begin(), start); //0からすべての頂点までの最短距離を計算

    for (auto i : V) { //すべての頂点への最短距離を出力．到達不可能であればd[i]は-1
        cout << "d[" << i << "] : " << d[i] << endl;
    }
}
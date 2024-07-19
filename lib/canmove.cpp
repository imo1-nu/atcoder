#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dx = {0, 0, -1, 1};
vector<ll> dy = {-1, 1, 0, 0};
ll H, W;

bool canmove(ll x, ll y) {
    if (0 <= x && x < H && 0 <= y && y < W) return true;
    else return false;
}

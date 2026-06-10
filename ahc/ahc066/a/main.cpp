#include <bits/stdc++.h>
using namespace std;

int N, M, T_limit;
vector<string> v_wall, h_wall;
vector<int> ball_r, ball_c, basket_r, basket_c;

vector<vector<int>> dir_cost, dir_end;
vector<vector<string>> nav_path;

const vector<string> CAND_PATS = {"FFF","FFFF","FFFFF","RFFF","RFFFF","LFFF","LFFFF"};
const int NPATS = 7;
vector<vector<vector<uint8_t>>> nav_cnt;
int bp = 0, bpL = 3;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int RandInt(int l, int r) { return rand() % (r - l + 1) + l; }
double Randdouble(double l, double r) { return (double)rand() / RAND_MAX * (r - l) + l; }

bool can_move(int i, int j, int d) {
    if (d == 0) return i > 0   && h_wall[i-1][j] == '0';
    if (d == 1) return j < N-1 && v_wall[i][j]   == '0';
    if (d == 2) return i < N-1 && h_wall[i][j]   == '0';
    if (d == 3) return j > 0   && v_wall[i][j-1] == '0';
    return false;
}

void compute_dir_bfs() {
    int NN = N * N, NS = NN * 4;
    dir_cost.assign(NS, vector<int>(NN, INT_MAX));
    dir_end.assign(NS, vector<int>(NN, -1));
    nav_path.assign(NS, vector<string>(NN));
    nav_cnt.assign(NPATS, vector<vector<uint8_t>>(NS, vector<uint8_t>(NN, 0)));
    vector<int> dist(NS), prev_s(NS);
    vector<char> pop(NS);
    for (int init_s = 0; init_s < NS; init_s++) {
        fill(dist.begin(), dist.end(), INT_MAX);
        fill(prev_s.begin(), prev_s.end(), -1);
        dist[init_s] = 0;
        queue<int> q; q.push(init_s);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            int cell = s >> 2, d = s & 3, ci = cell / N, cj = cell % N;
            auto tp = [&](int ns, char op) {
                if (dist[ns] == INT_MAX) { dist[ns]=dist[s]+1; prev_s[ns]=s; pop[ns]=op; q.push(ns); }
            };
            tp(cell*4+(d+1)%4,'R'); tp(cell*4+(d+3)%4,'L');
            if (can_move(ci,cj,d)) tp((ci+di[d])*N*4+(cj+dj[d])*4+d,'F');
        }
        for (int dc = 0; dc < NN; dc++) {
            for (int dd = 0; dd < 4; dd++) {
                int ds = dc*4+dd;
                if (dist[ds] < dir_cost[init_s][dc]) { dir_cost[init_s][dc]=dist[ds]; dir_end[init_s][dc]=dd; }
            }
            if (dir_cost[init_s][dc] == INT_MAX) continue;
            int bds = dc*4+dir_end[init_s][dc];
            string path; for (int s=bds; s!=init_s; s=prev_s[s]) path+=pop[s];
            reverse(path.begin(),path.end());
            nav_path[init_s][dc] = path;
            for (int p = 0; p < NPATS; p++) {
                const string& pat = CAND_PATS[p];
                int L=pat.size(), n=path.size(), cnt=0, i=0;
                while (i+L<=n) { if (path.substr(i,L)==pat){cnt++;i+=L;} else i++; }
                nav_cnt[p][init_s][dc] = (uint8_t)min(cnt,255);
            }
        }
    }
}

string gen_ops(const vector<int>& perm) {
    string ops; ops.reserve(M*30);
    int cs = 1;
    for (int k : perm) {
        int bc=ball_r[k]*N+ball_c[k]; ops+=nav_path[cs][bc]; ops+='S'; cs=bc*4+dir_end[cs][bc];
        int bk=basket_r[k]*N+basket_c[k]; ops+=nav_path[cs][bk]; ops+='S'; cs=bk*4+dir_end[cs][bk];
    }
    return ops;
}

// ops 文字列と split_pos を同時返す (perm[0..k-1] が part1)
pair<string,int> gen_ops_split(const vector<int>& perm, int k) {
    string ops; ops.reserve(M*30);
    int cs=1, split_pos=0;
    for (int idx=0;idx<M;idx++) {
        int ball=perm[idx];
        int bc=ball_r[ball]*N+ball_c[ball]; ops+=nav_path[cs][bc]; ops+='S'; cs=bc*4+dir_end[cs][bc];
        int bk=basket_r[ball]*N+basket_c[ball]; ops+=nav_path[cs][bk]; ops+='S'; cs=bk*4+dir_end[cs][bk];
        if (idx==k-1) split_pos=(int)ops.size();
    }
    return {ops, split_pos};
}

void select_best_pattern(const vector<int>& perm) {
    array<int,NPATS> cnts={};
    int cs=1;
    for (int k:perm){
        int bc=ball_r[k]*N+ball_c[k]; for(int p=0;p<NPATS;p++) cnts[p]+=nav_cnt[p][cs][bc];
        cs=bc*4+dir_end[cs][bc];
        int bk=basket_r[k]*N+basket_c[k]; for(int p=0;p<NPATS;p++) cnts[p]+=nav_cnt[p][cs][bk];
        cs=bk*4+dir_end[cs][bk];
    }
    bp=0; bpL=3;
    int best_sv=INT_MIN;
    for(int p=0;p<NPATS;p++){
        int L=CAND_PATS[p].size(), sv=(cnts[p]-1)*(L-1)-2;
        if(sv>best_sv){best_sv=sv;bp=p;bpL=L;}
    }
}

double GetScoreMacro(const vector<int>& perm) {
    const auto& ct=nav_cnt[bp];
    double ops=0; int cnt=0,cs=1;
    for(int k:perm){
        int bc=ball_r[k]*N+ball_c[k]; ops+=dir_cost[cs][bc]; cnt+=ct[cs][bc]; cs=bc*4+dir_end[cs][bc];
        int bk=basket_r[k]*N+basket_c[k]; ops+=dir_cost[cs][bk]; cnt+=ct[cs][bk]; cs=bk*4+dir_end[cs][bk];
    }
    return ops-(double)(bpL-1)*cnt;
}

vector<int> greedy_perm() {
    vector<int> perm; vector<bool> used(M,false); int cs=1;
    for(int iter=0;iter<M;iter++){
        int bk=-1,bd=INT_MAX;
        for(int k=0;k<M;k++){
            if(used[k])continue;
            int d=dir_cost[cs][ball_r[k]*N+ball_c[k]];
            if(d<bd){bd=d;bk=k;}
        }
        perm.push_back(bk); used[bk]=true;
        int bc=ball_r[bk]*N+ball_c[bk]; cs=bc*4+dir_end[cs][bc];
        int bkk=basket_r[bk]*N+basket_c[bk]; cs=bkk*4+dir_end[cs][bkk];
    }
    return perm;
}

// ===== MACRO COMPRESSION =====
int count_mac_in_pat(const string& pat, const string& cur_mac) {
    int cm=cur_mac.size(),count=0,pos=0;
    while(pos+cm<=(int)pat.size()){ if(pat.substr(pos,cm)==cur_mac){count++;pos+=cm;} else pos++; }
    return count;
}
pair<string,string> apply_macro_single(const string& s, const string& cur_mac) {
    int n=s.size(); if(n<4) return {s,""};
    vector<int> run(n+1,0);
    for(int i=n-1;i>=0;i--) run[i]=(s[i]!='S')?run[i+1]+1:0;
    int bs=0; string bp_=""; int bo=0;
    for(int L=min(n/2,200);L>=2;L--){
        unordered_map<string,vector<int>> pm;
        for(int i=0;i+L<=n;i++){ if(run[i]<L)continue; pm[s.substr(i,L)].push_back(i); }
        for(auto&[pat,pos]:pm){
            int nocc=0,le=0;
            for(int p:pos) if(p>=le){nocc++;le=p+L;}
            if(nocc<2)continue;
            int ss=(nocc-1)*(L-1)-2;
            int occ=cur_mac.empty()?0:count_mac_in_pat(pat,cur_mac);
            int sn=ss+occ*((int)cur_mac.size()-1);
            int sv=max(ss,sn),ov=(sn>ss)?occ:0;
            if(sv>bs){bs=sv;bp_=pat;bo=ov;}
        }
    }
    if(bs<=0) return {s,""};
    int L=bp_.size(),cm=cur_mac.size();
    string def="M";
    if(bo>0&&cm>0){int pos=0;while(pos<L){if(pos+cm<=L&&bp_.substr(pos,cm)==cur_mac){def+='P';pos+=cm;}else def+=bp_[pos++];}}
    else def+=bp_;
    def+='M';
    string result; bool rec=false;
    for(int i=0;i<n;){
        if(run[i]>=L&&s.substr(i,L)==bp_){
            if(!rec){result+=def;rec=true;}else result+='P';
            i+=L;
        } else result+=s[i++];
    }
    return {result,bp_};
}
string apply_macros_multi(const string& s, int mr=12) {
    string result=s; int ss=0; string cm="";
    for(int r=0;r<mr;r++){
        string suf=result.substr(ss);
        auto[comp,nm]=apply_macro_single(suf,cm);
        if((int)comp.size()==(int)suf.size())break;
        result=result.substr(0,ss)+comp; cm=nm;
        int lp=-1;
        for(int i=(int)result.size()-1;i>=ss;i--) if(result[i]=='P'){lp=i;break;}
        if(lp==-1)break;
        ss=lp+1;
    }
    return result;
}

// ===== 2-ROUND SPLIT SA =====
// dir=1 (Right) を固定出発方向として nav_cnt を使用
// nav_cnt はターンパターン ("RFFF" 等) も正確に計測できる
const int FPATS = 7;  // CAND_PATS と同じ
const int FLEN[FPATS] = {3,4,5,4,5,4,5};  // CAND_PATS のパターン長

// Indexed: prev=0..M-1 = basket_i, prev=M = start(0,0)
int trans2[41][40];      // 方向考慮 transition distance
uint8_t dc2[FPATS][40];      // delivery pattern counts (nav_cnt ベース)
uint8_t tc2[FPATS][41][40];  // transition pattern counts
int del_const2 = 0;

void compute_cell_structures() {
    // 各セグメントの出発状態を "basket の cell × 4 + dir=1 (Right)" で近似
    // 実際の方向伝播を無視した近似だが、ターンパターンを正確に捉えられる
    int start_state = 1;  // (0,0) facing Right

    del_const2 = 0;
    for (int i = 0; i < M; i++) {
        // delivery: ball_i -> basket_i
        int bs = ball_r[i]*N*4 + ball_c[i]*4 + 1;  // ball facing Right
        int bk = basket_r[i]*N + basket_c[i];
        del_const2 += dir_cost[bs][bk];
        for (int p = 0; p < FPATS; p++) dc2[p][i] = nav_cnt[p][bs][bk];
    }

    for (int prev = 0; prev <= M; prev++) {
        // prev=M → start, prev=k → basket_k facing Right
        int src_state = (prev < M) ?
            (basket_r[prev]*N*4 + basket_c[prev]*4 + 1) : start_state;
        for (int j = 0; j < M; j++) {
            int bj = ball_r[j]*N + ball_c[j];
            trans2[prev][j] = dir_cost[src_state][bj];
            for (int p = 0; p < FPATS; p++) tc2[p][prev][j] = nav_cnt[p][src_state][bj];
        }
    }
}

// SA state for 2-round split
struct S2 {
    int perm[40], k;
    int cnt1[FPATS], cnt2[FPATS];
    int tsum; // trans_sum only
};

void s2_init(S2& s, const vector<int>& p, int k) {
    for(int i=0;i<M;i++) s.perm[i]=p[i];
    s.k=k;
    memset(s.cnt1,0,sizeof(s.cnt1));
    memset(s.cnt2,0,sizeof(s.cnt2));
    s.tsum=0;
    for(int pos=0;pos<M;pos++){
        int b=s.perm[pos],pb=(pos>0)?s.perm[pos-1]:M;
        bool g1=(pos<s.k);
        for(int pp=0;pp<FPATS;pp++){
            int c=dc2[pp][b]+tc2[pp][pb][b];
            if(g1)s.cnt1[pp]+=c; else s.cnt2[pp]+=c;
        }
        s.tsum+=trans2[pb][b];
    }
}

double s2_score(const S2& s) {
    double s1=0,s2=0;
    for(int p=0;p<FPATS;p++){
        if(s.cnt1[p]>=2) s1=max(s1,(s.cnt1[p]-1.0)*(FLEN[p]-1)-2);
        if(s.cnt2[p]>=2) s2=max(s2,(s.cnt2[p]-1.0)*(FLEN[p]-1)-2);
    }
    return s.tsum+del_const2-s1-s2;
}

void s2_rm(S2& s, int pos) {
    int b=s.perm[pos],pb=(pos>0)?s.perm[pos-1]:M;
    bool g1=(pos<s.k);
    for(int p=0;p<FPATS;p++){int c=dc2[p][b]+tc2[p][pb][b];if(g1)s.cnt1[p]-=c;else s.cnt2[p]-=c;}
    s.tsum-=trans2[pb][b];
}

void s2_add(S2& s, int pos) {
    int b=s.perm[pos],pb=(pos>0)?s.perm[pos-1]:M;
    bool g1=(pos<s.k);
    for(int p=0;p<FPATS;p++){int c=dc2[p][b]+tc2[p][pb][b];if(g1)s.cnt1[p]+=c;else s.cnt2[p]+=c;}
    s.tsum+=trans2[pb][b];
}

void s2_swap(S2& s, int l, int r) {
    // collect affected positions (l, l+1, r, r+1) deduped
    int aff[4],na=0;
    for(int pos:{l,l+1,r,r+1}){
        if(pos<0||pos>=M) continue;
        bool dup=false; for(int a=0;a<na;a++) if(aff[a]==pos){dup=true;break;}
        if(!dup) aff[na++]=pos;
    }
    for(int a=0;a<na;a++) s2_rm(s,aff[a]);
    swap(s.perm[l],s.perm[r]);
    for(int a=0;a<na;a++) s2_add(s,aff[a]);
}

void s2_chk(S2& s, int dk) {
    if(dk>0&&s.k<M){
        int pos=s.k,b=s.perm[pos],pb=(pos>0)?s.perm[pos-1]:M;
        for(int p=0;p<FPATS;p++){int c=dc2[p][b]+tc2[p][pb][b];s.cnt2[p]-=c;s.cnt1[p]+=c;}
        s.k++;
    } else if(dk<0&&s.k>0){
        int pos=s.k-1,b=s.perm[pos],pb=(pos>0)?s.perm[pos-1]:M;
        for(int p=0;p<FPATS;p++){int c=dc2[p][b]+tc2[p][pb][b];s.cnt1[p]-=c;s.cnt2[p]+=c;}
        s.k--;
    }
}

int find_best_k(const vector<int>& perm) {
    S2 s; s2_init(s,perm,0);
    double best=s2_score(s); int bk=0;
    for(int k=1;k<=M;k++){
        s2_chk(s,1);
        double sc=s2_score(s);
        if(sc<best){best=sc;bk=k;}
    }
    return bk;
}

S2 run_sa2(S2 init_s, double st, double et, double Ts, double Te, const function<double()>& el) {
    S2 s=init_s;
    double cur=s2_score(s);
    S2 best_s=s; double best=cur;
    for(int i=0;;i++){
        if(i%1000==0&&el()>et) break;
        double t=el(), prog=max(0.0,min(1.0,(t-st)/(et-st)));
        double temp=Ts*pow(Te/Ts,prog);
        int mv=rand()%4;
        if(mv<=2){
            // swap
            int l=RandInt(0,M-1),r=RandInt(0,M-1);
            if(l>r) swap(l,r);
            if(l==r) continue;
            s2_swap(s,l,r);
            double nc=s2_score(s);
            if(nc<cur||Randdouble(0,1)<exp((cur-nc)/temp)){
                cur=nc; if(nc<best){best=nc;best_s=s;}
            } else s2_swap(s,l,r);
        } else {
            // change k (多めに試す: ±1, ±2, ±3)
            int dk=(rand()%2==0)?1:-1;
            int steps=1+(rand()%3);
            int old_k=s.k;
            for(int step=0;step<steps;step++) s2_chk(s,dk);
            if(s.k!=old_k){
                double nc=s2_score(s);
                if(nc<cur||Randdouble(0,1)<exp((cur-nc)/temp)){
                    cur=nc; if(nc<best){best=nc;best_s=s;}
                } else { while(s.k!=old_k) s2_chk(s,-dk); }
            }
        }
    }
    return best_s;
}

// 2-round 分割圧縮: part1 にマクロ1、part2 にマクロ2 (nesting 付き)
// baseline (単一ラウンド) とどちらか短い方を返す
string apply_macros_split(const string& ops, int split_pos) {
    // Baseline: standard single-pass multi-round
    string cand1 = apply_macros_multi(ops);

    if (split_pos <= 0 || split_pos >= (int)ops.size()) return cand1;

    string part1 = ops.substr(0, split_pos);
    string part2 = ops.substr(split_pos);

    // Round 1: best macro for part1 only
    auto [comp1, mac1] = apply_macro_single(part1, "");
    if (mac1.empty()) return cand1;  // no macro found

    // Round 2: best macro for part2 (with nesting from mac1)
    auto [comp2, mac2] = apply_macro_single(part2, mac1);

    string cand2 = comp1 + comp2;
    // Also try: round 2 without nesting
    {
        auto [c2b, m2b] = apply_macro_single(part2, "");
        string cand2b = comp1 + c2b;
        if ((int)cand2b.size() < (int)cand2.size()) { cand2=cand2b; }
    }

    return ((int)cand2.size() < (int)cand1.size()) ? cand2 : cand1;
}

// GetScoreComp for final refinement
static vector<int> fq(6561),fl(6561);
int fast_sav(const string& ops,int L){
    int n=ops.size(); if(n<2*L)return 0;
    int np=1; for(int k=0;k<L;k++)np*=3;
    fill(fq.begin(),fq.begin()+np,0);fill(fl.begin(),fl.begin()+np,-1);
    vector<int> run(n+1,0);
    for(int i=n-1;i>=0;i--) run[i]=(ops[i]!='S')?run[i+1]+1:0;
    auto enc=[](char c){return(c=='F')?0:(c=='R')?1:2;};
    for(int i=0;i+L<=n;i++){
        if(run[i]<L)continue;
        int h=0; for(int j=i;j<i+L;j++)h=h*3+enc(ops[j]);
        if(i>=fl[h]){fq[h]++;fl[h]=i+L;}
    }
    int best=0;
    for(int k=0;k<np;k++){int c=fq[k];if(c>=2)best=max(best,(c-1)*(L-1)-2);}
    return best;
}
int GetScoreComp(const vector<int>& perm){
    string ops=gen_ops(perm); int n=ops.size(),ms=0;
    for(int L=3;L<=5;L++) ms=max(ms,fast_sav(ops,L));
    return n-ms;
}

void apply_move(vector<int>& perm, int l, int r, int choice) {
    switch(choice){
    case 0: swap(perm[l],perm[r]); break;
    case 1: reverse(perm.begin()+l,perm.begin()+r+1); break;
    case 2: {int e=perm[l];perm.erase(perm.begin()+l);perm.insert(perm.begin()+min(r,(int)perm.size()),e);break;}
    default: if(l+1<M){int e1=perm[l],e2=perm[l+1];perm.erase(perm.begin()+l,perm.begin()+l+2);int ins=min(r,(int)perm.size());perm.insert(perm.begin()+ins,e2);perm.insert(perm.begin()+ins,e1);}else swap(perm[l],perm[r]);
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin>>N>>M>>T_limit;
    v_wall.resize(N); for(int i=0;i<N;i++) cin>>v_wall[i];
    h_wall.resize(N-1); for(int i=0;i<N-1;i++) cin>>h_wall[i];
    ball_r.resize(M);ball_c.resize(M);basket_r.resize(M);basket_c.resize(M);
    for(int k=0;k<M;k++) cin>>ball_r[k]>>ball_c[k]>>basket_r[k]>>basket_c[k];

    compute_dir_bfs();
    compute_cell_structures();
    srand(42);

    auto t0=chrono::steady_clock::now();
    auto elapsed=[&](){return chrono::duration<double>(chrono::steady_clock::now()-t0).count();};

    vector<int> gp=greedy_perm();
    select_best_pattern(gp);

    string best_ops=""; int best_actual=INT_MAX;

    // Phase 1: 2-round split SA from greedy + split compression
    {
        int bk=find_best_k(gp);
        S2 s0; s2_init(s0,gp,bk);
        double T0=max(1.0,abs(s2_score(s0)));
        S2 r1=run_sa2(s0,0.0,0.9,T0*0.04,T0*0.0005,elapsed);
        vector<int> p1(r1.perm,r1.perm+M);
        auto [ops1,sp1]=gen_ops_split(p1,r1.k);
        if((int)ops1.size()>T_limit) ops1.resize(T_limit);
        string compressed1=apply_macros_split(ops1,sp1);
        if((int)compressed1.size()<best_actual){best_actual=compressed1.size();best_ops=compressed1;}
    }

    // Phase 2: 2-round split SA from random start + split compression
    {
        vector<int> rp(M); iota(rp.begin(),rp.end(),0);
        shuffle(rp.begin(),rp.end(),default_random_engine(54321));
        int bk=find_best_k(rp);
        S2 s1; s2_init(s1,rp,bk);
        double T1=max(1.0,abs(s2_score(s1)));
        S2 r2=run_sa2(s1,0.9,1.7,T1*0.04,T1*0.0005,elapsed);
        vector<int> p2(r2.perm,r2.perm+M);
        auto [ops2,sp2]=gen_ops_split(p2,r2.k);
        if((int)ops2.size()>T_limit) ops2.resize(T_limit);
        string compressed2=apply_macros_split(ops2,sp2);
        if((int)compressed2.size()<best_actual){best_actual=compressed2.size();best_ops=compressed2;}
    }

    // Phase 3: single-round SA with GetScoreMacro from greedy
    {
        select_best_pattern(gp);
        vector<int> perm=gp;
        double cur=GetScoreMacro(perm);
        vector<int> bp=perm; double bs=cur;
        for(int i=0;;i++){
            if(i%500==0&&elapsed()>1.82) break;
            int l=RandInt(0,M-1),r=RandInt(0,M-1); if(l>r)swap(l,r);
            vector<int> sv=perm;
            apply_move(perm,l,r,rand()%4);
            double nc=GetScoreMacro(perm);
            double t=elapsed(),prog=max(0.0,min(1.0,(t-1.7)/0.12));
            double temp=5.0*pow(0.5/5.0,prog);
            if(nc<cur||Randdouble(0,1)<exp((cur-nc)/temp)){cur=nc;if(nc<bs){bs=nc;bp=perm;}}
            else perm=sv;
        }
        string ops=gen_ops(bp);
        if((int)ops.size()>T_limit) ops.resize(T_limit);
        ops=apply_macros_multi(ops);
        if((int)ops.size()<best_actual){best_actual=ops.size();best_ops=ops;}
    }

    for(char c:best_ops) cout<<c<<'\n';
    return 0;
}

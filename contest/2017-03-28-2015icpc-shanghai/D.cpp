#include <bits/stdc++.h>

#define DEBUG 
//printf("%d\n", __LINE__)
using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 1e5+5;
const int MAXM = 2e5+5;

vector<int> board;

struct query {
  int x,h;
  int l,r,z;
  bool operator < (const query & T) const {
    if (l != T.l) return l < T.l;
    if (r != T.r) return r > T.r;
    return h > T.h;
  }
};

int N, M;
int h[MAXN];
query q[MAXM];
vector<pair<int,int>> hh; 

bool cmp1(query& a,query& b) {
  return a.x < b.x ;
}

int hhfind(int th) {
  //cout << "hh-------------------" << endl;
  //for(auto th: hh) {
  //  cout << th.first << ' ' << th.second << endl;
  //}
  //cout << "hh------------------------ End!!!" << endl;
  if(hh.back().first >= th) return hh.back().second;
  int l = 0, r = hh.size()-1;
  while(r-l>1) {
    int mid = (l+r) >> 1;
    if(hh[mid].first < th) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return hh[l].second;
}
void read() {
  scanf("%d%d", &N, &M);
  //cout << N << ' ' << M << endl;
  rep(i,2,N+1) scanf("%d", &h[i]);
  h[1] = 1e9+13;
  h[N+1] = 1e9+13;
  rep(i,1,M+1) {
    int tx,ty,tz;
    scanf("%d%d%d", &tx, &ty, &tz); 
    q[i].x = tx;
    q[i].h = ty+1;
    q[i].z = tz;
  }
  sort(q+1, q+1+M, cmp1);
  int ind = 1;
  hh.clear();
  hh.push_back(make_pair(h[1],0));
  rep(i, 1, N+1) {
    if(ind > M) break;
    while(q[ind].x == i && ind <= M) {
      q[ind].l = hhfind(q[ind].h)+1;
      ind++;
    }
    if (i == N) break;
    while(h[i+1] >= hh.back().first) {
      hh.pop_back();
    } 
    hh.push_back(make_pair(h[i+1],i));
  }
  hh.clear();
  ind = M;
  hh.push_back(make_pair(h[N+1],N+1));
  per(i, 1, N+1) {
    if(ind < 1) break;
    while(q[ind].x == i && ind > 0) {
      q[ind].r = hhfind(q[ind].h);
      ind--;
    }
    if (i == 1) break;
    while(h[i] >= hh.back().first) {
      hh.pop_back();
    } 
    hh.push_back(make_pair(h[i],i));
  }
  /*for(int i = 1; i <= M; i++) {
    //cout<< "q[" << i << "]:" << endl;
    //cout << q[i].x << ' ' <<q[i].h << ' ' <<q[i].z << endl;
    //cout << q[i].l << ' ' <<q[i].r << endl;
  }*/
}

struct LINE{
  int l, r, h, z0, z1;
};

vector<LINE> line;

int index;

pair<int, int> dfs(int pL, int pR){
  //if (line[index].l > pR) return make_pair(0, 0);
  
  if (index == line.size()) return make_pair(0, 0);
  int curIndex = index++;
  pair<int, int> res = make_pair(line[curIndex].z0, line[curIndex].z1);
  
  for (;index < line.size();){
    DEBUG;
    //printf("%d\n", index);
    if (line[index].l > line[curIndex].r-1) break;
    //printf("%d\n", index);
    pair<int, int> tmp = dfs(line[curIndex].l, line[curIndex].r);
    res.first += tmp.first;
    res.second += max(tmp.first, tmp.second);
  }

 // printf("L = %d, R = %d, H = %d, water = %d, empty = %d\n",
   //   line[curIndex].l, line[curIndex].r, line[curIndex].h, 
   //   line[curIndex].z0, line[curIndex].z1);

  //cout << curIndex << ' ' << res.first << ' ' << res.second << endl;
  return res;
}


int work(){
  read();
  sort(q+1, q+M+1);

  DEBUG;
  line.clear();
  line.push_back((LINE){-1, 1000000000+9, 100000000+9, 0, 0});
  line.push_back((LINE){q[1].l, q[1].r, q[1].h, q[1].z == 1, q[1].z == 0});
  for (int i = 2; i <= M; ++i) {
    if (q[i].l != q[i-1].l || q[i].r != q[i-1].r || q[i].h != q[i-1].h) {
      line.push_back(
          (LINE){q[i].l, q[i].r, q[i].h, q[i].z == 1, q[i].z == 0});
    } else {
      int k = line.size() - 1;
      line[k].z0 += q[i].z == 1;
      line[k].z1 += q[i].z == 0;
    }
  }

 // cout << line.size() << endl;
  /*for (int i = 0; i < line.size(); ++i) {
    cout << line[i].l << ' ' << line[i].r << endl;
  }*/

  index = 0;
  pair<int, int> ans = dfs(-1, 1e9+9);

  return max(ans.first, ans.second);
}

int main() {
#ifndef ONLINE_JUDGE
  //freopen("D.in","r",stdin);
#endif

  int Cas;
  scanf("%d", &Cas);
  for (int cas = 1; cas <= Cas; ++cas) {
    printf("Case #%d: %d\n", cas, work());
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


#include<bits/stdc++.h>

using namespace std;

const int maxN = 800 + 13;;

const double eps = 1e-8;
const int inf = 0x7f7f7f7f;

inline int sgn(double x) { 
  if(x < -eps) return -1;
  if(x > eps) return 1;
  return 0;
}

struct Point {
  double x, y;
  Point(){};
  Point(double x, double y) : x(x), y(y){};
  void read() {
    scanf("%lf%lf",&x, &y);
  }
  Point operator - (const Point& b) {
    return Point(x - b.x, y - b.y);
  }
  //det
  double operator ^ (const Point& b) {
    return x*b.y - y*b.x;
  }
};

struct Seg {
  Point s,e;
  Seg(){};
  Seg(Point s, Point e) : s(s), e(e){};
};
#define cross(p1, p2, p3) ((p2.x-p1.x)* (p3.y-p1.y) - (p3.x-p1.x) * (p2.y-p1.y))


bool inter(Seg& l1, Seg& l2) {
  return 
    max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) && 
    max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) && 
    max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) && 
    max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) && 
    sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) < 0 &&
    sgn((l1.s - l2.e) ^ (l2.s - l2.e)) * sgn((l1.e - l2.e) ^ (l2.s - l2.e)) < 0;
}

const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};

int N;
Point tri[10];
vector<int> e[maxN];
int num[maxN][maxN];
Seg ts[10];
int dis[maxN],v[maxN];
queue<int>q;
char s[maxN];
char map_[maxN][maxN];

bool inTri(Point p) {
  for(int i = 1; i <= 3; i++) {
    if(sgn((tri[i+1]-tri[i])^(p-tri[i])) * sgn((tri[i+2]-tri[i+1])^(p-tri[i+1])) <= 0) {
      return false;
    }
  }
  return true;
}

int work() {
  if(scanf("%d", &N) != 1) return 0;
  for(int i = 1; i <= 3; i++) {
    tri[i].read();
    tri[i+3] = tri[i];
  }
  ts[1] = Seg(tri[1], tri[2]);
  ts[2] = Seg(tri[2], tri[3]);
  ts[3] = Seg(tri[3], tri[1]);
  int ind = 0;
  for(int y = 0; y < N; y++) {
    for(int x = 0; x < N; x++){
      ind++;
      num[x][y] = ind;
      Point tp = Point(x, y);
      if(inTri(tp)) num[x][y] = 0;
    }
  }
  for(int y = N-1 ; y >= 0; y--) {
    for(int x = 0; x < N; x++) {
      char c = getchar();
      if (c != '#' && c != '.') {
	--x;
	continue;
      }
      if (c == '#') {
	num[x][y] = 0;
      }
    }
  }
  for(int i = 0; i <= N*N; i++) e[i].clear();
  for(int x = 0; x < N; x++) {
    for(int y = 0; y < N; y++) {
      if(num[x][y] == 0) continue;
      for(int k = 0 ; k < 8; k++) {
	int tx = x + dx[k];
	int ty = y + dy[k];
	if(tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
	if(num[tx][ty] == 0) continue;
	Seg tSeg = Seg(Point(x,y) , Point(tx,ty));
	bool ok = true;
	for(int l = 1; l <= 3; l++) {
	  if(inter(tSeg, ts[l])) ok = false;
	}
	if(ok) {
	  Point tp = Point((double)(x - tx), (double)(y - ty));
	  
	  if(inTri(Point(x - tp.x * 1e-4, y - tp.y * 1e-4))) continue;
	  if(inTri(Point(tx + tp.x * 1e-4, ty + tp.y * 1e-4))) continue;
	
	  e[num[x][y]].push_back(num[tx][ty]);
	} 
      }
    }
  }
  memset(dis,0x7f,sizeof(dis));
  memset(v,0,sizeof(v));
  while(!q.empty()) q.pop();
  dis[num[0][0]] = 0;
  v[num[0][0]] = 1;
  if (num[0][0]) q.push(num[0][0]);
  while(!q.empty()) {
    int id = q.front();
    v[id] = 0; q.pop();
    int temp  = dis[id] + 1;
    for(auto tt : e[id]) {
      if(temp < dis[tt]) {
	dis[tt] = temp;
	if(!v[tt]) {
	  q.push(tt);
	  v[tt] = 1;
	}
      }
    }
  }
  if(dis[num[N-1][N-1]] == inf) {
    printf("-1\n");
  } else {
    printf("%d\n", dis[num[N-1][N-1]]);
  }
  return 1;
}

int main(){
  while(work());
  return 0;
}


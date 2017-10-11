#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-8;

int dcmp(double x){
  if(fabs(x)<eps)return 0;
  else return x<0 ? -1:1;
}

struct Point3{
  double x,y,z;
  Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){} 
};
bool operator==(const Point3& a,const Point3& b){
  return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0 && dcmp(a.z-b.z)==0 ;
}
typedef Point3 Vector3;
Vector3 operator+(Vector3 A,Vector3 B){
  return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);
}
Vector3 operator-(Vector3 A,Vector3 B){
  return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);
}
Vector3 operator*(Vector3 A,double p){
  return Vector3(A.x*p,A.y*p,A.z*p);
}
Vector3 operator/(Vector3 A,double p){
  return Vector3(A.x/p,A.y/p,A.z/p);
}


double Dot(Vector3 A,Vector3 B){return A.x*B.x+A.y*B.y+A.z*B.z;}
double Length(Vector3 A){return sqrt(Dot(A,A));}
double Angle(Vector3 A,Vector3 B){return acos(Dot(A,B)/Length(A)/Length(B));}

Vector3 Cross(Vector3 A,Vector3 B){
  return Vector3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);
}
double Area2(Point3 A,Point3 B,Point3 C){return Length(Cross(B-A,C-A));}
//点p在三角形p0p1p2中（利用面积法算点是否在三角形内，假定所有的点共面）
bool PointInTri(Point3 p,Point3 p0,Point3 p1,Point3 p2){
  double area1=Area2(p,p0,p1);
  double area2=Area2(p,p1,p2);
  double area3=Area2(p,p2,p0);
  if(dcmp(area1) == 0) return false;
  if(dcmp(area2) == 0) return false;
  if(dcmp(area3) == 0) return false;
  return dcmp(area1+area2+area3-Area2(p0,p1,p2))==0;
}
//三角形p0p1p2是否和线段AB相交(此函数会把线段在平面上的情况视为不相交）
bool TriSegIntersection(Point3 p0,Point3 p1,Point3 p2,Point3 A,Point3 B,Point3& p){
  Vector3 n=Cross(p1-p0,p2-p0);
  if(dcmp(Dot(n,B-A))==0)return false;//平行或共面
  else{                               //直线AB和平面P0P1P2有唯一交点
    double t=Dot(n,p0-A)/Dot(n,B-A);
    if(dcmp(t)<0 || dcmp(t-1)>0)return false;//交点不在线段AB上
    p=A+(B-A)*t;                             //计算交点
    return PointInTri(p,p0,p1,p2);           //判断交点是否在三角形内
  }
}

const int maxN = 20;
int N;
int label[maxN];
vector<Point3> surface[maxN];
Point3 oo;

bool test(Point3 A) {
  for(int i = 1; i <= N; i++) {
    double tx = 0, ty = 0, tz = 0;
    tx += surface[i][0].x;
    ty += surface[i][0].y;
    tz += surface[i][0].z;
    int nn = surface[i].size();
    int ok = true;
    for(int j = 2; j < nn; j++) {
      Point3 tp;
      if(TriSegIntersection(surface[i][0],surface[i][j],surface[i][j],oo,A,tp)) 
        return true;
    }
  }
  return false;
}

int n;

void delBlank(){
	while (getchar() != '\n');
}

void nextD(char ** cur){
	//cout << *cur << endl;
	//++(*cur);
        while (*(*cur) == ' ') ++(*cur);
	while (*(*cur) != '\0' && *(*cur) != ' ' && *(*cur) != '\t') ++(*cur);
}

char buff[1024];

int readData(){
  int n;
  scanf("%d", &n); delBlank();
  N=n;
  for (int i = 0; i < n; ++i) {
    gets(buff);
    char * cur = buff;
    int id;
    sscanf(cur, "%d", &id);
    label[i] = id;
    nextD(&cur);
    double x, y, z;
    while (sscanf(cur, "%lf%lf%lf", &x, &y, &z) == 3) {
      surface[i].push_back(Point3(x, y, z));
      nextD(&cur);
      nextD(&cur);
      nextD(&cur);
      if (*cur == '\0') break;
    }
  }
  return 0;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("nn-e.in","r",stdin);
#endif
  readData();
  double x,y,z;
  scanf("%lf%lf%lf", &x, &y, &z);
  oo = Point3(x,y,z);
  vector<int> ans;
  for(int i = 0; i < N; i++) {
    double tx = 0, ty = 0, tz = 0;
    bool ok = true;
    for(int j = 0; j < surface[i].size(); j++) {
      tx += surface[i][j].x;
      ty += surface[i][j].y;
      tz += surface[i][j].z;
      if(test(surface[i][j])) {
        ok = false;
        break;
      }
    }
    double nn = surface[i].size();
    if(test(Point3(tx/nn,ty/nn,tz/nn))) ok = false;
    if(ok) {
      ans.push_back(label[i]);
    }
  }
  sort(all(ans));
  for(auto tt: ans) {
    printf("%d ", tt);
  }
  printf("\n");
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;
  return 0;
}


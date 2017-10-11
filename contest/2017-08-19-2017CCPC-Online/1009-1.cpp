#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

double sqr(double x){return x*x;}

double R,r;
int k,T;

ofstream fin,fout;

int main() {
  //fin = ofstream("cf-77e.in");
  //fout = ofstream("cf-77e.out");
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    scanf("%lf%lf%d", &R, &r, &k);
    //fin << R << ' ' << r << ' ' << k << endl;
    R*=2;
    r*=2;
    double D=1.*R*R/r;
    double h=D-R;
    double w=h*k;
    double s=sqrt(sqr(R+h*0.5)+sqr(w));
    printf("%.4f\n",0.5*(R*R/(s-h*0.5)-R*R/(s+h*0.5)));
    //fout << fixed << setprecision(4);
    //fout << 0.5*(R*R/(s-h*0.5)-R*R/(s+h*0.5)) << endl;
  }
  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}



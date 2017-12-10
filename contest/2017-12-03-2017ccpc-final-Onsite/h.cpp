#include<bits/stdc++.h>

using namespace std;

const double error_ = 1e-8;

int sgn(double x){
  if (x > error_) return 1;
  if (x < error_) return -1;
  return 0;
}

double dist(const vector<double> & a, const vector<double> & b){
  double dis = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    double dx = a[i] - b[i];
    dis += dx * dx;
  }
  return sqrt(dis);
}

double dists(const vector<double> & a, const vector<vector<double> > & points) {
  for (int i = 0; i < (int)points.size(); ++i) {
    double res = dist(a, points[i]);
    if (sgn(res - 1) != 0) return false;
  }
  return true;
}

void showV(const vector<double> & v){
  for (int i = 0; i < (int)v.size(); ++i) {
    cout << v[i] << ' ';
  } cout << endl;
}

void getNormal(vector<double> & v){
  double len = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    len += v[i] * v[i];
  }
  len = sqrt(len);
  if (len == 0) return;
  for (int i = 0; i < (int)v.size(); ++i) {
    v[i] /= len;
  }
}

vector<double> getNextPoint(const vector<vector<double> > & point, const int N){
  double rate = 0.9;
  vector<double> empty;
  for (int i = 0; i < 10; ++i) {
    vector<double> res;
    for (int k = 0; k < N; ++k) {
      res.push_back(rand() % 31415 / 3.1415);
    }
    while (!dists(res, point)) {
      vector<double> dp(N);
      for (int j = 0; j < (int)point.size(); ++j) {
	double d = dist(point[j], res);
	vector<double> normalV;
	for (int k = 0; k < N; ++k) {
	  normalV.push_back(point[j][k] - res[k]);
	}
	getNormal(normalV);
	for (int k = 0; k < N; ++k) {
	  dp[k] += (normalV[k]) * (d - 1);
	}
      }
      for (int k = 0; k < N; ++k) {
	res[k] += dp[k] * rate / point.size();
      }
     // showV(res);
      rate *= 0.99;
      if (rate < error_) break;
    }
    return res;
  }
  assert(false);
  return empty;
}

vector<vector<double> > work(){
  int N, M;
  scanf("%d%d", &N, &M);
  vector<vector<double> > initPoint;
  for (int i = 0; i < M; ++i) {
    vector<double> P;
    for (int k = 0; k < N; ++k) {
      double x;
      scanf("%lf", &x);
      P.push_back(x);
    }
    initPoint.push_back(P);
  }

  //cout << "LINE : " << __LINE__ << endl;
   // cout << N << ' ' << initPoint.size() << endl;
  while ((int)(initPoint.size()) <= N) {
    //cout << N << endl;
    vector<double> res = getNextPoint(initPoint, N);
    initPoint.push_back(res);
  }
  vector<vector<double> > resP;
  for (int i = M; i < initPoint.size(); ++i) {
    resP.push_back(initPoint[i]);
  }
  return resP;
}

int main(){
  srand(time(0));
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    vector<vector<double> > ans = work();
    printf("Case #%d: %d\n", i, (int)ans.size());
    for (int k = 0; k < ans.size(); ++k) {
      for (int j = 0; j < ans[k].size(); ++j) {
	printf("%.18lf%c", ans[k][j], j+1 != ans[k].size() ? ' ' : '\n');
      }
    }
  }

}

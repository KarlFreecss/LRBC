#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

const int MAXN = 100 + 5;

int a[3], b[3], a_b[3][3], b_a[3][3]; 
int f[MAXN][MAXN][MAXN];
bool state[MAXN][MAXN][MAXN];

struct xx{
  int x, y, z;
  friend bool operator < (const xx& a, const xx& b) {
    if(a.z != b.z) return a.z < b.z;
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
  }
};

void work(){
  vector<xx> ans;
  int ind = 0;
  for(int i = 1; i <= 2000; i++) {
    for(int j = i; j <= 2000; j++) {
      for(int k = j ; k <= 2000; k++) {
	if(i*i + j*j == k*k - 7) {
	  ////cout << ind << " : "; cout << " ans = " << k << " -- ";
	  //cout << i << ' ' << j << ' ' << k << endl;
	  ans.push_back({i,j,k});
	}
      }
    }
  }
  sort(ans.begin(), ans.end());
  ind = 0;
  for(auto tt : ans) {
    ++ ind;
    cout << ind << " : " ;
    cout << tt.x << ' ' << tt.y << ' ' << tt.z << endl;
  }
}

int main(){
  int T;
  scanf("%d", &T);
  T = 1;
  for (int i = 0; i < T; ++i) {
    work();
  }
}

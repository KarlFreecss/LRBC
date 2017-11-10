#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

char m[3][3];

void work(){
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j) {
      char c = getchar();
      if (c != '.' && c != 'Z' && c != 'T' && c != 'C') {
	--j;
	continue;
      }
      m[i][j] = c;
    }
  }
  
  for (int i = 0; i < 3; ++i) {
    if (m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != '.') {
      printf("%c\n", m[i][0]);
      return;
    }
    if (m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != '.') {
      printf("%c\n", m[0][i]);
      return;
    }
  }

  if (m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != '.') {
    printf("%c\n", m[0][0]);
    return ;
  }

  if (m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != '.') {
    printf("%c\n", m[0][2]);
    return ;
  }
  puts("ongoing");
}

int main(){
  int T;
  scanf("%d", &T);
debug(T);
  for (int i = 0; i < T; ++i) {
    work();
  }
}

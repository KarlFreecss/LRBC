#include<bits/stdc++.h>

#define debug(x) cout << __LINE__ << " : " #x " = " << x << endl;

typedef long long ll;


using namespace std;

const int MAXN = 100 + 5;

int a[3], b[3], a_b[3][3], b_a[3][3]; 
int tmpA[3], tmpB[3];

bool otherPlay(int attack_id, int to_attack_id, int helpDay, int needDay) {
  for (int i = 0; i <= 1; i ++) {
    tmpA[i] = a[i];
    tmpB[i] = b[i];
  }
  for (int i = 0; i <= 1; i ++) {
    for (int j = 0; j <= 1; j ++) {
      for (int k = 0; k <= 100 && k < needDay; k ++) {
	int bNeedDay = (max(0, a[j] - (b_a[0][j] + b_a[1][j]) * k) - 1) / b_a[i][j];
	bNeedDay += k;
	if (needDay <= bNeedDay) {
	  tmpB[to_attack_id] = 0;
	  tmpB[to_attack_id ^ 1] -= (needDay - helpDay) * a_b[attack_id ^ 1][to_attack_id ^ 1];
	  tmpA[j] -= b_a[i][j] * (needDay - 1) + b_a[i ^ 1][j] * k;
	  tmpA[j ^ 1] -= (needDay - 1 - k) * b_a[i ^ 1][j ^ 1];
	  
	  bNeedDay = (tmpA[j] - 1) / b_a[to_attack_id ^ 1][j] + 1;
	  needDay = (tmpB[to_attack_id ^ 1] - 1) / (a_b[0][to_attack_id ^ 1] + a_b[1][to_attacked_id ^ 1]) + 1;
	  if (bNeedDay > needDay) {
	    continue;
	  } else {
	    tmpB[to_attack_id ^ 1] -= (a_b[0][to_attacked_id ^ 1] + a_b[1][to_attacked_id ^ 1]) * (bNeedDay - 1);
	    bNeedDay = (tmpA[j ^ 1] - 1) / b_a[to_attack_id ^ 1][j ^ 1] + 1;
	    needDay = (tmpB[to_attack_id ^ 1] - 1) / a_b[j ^ 1][to_attack_id ^ 1] + 1;
	    if (needDay <= bNeedDay) {
	      continue;
	    } else {
	      return false;
	    }
	  }
	} else {
	  tmpB[to_attack_id] -= (bNeedDay) * (a_b[0][to_attack_id] + a_b[1][to_attack_id]);
	  tmpB[to_attack_id ^ 1] -= (bNeedDay - min(helpDay, bNeedDay)) * a_b[attack_id ^ 1][to_attack_id ^ 1];
	  tmpA[j] = 0;
	  tmpA[j ^ 1] -= (needDay - k) * b_a[i ^ 1][j ^ 1];
  
	  bNeedDay = (tmpA[j ^ 1] - 1) / (b_a[0][j ^ 1] + b_a[1][j ^ 1]) + 1;
	  needDay = (tmpB[to_attack_id] - 1) / (a_b[j ^ 1]) + 1;
	  if (needDay > bNeedDay) {
	    return false;
	  } else {
	  }
	}
	if ((b_a[0][j] + b_a[1][j]) * k > a[j])
	  break;
      }
    }
  }
  return true;
}

bool play() {
  for (int i = 0; i <= 1; i ++) {
    for (int j = 0; j <= 1; j ++) {
      for (int k = 0; k <= 100; k ++) {
	int needDay = (max(0, b[j] - (a_b[0][j] + a_b[1][j]) * k) - 1) / a_b[i][j] + 1;
	needDay += k;
	bool result = otherPlay(i, j, k, needDay);
	if (result == true)
	  return true;
	if ((a_b[0][j] + a_b[1][j]) * k > b[j])
	  break;
      }
    }
  }
}

void work(){
  bool a_first, b_first;
  scanf("%d%d", &a[0], &a[1]);
  scanf("%d%d", &a[0], &b[1]);
  for (int i = 0; i <= 1; i ++) {
    for (int j = 0; j <= 1; j ++) {
      scanf("%d", &a_b[i][j]);
    }
  }
  for (int i = 0; i <= 1; i ++) {
    for (int j = 0; j <= 1; j ++) {
      scanf("%d", &b_a[i][j]);
    }
  }
  a_first = play();
  for (int i = 0; i <= 1; i ++)
    swap(a[i], b[i]);
  for (int i = 0; i <= 1; i ++) {
    for (int j = 0; j <= 1; j ++) {
      swap(a_b[i][j], b_a[i][j]);
    }
  }
  b_first = play();
  if (a_first && b_first) {
    printf("It depends\n");
  } else if (!a_first) {
    printf("Bob wins\n");
  } else if (!b_first) {
    printf("Alice wins\n");
  }
}

int main(){
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; ++i) {
    work();
  }
}

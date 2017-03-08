#include<bits/stdc++.h>

using namespace std;

const int MAXN = 6e4+6;

int n;
int x[MAXN];
int v[MAXN];

using LL = long long;

struct FRIEND{
	LL x, v;	
}fri[MAXN];

int check(double tim){
	double minL = 1e16;
	double maxL = -1;
	for (int i = 0; i < n; ++i) minL = min(minL, fri[i].x + fri[i].v * tim);
	for (int i = 0; i < n; ++i) maxL = max(maxL, fri[i].x - fri[i].v * tim);
	if (maxL > minL) return 0;
	return 1;
}

int work(){
	if (scanf("%d", &n) != 1) return 0;
	for (int i = 0; i < n; ++i) scanf("%I64d", &fri[i].x);
	for (int i = 0; i < n; ++i) scanf("%I64d", &fri[i].v);
	double l = 0, r = 1e10;
	for (int i = 0; i < 1000; ++i) {
		double mid = (l + r) / 2;
		int flag = check(mid);
		if (flag) r = mid;
		else l = mid;
	}
	
	printf("%.20lf\n", r);

	return 1;
}

int main(){
	while (work());
	return 0;
}

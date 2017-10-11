#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

const int MAXN = 310;
const int MAXM = 310;
const int MAXVAL = 1e8;
const int MINVAL = -1 * MAXVAL;

int a[MAXN][MAXM], sum[MAXN], minLine[MAXN], F[MAXN], G[MAXN];
int N, M, P, res;

int main() {
	while (scanf("%d%d%d", &N, &M, &P) != EOF) {
		bool flag = false;
		int minVal = MAXVAL, minX = 0, minY = 0;
		for (int i = 1; i <= N; i ++) {
			for (int j = 1; j <= M; j ++) {
				scanf("%d", &a[i][j]);
				if (a[i][j] < P)
					flag = true;
				if (a[i][j] < minVal) {
					minVal = a[i][j];
					minX = i;
					minY = j;
				}
			}
		}
		if (N == 1 && M == 1) {
			res = max(a[1][1], P);
			printf("%d\n", P);
			continue;
		}
		if (!flag) {
			a[minX][minY] = P;
		}
		res = -MAXVAL;
		for (int i = 1; i <= N; i ++) {
			for (int k = 1; k <= M; k ++) {
				sum[k] = 0;
				minLine[k] = MAXVAL;
			}
			for (int j = i; j <= N; j ++) {
				F[0] = 0;
				G[0] = 0;
				for (int k = 1; k <= M; k ++) {
					sum[k] += a[j][k];
					minLine[k] = min(minLine[k], a[j][k]);
					F[k] = max(F[k - 1] + sum[k], sum[k]);
					G[k] = max(G[k - 1] + sum[k], F[k - 1] + sum[k] + (P - minLine[k]));
					G[k] = max(G[k], sum[k] + (P - minLine[k]));
					res = max(res, F[k]);
					res = max(res, G[k]);
				}
				/*
				cout << "=================" << endl;
				cout << i << " " << j << endl;
				for (int k = 1; k <= M; k ++)
					cout << sum[k] << " ";
				cout << endl;
				for (int k = 1; k <= M; k ++)
					cout << minLine[k] << " ";
				cout << endl;
				for (int k = 1; k <= M; k ++)
					cout << G[k] << " ";
				cout << endl;
				for (int k = 1; k <= M; k ++)
					cout << F[k] << " ";
				cout << endl;
				
				cout << "=================" << endl;
				*/
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x, y) memset(x, y, sizeof(x))
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b > a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b < a)a = b; }
const int N = 4010, M = 0, Z = 1e9 + 7, inf = 0x3f3f3f3f;
template <class T1, class T2>inline void gadd(T1 &a, T2 b) { a = (a + b) % Z; }
int casenum, casei;
 
 
int n, m, nn;
int x, y;
vector<int> a[N];
bool pick[N];
int sta[N], top;
bool dfs(int x)
{
    if(pick[x ^ 1]) return 0;
    if(pick[x]) return 1;
    pick[x] = 1;
    sta[++ top] = x;
    for(int i = a[x].size() - 1; ~ i; -- i){
        int y = a[x][i];
        if(!dfs(y)) return 0;
    }
    return 1;
}
bool solve()
{
    for(int i = 0; i < nn; i += 2) if(!pick[i] && !pick[i ^ 1]){
        top = 0;
        if(!dfs(i)){
            while(top) pick[sta[top --]] = 0;
            top = 0;
            if(!dfs(i ^ 1)) return 0;
        }
    }
    return 1;
}
 
int main()
{
  freopen("K.in","r",stdin);
  while (true) {
    if (scanf("%d%d", &n, &m) != 2) break;
    int flag = 0;
    nn = n * 2;
    for(int i = 0; i < nn; i ++) pick[i] = 0, a[i].clear();
    for(int i = 1; i <= m; i ++){
        scanf("%d%d", &x, &y);
        int xx = abs(x), yy = abs(y);
        xx *= 2; yy *= 2;
        xx --; yy --;
        if(x < 0 && y < 0) flag = 1;
        if(x < 0 && y < 0){
            a[xx].push_back(yy ^ 1);
            a[yy].push_back(xx ^ 1);
            //printf("%d %d\n", xx, yy ^ 1);
            //printf("%d %d\n", yy, xx ^ 1);
             
        }
        else if(x < 0 && y > 0){
            a[xx].push_back(yy);
            a[yy ^ 1].push_back(xx ^ 1);
            //printf("%d %d\n", xx, yy);
            //printf("%d %d\n", yy ^ 1, xx ^ 1);
             
        }
        else if(x > 0 && y < 0){
            a[yy].push_back(xx);
            a[xx ^ 1].push_back(yy ^ 1);
            //printf("%d %d\n", yy, xx);
            //printf("%d %d\n", xx ^ 1, yy ^ 1);
             
        }
        else if(x > 0 && y > 0){
            a[xx ^ 1].push_back(yy);
            a[yy ^ 1].push_back(xx);
            //printf("%d %d\n", xx ^ 1, yy);
            //printf("%d %d\n", yy ^ 1, xx);
             
        }
    }
    if(!flag){puts("-1"); continue;}
    if(!solve()) {puts("0"); continue;}
    int flag1 = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < nn; j ++){
            //a[i].clear();
            pick[j] = 0;
        }
        int xx = i * 2 - 1;
        //a[xx].push_back(xx ^ 1);
        a[xx ^ 1].push_back(xx);
         
        if(!solve()){
          flag1 = 1;
            puts("1"); break;
        }
        //a[xx].pop_back();
        a[xx ^ 1].pop_back();
    }
    if (flag1 == 0)
    puts("2");
  }
    return 0;
}

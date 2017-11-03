#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pb push_back
#define fi first 
#define se second 
#define mk(a,b)  make_pair((a), (b))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxN = 1900000+13;
const int maxE = 4000000+13;

struct Node {
  Node* ch[27];
  Node* fa;
  int id , endid;
  Node() {
    id = endid = 0;
    fa = NULL;
    for(int i = 0;i < 27; i++) ch[i] = NULL;
  };
}Npool[maxN], *Nptr, *rt;

int N, M;
char buffer[maxN];
int ind = 0;
int v[maxN];
queue< pair<Node*,int> > q;
int ans[maxN];

void insert_dic(char a[], int len) {
  Node *p = rt;
  for(int i = 0; i < len ; i++) {
    //cout << i << endl;
    int tt = a[i] - 'a';
    if(p->ch[tt] == NULL) {
      p->ch[tt] = new (Nptr++) Node();
      p->ch[tt]->fa = p;
      p->ch[tt]->id = ++ind;
    }
    p = p->ch[tt];
    //cout << "out " << endl;
  }
  //cout << "end part1 " << endl;
  Node *ed = p;
  p = rt;
  for(int i = 0; i < len ; i++) {
    int tt = a[i] - 'a';
    p = p->ch[tt];
    if(p->ch[26] == NULL) {
      p->ch[26] = ed;
    }
  }
  return ;
}

void insert_word(char a[],int len,int n) {
  Node *p = rt;
  for(int i = 0; i < len ; i++) {
    int tt = a[i] - 'a';
    if(p->ch[tt] == NULL) {
      p->ch[tt] = new (Nptr++) Node();
      p->ch[tt]->id = ++ind;
    }
    p = p->ch[tt];
  }
  ans[n] = p->id;
  p->endid = n;
  return ;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("B.in","r",stdin);
#endif
  memset(v,0,sizeof(v));
  memset(ans,0,sizeof(ans));
  scanf("%d", &N);
  scanf("%d", &M);
  Nptr = Npool;
  ind = 0;
  rt = new (Nptr++) Node();
  rt->id = ++ind;
  for(int i = 1; i <= N; i++) {
    scanf("%s", buffer);
    //cout << buffer << endl;
    insert_dic(buffer, strlen(buffer));
  }
  for(int i = 1; i <= M; i++) {
    scanf("%s", buffer);
    //cout << buffer << endl;
    insert_word(buffer, strlen(buffer) , i);
  }
  q.push(make_pair(rt,0));
  v[rt->id] = 1;
  int need = M;
  int kk = 0;
  while(!q.empty() && need > 0) {
    Node *p = q.front().first;
    int ta = q.front().second;
    if(p->endid != 0) {
      //ans[p->endid] = ta;
      need--;
    }
    q.pop();
    for(int i = 0; i < 27; i++) {
      if(p->ch[i] != NULL) {
        if(v[p->ch[i]->id] > 0) continue;
        q.push(make_pair(p->ch[i], ta+1));
        v[p->ch[i]->id] = ta+1;
      }
    }
    if(p->fa!=NULL) {
      if(v[p->fa->id] > 0) continue;
      q.push(make_pair(p->fa, ta+1));
      v[p->fa->id] = ta+1;
    }
  }
  for(int i = 1; i <= M; i++) {
    printf("%d\n", v[ans[i]]);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


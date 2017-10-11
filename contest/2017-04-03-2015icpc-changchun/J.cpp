#include <bits/stdc++.h>

using namespace std;

#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

typedef long long ll;
typedef unsigned long long ull;

const int maxN = 1000+13;
const int maxNode = 40000+13;
const int maxDigtal = 32;

struct Node {
  int id,n;
  Node* son[2];
  Node (){n = 0;son[0] = son[1] = NULL;};
  Node(int _id){id = _id; n = 0;son[0] = son[1] = NULL;};
}Npool[maxNode],*Nptr;

int T,N;
ll s[maxN];
ll p2[maxN];
int n2[maxN][maxDigtal];
Node *rt ;

void insert(int index) {
  Node *tp = rt;
  per(i, 0 ,maxDigtal) {
    tp->n++;
    int t2 = n2[index][i];
    if(tp->son[t2]!=NULL) {
      tp = tp->son[t2];
    }else {
      tp -> son[t2] = new (Nptr++) Node();
      tp = tp->son[t2];
    }
  }
  tp->n++;
  return ;
}
void del(int index) {
  Node *tp = rt;
  per(i, 0 ,maxDigtal) {
    tp->n--;
    int t2 = n2[index][i];
    tp = tp->son[t2];
  }
  tp->n--;
}

void init() {
  rt = new Node();
  Nptr = Npool;
}
int tn2[maxDigtal];

ll find(ll ts) {
  ll ret = 0;
  rep(i, 0, maxDigtal) {
    tn2[i] = ts&1;
    ts >>= 1;
  }
  Node *tp = rt;
  per(i, 0 ,maxDigtal) {
    int tt = tn2[i];
    int rtt = tt^1;
    if(tp->son[rtt]!=NULL && tp->son[rtt]->n > 0){
      ret += p2[i];
      tp = tp->son[rtt];
    } else {
      tp = tp->son[tt];
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//  freopen("J.in","r",stdin);
#endif
  p2[0] = 1;
  rep(i, 1, maxDigtal) p2[i] = p2[i-1] << 1;
  scanf("%d", &T);
  rep(cas, 1, T+1) {
    init();
    int ans = 0;
    scanf("%d", &N);
    rep(index, 1, N+1) {
      scanf("%lld", &s[index]);
      int tn = s[index];
      rep(i, 0, maxDigtal) {
        n2[index][i] = tn&1;
        tn >>= 1;
      }
      insert(index);
    }
    rep(i,1,N+1) {
      rep(j,i+1,N+1) {
        del(i);del(j);
        int ta = find(s[i]+s[j]);
        //cout << i << ' ' << j << ' ' << ta << endl;
        if(ta > ans) ans = ta;
        insert(i); insert(j);
      }
    }
    printf("%d\n", ans);
  }

  //cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


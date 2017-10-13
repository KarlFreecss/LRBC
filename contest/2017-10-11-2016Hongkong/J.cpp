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

const int MAX = 2;
const int MAXN = 2e5 + 100;
typedef struct Trie_Node {
  struct Trie_Node *fail;
  struct Trie_Node *next[MAX];
  int count;
  int stat;
  struct Trie_Node *resP;
  int res;
  int id;
} Trie;

Trie *Q[MAXN];
Trie Npool[MAXN], *Nptr;
char str[MAXN];
int head, tail, n;

void insert(Trie *root, char *word)
{
  Trie *p = root;
  int i = 0;
  while (word[i] != '\0') {
//    cout << "word = " << word[i] - '0' << " " << p->id << " " << endl;
    if (p->next[word[i] - '0'] == NULL) {
      Trie *temp = new (Nptr++) Trie;
      //Trie *temp = new Trie;
      for (int j = 0;j < MAX; j ++)
        temp->next[j] = NULL;
      temp->count = 0;
      temp->fail = NULL;
      temp->resP = NULL;
      temp->id = p->id * 2 + word[i] - '0';
//      cout << "id = " << temp->id << endl;
      p->next[word[i] - '0'] = temp;
    }
    p = p->next[word[i] - '0'];
//    cout << p->id << endl;
    i ++;
  }
  p->count = 1;
}
void build_ac(Trie *root) {
  root->fail = NULL;
  head = tail = 0;
  Q[head++] = root;
  while (head != tail) {
//    cout << head << " " << tail << endl;
    Trie *temp = Q[tail ++];
    Trie *p = NULL;
    for (int i = 0; i < MAX; i ++) {
//      cout << i << endl;
      if (temp->next[i] != NULL) {
//        cout << "*" << endl;
        if (temp == root) {
//          cout << "**" << endl;
          temp->next[i]->fail = root;
          temp->next[i]->count += temp->next[i]->fail->count;
        }
        else {
//          cout << "***" << endl;
          p = temp->fail;
          while (p != NULL) {
//            cout << "****" << endl;
            if (p->next[i] != NULL) {
//              cout << "*****" << endl;
              temp->next[i]->fail = p->next[i];
//              cout << "*****" << endl;
              temp->next[i]->count += temp->next[i]->fail->count;
 //             cout << "*****" << endl;
              break;
            }
            p = p->fail;
          }
          if (p == NULL) {
            temp->next[i]->fail = root;
            temp->next[i]->count += temp->next[i]->fail->count;
          }
        } 
        Q[head++] = temp->next[i];
//        cout << tail - 1 << " " << head - 1 << " " << i << endl;
      } else {
        if (temp != root)
          temp->next[i] = temp->fail->next[i];
      }
    }
    if (temp->count == 0)
      temp->stat = -3;
    else temp -> stat = 0;
  }
}
int getRes(Trie *temp) {
  if (temp->stat == -3) {
    int res = -100;
    temp->stat = -2;
    Trie *p;
    for (int i = 0; i < MAX; i ++) {
      p = temp;
//      while (p != NULL && p->next[i] == NULL)
//        p = p->fail;
      if (p->next[i] == NULL) {
        return -1;
      } else {
        int tmp = getRes(p->next[i]);
        if (tmp == -1)
          return -1;
        else if (res < tmp) {
          res = max(res, tmp);
          temp->resP = p->next[i];
          temp->res = i;
        }
      }
    }
    res ++;
//    cout << res << endl;
    temp->stat = res;
    return res;
  } else if (temp->stat == -2) {
    return -1;
  } else {
    return temp->stat;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("J.in","r",stdin);
#endif
  Nptr = Npool;
  scanf("%d", &n);
  Trie *root = new (Nptr++) Trie;
  //Trie *root = new Trie;
  root->count = 0;
  root->fail = NULL;
  root->resP = NULL;
  root->id = 1;
  for (int i = 0; i < MAX; i ++)
    root->next[i] = NULL;
//  cout << "===============" << endl;
  for (int i = 0; i < n; i ++) {
    scanf("%s", &str);
//    cout << str << endl;
    insert(root, str);
  }
//  cout << "===============" << endl;
  build_ac(root);
//  cout << "===============" << endl;
  int res = getRes(root);
//  cout << res << endl;
  if (res == -1) {
    printf("%d\n", res);
  } else {
    Trie *p = root;
    while (p->resP->stat != 0) {
      printf("%d", p->res);
      p = p->resP;
    }
    printf("\n");
  }

//  cout<<"time: "<<(ll)clock()*1000/CLOCKS_PER_SEC<<" ms"<<endl;

  return 0;
}


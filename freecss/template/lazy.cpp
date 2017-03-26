#include <bits/stdc++.h>

using namespace std;

const int inf = 0x7fffffff;
const int MAXN = 1e5+5;
int minTree[MAXN * 4];

using namespace std;
typedef long long LL;

struct treeNode{
	int l;
	int r;
    int v;
	int num;
    bool lazy;
};

struct segmentTree{
private:
	void build(const int l, const int r, const int index){
		node[index] = (treeNode){l, r, inf, l, 0};
		if (l == r) return;
		int mid = (l+r)>>1;
		build(l, mid, index<<1);
		build(mid+1, r, index<<1|1);
	}

public:
	treeNode node[MAXN*4];

	segmentTree(int n = MAXN){
		build(1, n, 1);
	}

	void insert(const int l, const int r, const int index, const int value){
		if (node[index].r < l || node[index].l > r) return;
	//	printf("insert : l = %d, r = %d, index = %d, value = %d\n", l, r, index, value);
	//	printf("insert : L = %d, R = %d\n", node[index].l, node[index].r);
		if (l <= node[index].l && r >= node[index].r && node[index].v >= value) {
			node[index].v = value;
			node[index].lazy = true;
			return ;
		}

		if (node[index].l == node[index].r) return;
		if (node[index].lazy) {
			insert(node[index<<1].l, node[index<<1].r, index<<1, node[index].v);
			insert(node[index<<1|1].l, node[index<<1|1].r, index<<1|1, node[index].v);
			node[index].lazy = 0;
		}
	
		int mid = (node[index].l + node[index].r) >> 1;
		if (l <= mid) insert(l, r, index<<1, value);
		if (r > mid) insert(l, r, index<<1|1, value);
	
	//	printf("L = %d, R = %d, index = %d, value = %d\n", node[index].l, node[index].r, index<<1, node[index<<1].v);
		//printf("L = %d, R = %d, index = %d, value = %d\n", node[index].l, node[index].r, index<<1|1, node[index<<1|1].v);

		if (node[index << 1].v <= node[index << 1|1].v) {
			node[index].v = node[index<<1].v;
			node[index].num = node[index<<1].num;
		} else {
			node[index].v = node[index<<1|1].v;
			node[index].num = node[index<<1|1].num;
		}
	}

	pair<int, int> query(const int l, const int r, const int index){
		//printf("query : l = %d, r = %d, index = %d\n", l, r, index);
	//	printf("query : l = %d, r = %d, value = %d, lazy = %d\n", node[index].l, node[index].r, node[index].v, node[index].lazy);
		if (node[index].l > r || node[index].r < l) return make_pair(inf, inf);
		if (node[index].l >= l &&
			node[index].r <= r) return make_pair(node[index].v, node[index].num);

		if (node[index].l == node[index].r)  return make_pair(inf, inf);
		if (node[index].lazy) {
			insert(node[index<<1].l, node[index<<1].r, index<<1, node[index].v);
			insert(node[index<<1|1].l, node[index<<1|1].r, index<<1|1, node[index].v);
			node[index].lazy = 0;
		}
		
		int mid = (node[index].l + node[index].r) >> 1;
		pair<int, int> tl = make_pair(inf, inf), tr = make_pair(inf, inf);
		if (l <= mid) tl = query(l, r, index<<1);
		if (r > mid) tr = query(l, r, index<<1|1);
		if (tl.first <= tr.first) return tl;
		else return tr;
	}
}st;

int check[102400];

int main(){
	srand(time(0));
	int n = 25600 + 5;

	for (int i = 1; i < 102400; ++i) {
		check[i] = inf;
	}

	for (int i = 0; i < n; ++i) {
		int l = rand() + 1;
		int r = rand() + l;
		int value = rand() + (n-i);
		//cout << l << ' ' << r << ' ' << value << endl;
		st.insert(l, r, 1, value);
		for (int i = l; i <=r; ++i) {
			if (check[i] > value) check[i] = value;
		}

		l = rand() + 1;
		r = rand() + l;
		//cout << l << ' ' << r << endl;
		int ans = 0x7fffffff;
		for (int i = l; i <= r; ++i) {
			if (ans > check[i]) ans = check[i];
		}
		int tmp = st.query(l, r, 1).first;
		if (ans != tmp)
		   	cout << "ans = " << tmp << ' ' << ans << endl;

	}

/*	int l, r, v;
	for (int i = 0; i < 5; ++i) {
		cin >> l >> r >> v;
		st.insert(l, r, 1, v);
		cin >> l >> r;
		cout << st.query(l, r, 1).first << endl;
	}*/
	return 0;
} 

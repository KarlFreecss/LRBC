#include<set>
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long ll;
set<ll> S;
vector<ll> V;

void work(){
    ll p;
    cin >> p;
    for (int i = -1100000; i < 1100000; ++i) {
    }
    puts("NO");
}

int main(){
    for (ll i = -1000000; i < 1000000; ++i) {
        S.insert(i * i * i);
        V.push_back(i * i * i);
    }


    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        work();
    }
    return 0;
}


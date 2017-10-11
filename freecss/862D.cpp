#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string str(n, '0');
    cout << string("? ") + str << endl;
    fflush(stdout);

    int l = 1, r = n;
    int stdD;
    int pos0 = -1, pos1 = -1;
    cin >> stdD;
    for (int i = 0; i < 16; ++i) {
        if (pos0 != -1 && pos1 != -1) {
            cout << "! " << pos0 << ' ' << pos1 << endl;
            fflush(stdout);
            break;  
        }
        int mid = (l + r) >> 1;
        string str(n, '0');
        for (int i = l - 1; i < mid; ++i) {
            str[i] = '1';
        }
        cout << "? " << str << endl;
        int d;
        cin >> d;
        if (stdD - (mid - l + 1) == d) {
            pos1 = l;
            l = mid + 1;
        } else if (stdD + (mid - l + 1) == d) {
            pos0 = l;
            l = mid + 1;
        } else r = mid;
    }
    return 0;
}

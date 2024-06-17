#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    public:
    vector<int> bit;
    int size;

    FenwickTree(int n) {
        size = n;
        bit.resize(n+1, 0);
    }

    void update(int id, int val) {
        while(id <= size) {
            bit[id] += val;
            id += id & -id;
        }
    }

    int query(int id) {
        int sum = 0;
        while(id > 0) {
            sum += bit[id];
            id -= id & -id;
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    FenwickTree ft(n);
    vector<int> arr(n+1, 0);

    for(int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        arr[i] = j;
        ft.update(i, j);
    }

    int q;
    cin >> q;
    while(q--) {
        int typeOfQuery;
        cin >> typeOfQuery;
        if(typeOfQuery == 1) {
            int l, r;
            cin >> l >> r;
            int ans = ft.query(r) - ft.query(l-1);
            cout << ans << endl;
        } else {
            int id, val;
            cin >> id >> val;
            ft.update(id, val - arr[id]);
            arr[id] = val;
        }
    }

    return 0;
}

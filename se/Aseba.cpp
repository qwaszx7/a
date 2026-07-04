#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> intersectar(const set<int>& a, const set<int>& b) {
    set<int> resultado;
    set<int>::const_iterator it = a.begin();
    while (it != a.end()) {
        if (b.count(*it)) resultado.insert(*it);
        it++;
    }
    return resultado;
}

int main() {
    int n; cin >> n;

    set<int> acum;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        set<int> sensor;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            sensor.insert(x);
        }
        if (i == 0) acum = sensor;
        else        acum = intersectar(acum, sensor);
    }

    bool primero = true;
    set<int>::iterator it = acum.begin();
    while (it != acum.end()) {
        if (!primero) cout << " ";
        cout << *it;
        primero = false;
        it++;
    }
    cout << "\n";
}

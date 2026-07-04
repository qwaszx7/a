#include <iostream>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> comun, siguiente;

    int m; cin >> m;
    for (int j = 0; j < m; j++) {
        int x; cin >> x;
        comun.insert(x);
    }

    for (int i = 1; i < n; i++) {
        cin >> m;
        siguiente.clear();
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            siguiente.insert(x);
        }
        set<int> tmp;
        set<int>::iterator it = comun.begin();
        while (it != comun.end()) {
            if (siguiente.count(*it)) tmp.insert(*it);
            it++;
        }
        comun = tmp;
    }

    bool primero = true;
    set<int>::iterator it = comun.begin();
    while (it != comun.end()) {
        if (!primero) cout << " ";
        cout << *it;
        primero = false;
        it++;
    }
    cout << "\n";
}

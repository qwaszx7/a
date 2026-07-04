#include <iostream>
#include <vector>
using namespace std;

struct Patrol {
    int N, k, M, MinShadow, MaxDanger;
    vector<int> P, S;
    vector<bool> usado;

    int backtrack(int paso, int ultimo_p, int sum_shadow, int sum_danger) {
        if (sum_danger > MaxDanger) return 0;
        if (paso == k) {
            if (sum_shadow >= MinShadow) return 1;
            return 0;
        }
        int total = 0;
        for (int i = 0; i < N; i++) {
            if (!usado[i] && (paso == 0 || abs(P[i] - ultimo_p) <= M)) {
                usado[i] = true;
                total += backtrack(paso + 1, P[i], sum_shadow + S[i], sum_danger + P[i]);
                usado[i] = false;
            }
        }
        return total;
    }
};

int main() {
    Patrol p;
    cin >> p.N >> p.k >> p.M >> p.MinShadow >> p.MaxDanger;
    p.P.resize(p.N); p.S.resize(p.N); p.usado.assign(p.N, false);
    for (int i = 0; i < p.N; i++) cin >> p.P[i] >> p.S[i];
    cout << p.backtrack(0, 0, 0, 0) << "\n";
}

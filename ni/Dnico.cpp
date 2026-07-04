#include <iostream>
#include <vector>
using namespace std;

int backtrack(int paso, int ultimo_p, int sum_shadow, int sum_danger,
              int N, int k, int M, int MinShadow, int MaxDanger,
              vector<int>& P, vector<int>& S, vector<bool>& usado) {
    if (sum_danger > MaxDanger) return 0;
    if (paso == k) {
        if (sum_shadow >= MinShadow) return 1;
        return 0;
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (!usado[i] && (paso == 0 || abs(P[i] - ultimo_p) <= M)) {
            usado[i] = true;
            total += backtrack(paso + 1, P[i], sum_shadow + S[i], sum_danger + P[i],
                               N, k, M, MinShadow, MaxDanger, P, S, usado);
            usado[i] = false;
        }
    }
    return total;
}

int main() {
    int N, k, M, MinShadow, MaxDanger;
    cin >> N >> k >> M >> MinShadow >> MaxDanger;
    vector<int> P(N), S(N);
    vector<bool> usado(N, false);
    for (int i = 0; i < N; i++) cin >> P[i] >> S[i];
    cout << backtrack(0, 0, 0, 0, N, k, M, MinShadow, MaxDanger, P, S, usado) << "\n";
}

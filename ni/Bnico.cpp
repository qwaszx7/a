#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> M(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> M[i][j];

    long long count = 0;
    for (int i = 0; i < R - 1; i++)
        for (int j = 1; j < C - 1; j++)
            if (M[i][j] == M[i+1][j-1] && M[i][j] == M[i+1][j+1])
                count++;

    cout << count << "\n";
}

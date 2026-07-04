#include <stdio.h>

int M[500][500];

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf("%d", &M[i][j]);

    long long count = 0;
    for (int i = 1; i < R; i++) {        // fila de las colas
        for (int j = 0; j < C - 2; j++) // cola izq en j, cola der en j+2
            if (M[i][j] == M[i][j+2] && M[i-1][j+1] == M[i][j])
                count++;
    }
    printf("%lld\n", count);
}

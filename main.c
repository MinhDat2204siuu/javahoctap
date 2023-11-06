#include <stdio.h>
#include <stdbool.h>

int n, m;
int a[11][11];
int ans1;
int ans = 0;

bool valid(int row, int col, int num) {
    for (int i = 1; i <= 9; i++) {
        if (a[row][i] == num || a[i][col] == num) {
            return false;
        }
    }

    int subgrid_start_row = 3 * ((row - 1) / 3);
    int subgrid_start_col = 3 * ((col - 1) / 3);

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[subgrid_start_row + i][subgrid_start_col + j] == num) {
                return false;
            }
        }
    }

    return true;
}

void xulydequy() {
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (a[x][y] == 0) {
                for (int z = 1; z <= 9; z++) {
                    if (valid(x, y, z)) {
                        a[x][y] = z;
                        xulydequy();
                        a[x][y] = 0;
                    }
                }
                return;
            }
        }
    }
    ans++;
}

int main() {
    m = 9;
    n = 9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    xulydequy();
    printf("%d\n", ans);
    return 0;
}

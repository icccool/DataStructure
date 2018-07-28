#include <stdio.h>
#define N 8
typedef struct _tag_Pos {
    int ios;
    int jos;
} Pos;

static int count = 0;
static char board[N+2][N+2];
static Pos pos[3] = {{ -1, -1}, { -1, 0}, { -1,  1}};

void display() {
    for (int i = 0;i < N + 2;i++) {
        for (int j = 0;j < N + 2;j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void init() {
    for (int i = 0; i < N + 2;i++) {
        board[0][i] = '#';
        board[i][N+1] = '#';
        board[i][0] = '#';
        board[N+1][i] = '#';
    }
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= N;j++) {
            board[i][j] = ' ';
        }
    }
}

int check(int i, int j) {
    int ret = 1;
    for (int p = 0;p < 3;p++) {
        int n = i;
        int m = j;
        while (ret && (board[n][m] != '#')) {
            n = n + pos[p].ios;
            m = m + pos[p].jos;
            ret = ret && (board[n][m] != '*');
        }
    }
    return ret;
}

void find(int i) {
    if (i > N) {
        count++;
        printf("Solution : %d \n", count);
        display();
    } else {
        for (int j = 1;j <= N;j++) {
            if (check(i, j)) {
                board[i][j] = '*';
                find(i + 1);
                board[i][j] = ' ';
            }
        }
    }
}

/* 8皇后问题 */
int main() {
    init();
    find(1);
    return 0;
}

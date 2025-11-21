#include <stdio.h>
#include <string.h>

int n, m;
int a[104][104];
int dist[104][104];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef struct {
    int y, x;
} Node;

Node queue[20004];
int front = 0, rear = 0;

void push(int y, int x) {
    queue[rear].y = y;
    queue[rear].x = x;
    rear++;
}

Node pop() {
    return queue[front++];
}

int empty() {
    return front == rear;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char s[104];
        scanf("%s", s);   // 공백 없는 문자열
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    memset(dist, 0, sizeof(dist));

    push(0, 0);
    dist[0][0] = 1;

    while (!empty()) {
        Node cur = pop();
        int y = cur.y;
        int x = cur.x;

        if (y == n - 1 && x == m - 1) break;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (dist[ny][nx] != 0) continue;
            if (a[ny][nx] == 1) {
                dist[ny][nx] = dist[y][x] + 1;
                push(ny, nx);
            }
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);
    return 0;
}

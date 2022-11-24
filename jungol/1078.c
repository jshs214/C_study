#include<bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int m, n, k, y, x, ret, ny, nx, t;
int rx1, ry1, rx2, ry2, rcnt, cnt;
int area[100];
int a[104][104] = { 0 };
bool visited[104][104];

void dfs(int y, int x) {
    visited[y][x] = 1;
    rcnt++;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 0 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = i; i < k; i++) {
        scanf("%d %d %d %d", &rx1, &ry1, &rx2, &ry2);
        for (int i = ry1; i < ry2; i++) {
            for (int j = rx1; j < rx2; j++) {
                a[i][j] = 1;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && !visited[i][j]) {
                ret++; dfs(i, j);
                area[cnt++] = rcnt;
                rcnt = 0;
            }
        }
    }
    cout << ret << '\n';
    sort(area + 0, area + cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d ", area[i]);
    }

    return 0;
}

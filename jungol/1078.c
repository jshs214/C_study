#include<stdio.h>

int map[101][101];
int checkmap[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int nx, ny;
int x1, x2, y1, y2;
int M, N, K;
int rcnt, cnt=0;

void setmap(int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
}
void make(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			map[i][j] = 1;
		}
	}
}


void check(int M, int N) {	//y, x
	checkmap[M][N] = 1;
	rcnt++;
	for (int k = 0; k < 4; k++) {
		ny = M + dy[k];
		nx = N + dx[k];
		if (ny <0 || nx <0 || ny>=M || nx >=N) continue;
		if (map[ny][nx] == 0 && checkmap[ny][nx] != 1) {
			check(ny, nx);
		}
	}
	return;

}

int main()
{
	int count=0;
	int result[100];
	scanf("%d %d %d", &M, &N, &K);
	
	setmap(M, N);

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		make(x1, y1, x2, y2);
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && checkmap[i][j] != 1) {
				count++;
				check(i, j);
				result[cnt++] = rcnt;
				rcnt = 0;
			}
		}
	}

	printf("%d\n", count);

	for (int i = 0; i < cnt; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}
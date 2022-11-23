#include <stdio.h>

int array[35] = { 0, };

void set()
{	
	array[2] = 1;
	array[3] = 2;
	for (int i = 4; i < 35; i++) {
		array[i] = array[i - 2] + array[i-1];
	}
}

int main() {
	set();

	int D, K;
	int A, B;	//첫날, 둘째 날
	int i, j;

	scanf("%d %d", &D, &K);

	for (i = 0; i < 100000; i++) {
		for (j = 1; j < 100000; j++) {
			if (array[D - 2] * i + array[D - 1] * j == K) {
				A = i;
				B = j;
				printf("%d %d", A, B);
				return 0;
			}
		}
	}
	return 0;
}
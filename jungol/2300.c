#include <stdio.h>
#include <stdlib.h>

int a, b;	//ù°, ��° ��
int min, max;

int main(){
	int n;
	int answer;
	scanf("%d", &n);	//�Է� �� �ݺ�

	int i, j;
	int* value = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}

	min = 0, max = n-1;

	while (value[min]<value[max]) {
		a = value[min];
		b = value[max];
		printf("%d %d\n", a, b);

		answer = value[min] + value[max];
		if (answer == 0){
			a = value[min];
			b = value[max];
			break;
		}
		else if (answer > 0)
			max--;
		else
			min++;
	}


	printf("%d %d", a, b);
	return 0;
}
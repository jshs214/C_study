#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int a[7][7];

int check(int input) {
	int bingo = 0, count = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == input)
				a[i][j] = 0;
		}
	}

	//����
	for (int j = 0; j < 5; j++) {
		count = 0;
		for (int i = 0; i < 5; i++) {
			if (a[j][i] == 0) {
				count++;
			}
			if (count == 5)
				bingo++;
			if (bingo >= 3)
				return 1;
		}
	}

	//����
	for (int j = 0; j < 5; j++) {
		count = 0;
		for (int i = 0; i < 5; i++) {
			if (a[i][j] == 0) {
				count++;
			}
			if (count == 5)
				bingo++;
			if (bingo >= 3)
				return 1;
		}
	}

	//�밢
	count = 0;
	for (int i = 0; i < 5; i++) {
		if (a[i][i] == 0)
			count++;
		if (count == 5)
			bingo++;
		if (bingo >= 3)
			return 1;
	}


	//�밢
	int y = 4;
	count = 0;
	for (int i = 0; i < 5; i++) {
		if (a[i][y--] == 0)
			count++;
		if (count == 5)
			bingo++;
		if (bingo >= 3)
			return 1;
	}

	return 0;
}

int main()
{
	int input;
	int call = 0, result = 0;

	int i, j;

	/* ���� �� ����� �Է� */
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < 25; i++) {
		scanf("%d", &input);
		call++;	//��ȸ�ڰ� �θ� ��

		result = check(input);
		if (result == 1) {
			printf("%d", call);
			return 0;
		}
	}


	return 0;

}
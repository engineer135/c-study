// �� �� �� ��� ��ȯ�ϴ°� �ƴ϶� �ε����� �����ص״ٰ� �������� �ѹ��� ��ȯ�Ѵ�.
// ��ø�� for������ ����

#include <stdio.h>

int main(void) {
	int aList[5] = { 30, 40, 10, 50, 20 };
	//int aList[5] = { 5, 2, 1, 0, 3 };
	//int aList[5] = { 5, 2, 1, 4, 0 };
	int i = 0, j = 0, nMinIndex = 0, nTmp = 0;

	//�ڵ� �ۼ�
	for (i = 0; i < 5; ++i) {
		printf("i=%d\n", i);
		nMinIndex = i;
		for (j = i+1; j < 5; j++) {
			printf("j====%d\n", j);
			
			if (aList[nMinIndex] > aList[j]) {
				nMinIndex = j;
			}	

			printf("nMinIndex====%d\n", nMinIndex);
			printf("aList[nMinIndex]====%d\n", aList[nMinIndex]);
			printf("aList[j]====%d\n", aList[j]);
		}

		if (nMinIndex != i) { // ���信 �ִ� if��.. �̰� ���� ������ �ڵ����� ���.. 
			nTmp = aList[i];
			aList[i] = aList[nMinIndex];
			aList[nMinIndex] = nTmp;
		}		
	}

	//�Ʒ� ����
	for (i = 0; i < 5; ++i)
		printf("%d\n", aList[i]);

	putchar('\n');
	return 0;
}

//��
// 10 20 30 40 50
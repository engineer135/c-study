// å�� ���� ����... ���� ���� �Ѱ��ΰ�...
#include <stdio.h>

int main(void) {
	int aList[5][5] = { 0 };
	int x = -1, y = 0, nCounter = 0;
	int i = 0, j = 0, nLength = 9, nDirection = 1;

	// �迭 ä��� ��� ������ 9 > 7 > 5 > 3 > 1 ������ ������. ���⼭ ����.. �� õ�鵥... ��� �̷� ������???
	for (nLength = 9; nLength > 0; nLength -= 2) {
		for (i = 0; i < nLength; ++i) {
			if (i < nLength / 2 + 1) {
				// ����/2+1�� ���� 5���� ������ ���η� �ְ�
				x += nDirection;
			}
			else {
				// �� �ܴ� ���η� ���� ����.. ��.. ���..
				y += nDirection;
			}
			aList[y][x] = ++nCounter;
		}
		// �ѹ� ��������, ������ �ٲ�Ƿ� ������ ������Ѵ�.. ����...;;
		nDirection = -nDirection;
	}

	for (i = 0; i < 5; ++i) {		
		for (j = 0; j < 5; ++j) {
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}

// �Ƹ���׿� �ڵ尡..
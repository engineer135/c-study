// 1  2  3  4  5
// 16 17 18 19 6
// 15 24 25 20 7
// 14 23 22 21 8
// 13 12 11 10 9

// ������ ������� ���� ä���. ���� ���ѽð� 180��¥�� ����!! ���ݱ����� �ְ��̵���!!
// �ݺ����� 4���̻� ����� �� ���� << �� ������ ũ��..
// 7�� 25�� ����!
// 9tl 15�� �Ϸ�.. �ٵ� �̰� �´� ������ �𸣰ڴ�...

// 0 1 2 ������
// 3 4 ������

// flag 1 ������
// 2 ��
// flag 3 �Ʒ���
// 4 ��

// i 0		 j 0 1 2 3 4
// i 1 2 3 4 j 4
// i 4		 j 3 2 1 0
// i 3 2 1	 j 0
// i 1		 j 1 2 3
// i 2 3	 j 3
// i 3		 j 2 1 
// i 2		 j 1 2
// end

// �̷������� ����..


#include <stdio.h>

int main(void) {
	
	int arr[5][5] = { 0 };
	int i = 0, j = 0, num = 1, nFlag = 1, iCounter = 4, jCounter = 4;

	for (num = 1; num < 26; ++num) {
		if (nFlag == 1) {
			printf("������ %d [%d][%d] \n", num, i, j);
			// ������
			arr[i][j] = num;
			if (jCounter == j) {
				nFlag = 3;
				jCounter--;
				i++;
			}
			else {
				j++;
			}
		}else if (nFlag == 3) {
			printf("�Ʒ��� %d [%d][%d] \n", num, i, j);
			// �Ʒ���
			arr[i][j] = num;
			if (iCounter == i) {
				nFlag = 2;
				iCounter--;
				j--;
			}
			else {
				i++;
			}
		}else if (nFlag == 2) {
			printf("������ %d [%d][%d] \n", num, i, j);
			printf("jCounter %d\n", jCounter);
			// ������
			arr[i][j] = num;
			if (i + j == 4) {
				nFlag = 4;				
				i--;
			}
			else {
				j--;
			}
		}else if (nFlag == 4) {
			printf("���� %d [%d][%d] \n", num, i, j);
			// ����
			arr[i][j] = num;
			if (iCounter + i == 4) {
				nFlag = 1;
				j++;				
			}
			else {
				i--;
			}
		}
	}

	for (i = 0; i < 5; ++i) {
		//printf("i==%d\n", i);		
		for (j = 0; j < 5; ++j) {
			printf("%d %d\n", i, j);
			printf("%d\n", arr[i][j]);
		}
	}


	return 0;
}
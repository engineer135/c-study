#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// arr[x][y]
	// arr[int**][int*]
	// TODO 1.�� ��ƺ��� ����غ���
	// TODO 2.CHAR ���� �� ��ƺ��� ����غ���

	// �ٵ� �� scanf_s�� ������ �μ��� ����� ������ �μ��� �ʹ� ���ٰ� �׷���? �װ� �´� ���� �ƴѰ�..??
	
	// 10:33 start ~ 11:26 end

	// arr[student][subject] �迭 �����, �� �޾Ƽ� ��±��� �غ���
	int studentCnt, subjectCnt, i, j;
	
	printf("�л� ���� �Է��ϼ���.\n");
	scanf_s("%d", &studentCnt, sizeof(int));
	
	// �л�����ŭ �迭 ����
	int **arr = (int**)malloc(sizeof(int*)*studentCnt);

	printf("���� ���� �Է��ϼ���.\n");
	scanf_s("%d", &subjectCnt, sizeof(int));

	// �������ŭ �迭 �����ؼ� �л� �迭�� ���
	// ù��° �迭�� �л� ����ŭ �����Ҵ� ���� �޸𸮸� ���
	// �ι�° �迭�� ���� ����ŭ �����Ҵ� ���� �޸𸮸� ��´�.
	// �ι�° �迭�� �����Ҵ� ���� �޸� �ּ��� �ڷ����� int* �̹Ƿ� 4����Ʈ�� ��� �а� ��.
	// �����Ҵ� ������ �޸� ũ�⸦ int * ����� ��ŭ �ް�, 4����Ʈ�� ��� ������ �� ���� �о�� �� ����.
	// �̴� ù��° �迭�� ��������. int** �̹Ƿ� 4����Ʈ�� ��� �� �л��� �о�´�.
	for (i = 0; i < studentCnt; i++) {
		arr[i] = (int*)malloc(sizeof(int*)*subjectCnt); // �� ������ �ٽ��� �ƴұ� ����
	}

	for (i = 0; i < studentCnt; i++) {
		for (j = 0; j < subjectCnt; j++) {
			printf("�л� %d �� ���� %d ������ �Է��ϼ���.\n", i, j);
			scanf_s("%d", &arr[i][j], sizeof(arr[i][j])); // ���⼭ ���� ���� ��� �κ�. 
			//arr[i][j] = *(*(arr + i)+j) �̹Ƿ� ���� ���� �����ڰ� �����Ƿ� �������� �ּҰ� �ƴ� �����Ͱ� ����Ű�� �ּ��� ���� ���´�.
			//���� �տ� &�� �ٿ��� ���� �ּҸ� �Ѱ������.
		}
	}

	for (i = 0; i < studentCnt; i++) {
		for (j = 0; j < subjectCnt; j++) {
			printf("�л� %d �� ���� %d ���� : %d \n", i, j, arr[i][j]);			
		}
	}
	
	// �����Ҵ� �޸� ����
	for (i = 0; i < studentCnt; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
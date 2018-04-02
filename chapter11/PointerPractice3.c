#include <stdio.h>
#include <stdlib.h> // maaloc
#include <string.h> // memset

int main(void) {
	// �����Ҵ�. ����� ������ �ݵ�� free�Լ��� ����������Ѵ�.
	int *pList = NULL;
	pList = malloc(sizeof(int) * 3);
	// 12����Ʈ ������ �޸𸮰� �����Ҵ�ȴ�. �ʱⰪ�� cd�� ����.
	
	// 0���� �ʱ�ȭ�ϰ� ������ memset �Լ�
	//memset(pList, 0, sizeof(int) * 3);
	
	// malloc + malloc �ѹ濡 �ϰ� ������ calloc �Լ�
	//pList = calloc(3, sizeof(int));

	// �޸� ���� �¿쿡 fd fd fd fd (4����Ʈ) �ٸ�����Ʈ�� ǥ�õǰ�, ���Ⱑ �����Ҵ�� �޸� �ڸ��Դϴ� ǥ�����ش�.
	// �� �ٸ�����Ʈ ������ ħ���ϸ� ������ �߻���.
	// ���� ��
	//*(((char*)pList) + 12) = 'A'; // fd�� ����.. free�Ҷ� ���� �߻�
	//*(((char*)pList) + 16) = 'A'; // fd�� �ȱ���.. �׷��� ������ �߻��ϳ�;; ������ ����;;
	*(((char*)pList) - 5) = 'A'; // fd�� �ȱ���.. �̰� ���� �ȳ� ������.

	free(pList);

	char str[10] = {"Hello~"};
	char *pstr = str;
	char *pstr2 = (char*)malloc(sizeof(char) * 10);

	printf("str ������ �ּ� ��� %p\n", str); //0018FEEC
	printf("str ������ ���� ��� %c\n", str); //H
	printf("str ������ ���ڿ� ��� %s\n", str); //Hello~

	// �Ʒ��� ���� ���̰� ����. �� ����ص���.. �����͵� ������� ���� ����ϸ� �׷��� ����� �ʴ�.
	printf("������ ������ ����Ű�� �ּ� ��� %p\n", pstr); //0018FEEC
	printf("������ ������ �ּ� ��� %p\n", &pstr); //0018FEE0
	printf("������ ������ ����Ű�� �ּ��� ���� ��� %c\n", *pstr); //H	
	printf("������ ������ ����Ű�� �ּ��� ���ڿ� ��� %s\n", pstr); //Hello~

	printf("%p\n", &pstr2);

	pstr2 = str;

	printf("%p\n", &pstr2);
	
	free(pstr2);

	return 0;
}
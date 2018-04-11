#include <stdio.h>
#include <string.h>

int main(void) {
	// ���ڿ� ��� �� �迭 �κ� �� ���ذ� �Ȱ��� �ٽ� �����غ��ϴ�.
	char aStr[] = {"Hello"};
	char bStr[] = {"World"};

	//aStr = bStr; // �̷��Դ� �ȵȴ�.
	//aStr = �ּҴϱ�.. �翬�� �ȵǴ� ����

	strcpy_s(aStr, sizeof(aStr), bStr); 

	printf("aStr===%s\n", aStr);

	// ����� ����
	// 1. �̸��� ������ �ʴ� ���ͷ� ���
	int num = 30 + 40;
	// 1. ���� 30, 40�� �޸� ������ ��� ���·� ����
	// 2. �� ����� ������� ���� ����
	// 3. ���� ��� 70�� ���� num�� ����
	// ���� num�� �޸� �Ҵ�� �޸� ������ '�̸�'�� ����. �̰��� ���ͷ� ��� or ���ͷ�.

	// 2. �̸��� ���ϴ� �ɺ��� ���(Const ���)
	
	
	// �迭�� �̸��� �����Ͷ�� �� �� �ִ�. ��, �� ���� �ٲ� �� ���� ��������� �������̴�.
	char testStr[] = {"Hi"}; // ���� ������ ���ڿ�
	char *pStr = "Hi"; // ��� ������ ���ڿ�
	// testStr ������ �� ��ü�� ���ڿ� ��ü�� �����ϴ� �迭�̰�
	// pStr ������ �޸𸮻� �ڵ����� ����� ���ڿ��� ù��° ���ڸ� �ܼ��� ����Ű���� �ִ� ������ ������.
	// 30+40�� ����� ����ȴٰ� �ߵ���, pStr ������ ������ ��� "Hi"�� ����������.
	// testStr�� ����ؼ� ���� 'H'�� ����� ��ġ�� ����Ű�� ���¿��߸� ������,
	// ������ ���� pStr�� �ٸ� ��ġ�� ����ų �� �ִ�. 
	// �̰� ���� ������ ������.

	// testStr = { "Hello" }; �Ұ�
	// testStr = &testStr[0]; �Ұ�

	printf("%s\n", pStr);
	pStr = "Hello"; //����. ����Ű�� ��� �޶���.
	printf("%s\n", pStr);
	pStr = &pStr[1]; //����. e�� ����Ŵ.
	printf("%s\n", pStr);

	// �̷� �κ��� ������ ���� C ���α׷����� �ξ� �� ���°� ����...

	return 0;
}
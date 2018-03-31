#include <stdio.h>

int main(void) {
	int nData = 10;
	int *pnData = &nData; // ���� x�� ����Ű��, int ���Ŀ� ���� ������ ���� ���� �� ����.
	printf("%p\n", pnData); // 007AFA48
	printf("%d\n", *pnData); // 10 ���
	*&nData = 20;
	printf("%p\n", &nData); // 007AFA48
	printf("%d\n", nData); // 20 ���

	// ���� �迭
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer; // �迭�� �̸��� �ּ��̹Ƿ�, & ��ȣ �ʿ� ����. �ٷ� ������ �� �ִ�. szBuffer = &szBuffer[0]
	int nLength = 0;

	// ���ڿ��� ���� �ǹ��ϴ� Null ���ڰ� �ɶ����� �ݺ�
	// �ټ��� �ݺ��ǰ���
	while (*pszData != '\0') {
		printf("%c \n", *pszData);
		// �����͸� �������� ��ĭ �̵���Ų��. ���⼱ char �� �������̹Ƿ� 1byte�� �̵��Ѵ�. int���̸� 4byte �� �̵��ϰ���!
		pszData++; // �� �κ��� �߿��� �κ�. �����ʹ� �����̹Ƿ� ����� ���� ���� ����ּҷ� ������ ������Ʈ�ϸ� �װ��� ���ο� �����ּҰ� �Ǿ� ������ ������ ������ �����ϴ�!
		nLength++;
	}

	//strlen() �Լ��� ���ڿ��� ����(����Ʈ ���� ũ��)�� ����Ѵ�
	printf("Length : %d\n", nLength); //5
	printf("Length : %d\n", strlen(szBuffer)); //5
	printf("Length : %d\n", strlen("World")); //5
	
	// Null ���ڰ� ������ ��ġ(�ּ�)���� ������ġ(�ּ�)�� ���� ���ڿ��� ���̸� �� �� �ִ�.
	printf("Length : %d\n", pszData - szBuffer); //5

	// �����ð��� �޸� �����Ҵ翡 ���ؼ� �˾ƺ���.

	return 0;
}
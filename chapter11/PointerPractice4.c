#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// �޸� ����

	int a = 0;
	int b = 2;
	a = b; // �̰� ����

	char szSrcBuf[12] = {"Hello"};
	char szDstBuf[12] = { 0 };

	//szSrcBuf = szDstBuf; // �̰� �ȵ�. szSrcBuf�� ����̱� ������ r-value��. 

	// �ܼ��� �ּҸ� ���� shallow copy
	char *pszData = NULL;
	pszData = szSrcBuf;

	// �����Ҵ� �� �ּҸ� ������ ��� memory leak �߻�
	char *pszData2 = malloc(sizeof(char) * 12);
	// �޸� �ּ� 0x034B68C0 �� �����Ҵ��.
	// &pszData2 = C0 68 4B 03 �� ����Ǿ�����. �����Ҵ�� �޸� �ּ�!

	//pszData2 = szSrcBuf; // �׷��� �̷��� shallow copy �ϴ� ����, szSrcBuf �ּҰ� ����Ǿ�, pszData2 �ּҰ� �����Ҵ�� �޸� �ּҰ� �ƴ� szSrcBuf�� ����Ű�� �ȴ�.
	//puts(pszData2); // Hello�� ����� �� ��. �̻��� �����.
	//free(pszData2); // ������ free�ϴ� ����, �����Ҵ�� �޸� �ּҰ� �ƴ� szSrcBuf �ּҸ� free�Ϸ��� �ϴ� ������ �߻��Ѵ�.
	
	// ������� ���� deep copy
	memcpy(pszData2, szSrcBuf, sizeof(szSrcBuf));
	puts(pszData2);
	free(pszData2); // �̷��� deep copy �ؾ� ������ ����ȴ�. �̷��� ���� �ȳ���.
	

	// ���ڿ� ��� ( Hello ���� ) �� PE image DATA ������ ����ȴ�. ���߿����� read only ����.
	// �׷��� �Ʒ��� ���� ��� same�� ���. ���� ���ڿ� �ּҴ� ��� ����. 
	char str[12] = {"Hello"};
	char *pstr = "Hello";

	// ���ڿ� �񱳰� �ƴ� �ּ� ��
	if (pstr == "Hello")
		puts("Same");
	else
		puts("Diff");

	char str2[12] = { "I am a boy." };
	char *pszFound = strstr(str2, "am"); // ���� �߰ߵ� �ּ� �ε����� ��ȯ�Ѵ�.
	int nIndex = pszFound - str2; // ����ּ� - �����ּ� = index

	printf("%d\n", nIndex);

	// ���⼭ ����ִ� �� �Ѱ���..
	// str2���� 49 20 61 6d 20 61 20 62 6f 79 2e 00 ���� ����Ǿ��ִµ�... ������ 00�� null����
	// 6d 61 20 49 �̰� 10������ ��ȯ�ϸ�, 1835081801 �̰�, �Ʒ�ó�� ������ �� puts�� ����ϸ� I am�� ��µȴ�.
	int nData = 1835081801; // �̰� I am �̴�.
	puts(&nData);
	// puts�� null ���� ���ö����� ����ϴµ�, �޸��߿� cc�� ������ ���ڷ� ���̶�� ���ڰ� ��µȴ�. I am�������� << �̷������� ���̴�. cc �ƽ�Ű �ڵ尪�� �� �����̱� ������.

	int nData2 = *((int*)str2); // int�� �����ͷ� ����ȯ ��, ���������ϸ�, �ش� �����Ͱ� ����Ű�� �ּ��� '��'�� �����Ƿ�...
	printf("%d\n", nData); // 1835081801 �� ��µ�. 

	// �����! �ڷ����̶� ���� ������ �޸𸮿� ����� ������ �ؼ��ϴ� ����̴�!

	return 0;
}
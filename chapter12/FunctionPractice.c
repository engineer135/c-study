#include <stdio.h>

// ���Ǻ� ������
#ifdef _UNICODE // unicode�� ���ǵǾ� �ִ� ���
#define TCHAR wchar_t
#else
#define TCHAR char
#endif

// call by value
int add1(int a, int b) {
	return a + b;
}

// call by reference
int add2(int *a, int *b) {
	return *a + *b;
}

// call by referennce �� ���� ��ǥ���� '��ȯ'�� �Լ��� ������ ��
void swap(int *pLeft, int *pRight) {
	// �� �ּ��� ���� ��ȯ�Ѵ�.
	int nTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = nTmp;
}

// ���ڿ� ���� �����ϴ� �Լ�
int getLength(const char *pszParam) {
	int nLength = 0;
	while (pszParam[nLength] != '\0') {
		nLength++;
	}

	return nLength;
}

// �߸��� �ּ� ���� �Լ� ��
int* getNum(void) {
	int nData = 10;
	return &nData; // �Լ��� ��ȯ�ϸ� �Ҹ��� �ڵ������� �ּҸ� ��ȯ�ϰ� �ִ�.
}

// ���ȣ��
void putData(char *pszParam) {
	if (*pszParam == '\0') {
		return;
	}

	// ���� �� ������ ������ �ٲٸ� ���ڿ��� �������� ��µ�
	putchar(*pszParam);

	//Sleep(500); // �ѱ��ھ� ǥ��Ǵ°� ���� ���� ���� �ɾ��ش�.

	// ���� ���ڸ� ����Ű�� �ּҸ� �Ű������� ���ȣ���Ѵ�.
	putData(pszParam + 1); // �޸� �ּ� �̵�..

	
}

int main(int argc, char* argv[]) {
	// stack ������ �׸��� ���� �����ϴ°� �߿�
	int a = 2, b = 3;
	printf("%d\n", add1(a, b)); 
	printf("%d\n", add2(&a, &b));

	printf("%d, %d\n", a, b); //2,3
	swap(&a, &b);
	printf("%d, %d\n", a, b); //3,2

	char *pszData = "Hello~";
	printf("%d\n", getLength("Hi")); // 2
	printf("%d\n", getLength(pszData)); // 6
	
	// �Լ����� �߿��� ���� �����Ҷ�, ��ȯ�� �ּҰ� ����Ű�� ��� �޸𸮴� �ݵ�� ��ȿ�� ���̾�� �Ѵ�!
	// ��, �ü���� ��ȯ�߰ų� �� ����� �޸𸮿� ���� �ּҸ� ��ȯ�ϸ� �ȵȴ�!
	int nResult;
	nResult = *getNum();
	//printf("%d\n", nResult); // warning C4172: ���� ���� �Ǵ� �ӽ�: nData�� �ּҸ� ��ȯ�ϰ� �ֽ��ϴ�. << ���� �߻�!

	// �̸� �����Ϸ��� ���������ӿ� ���� ���ذ� �ʿ�.

	// �ڵ������� ���� ���� �޸𸮸� ����Ѵ�. ex) �Լ��� �Ű����� or �������� ��
	// �Լ� ���ο� ����� ������ �Ű������� �⺻������ '����'�� ����Ѵ�.
	// �Լ����� �������� �����Ǿ�, ������ �������� ���δ�.
	// �Ű����� -> ���� ������ ���ÿ� ���̰�,
	// �Լ� �����ϸ�, ���ÿ� �ִ� �Լ��� �ű� ���� �������� �������. �ش� �������� �������� ��� ������ٴ� ���.
	// ���ÿ��� �ĺ��ڸ� �˻��� ���� ������ �� ������ �Ʒ������� �˻��Ѵ�. �׸��� �ִ� �Լ� ��ü ���������� �˻�. �׷��� ������ ������������ ã�´�.
	// �����Ҵ�� �޸𸮴� ���� ������ �ƴϹǷ� ������ ǥ���ϰ�, ���ÿ� �ִ� ������ ������ �������ش�.
	// ���� �� ������ ������ �����Ҵ�� �޸𸮿��� ����� ���� �������� �ʵ��� �Ű� �Ἥ �����ϴ°� �߿�!
	// free()�� ���ϰų�, ������ ������ ��ȯ���� �ʾ� �Լ� �Ҹ�� ������ ������� �Ǹ�, �޸� ����(memory leak)�� �߻��ϴ� ��!
	// ��������, ���������� ������ ������ ����ϴ� �������̹Ƿ� ���ð��� �����ϰ� ���� ������ ǥ��.

	// ���ȣ��. ���� �������� �� �����ִ� ������..
	putData("TestData");
	putchar('\n');

	// ���ȣ���� �����ϰ� ����.
	// ������ ������ 
	// 1. ���ÿ��� �ڵ������� �Ű����� ������ ���� �������� �����ϱ� ���� ���� �������� ���Ե�
	// 2. �Լ�ȣ�⿡ ���� ���α׷��� �帧�� ����ǰ�
	// 3. �Ű������� �����ϴ� ���굵 �����ؾ� ��.
	// -> �ݺ����� ���� �ξ� �� ���� ������ �����(�Լ� ȣ�⿡ ���ݵǴ� call overhead -> �̰� �����Ѱ� ��ũ�� -> �ζ��� �Լ�. �ڿ��� ��� )

	// ���� ũ��� 1MB �ۿ� �ȵǴµ�, �̰� ��� �ö󰡴ٺ��� ���İ��� �޸� ��뷮�� 80~90%���� ���� �� �ְ�, ���� �޸𸮸� ��� �����ϸ� Stack overflow�� �߻��ϱ⵵ �Ѵ�.
	// �ݺ������� �� �� �ִٸ� �ݺ������� ����.
	// ���ȣ�� �ϴ� ������ �ڵ尡 '����'������ ����
	// ������ tree �� �ٷ궧�� ��κ� ���ȣ���� ����ϰ�, �װ��� �´�!


	// ���ڿ��� ������ ���� �迭
	// char[n]
	// ���ڿ� ����� write �ȵǴ� read only��� ���̰�
	// const char[n] �� ����.
	// ������ �Ǵ� ��Ȳ�� �̸� �Է¹�����
	// ����ڰ� �Է��ϴ� ���������� ���ڿ��� ���������� �޸𸮿� �����ؾ� �ϴµ�, �̶� over�� �߻��� �� �ִ�. 
	// �ֳĸ� ����ڰ� �Է��ϴ� ���ڿ��� ���̸� �˼��� �����ϱ�!
	// �̰� Buffer overflow ����... �ɰ��� ���� ������ ������.
	// �׷��Ƿ� �׻� ���������� �����͸� '�˻�'�ϴ� ������ �� �ʿ��ϴ�. �̰� ��ť��Ƽ �ڵ�. _s ���� ��ť��Ƽ ���ڽ���(?) �Լ��� ��� �ϴ� ����... �ڼ��Ѱ� å�� ����.

	
	
	// �����ڵ� ���ڿ�
	// MBCS VS Unicoide
	// "Hello" VS L"Hello"
	// char[6] VS wchar_t[6] ms���� ���� ����
	// 1byte VS ucs16 = 2bytes �뷮�� �ι�.
	wchar_t wcsBuffer[12] = { L"Hello" }; // ������ؼ� ���� H0e0l0l0o0 �̷������� ������.. 24����Ʈ..

	puts(wcsBuffer); // H �̷��� �����°� �翬�ϴ�. �߰��� 0�� ��������~
	_putws(wcsBuffer); // Hello

	// �����ڵ� �ٷ� ���� �����ڵ� ���� �Լ��� ����.
	// ������Ʈ > �Ӽ� > ���� �Ӽ� > �Ϲ� > ���� ���� <<<< ���⼭ ���� ����. ������� �⺻�� �����ڵ�.
	// ���Ǻ� �������� ����غ���

	TCHAR ch;
	printf("%d\n", sizeof(TCHAR)); // ���������� �����ڵ��� ��� 2 ���, ���������� ��Ƽ ����Ʈ�� ��� 1 ���

	// ������� wchar_t ����ؾ�������.. �������� char.. 

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include ����
// void TestFunc(int nParam); �̰� Test.h ���Ϸ� �ű�ϴ�
#include "Test.h" // Test.h�� �ű� �� ��Ŭ����ؼ� ���

// ���Ǻ� ������ ����
//#define _DEBUG_

#ifdef _DEBUG_
#define MODMESSAGE "Debug Mode"
#else
#define MODMESSAGE "Realease Mode"
#endif
// ������ ��� ���� ������ _DEBUG ���� ����


// ��ũ�� ����
#define ADD(a,b)	(a+b) //��ũ��
#define ADD2(a,b)	a+b //��ũ�� ��ȣ�� �� ����� �Ѵ�. �ֳĸ� �׳� ġȯ�һ��̹Ƿ�..
#define PASTER(a,b) a##b //�ϳ��� �ٿ��ִ� ��ũ�� Ư��ȭ ������

// �ζ������� ����� ������ �տ� __inline �� �ٿ��ָ� ��.
int Add(int a, int b) {
	return a + b;
}

int main(void) {
	// #include, ��ũ��, �ζ��� �Լ� ���
	// �������ϱ� ���� 'ó��(�ڵ带 ����)'�ϴ� ��
	// �� ��ȣ�� �پ��ִ�.

	// ���Ǻ� ������
	// _DEBUG ���� ������ ���� �ٸ� �ڵ� �������Ѵ�.
	puts(MODMESSAGE);

	// .h������ ��� �����̴�. '����'�鸸 ��Ƴ��� ����.
	// #include <~~.h>	�����Ϸ� ������ �ִ� ���丮(�ý��� ���丮)���� �ش� ������ ã��
	// ������Ʈ > �Ӽ� > �����Ӽ� > VC++ ���丮 > ���Ե��丮
	// $(VC_IncludePath); 
	// $(WindowsSDK_IncludePath);

	// #include "~~.h"	���� ���丮���� ã��

	TestFunc(10);

	// ��ũ��
	// A�Լ��� B�Լ��� ȣ���ϰ� �Ǹ�
	// ���� �����ӿ� A, B ������ ���̴µ�, �̶� call overhead ����� �߻�(������ ����, �Ű����� ����, �帧(�Դ� ����..)�� ���õ� ������� ��� ��)
	// �ٵ� �̶� �Լ� ����� �ָ��� ���� �ڵ�.. �׸��� ���� ȣ��Ǹ�.. 
	// �����δ� �Լ� ��������� ���������δ� �Լ��� �ƴ� ������ ����� �� ������� ����� ���� �� ���� ������
	// �ؼ� ���°� ��ũ�ο���.
	// �ٵ� ���� ��ũ�� ��� �����ϸ� ���� ����.. �� �ʿ��Ҷ� ����..
	// ��� �ζ��� �Լ��� ����. �̰ɷ� �ȵǴ� �͸� ��ũ�η� ������.
	// ��ũ�� ���� ū ������ �Ű������� �ڷ����� ����! �Ǽ��ص� ��!

	printf("%d\n", ADD(3, 4)); // ��ũ��
	printf("%d\n", (3 + 4)); // �������ϸ� �̷������� �ٲ�. �Լ� ȣ���� ����!
	
	// ��ũ�ο� ��ȣ ������ ����� ����
	printf("%d\n", ADD2(3, 4) * 2); // 14�� �ƴ϶� 11�� ������!
	printf("%d\n", 3 + 4 * 2); // �������ϸ� �̷������� �ٲ�. �׳� �ܼ� ġȯ�̶�� ���� �ɵ�?

	int nData = 23;
	printf("%d\n", PASTER(nDa, ta)); // 23

	
	// �ζ��� �Լ�
	int nInput;
	scanf_s("%d", &nInput);
	printf("%d\n",Add(nInput, 4));
	// �𽺾�������� Ȯ���غ��� ���� �Լ� ȣ�� ���ϰ�, �����Ϸ��� add ó���ϰ� ����
	// ������ �Ӽ� > �����Ӽ� > c/c++ > ����ȭ > �ζ��� �Լ� Ȯ���� �⺻������ �Ǿ��ֱ� ����
	// �̰� ���������� �ٲٸ�, ������ �Լ� call �Ѵ�.
	// �����Ϸ��� �ζ������� ���� �� ������ ������ �˾Ƽ� ����. ¼��..
	// �̸�ó�� inline ���� �����. ����. ��������. �׷��� �̸��� �ζ��� �Լ�!
	// ��ũ�� ������ �����鼭 ��ũ���� ��� ������ �� ������ �ִ� ���� �ζ��� �Լ�. 
	// �׷��� ������ �ζ����� ����.
	// java�� c#�� VM�� �ϴϱ� �ζ��� �Լ� ������ �ʹ�. ��Ȯ���� ������.

	return 0;
}
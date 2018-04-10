#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TestFunc(int); //(����)����
int g_nData = 0; // �������� ���� �� ����

int main(void) {
	// ������ ��� ����̷� 2
	// �������� 3����
	// 1 const
	// 2 volatile
	// 3 typedef

	// �⺻������ 3�� ������ �ٸ�. 1,2�� ����
	// const �� volatile  ���̴� ����?

	// �����Ϸ�����, ������������ �� �������� �ش޶�� �ϴ� ��!
	// �����ð��� �����, �˾Ƽ� ������ ��ŵ�ߴ� ��Ȳ���� ��ŵ���� �ʰ� �Ϸ���
	// ������ volatile�� �ٿ��ָ� �ȴ�. �̷��� �ϸ�, ������ ���� ���� ���� �����ϵȴ�.
	// �̷��� �ϸ� �� ������ ���õ� ��� ���꿡 ���� �����Ϸ��� ����ȭ ��Ģ�� �������� ����.

	//int nResult = 0;
	volatile int nResult = 0;

	// �ǹ� ���� ����...
	for (int i = 0; i < 10; ++i) {
		nResult = 10; 
	}

	printf("nResult = %d\n", nResult);

	// ������ ����϶�
	/*
	010A1040  push        0Ah
	010A1042  push        offset string "nResult = %d\n" (010A20F8h)
	010A1047  call        printf(010A1010h)
	010A104C  add         esp, 8
	*/

	// ����� ����϶�
	/*
	int nResult = 0;
	011517CE  mov         dword ptr[nResult], 0

		for (int i = 0; i < 10; ++i) {
			011517D5  mov         dword ptr[ebp - 14h], 0
				011517DC  jmp         main + 37h(011517E7h)
				011517DE  mov         eax, dword ptr[ebp - 14h]
				011517E1  add         eax, 1
				011517E4  mov         dword ptr[ebp - 14h], eax
				011517E7  cmp         dword ptr[ebp - 14h], 0Ah
				011517EB  jge         main + 46h(011517F6h)
				nResult = 10;
			011517ED  mov         dword ptr[nResult], 0Ah
		}
	011517F4  jmp         main + 2Eh(011517DEh)

		printf("nResult = %d\n", nResult);
	011517F6  mov         eax, dword ptr[nResult]
		011517F9  push        eax
		011517FA  push        offset string "nResult = %d\n" (01157B30h)
		011517FF  call        _printf(01151334h)
		01151804  add         esp, 8
	*/

	// �׷��ٸ� �̷� ���� ���� �߻��ұ�??
	// ���⼭ nResult ������ ����� �޸� ������ '�ܺα��(���Ű���)' ���� write�� �ϴ� ���
	// ������ �� �𸣰ڴ�.. -_-




	// extern �ܺκ��� ����
	// c���� ���� �� ���Ǹ� ���� �ϱ⵵ �ϰ� ���� �ϱ⵵ �Ѵ�.
	// �Լ��� ��쿡��
	// �������� -> *.h ����
	// ���� -> *.c ����
	// �̰��� ��Ģ.
	// �ΰ��� ���ļ� c��� ���α׷��� �ϼ���
	// �����̶� ����?
	// ������ ���� - ����(�߻���) ������Ÿ�Ӷ� �߿�!
	// ���Ǵ� ���� - ����! ��ũŸ�ӿ� �̷�����!
	// ������ �ִµ� ���ǰ� ������, �����϶��� ���� ������ ��ũŸ�ӿ� ���� �߻�!
	// �����ڵ� LNK ��¼�� �ϴ� ����...
	// TestFunc(10);

	// �Լ��� UI / ��� �Լ��� ������ �� ����. ������ ����.
	// 1. ���� .c ���Ϸ� ������ �ڵ�����ϴ� �� (���� ������)
	// Hello.c / Test.c -(������)-> Hello.obj + Test.obj -(��ũ)-> Hello.exe
	// ���� ��� Hello.c�� TestFunc ������ �ְ�
	// Test.c�� TestFunc ���ǰ� �ִ� ���
	// ��Ŀ�� Hello.obj ���� �Լ� ���� �߰��ϸ�
	// TestFunc ���Ǹ� ã�Ƽ�, Test.obj�� ����! �� �� �ٽ� 
	// Hello.obj�� ���ƿͼ� ��ũ�� ���ش�. �ٴ��� �ϵ���...
	// �׷��� ���� Test2.c ��� ���Ͽ� �Ȱ��� �Լ����� ���ǵǾ��ִٸ�?????
	// ������ �ȵ�. ��ũ ���� �߻��Ѵ�.

	int a; //����
	int a = 10; //���� �� ����

	// g_nData��� �������� ������ ����, �ܺ� *.c���� ���� ������ extern�� �ٿ��ش�.
	// extern int g_nData; <<<< �̷��� �ϸ� �ܺ� *.c���� �̹� ����Ǿ� �ִ� g_nData ���������� �����´�.


	return 0;
}

// �Լ� ����
/*
void TestFunc(int nParam) {
	printf("%d\n", nParam);
}
*/
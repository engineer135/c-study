#include <stdio.h>
#include <windows.h>

// �Լ� ���� ����
//void PrintValue(int);
//#pragma comment(lib, "..\\Debug\\LibTest.lib")
// �ٵ� �̰� ���� ������ ����� �ϳ�??? LibTest.h ���� ���� �ű�� �ű�°� ���ڴ�!
#include "..\LibTest\LibTest.h" // �׸��� �̷��� ��Ŭ���!!

int main(void) {
	PrintValue(10);
	Sleep(3000); // �̰� ���ϸ� �ٷ� ����.. ���� ������?
	return 0;
}
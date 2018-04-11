#include <stdio.h>
#include <windows.h>

// 함수 원형 선언
//void PrintValue(int);
//#pragma comment(lib, "..\\Debug\\LibTest.lib")
// 근데 이걸 내가 일일이 써줘야 하나??? LibTest.h 파일 만들어서 거기다 옮기는게 좋겠다!
#include "..\LibTest\LibTest.h" // 그리고 이렇게 인클루드!!

int main(void) {
	PrintValue(10);
	Sleep(3000); // 이거 안하면 바로 꺼짐.. 무슨 차이지?
	return 0;
}
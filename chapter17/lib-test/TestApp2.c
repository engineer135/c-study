#include <stdio.h>
#include <windows.h>
#include "..\LibTest\LibTest.h"

// 이런식으로 사용 가능하므로 재사용성이 좋다.
int main(void) {
	PrintValue(30);
	Sleep(3000); // 이거 안하면 바로 꺼짐.. 무슨 차이지?
	return 0;
}
#include <stdio.h>
#include <string.h>

int main(void) {
	// 문자열 상수 및 배열 부분 잘 이해가 안가서 다시 정리해봅니다.
	char aStr[] = {"Hello"};
	char bStr[] = {"World"};

	//aStr = bStr; // 이렇게는 안된다.
	//aStr = 주소니까.. 당연히 안되는 거임

	strcpy_s(aStr, sizeof(aStr), bStr); 

	printf("aStr===%s\n", aStr);

	// 상수의 종류
	// 1. 이름을 지니지 않는 리터럴 상수
	int num = 30 + 40;
	// 1. 정수 30, 40이 메모리 공간에 상수 형태로 저장
	// 2. 두 상수를 기반으로 덧셈 진행
	// 3. 덧셈 결과 70을 변수 num에 저장
	// 변수 num과 달리 할당된 메모리 공간에 '이름'이 없다. 이것이 리터럴 상수 or 리터럴.

	// 2. 이름을 지니는 심볼릭 상수(Const 상수)
	
	
	// 배열의 이름은 포인터라고 볼 수 있다. 단, 그 값을 바꿀 수 없는 상수형태의 포인터이다.
	char testStr[] = {"Hi"}; // 변수 형태의 문자열
	char *pStr = "Hi"; // 상수 형태의 문자열
	// testStr 변수는 그 자체로 문자열 전체를 저장하는 배열이고
	// pStr 변수는 메모리상에 자동으로 저장된 문자열의 첫번째 문자를 단순히 가리키고만 있는 포인터 변수다.
	// 30+40이 상수로 저장된다고 했듯이, pStr 포인터 변수에 담는 "Hi"도 마찬가지임.
	// testStr은 계속해서 문자 'H'가 저장된 위치를 가리키는 상태여야만 하지만,
	// 포인터 변수 pStr은 다른 위치를 가리킬 수 있다. 
	// 이게 둘의 유일한 차이임.

	// testStr = { "Hello" }; 불가
	// testStr = &testStr[0]; 불가

	printf("%s\n", pStr);
	pStr = "Hello"; //가능. 가리키는 대상만 달라짐.
	printf("%s\n", pStr);
	pStr = &pStr[1]; //가능. e를 가리킴.
	printf("%s\n", pStr);

	// 이런 부분은 윤성우 열혈 C 프로그래밍이 훨씬 잘 나온것 같다...

	return 0;
}
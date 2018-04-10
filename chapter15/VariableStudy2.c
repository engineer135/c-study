#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TestFunc(int); //(원형)선언
int g_nData = 0; // 전역변수 선언 및 정의

int main(void) {
	// 변수와 상수 고급이론 2
	// 형한정어 3가지
	// 1 const
	// 2 volatile
	// 3 typedef

	// 기본적으로 3은 성질이 다름. 1,2만 보자
	// const 와 volatile  차이는 뭐지?

	// 컴파일러에게, 생략하지말고 꼭 컴파일을 해달라고 하는 것!
	// 이전시간에 배웠던, 알아서 루프문 스킵했던 상황에서 스킵하지 않게 하려면
	// 변수에 volatile을 붙여주면 된다. 이렇게 하면, 릴리즈 모드라도 생략 없이 컴파일된다.
	// 이러헥 하면 이 변수와 관련된 모든 연산에 대해 컴파일러가 최적화 규칙을 적용하지 않음.

	//int nResult = 0;
	volatile int nResult = 0;

	// 의미 없는 루프...
	for (int i = 0; i < 10; ++i) {
		nResult = 10; 
	}

	printf("nResult = %d\n", nResult);

	// 릴리즈 모드일때
	/*
	010A1040  push        0Ah
	010A1042  push        offset string "nResult = %d\n" (010A20F8h)
	010A1047  call        printf(010A1010h)
	010A104C  add         esp, 8
	*/

	// 디버그 모드일때
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

	// 그렇다면 이런 경우는 언제 발생할까??
	// 저기서 nResult 변수가 저장된 메모리 영역에 '외부기기(센거같은)' 직접 write를 하는 경우
	// 지금은 잘 모르겠다.. -_-




	// extern 외부변수 선언
	// c언어는 선언 및 정의를 따로 하기도 하고 같이 하기도 한다.
	// 함수인 경우에는
	// 원형선언 -> *.h 파일
	// 정의 -> *.c 파일
	// 이것이 원칙.
	// 두개가 합쳐서 c언어 프로그램이 완성됨
	// 선언이란 뭘까?
	// 선언은 공약 - 개념(추상적) 컴파일타임때 중요!
	// 정의는 이행 - 구현! 링크타임에 이뤄진다!
	// 선언은 있는데 정의가 없으면, 컴파일때는 오류 없지만 링크타임에 오류 발생!
	// 에러코드 LNK 어쩌구 하는 오류...
	// TestFunc(10);

	// 함수는 UI / 기능 함수를 나누는 게 좋다. 관리를 위해.
	// 1. 여러 .c 파일로 나눠서 코드분할하는 법 (분할 컴파일)
	// Hello.c / Test.c -(컴파일)-> Hello.obj + Test.obj -(링크)-> Hello.exe
	// 예를 들어 Hello.c에 TestFunc 선언이 있고
	// Test.c에 TestFunc 정의가 있는 경우
	// 링커가 Hello.obj 에서 함수 선언 발견하면
	// TestFunc 정의를 찾아서, Test.obj로 점프! 한 뒤 다시 
	// Hello.obj로 돌아와서 링크를 해준다. 바느질 하듯이...
	// 그런데 만약 Test2.c 라는 파일에 똑같은 함수명이 정의되어있다면?????
	// 조립이 안됨. 링크 오류 발생한다.

	int a; //선언
	int a = 10; //선언 및 정의

	// g_nData라는 전역변수 선언한 것을, 외부 *.c에서 쓰고 싶을때 extern을 붙여준다.
	// extern int g_nData; <<<< 이렇게 하면 외부 *.c에서 이미 선언되어 있는 g_nData 전역변수를 가져온다.


	return 0;
}

// 함수 정의
/*
void TestFunc(int nParam) {
	printf("%d\n", nParam);
}
*/
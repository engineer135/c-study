#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __stdcall GetMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax)nMax = b;
	if (c > nMax)nMax = c;
	return nMax;
}

// 함수 포인터 예제
// (int(*)(char*) 아래에서 카피한 소스는 즉
// int (*이름) (char*) 이 얘기임. 함수이름이 주소라는 사실을 기억하면 그리 어렵지 않다. (응?)
int TestFunc(char *pszParam) {
	return 0;
}

// 함수 포인터를 매개변수로 받는 함수
void MyTest( int(*pfTest)(char*), int nParam) {

}

// 각 항을 비교하는 함수
int MyCmp(const void *left, const void *right) {
	return *(int*)left - *(int*)right;
}

// 문자열 비교하는 함수
int MyStrCmp(const void *left, const void *right) {
	return strcmp(*(char**)left, *(char**)right);
}

// 함수포인터의 배열
//void(*pfList[3])(int);
void TestFunc1(int nParam) {
	printf("TestFunc1");
}
void TestFunc2(int nParam) {
	printf("TestFunc2");
}
void TestFunc3(int nParam) {
	printf("TestFunc3");
}

int main(void) {
	// 함수에 대한 고급 이론1
	// c 전문가가 되려면 반드시 알아야 할 챕터

	// 함수의 본질 또한 주소상수다.
	// 배열은 유도형 자료. 
	// 함수는 함수형 자료.
	// 반환형식 호출규칙 함수이름();
	
	// 코드 최적화 = 안해도 되는걸 찾아서 안하면 됨. 코드 군살 빼기

	// 함수 호출 규칙 calling convention
	// 스택은 선형 자료구조. 자료 입출력하는 곳이 한곳. push and pop. 입출력하는 곳이 두개면 queue.
	// main() -> TestFunc(int nParam)
	// TestFunc nParam
	//			b
	// main		a
	// TestFunc 작업이 완료되면 TestFunc는 스택에서 사라지고, 담겨있던 매개변수(nParam)도 사라진다.
	// 메모리 할당 해제가 자동으로 되는 거지.
	// 그래서 자동변수라고 부른다.

	// 호출규칙 정리
	// 매개변수 할당 해제(스택 정리)를 누가 할거냐 정해주는 것
	// 1. __cdecl (default) 비쥬얼 스튜디오 설정에서 설정 가능. 설정 > c/c++ > 고급 > 호출규칙
	// 씨디클러레이션~ 호출자(Caller)가 스택 정리(ESP Register=스택포인터가 한다.)
	int nResult = 10;
	GetMax(1, 2, 3);

	// 그럼 현재 스택프레임에는 아래서부터 nREsult, c, b, a, nMax 순으로 들어가 있음
	// 디스어셈블리를 보면 
	// 00CB1760  add         esp,0Ch <--- 이부분이 스택 정리하는 어셈블리어
	// 0C 는 12. 왜 12일까? 매개변수 int형 3개. 4*3=12
	// 이 라인이 main 함수 안에 있다.

	// 2. __stdcall 스탠다드콜. (win32 api등의 표준규약) 피호출자 함수가 정리한다.
	// 009F1765  add         esp,0CCh

	// 3. __fastcall 패스트콜.
	// 스탠다드콜과 거의 동일. 
	// 차이는 매개변수를 스택을 이용해 복사하지 않고 값을 레지스터에 넣어서 넘김. 속도가 쪼금 빨라짐.
	// 스탠다드콜은 ram(스택) 에서 ram(스택)으로 카피
	// 패스트콜은 레지스터 에서 ram(스택)으로 카피가 된다. 

	// 스탠다드콜, 패스트콜 언제 쓸까? -> 컴파일러가 결정. 고민하지 말자..

	// 그럼 이걸 왜 씀?
	// __cdecl은 호출자가 정리를 해야하므로 스택정리 코드가 덧붙어서 크기가 좀 커짐
	// 하지만 가변인자 함수를 지원해준다.
	// __stdcall은 스택을 정리하기 위한 명령어 한줄이 줄어든다.
	// 따라서 함수가 자주 불리는 환경에서 빠른 속도와 프로그램의 전체적인 사이즈를 줄여주게 됨.
	// __stdcall은 빠르지만, 가변인자를 받을 수 없다.
	// 그 이유는, 호출자 함수는 가변 인자의 스택 크기를 알지만
	// 피호출자 함수는 가변 인자의 스택 크기를 알 수 없기 때문




	// 포인터는 주소저장형식
	// 가리키는 대상의 형식이 int면 int *Ptr 이라고 쓰잖아?
	// 그렇다면 함수형식이라면 어떻게 써야 할까?
	// 아래는 동일하다. 함수 이름은 주소이므로! 배열이랑 똑같네..?
	void *pData = main;
	printf("%p\n", pData);
	printf("%p\n", main);

	TestFunc("");
	int nData = (int)TestFunc;
	// nData(); //이건 불가능
	((int(*)(char*))nData)(""); //이건 가능! 헐! 이게 무슨 말이냐..;;

	MyTest(TestFunc, 10); //이렇게도 호출이 됨! 매개변수로 함수를 넘김!


	// 그렇다면 역호출이란 뭘까?
	int aList[5] = { 20, 50, 10, 30, 40 };
	// 정렬을 하고 싶다
	qsort(aList, 5, sizeof(int), MyCmp); // 정렬이 되네!?

	// qsort() 함수는 철수가 만들고
	// main() 함수는 영희가 만듦
	// main에서 qsort call할때, MyCmp 주소를 매개변수로 넘기면,
	// qsort에서 MyCmp 함수를 콜백할 수 있다. 
	// 내가 만든 함수를 내가 call하지 않음. 
	// 그래서 어렵다. 흐름이 끊기거든!
	// 콜백함수는 결국 함수주소를 '등록'하는 것.

	for (int i = 0; i < 5; ++i) {
		printf("%d\n", aList[i]); // 10 20 30 40 50
	}

	// 유저레벨에서 함수 만들고 &함수를 커널에 등록해주면
	// 커널(os)가 주기적으로 call한다. 언제? 왜? 몇번이나 부르지? 모름. 커널이 안다.
	// 커널이 정한 규칙대로 등록을 해놓으면, 알아서 호출이 됨
	// 비동기적인 특성을 가짐

	// qsort함수는 왜 콜백 구조로 만들었을까?
	// qsort함수는 평균정렬속도가 가장 빠르다고 알려진 정렬 알고리즘임
	// '무엇'을 정렬하는데, 여기서 '무엇'인지에 따라 비교방법은 달라질 것이다.
	// 만약 배열이 int가 아닌 char* 라면
	char* strList[5] = {
		"황남빵",
		"바나나빵",
		"감자",
		"나비",
		"스타벅스",
	};

	qsort(strList, 5, sizeof(char*), MyStrCmp); // MyCmp 함수로는 당연히 정렬이 안된다!!! 

	for (int i = 0; i < 5; ++i) {
		printf("%s\n", strList[i]);
	}
	
	// 이렇게 하면 가능
	// 만약 정렬해야할것이 그림이라면? 사람 수대로 정렬하라...
	// 이건 비교로직과는 아무 관련이 없잖소?
	// 그래서 비교하는 방법은 당신이 짜세요.
	// 콜백함수는 인터페이스라고 볼 수 있음. 함수형 프로그래밍이네.

	// 함수포인터 + Lookup 배열 = 스위치문을 완벽 대체 가능
	void(*pfList[3])(int) = {
		TestFunc1, TestFunc2, TestFunc3
	}; // 함수에 대한 포인터 변수네.. 모양이 좀 어려워서 그렇지 별거 없다.
	int nInput;
	printf("호출할 함수 인덱스 입력하세요.\n");
	scanf_s("%d", &nInput);
	pfList[nInput](10); //이렇게도 호출 가능 ㅋ nInput에 따라 다른 함수를 호출한다. ^^
	// 자바스크립트로 하면 더 간단할듯... 

	return 0;
}
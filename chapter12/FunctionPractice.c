#include <stdio.h>

// 조건부 컴파일
#ifdef _UNICODE // unicode가 정의되어 있는 경우
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

// call by referennce 중 가장 대표적인 '교환'을 함수로 구현한 것
void swap(int *pLeft, int *pRight) {
	// 두 주소의 값을 교환한다.
	int nTmp = *pLeft;
	*pLeft = *pRight;
	*pRight = nTmp;
}

// 문자열 길이 리턴하는 함수
int getLength(const char *pszParam) {
	int nLength = 0;
	while (pszParam[nLength] != '\0') {
		nLength++;
	}

	return nLength;
}

// 잘못된 주소 전달 함수 예
int* getNum(void) {
	int nData = 10;
	return &nData; // 함수가 반환하면 소멸할 자동변수의 주소를 반환하고 있다.
}

// 재귀호출
void putData(char *pszParam) {
	if (*pszParam == '\0') {
		return;
	}

	// 다음 두 구문의 순서를 바꾸면 문자열이 뒤집어져 출력됨
	putchar(*pszParam);

	//Sleep(500); // 한글자씩 표기되는거 보기 위해 슬립 걸어준다.

	// 다음 글자를 가리키는 주소를 매개변수로 재귀호출한다.
	putData(pszParam + 1); // 메모리 주소 이동..

	
}

int main(int argc, char* argv[]) {
	// stack 프레임 그리는 법을 이해하는게 중요
	int a = 2, b = 3;
	printf("%d\n", add1(a, b)); 
	printf("%d\n", add2(&a, &b));

	printf("%d, %d\n", a, b); //2,3
	swap(&a, &b);
	printf("%d, %d\n", a, b); //3,2

	char *pszData = "Hello~";
	printf("%d\n", getLength("Hi")); // 2
	printf("%d\n", getLength(pszData)); // 6
	
	// 함수에서 중요한 것은 리턴할때, 반환한 주소가 가리키는 대상 메모리는 반드시 유효한 것이어야 한다!
	// 즉, 운영체제에 반환했거나 곧 사라질 메모리에 대한 주소를 반환하면 안된다!
	int nResult;
	nResult = *getNum();
	//printf("%d\n", nResult); // warning C4172: 지역 변수 또는 임시: nData의 주소를 반환하고 있습니다. << 에러 발생!

	// 이를 이해하려면 스택프레임에 대한 이해가 필요.

	// 자동변수는 스택 영역 메모리를 사용한다. ex) 함수의 매개변수 or 지역변수 등
	// 함수 내부에 선언된 변수와 매개변수는 기본적으로 '스택'을 사용한다.
	// 함수별로 스코프가 생성되어, 스택이 차곡차곡 쌓인다.
	// 매개변수 -> 변수 순으로 스택에 쌓이고,
	// 함수 리턴하면, 스택에 있는 함수와 거기 딸린 변수들이 사라진다. 해당 스코프의 변수들이 모두 사라진다는 얘기.
	// 스택에서 식별자를 검색할 때는 스택의 맨 위에서 아래쪽으로 검색한다. 그리고 최대 함수 몸체 스코프까지 검색. 그래도 없으면 전역변수에서 찾는다.
	// 동적할당된 메모리는 스택 영역이 아니므로 별도로 표시하고, 스택에 있는 포인터 변수와 연결해준다.
	// 따라서 이 포인터 변수와 동적할당된 메모리와의 연결된 끈이 끊어지지 않도록 신경 써서 개발하는게 중요!
	// free()를 안하거나, 포인터 변수를 반환하지 않아 함수 소멸시 변수도 사라지게 되면, 메모리 누수(memory leak)가 발생하는 것!
	// 정적변수, 전역변수는 데이터 영역을 사용하는 변수들이므로 스택과는 무관하게 별도 영역에 표시.

	// 재귀호출. 스택 프레임을 잘 보여주는 예랄까..
	putData("TestData");
	putchar('\n');

	// 재귀호출은 간편하고 좋다.
	// 하지만 단점은 
	// 1. 스택에는 자동변수나 매개변수 말고도 스택 프레임을 관리하기 위한 여러 정보들이 포함됨
	// 2. 함수호출에 의해 프로그램의 흐름도 변경되고
	// 3. 매개변수를 복사하는 연산도 수행해야 함.
	// -> 반복문에 비해 훨씬 더 많은 연산이 수행됨(함수 호출에 수반되는 call overhead -> 이걸 개선한게 매크로 -> 인라인 함수. 뒤에서 배움 )

	// 스택 크기는 1MB 밖에 안되는데, 이게 계속 올라가다보면 순식간에 메모리 사용량이 80~90%까지 오를 수 있고, 스택 메모리를 모두 소진하면 Stack overflow가 발생하기도 한다.
	// 반복문으로 할 수 있다면 반복문으로 하자.
	// 재귀호출 하는 이유는 코드가 '간결'해지기 때문
	// 하지만 tree 를 다룰때는 대부분 재귀호출을 사용하고, 그것이 맞다!


	// 문자열의 본질은 문자 배열
	// char[n]
	// 문자열 상수란 write 안되는 read only라는 것이고
	// const char[n] 과 같다.
	// 문제가 되는 상황은 이름 입력받을때
	// 사용자가 입력하는 가변길이의 문자열을 고정길이의 메모리에 저장해야 하는데, 이때 over가 발생할 수 있다. 
	// 왜냐면 사용자가 입력하는 문자열의 길이를 알수가 없으니까!
	// 이게 Buffer overflow 문제... 심각한 보안 결함을 동반함.
	// 그러므로 항상 가변길이의 데이터를 '검사'하는 과정이 꼭 필요하다. 이게 시큐리티 코딩. _s 붙은 시큐리티 인핸스드(?) 함수를 써야 하는 이유... 자세한건 책을 보자.

	
	
	// 유니코드 문자열
	// MBCS VS Unicoide
	// "Hello" VS L"Hello"
	// char[6] VS wchar_t[6] ms에서 만든 형식
	// 1byte VS ucs16 = 2bytes 용량이 두배.
	wchar_t wcsBuffer[12] = { L"Hello" }; // 디버그해서 보면 H0e0l0l0o0 이런식으로 들어가있음.. 24바이트..

	puts(wcsBuffer); // H 이렇게 나오는게 당연하다. 중간에 0이 들어가있으니~
	_putws(wcsBuffer); // Hello

	// 유니코드 다룰 때는 유니코드 전용 함수를 쓰자.
	// 프로젝트 > 속성 > 구성 속성 > 일반 > 문자 집합 <<<< 여기서 선택 가능. 윈도우는 기본이 유니코드.
	// 조건부 컴파일을 사용해보자

	TCHAR ch;
	printf("%d\n", sizeof(TCHAR)); // 문자집합이 유니코드인 경우 2 출력, 문자집합이 멀티 바이트인 경우 1 출력

	// 윈도우는 wchar_t 사용해야하지만.. 리눅스는 char.. 

	return 0;
}
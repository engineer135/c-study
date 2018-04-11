#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include 예제
// void TestFunc(int nParam); 이걸 Test.h 파일로 옮깁니다
#include "Test.h" // Test.h로 옮긴 후 인클루드해서 사용

// 조건부 컴파일 예제
//#define _DEBUG_

#ifdef _DEBUG_
#define MODMESSAGE "Debug Mode"
#else
#define MODMESSAGE "Realease Mode"
#endif
// 릴리즈 모드 쓰고 싶으면 _DEBUG 라인 삭제


// 매크로 예제
#define ADD(a,b)	(a+b) //매크로
#define ADD2(a,b)	a+b //매크로 괄호로 꼭 묶어야 한다. 왜냐면 그냥 치환할뿐이므로..
#define PASTER(a,b) a##b //하나로 붙여주는 매크로 특수화 연산자

// 인라인으로 만들고 싶으면 앞에 __inline 만 붙여주면 됨.
int Add(int a, int b) {
	return a + b;
}

int main(void) {
	// #include, 매크로, 인라인 함수 등등
	// 컴파일하기 전에 '처리(코드를 변형)'하는 것
	// 샵 기호가 붙어있다.

	// 조건부 컴파일
	// _DEBUG 정의 유무에 따라 다른 코드 컴파일한다.
	puts(MODMESSAGE);

	// .h파일은 헤더 파일이다. '선언'들만 모아놓은 파일.
	// #include <~~.h>	컴파일러 설정에 있는 디렉토리(시스템 디렉토리)에서 해당 파일을 찾음
	// 프로젝트 > 속성 > 구성속성 > VC++ 디렉토리 > 포함디렉토리
	// $(VC_IncludePath); 
	// $(WindowsSDK_IncludePath);

	// #include "~~.h"	현재 디렉토리에서 찾음

	TestFunc(10);

	// 매크로
	// A함수가 B함수를 호출하게 되면
	// 스택 프레임에 A, B 순으로 쌓이는데, 이때 call overhead 비용이 발생(스택의 증가, 매개변수 복사, 흐름(왔다 갔다..)과 관련된 제어관련 비용 등)
	// 근데 이때 함수 만들기 애매한 양의 코드.. 그리고 자주 호출되면.. 
	// 겉으로는 함수 모양이지만 내부적으로는 함수가 아닌 놈으로 만들면 이 오버헤드 비용을 줄일 수 있지 않을까
	// 해서 나온게 매크로에요.
	// 근데 이젠 매크로 사용 웬만하면 하지 말자.. 꼭 필요할때 빼고..
	// 대신 인라인 함수를 쓰자. 이걸로 안되는 것만 매크로로 만들자.
	// 매크로 가장 큰 문제는 매개변수에 자료형이 없다! 실수해도 모름!

	printf("%d\n", ADD(3, 4)); // 매크로
	printf("%d\n", (3 + 4)); // 컴파일하면 이런식으로 바뀜. 함수 호출이 없다!
	
	// 매크로에 괄호 없을때 생기는 문제
	printf("%d\n", ADD2(3, 4) * 2); // 14가 아니라 11이 나오네!
	printf("%d\n", 3 + 4 * 2); // 컴파일하면 이런식으로 바뀜. 그냥 단순 치환이라고 보면 될듯?

	int nData = 23;
	printf("%d\n", PASTER(nDa, ta)); // 23

	
	// 인라인 함수
	int nInput;
	scanf_s("%d", &nInput);
	printf("%d\n",Add(nInput, 4));
	// 디스어셈블리로 확인해보면 실제 함수 호출 안하고, 컴파일러가 add 처리하고 있음
	// 이유는 속성 > 구성속성 > c/c++ > 최적화 > 인라인 함수 확장이 기본값으로 되어있기 때문
	// 이걸 사용안함으로 바꾸면, 무조건 함수 call 한다.
	// 컴파일러가 인라인으로 만들 수 있을거 같으면 알아서 만듦. 쩌네..
	// 이름처럼 inline 으로 만든다. 한줄. 구문으로. 그래서 이름이 인라인 함수!
	// 매크로 단점은 없으면서 매크로의 모든 장점을 다 가지고 있는 것이 인라인 함수. 
	// 그러니 무조건 인라인을 쓰자.
	// java나 c#은 VM이 하니까 인라인 함수 없을듯 싶다. 정확하진 않지만.

	return 0;
}
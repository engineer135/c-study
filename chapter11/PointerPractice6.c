#include <stdio.h>

void PrintUser(char(*puser)[12]) {
	for (int i = 0; i < 3; ++i)
		puts(puser[i]);
}

void TestFunc(void) {
	static int nData = 10; // 지역 변수지만, 전역 변수처럼 작동한다. 다만, 접근성이 TestFunc() 함수 내부루 제한된 것 뿐!
	printf("%d\n", nData++);
}

int main(void) {
	// 포인터 대망의 마지막 시간
	// 다차원 배열에 대한 포인터

	// int *pnData;
	// 포인터에 대해 명심할 것
	// 1. *pnData 는 포인터 변수라는 뜻.
	// 2. int 대상 형식.

	// 다차원 배열 => 배열의 배열. 같은 형식의 자료가 여럿!
	// char[4][12] => 캐릭터형(char) 배열[12]이 [4]개 있다. 4행 12열.

	char astrList[2][12] = { "Hello","World" };
	char(*pstrList)[12] = astrList;
	// astlList에 대한 포인터의 선언 및 정의..! 희한하게 생겼다. -_- 그냥 봐서는 전혀 이해가 안가는 모양이다..;;
	// 자세히 살펴보면
	// astrList를 가리키는 포인터 변수를 만들자는 의도니까...
	char str[5] = { "test" };
	char *pstr = str; // 1차원 배열은 이렇게 했었지.. 이때는 포인터 변수에 배열 표시가 없는게 자연스럽게 느껴졌다. 그럼 2차원 배열은?
	// char *pstrList[12] = astrList; 이런식으로 [2]가 없어지고 [12]만 남는다. 왜 그럴까?
	// 처음에 나는 astrList의 1차원 배열[2]은 2차원 배열[12]을 가리키는 포인터라고 생각하고
	// char* *pstrList = astrList; 이렇게 포인터에 대한 포인터라고 하면 될거라고 생각했으나 틀렸다!!
	// str[5] 같은 1차원 배열은 그림으로 그려보면 [char][char][char][char][char] 이런 모양일 것이다.
	// 각각의 요소형식은 char다. 그래서 포인터 선언할때 char *pstr로 하는 것이다.
	// astr[2][12] 는 [char[12]][char[12]] 이런 모양의 메모리다.
	// 각각의 요소형식은? 바로 char[12]다.
	// 그래서 포인터 변수 선언할 때 
	// char[12] * 이렇게 쓰면 좋겠지만, 자리바꿈이 일어나서 char * [12]가 된다. 
	// 자리바꿈은 astrList[2][12]의 case와 같다. 가만 생각해보면 astrList[12][2]가 논리적으로 맞는 것처럼 보이지만 쓸때는 astrList[2][12]로 쓰는 것처럼 여기서도 자리바꿈이 일어난다.
	// char * [12] 라고 쓰면 1. char가 12개 있는 배열에 대한 포인터인지 2. char 포인터가 12개 있다는 건지 헷갈리기 때문에
	// char(*)[12] 이렇게 괄호로 묶어서 표기해준다.
	// 자리바꿈때문에 헷갈리지만.. 정 이해 안되면 그냥 외우자 -_-
	// 아까 자주 실수한다던 char* *pstrList = astrList; 이렇게 쓰려면, 실제로 astrList의 요소형식이 char*(포인터) 여야 한다. 그러면 포인터에 대한 포인터이므로 이렇게 쓰는게 맞다.
	
	puts(astrList[0]); //Hello
	puts(astrList[1]); //World

	puts(pstrList[0]); //Hello
	puts(pstrList[1]); //World

	// 실습
	char aListUser[3][12] = {
		"이마트",
		"홈플러스",
		"롯데마트",
	}; // 배열 안에 중괄호로 감싸지 않아도 되는구나..
	char (*paListUser)[12] = aListUser;
	PrintUser(paListUser);

	// 정적 변수 static
	TestFunc();
	TestFunc();
	TestFunc();

	// static은 동시성을 지원하기 어렵다. 신중히 사용해야한다.. 골치 아픈 경우가 많으므로 ㅠㅠ 나도 한번 삽질 했었지..
	
	
	return 0;
}
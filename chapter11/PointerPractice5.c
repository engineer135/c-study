#include <stdio.h>

int main(void) {
	// 포인터의 배열

	int aList[3] = { 0 };
	int *pList = aList;
	// 해석 순서
	// 1. *pList => pList는 포인터이다.
	// 2. int => 포인터가 가리키는 대상체는 int다.
	
	// ex) int** *ppList = 머시기; 
	// 위와 같은 경우 
	// 1. ppList는 포인터이다
	// 2. 가리키는 대상은 int 포인터 포인터이다.

	// 포인터의 문제는 선언시 형식은 있는데 대상에 대한 개수 개념이 없다. 대상에 대한 유효성 확인이 안된다.
	// int *pnData 포인터의 경우
	// &int 하나만 가리킬수도 있고(4byte)
	// &int int int 배열 형태(3개)를 가리킬수도 있다.(12byte)
	// 어찌 됐든 알 방법이 없음. 개발자가 알아서 잘 해야함.

	int* apList[5] = { 0 }; // int형 포인터 5개가 들어갈 배열 선언
	int* *ppList = apList; // 포인터 배열의 포인터 선언 및 정의

	// 근데 여기서 좀 짜증나는 부분이 있는데.. 이 별표의 위치가 너무 자유롭다.
	char *astrList[3] = {"Hello", "World", "String"}; //이것도 가능. 위 apList와 동일하다. char형 포인터 3개가 들어갈 배열 선언이 되는 것임.
	// Hello = char[6]이고 이 주소가 astrList 첫번재 주소에 들어간다.
	// World = char[6]이고 이 주소가 astrList 두번재 주소에 들어간다.
	// String = char[7]이고 이 주소가 astrList 세번재 주소에 들어간다.
	
	printf("%s\n", astrList[0]); //Hello
	printf("%s\n", astrList[1]); //World
	printf("%s\n", astrList[2]); //String

	printf("%s\n", astrList[0]+1); //ello 잘 생각해보자. astrList[0]은 Hello의 주소이고, 이 주소에 +1을 했으므로 상대주소 계산이 돼어 ello가 나옴. 이하 동일.
	printf("%s\n", astrList[1]+2); //rld
	printf("%s\n", astrList[2]+3); //ing

	// 결국 char* 배열은 논리적으로 char의 2차원 배열과 동일하다.
	printf("%c\n", astrList[0][3]); //l
	printf("%c\n", astrList[1][3]); //l
	printf("%c\n", astrList[2][3]); //i

	// *는 지정연산자
	int nData = 10; // 주소가 0x0101FB18 이라면
	//*(int*)0x0101FB18 = 20; // 이렇게 접근 가능. 똑같은 이야기임. 물론 이 주소가 stack 영역이 맞는 경우에만 가능. 난 해보니 예외 발생! 엑세스 위반 발생함.
	printf("%d\n", nData); //20
	//printf("%d\n", *(int*)0x0101FB18); //20

	// 위에 나온 astrList[0] 연산을 풀어 쓰면 *(astrList + 인덱스) 가 된다.
	// 이 코드를 말로 표현하면 astrList라는 기준주소에 인덱스만큼 떨어진 상대주소를 char*로 '지정'한다 라는 뜻
	// 왜 char*로 해석하는가? astrList 배열 각 요소의 자료형이 char* 이기 때문이지!

	// 정리해보면
	// 포인터 자료형 char* 에 간접지정 연산을 하면 *(char *) == char 이다. int nData = 10; int *pnData = &nData; *pnData = 20;
	// 포인터 자료형 char* * 에 간접지정 연산을 하면 *(char **) == char* 이다. int *ppnData = &pnData; 포인터에 대한 포인터
	// 포인터 자료형 char** * 에 간접지정 연산을 하면 *(char ***) == char** 이다. int** *pppnData = &ppnData; 포인터에 대한 포인터에 대한 포인터..
	// 헷갈리지 말자. 익숙해질때까지 보자~~

	//  다중 포인터는 내일 하자!

	return 0;
}
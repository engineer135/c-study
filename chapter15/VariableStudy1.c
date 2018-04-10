#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 전처리기를 사용한 상수 정의 방법
#define CUTOFF 70

void getNumber(int *pNum) {
	printf("input your number! : ");
	int num;
	scanf_s("%d", &num, sizeof(num));
	*pNum = num;
}

void printNumber(const int *pNum) {
	printf("your number is %d. \n", *pNum);
}

void getName(char *pszName, int nSize) { // write
	printf("input your name! : ");
	char szBuffer[32];
	gets_s(szBuffer, sizeof(szBuffer));
	strcpy_s(pszName, nSize, szBuffer);
}

void printName(const char *pszName) { // read only 이므로 const를 써주는게 좋다. 값이 바뀔리가 없으므로.
	printf("your name is %s. \n", pszName);
}

int main(void) {
	// 변수와 상수 고급이론 1
	// 15장의 핵심 키워드는 컴파일러가 '코드를 최적화'하는 방법에 대해 공부해봅니다.
	// 빌드 모드에는 
	// 1. 디버그 모드
	// 2. 릴리즈 모드
	// 디버그할땐 잘 되다가 릴리즈때 에러가 나는 이유는?
	// 컴파일러 최적화에 답이 있다.
	
	// 1번 덩어리
	// a = b+3;
	// c = a+2;

	// 2번 덩어리
	// x = 10+y;
	// z =  3 x;

	// 덩어리 안에서는 의존성이 존재한다. 따라서 위에서 아래로 순차적으로 컴파일 해야한다.
	// 하지만 1번 2번 덩어리들은 서로 의존성이 전혀 없다.
	// 이는 동시에 컴파일해도 괜찮다는 이야기

	int nResult = 0;

	for (int i = 0; i < 10; ++i) {
		nResult = 10;
	}

	printf("nResult = %d\n", nResult);
	
	// 위와 같은 코드는 10번을 돌든 100번을 돌든 nResult는 10이다.
	// 디스어셈블리를 통해 보면, 디버그 모드에서는 기계어로 반복문을 만들지만
	// 릴리즈 모드에서는 반복문 만드는 걸 그냥 스킵해버림. 최적화!
	// 컴파일러가 아주 똘똘하구나!!!
	// 최적화를 잘 하려면
	// 특정 변수에 대해 의존성이 존재하는 연산들을 구별할 줄 알아야한다.

	// 변수는 적을 수록 좋다.
	// why? 메모리때문이기도 하지만
	// 변수끼리의 조합(의존성)에서 오는 경우의 수가 기하급수적으로 올라가기 때문.
	// -> 최적화하기가 어렵다.

	// 최적화된 코드를 작성하기 위해 노력
	// -> 컴파일러가 최적화하기 좋게 코드 작성
	
	// 최적화의 방해 요소
	// 1. 변수가 많은 경우 >>> 최대한 변수 개수를 줄이자
	// 2. 포인터 사용 주의(자제) >>> 포인터가 가리키는 위치는 런타임때 결정(돌려봐야 안다)
	// 그래서 c++에서는 최적화를 위해 참조(상수화된 포인터)가 등장
	// 그러므로 const 키워드를 '잘' '자주' 써야한다.

	// 상수형 포인터
	int nData = 1;
	int nData2 = 2;
	//int *pnData = &nData;

	// 형한정어를 int 앞에 쓴 경우 pnData가 가리키는 대상을 상수화한다
	const int *pnData1 = &nData;
	pnData1 = &nData2; // 변경 가능

	// 형한정어를 포인터 변수 앞에 쓴 경우(c++과 흡사)
	int *const pnData2 = &nData;
	//pnData2 = &nData2; // 변경 불가

	char szName[32] = { 0 };
	getName(szName, sizeof(szName)); // 사이즈를 같이 넘기는게 바람직하다.
	printName(szName);

	int num = 0;
	getNumber(&num); // 그냥 num을 넘기면, 0이 나오네? java도 똑같다. 스택프레임을 떠올려보자. 포인터로 넘겨야함.
	// 그동안 java에서 됐던 이유는 포인터를 넘겨줬기 때문이구나.. 
	printNumber(&num); // 여기는 그냥 num 넘겨두 되고, 포인터 넘겨두 됨.. 데이터 크면 포인터만 넘기는게 나을듯?

	// 심볼릭 상수를 만드는 또 다른 방법은 전처리기 사용
	// 전처리기는 컴파일(전) 처리기라는 소리, 컴파일시 해당 변수를 replace하고 컴파일한다.
	printf("합격선은 %d\n", CUTOFF);

	return 0;
}
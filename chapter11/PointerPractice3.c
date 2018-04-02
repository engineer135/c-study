#include <stdio.h>
#include <stdlib.h> // maaloc
#include <string.h> // memset

int main(void) {
	// 동적할당. 사용이 끝나면 반드시 free함수로 해제해줘야한다.
	int *pList = NULL;
	pList = malloc(sizeof(int) * 3);
	// 12바이트 영역의 메모리가 동적할당된다. 초기값은 cd로 셋팅.
	
	// 0으로 초기화하고 싶으면 memset 함수
	//memset(pList, 0, sizeof(int) * 3);
	
	// malloc + malloc 한방에 하고 싶으면 calloc 함수
	//pList = calloc(3, sizeof(int));

	// 메모리 영역 좌우에 fd fd fd fd (4바이트) 바리케이트가 표시되고, 여기가 동적할당된 메모리 자리입니다 표시해준다.
	// 이 바리케이트 영역을 침범하면 에러가 발생함.
	// 오류 예
	//*(((char*)pList) + 12) = 'A'; // fd가 깨짐.. free할때 에러 발생
	//*(((char*)pList) + 16) = 'A'; // fd가 안깨짐.. 그래도 에러가 발생하네;; 이유가 뭐지;;
	*(((char*)pList) - 5) = 'A'; // fd가 안깨짐.. 이건 에러 안남 괜찮음.

	free(pList);

	char str[10] = {"Hello~"};
	char *pstr = str;
	char *pstr2 = (char*)malloc(sizeof(char) * 10);

	printf("str 변수의 주소 출력 %p\n", str); //0018FEEC
	printf("str 변수의 문자 출력 %c\n", str); //H
	printf("str 변수의 문자열 출력 %s\n", str); //Hello~

	// 아래와 같이 차이가 난다. 잘 기억해두자.. 포인터도 변수라는 점만 기억하면 그렇게 어렵지 않다.
	printf("포인터 변수가 가르키는 주소 출력 %p\n", pstr); //0018FEEC
	printf("포인터 변수의 주소 출력 %p\n", &pstr); //0018FEE0
	printf("포인터 변수가 가르키는 주소의 문자 출력 %c\n", *pstr); //H	
	printf("포인터 변수가 가르키는 주소의 문자열 출력 %s\n", pstr); //Hello~

	printf("%p\n", &pstr2);

	pstr2 = str;

	printf("%p\n", &pstr2);
	
	free(pstr2);

	return 0;
}
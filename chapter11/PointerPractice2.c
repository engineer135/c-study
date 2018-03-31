#include <stdio.h>

int main(void) {
	int nData = 10;
	int *pnData = &nData; // 변수 x를 가리키는, int 형식에 대한 포인터 변수 선언 및 정의.
	printf("%p\n", pnData); // 007AFA48
	printf("%d\n", *pnData); // 10 출력
	*&nData = 20;
	printf("%p\n", &nData); // 007AFA48
	printf("%d\n", nData); // 20 출력

	// 문자 배열
	char szBuffer[16] = { "Hello" };
	char *pszData = szBuffer; // 배열의 이름이 주소이므로, & 기호 필요 없다. 바로 저장할 수 있다. szBuffer = &szBuffer[0]
	int nLength = 0;

	// 문자열의 끝을 의미하는 Null 문자가 될때까지 반복
	// 다섯번 반복되겠지
	while (*pszData != '\0') {
		printf("%c \n", *pszData);
		// 포인터를 다음으로 한칸 이동시킨다. 여기선 char 형 포인터이므로 1byte씩 이동한다. int형이면 4byte 씩 이동하겠지!
		pszData++; // 이 부분이 중요한 부분. 포인터는 변수이므로 계산을 통해 얻은 상대주소로 정보를 업데이트하면 그것이 새로운 기준주소가 되어 인접한 정보에 접근이 가능하다!
		nLength++;
	}

	//strlen() 함수로 문자열의 길이(바이트 단위 크기)를 출력한다
	printf("Length : %d\n", nLength); //5
	printf("Length : %d\n", strlen(szBuffer)); //5
	printf("Length : %d\n", strlen("World")); //5
	
	// Null 문자가 지정된 위치(주소)에서 시작위치(주소)를 빼면 문자열의 길이를 알 수 있다.
	printf("Length : %d\n", pszData - szBuffer); //5

	// 다음시간엔 메모리 동적할당에 대해서 알아보자.

	return 0;
}
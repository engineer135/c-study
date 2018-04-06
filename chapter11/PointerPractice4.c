#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 메모리 복사

	int a = 0;
	int b = 2;
	a = b; // 이건 가능

	char szSrcBuf[12] = {"Hello"};
	char szDstBuf[12] = { 0 };

	//szSrcBuf = szDstBuf; // 이건 안됨. szSrcBuf는 상수이기 때문에 r-value다. 

	// 단순히 주소만 복사 shallow copy
	char *pszData = NULL;
	pszData = szSrcBuf;

	// 동적할당 후 주소만 복사한 경우 memory leak 발생
	char *pszData2 = malloc(sizeof(char) * 12);
	// 메모리 주소 0x034B68C0 에 동적할당됨.
	// &pszData2 = C0 68 4B 03 이 저장되어있음. 동적할당된 메모리 주소!

	//pszData2 = szSrcBuf; // 그런데 이렇게 shallow copy 하는 순간, szSrcBuf 주소가 복사되어, pszData2 주소가 동적할당된 메모리 주소가 아닌 szSrcBuf를 가르키게 된다.
	//puts(pszData2); // Hello는 출력이 잘 됨. 이상이 없어보임.
	//free(pszData2); // 하지만 free하는 순간, 동적할당된 메모리 주소가 아닌 szSrcBuf 주소를 free하려고 하니 에러가 발생한다.
	
	// 내용까지 복사 deep copy
	memcpy(pszData2, szSrcBuf, sizeof(szSrcBuf));
	puts(pszData2);
	free(pszData2); // 이렇게 deep copy 해야 내용이 복사된다. 이러면 에러 안난다.
	

	// 문자열 상수 ( Hello 같은 ) 는 PE image DATA 영역에 저장된다. 그중에서도 read only 영역.
	// 그래서 아래와 같은 경우 same이 뜬다. 동일 문자열 주소는 모두 같다. 
	char str[12] = {"Hello"};
	char *pstr = "Hello";

	// 문자열 비교가 아닌 주소 비교
	if (pstr == "Hello")
		puts("Same");
	else
		puts("Diff");

	char str2[12] = { "I am a boy." };
	char *pszFound = strstr(str2, "am"); // 문자 발견된 주소 인덱스를 반환한다.
	int nIndex = pszFound - str2; // 상대주소 - 기준주소 = index

	printf("%d\n", nIndex);

	// 여기서 재미있는 것 한가지..
	// str2에는 49 20 61 6d 20 61 20 62 6f 79 2e 00 값이 저장되어있는데... 마지막 00은 null문자
	// 6d 61 20 49 이걸 10진수로 변환하면, 1835081801 이고, 아래처럼 저장한 후 puts로 출력하면 I am이 출력된다.
	int nData = 1835081801; // 이게 I am 이다.
	puts(&nData);
	// puts는 null 문자 나올때까지 출력하는데, 메모리중에 cc가 있으면 한자로 경이라는 문자가 출력된다. I am儆儆儆儆 << 이런식으로 말이다. cc 아스키 코드값이 저 문자이기 때문임.

	int nData2 = *((int*)str2); // int형 포인터로 형변환 후, 간접지정하면, 해당 포인터가 가르키는 주소의 '값'이 나오므로...
	printf("%d\n", nData); // 1835081801 가 출력됨. 

	// 결론은! 자료형이란 일정 길이의 메모리에 저장된 정보를 해석하는 방법이다!

	return 0;
}
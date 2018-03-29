// 분기 처리 대신 배열로 선택이라는 개념을 구현해보자
// 이처럼 정보검색 기능을 목적으로 한 배열을 lookup 배열이라 한다.

#include <stdio.h>

int main(int argc, char* argv[]) {
	// 과금률 결과를 담은 배열의 선언 및 정의
	double aRate[10] = {
		0.0, 0.1, 0.25, //1~3세 0%, 10%, 25% 이하 모두 이런 개념
		0.5, 0.5,
		0.6, 0.65,
		0.8, 0.82, 0.97
	};
	int nAge = 0, i = 0, nFee = 1000;

	// 요금표 출력
	printf("요금표\n");
	for (i = 1; i <= 10; ++i) {
		printf("%d세 요금 : \t%d원\n", i, (int)(nFee*aRate[i - 1]));
	}
	putchar('\n');

	// 나이를 입력 받고 배열 인덱스 범위 내부로 값을 강제 조정한다.
	printf("나이를 입력하세요! : ");
	scanf_s("%d", &nAge);
	if (nAge < 1) nAge = 1;
	else if (nAge > 10) nAge = 10;

	printf("최종요금은 %d원\n", (int)(nFee*aRate[nAge - 1]));
	putchar('\n');
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 형 재선언 예
typedef unsigned int UINT;
// #define UINT unsigned int; // 전처리기로 해도 유사
// BUT 전처리기로 하는 경우 단순 치환
// typedef 는 진짜 자료형이 됨

// 열거형 상수
// 순서대로 값이 0, 1, 2 이렇게 정의됨
// 캐릭터 움직임을 나타내는 상수
enum ACTION {MOVE, JUMP, ACTION};

// 열거형 상수 + 형 재선언
// 아래와 같은 경우 100, 101, 102 자동 증가
typedef enum COLOR {RED=100, GREEN, BLUE} COLOR;

int main(void) {
	// 변수와 상수 고급이론 3

	// 형 재선언 = 형 재정의
	// 형식 재선언이 필요한 일인가..?
	// 보통은 구조체 or 열거형 상수와 연계해서 사용
	// 하지만 기본형식은 재선언한다? 이거는 주의...자제해라. 큰일난다.
	// UINT nData; 이런식으로 'unsigned int'를 재정의 해서 쓴 경우
	// 코드의 가독성을 떨어뜨린다. 확인이 필요하니까.
	// LPARAM param; << 이건 뭐지? windows 프로그래밍에 있는 건데, long 형식임 ㅋ 왜 굳이 이렇게 -_-
	// 헝가리언 표기법 ms 사장
	// 변수 이름에서 '용도'가 드러나게 하라!
	// nData에서 n이 int...
	// 여기까진 좋은데 '형식'까지 드러나게 하자 이러다보니... 자료형 LPARAM 이런게 나옴..
	// 윈도우 프로그래밍 자료형이 아주 지랄스러움;; 그러니 도태되지...

	// 코딩 컨벤션
	// 구글 스타일 가이드를 참조하는게 좋다.

	// 체계적인 계획 하에 하자. 





	// 열거형 상수
	// 좋아요 이거
	// 정말 많이 쓰고 좋다.
	enum ACTION act = MOVE;
	printf("ACTION : %d\n", act); // 0

	COLOR color = GREEN;
	printf("GREEN : %d\n", color); // 101

	// 이런식으로 씁니다. 주석이 없어도 가독성이 매우 굿!
	switch (act) {
	case MOVE:
		printf("움직여라\n");
		break;
	case JUMP:
		printf("점프점프\n");
		break;
	case ACTION:
		printf("찔러!\n");
		break;
	}

	return 0;
}
// 책에 나온 정답... 나는 무얼 한것인가...
#include <stdio.h>

int main(void) {
	int aList[5][5] = { 0 };
	int x = -1, y = 0, nCounter = 0;
	int i = 0, j = 0, nLength = 9, nDirection = 1;

	// 배열 채우는 요소 개수가 9 > 7 > 5 > 3 > 1 순으로 끝난다. 여기서 착안.. 헐 천잰데... 어떻게 이런 생각을???
	for (nLength = 9; nLength > 0; nLength -= 2) {
		for (i = 0; i < nLength; ++i) {
			if (i < nLength / 2 + 1) {
				// 개수/2+1한 값이 5보다 작으면 가로로 넣고
				x += nDirection;
			}
			else {
				// 그 외는 세로로 값이 들어간다.. 헐.. 대박..
				y += nDirection;
			}
			aList[y][x] = ++nCounter;
		}
		// 한번 돌았으면, 방향이 바뀌므로 뺄셈을 해줘야한다.. 도랏...;;
		nDirection = -nDirection;
	}

	for (i = 0; i < 5; ++i) {		
		for (j = 0; j < 5; ++j) {
			printf("%d\t", aList[i][j]);
		}
		putchar('\n');
	}

	return 0;
}

// 아름답네요 코드가..
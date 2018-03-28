// 값 비교 후 즉시 교환하는게 아니라 인덱스만 저장해뒀다가 마지막에 한번만 교환한다.
// 중첩된 for문으로 구현

#include <stdio.h>

int main(void) {
	int aList[5] = { 30, 40, 10, 50, 20 };
	//int aList[5] = { 5, 2, 1, 0, 3 };
	//int aList[5] = { 5, 2, 1, 4, 0 };
	int i = 0, j = 0, nMinIndex = 0, nTmp = 0;

	//코드 작성
	for (i = 0; i < 5; ++i) {
		printf("i=%d\n", i);
		nMinIndex = i;
		for (j = i+1; j < 5; j++) {
			printf("j====%d\n", j);
			
			if (aList[nMinIndex] > aList[j]) {
				nMinIndex = j;
			}	

			printf("nMinIndex====%d\n", nMinIndex);
			printf("aList[nMinIndex]====%d\n", aList[nMinIndex]);
			printf("aList[j]====%d\n", aList[j]);
		}

		if (nMinIndex != i) { // 정답에 있던 if문.. 이게 좀더 섬세한 코딩이지 사실.. 
			nTmp = aList[i];
			aList[i] = aList[nMinIndex];
			aList[nMinIndex] = nTmp;
		}		
	}

	//아래 고정
	for (i = 0; i < 5; ++i)
		printf("%d\n", aList[i]);

	putchar('\n');
	return 0;
}

//예
// 10 20 30 40 50
// 1  2  3  4  5
// 16 17 18 19 6
// 15 24 25 20 7
// 14 23 22 21 8
// 13 12 11 10 9

// 달팽이 모양으로 숫자 채우기. 무려 제한시간 180분짜리 문제!! 지금까지중 최고난이도군!!
// 반복문을 4개이상 사용할 수 없음 << 이 제약이 크군..
// 7시 25분 시작!
// 9tl 15분 완료.. 근데 이게 맞는 답인지 모르겠다...

// 0 1 2 순방향
// 3 4 역방향

// flag 1 순방향
// 2 역
// flag 3 아래로
// 4 위

// i 0		 j 0 1 2 3 4
// i 1 2 3 4 j 4
// i 4		 j 3 2 1 0
// i 3 2 1	 j 0
// i 1		 j 1 2 3
// i 2 3	 j 3
// i 3		 j 2 1 
// i 2		 j 1 2
// end

// 이런식으로 진행..


#include <stdio.h>

int main(void) {
	
	int arr[5][5] = { 0 };
	int i = 0, j = 0, num = 1, nFlag = 1, iCounter = 4, jCounter = 4;

	for (num = 1; num < 26; ++num) {
		if (nFlag == 1) {
			printf("순방향 %d [%d][%d] \n", num, i, j);
			// 순방향
			arr[i][j] = num;
			if (jCounter == j) {
				nFlag = 3;
				jCounter--;
				i++;
			}
			else {
				j++;
			}
		}else if (nFlag == 3) {
			printf("아래로 %d [%d][%d] \n", num, i, j);
			// 아래로
			arr[i][j] = num;
			if (iCounter == i) {
				nFlag = 2;
				iCounter--;
				j--;
			}
			else {
				i++;
			}
		}else if (nFlag == 2) {
			printf("역방향 %d [%d][%d] \n", num, i, j);
			printf("jCounter %d\n", jCounter);
			// 역방향
			arr[i][j] = num;
			if (i + j == 4) {
				nFlag = 4;				
				i--;
			}
			else {
				j--;
			}
		}else if (nFlag == 4) {
			printf("위로 %d [%d][%d] \n", num, i, j);
			// 위로
			arr[i][j] = num;
			if (iCounter + i == 4) {
				nFlag = 1;
				j++;				
			}
			else {
				i--;
			}
		}
	}

	for (i = 0; i < 5; ++i) {
		//printf("i==%d\n", i);		
		for (j = 0; j < 5; ++j) {
			printf("%d %d\n", i, j);
			printf("%d\n", arr[i][j]);
		}
	}


	return 0;
}
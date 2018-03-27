#include <stdio.h>

int main(void)
{
    // 배열에서 최대값 구하기

    int aList[5] = {30, 40, 10, 50, 20};
    int i = 0;

    // 코드 작성
    for(int j=1; j < 5; ++j){
        if (aList[0] < aList[j]){
            aList[0] = aList[j];
        }
    }

    // 아래 코드는 고정
    for(i = 0; i < 5; ++i){
        printf("%d\n", aList[i]);
    }

    putchar('\n');

    printf("MAX : %d\n", aList[0]);
    return 0;
}
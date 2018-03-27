// 선택정렬로 알려진 버블정렬 구현
// 선택정렬은 값 교환을 마지막에 한번만 하고, 지금 하는 것은 즉시 교환하기 때문에 선택정렬로 알려진 버블정렬이다.
// 오름차순 정렬 ( 작은 값이 먼저 결정된다. )
// 인덱스0과 인덱스1 비교. 1이 작으면 0과 자리 바꿈. 0과 2 비교. 0 과 3 비교...
// 인덱스1과 인덱스2 비교. 이하 반복...

#include <stdio.h>

int main(void)
{
    int aList[5] = {30, 40, 10, 50, 20};
    int i=0, j=0, nTmp=0;

    // 여기 작성
    // 1. 중첩된 for문 사용
    // 제길 틀림;;;
    for(i=0;i<4;++i){
        for(j=i+1;j<5;++j){
            if(aList[j] < aList[i]){
                nTmp = aList[i];
                aList[i] = aList[j];
                aList[j] = nTmp;
            }
        }
    }

    // 아래는 고정
    for(i=0;i<5;++i)
        printf("%d\t", aList[i]);
    putchar('\n');
    return 0;
}

//예
//10 20 30 40 50
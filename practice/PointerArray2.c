#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// arr[x][y]
	// arr[int**][int*]
	// TODO 1.값 담아보고 출력해보기
	// TODO 2.CHAR 형태 값 담아보고 출력해보기

	// 근데 왜 scanf_s에 마지막 인수로 사이즈를 넣으면 인수가 너무 많다고 그러지? 그게 맞는 문법 아닌가..??
	
	// 10:33 start ~ 11:26 end

	// arr[student][subject] 배열 만들고, 값 받아서 출력까지 해보자
	int studentCnt, subjectCnt, i, j;
	
	printf("학생 수를 입력하세요.\n");
	scanf_s("%d", &studentCnt, sizeof(int));
	
	// 학생수만큼 배열 생성
	int **arr = (int**)malloc(sizeof(int*)*studentCnt);

	printf("과목 수를 입력하세요.\n");
	scanf_s("%d", &subjectCnt, sizeof(int));

	// 과목수만큼 배열 생성해서 학생 배열에 담기
	// 첫번째 배열에 학생 수만큼 동적할당 받은 메모리를 담고
	// 두번째 배열에 과목 수만큼 동적할당 받은 메모리를 담는다.
	// 두번째 배열에 동적할당 받은 메모리 주소의 자료형은 int* 이므로 4바이트씩 끊어서 읽게 됨.
	// 동적할당 받을때 메모리 크기를 int * 과목수 만큼 받고, 4바이트씩 끊어서 읽으면 한 과목씩 읽어올 수 있음.
	// 이는 첫번째 배열도 마찬가지. int** 이므로 4바이트씩 끊어서 한 학생씩 읽어온다.
	for (i = 0; i < studentCnt; i++) {
		arr[i] = (int*)malloc(sizeof(int*)*subjectCnt); // 이 로직의 핵심이 아닐까 싶음
	}

	for (i = 0; i < studentCnt; i++) {
		for (j = 0; j < subjectCnt; j++) {
			printf("학생 %d 의 과목 %d 점수를 입력하세요.\n", i, j);
			scanf_s("%d", &arr[i][j], sizeof(arr[i][j])); // 여기서 가장 많이 헤맨 부분. 
			//arr[i][j] = *(*(arr + i)+j) 이므로 간접 참조 연산자가 붙으므로 포인터의 주소가 아닌 포인터가 가리키는 주소의 값이 나온다.
			//따라서 앞에 &를 붙여서 실제 주소를 넘겨줘야함.
		}
	}

	for (i = 0; i < studentCnt; i++) {
		for (j = 0; j < subjectCnt; j++) {
			printf("학생 %d 의 과목 %d 점수 : %d \n", i, j, arr[i][j]);			
		}
	}
	
	// 동적할당 메모리 해제
	for (i = 0; i < studentCnt; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}
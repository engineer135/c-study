#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA
{
	unsigned int nHeight;
	char szName[12];
	char szPhone[12];
	unsigned char sex; // M or F
} USERDATA;

// 자기 참조 구조체
typedef struct LINKTEST
{
	char szName[12];
	char szPhone[12];
	unsigned char sex; // M or F
	struct LINKTEST *pNext; 
} LINKTEST;

// 구조체 맞춤 테스트용
// #pragma pack(push, 1)
typedef struct TESTDATA
{
	char ch;
	int nData;
} TESTDATA;


// 공용체
// 여러 개의 바이트 크기를 가지고 있는 변수를 쪼갤 때 공용체(union)를 사용한다.
// http://forum.falinux.com/zbxe/index.php?document_srl=796509&mid=lecture_tip 여기 참조하자.
typedef union _IP_ADDR
{
	int nAddress; //해석1
	short awData[2]; //해석2
	unsigned char addr[4]; //해석3
} IP_ADDR;

typedef struct MYDATA {
	char ch;
	int nData;
} MYDATA;

int main(void) {
	// 구조체와 공용체
	// c언어의 자료형은? 일정'길이'의 메모리에 저장된 정보를 '해석하는 방법'.
	// 배열 : 동일형식(자료형)의 연속(연접)된 '집합체'
	// 구조체 : 서로 같거나 '다른 형식들'의 연속된 집합체
	// 공용체 : 한 형식(같은 크기)에 '여러 해석방법을 부여'하는 문법

	// 구조체 선언 및 정의
	// 메모리를 꼭 따라가서 볼것! 중요! 디버거가 매우 잘 되어있음.
	// 메모리를 뜯어보면, 연속으로 저장되는 것을 확인할 수 있다.
	USERDATA a;
	a.nHeight = 180;
	strcpy_s(a.szName, sizeof(a.szName), "Bourne");
	strcpy_s(a.szPhone, sizeof(a.szPhone), "123-1234");
	a.sex = 'M';

	// 그럼 아래처럼도 가능하겠네?
	// 이렇게 응용하는 법을 알아야 합니다. 포인터는 절대권력이거든요.
	char buffer[sizeof(USERDATA)]; //구조체 크기의 배열 선언
	USERDATA *pData = (USERDATA*)buffer; //해당 배열을 포인터 변수로 지정
	pData->nHeight = 180;
	strcpy_s(pData->szName, sizeof(pData->szName), "Bourne");
	strcpy_s(pData->szPhone, sizeof(pData->szPhone), "123-1234");
	pData->sex = 'M';

	// 함수 호출시 구조체 그대로 넘기면, 스택프레임에 구조체 크기 메모리가 계속 쌓이므로 안좋다
	// 포인터로 넘겨야 한다.
	// 구조체 안에 포인터가 있고, 그 포인터가 자기 자신을 가리키는 자기 참조 구조체를 만들면
	// Single Linked List로 쓸 수 있다.
	LINKTEST user1 = { "person1", "1234", "M" };
	LINKTEST user2 = { "person2", "5678", "F" };
	user1.pNext = &user2;

	// 구조체 멤버 맞춤
	TESTDATA b;
	b.ch = 'A';
	b.nData = 300;

	printf("%d\n", sizeof(TESTDATA)); // 5바이트가 아닌 8바이트가 나옴!!
	// 이렇게 저장하면, 메모리에 연접하지 않고
	// 41 cc cc cc 2c 01 00 00 이런식으로 중간에 3바이트 낭비가 되게 된다. 헐!
	// 비쥬얼 스튜디오 설정 기본값 멤버 맞춤은 8바이트
	// 이를 피하려면 
	// #pragma pack(push, 1) 문구를 구조체 위에 추가해준다.
	// 이렇게 하면 1바이트씩 저장.. 3바이트 낭비 없어지지만 I/O 속도 느려진다. 이건 그냥 알고만 있자.


	// 공용체
	// 멤버중 가장 큰 놈 기준으로 메모리가 잡힌다.. 그리고 덮어쓰기 됨.. 희한한 녀석이네..
	IP_ADDR addr;
	addr.addr[0] = 192;
	addr.addr[1] = 168;
	addr.addr[2] = 0;
	addr.addr[3] = 10;
	printf("%d\n", addr.nAddress); //167815360

	// 구조체가 웃긴 점? 
	// 메모리만 보고는 이게 구조체다 확신할 수는 없음.. 그냥 추정만 할뿐. 리버싱할때 합리적 추론이 필요한 이유
	MYDATA myData;
	myData.ch = 'A';
	myData.nData = 300;

	// 위와 동일? 비슷?하게 메모리에 저장된다.
	char ch = 'B';
	char nData = 300;

	return 0;
}
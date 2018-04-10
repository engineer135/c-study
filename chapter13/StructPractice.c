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

// �ڱ� ���� ����ü
typedef struct LINKTEST
{
	char szName[12];
	char szPhone[12];
	unsigned char sex; // M or F
	struct LINKTEST *pNext; 
} LINKTEST;

// ����ü ���� �׽�Ʈ��
// #pragma pack(push, 1)
typedef struct TESTDATA
{
	char ch;
	int nData;
} TESTDATA;


// ����ü
// ���� ���� ����Ʈ ũ�⸦ ������ �ִ� ������ �ɰ� �� ����ü(union)�� ����Ѵ�.
// http://forum.falinux.com/zbxe/index.php?document_srl=796509&mid=lecture_tip ���� ��������.
typedef union _IP_ADDR
{
	int nAddress; //�ؼ�1
	short awData[2]; //�ؼ�2
	unsigned char addr[4]; //�ؼ�3
} IP_ADDR;

typedef struct MYDATA {
	char ch;
	int nData;
} MYDATA;

int main(void) {
	// ����ü�� ����ü
	// c����� �ڷ�����? ����'����'�� �޸𸮿� ����� ������ '�ؼ��ϴ� ���'.
	// �迭 : ��������(�ڷ���)�� ����(����)�� '����ü'
	// ����ü : ���� ���ų� '�ٸ� ���ĵ�'�� ���ӵ� ����ü
	// ����ü : �� ����(���� ũ��)�� '���� �ؼ������ �ο�'�ϴ� ����

	// ����ü ���� �� ����
	// �޸𸮸� �� ���󰡼� ����! �߿�! ����Ű� �ſ� �� �Ǿ�����.
	// �޸𸮸� ����, �������� ����Ǵ� ���� Ȯ���� �� �ִ�.
	USERDATA a;
	a.nHeight = 180;
	strcpy_s(a.szName, sizeof(a.szName), "Bourne");
	strcpy_s(a.szPhone, sizeof(a.szPhone), "123-1234");
	a.sex = 'M';

	// �׷� �Ʒ�ó���� �����ϰڳ�?
	// �̷��� �����ϴ� ���� �˾ƾ� �մϴ�. �����ʹ� ����Ƿ��̰ŵ��.
	char buffer[sizeof(USERDATA)]; //����ü ũ���� �迭 ����
	USERDATA *pData = (USERDATA*)buffer; //�ش� �迭�� ������ ������ ����
	pData->nHeight = 180;
	strcpy_s(pData->szName, sizeof(pData->szName), "Bourne");
	strcpy_s(pData->szPhone, sizeof(pData->szPhone), "123-1234");
	pData->sex = 'M';

	// �Լ� ȣ��� ����ü �״�� �ѱ��, ���������ӿ� ����ü ũ�� �޸𸮰� ��� ���̹Ƿ� ������
	// �����ͷ� �Ѱܾ� �Ѵ�.
	// ����ü �ȿ� �����Ͱ� �ְ�, �� �����Ͱ� �ڱ� �ڽ��� ����Ű�� �ڱ� ���� ����ü�� �����
	// Single Linked List�� �� �� �ִ�.
	LINKTEST user1 = { "person1", "1234", "M" };
	LINKTEST user2 = { "person2", "5678", "F" };
	user1.pNext = &user2;

	// ����ü ��� ����
	TESTDATA b;
	b.ch = 'A';
	b.nData = 300;

	printf("%d\n", sizeof(TESTDATA)); // 5����Ʈ�� �ƴ� 8����Ʈ�� ����!!
	// �̷��� �����ϸ�, �޸𸮿� �������� �ʰ�
	// 41 cc cc cc 2c 01 00 00 �̷������� �߰��� 3����Ʈ ���� �ǰ� �ȴ�. ��!
	// ����� ��Ʃ��� ���� �⺻�� ��� ������ 8����Ʈ
	// �̸� ���Ϸ��� 
	// #pragma pack(push, 1) ������ ����ü ���� �߰����ش�.
	// �̷��� �ϸ� 1����Ʈ�� ����.. 3����Ʈ ���� ���������� I/O �ӵ� ��������. �̰� �׳� �˰� ����.


	// ����ü
	// ����� ���� ū �� �������� �޸𸮰� ������.. �׸��� ����� ��.. ������ �༮�̳�..
	IP_ADDR addr;
	addr.addr[0] = 192;
	addr.addr[1] = 168;
	addr.addr[2] = 0;
	addr.addr[3] = 10;
	printf("%d\n", addr.nAddress); //167815360

	// ����ü�� ���� ��? 
	// �޸𸮸� ����� �̰� ����ü�� Ȯ���� ���� ����.. �׳� ������ �һ�. �������Ҷ� �ո��� �߷��� �ʿ��� ����
	MYDATA myData;
	myData.ch = 'A';
	myData.nData = 300;

	// ���� ����? ���?�ϰ� �޸𸮿� ����ȴ�.
	char ch = 'B';
	char nData = 300;

	return 0;
}
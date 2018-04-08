#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define MAIN_X 8 //������ ����ũ�� 
#define MAIN_Y 8 //������ ����ũ�� 
#define MAIN_X_ADJ 0 //������ ��ġ���� 
#define MAIN_Y_ADJ 0 //������ ��ġ����
#define SUCCESS_X 10 //�������� �ߴ� X ��ġ
#define SUCCESS_Y 10 //�������� �ߴ� Y ��ġ

int main_org[MAIN_Y][MAIN_X]; //�������� ������ �����ϴ� �迭 ����Ϳ� ǥ���Ŀ� main_cpy�� ����� 
int main_cpy[MAIN_Y][MAIN_X]; //�� maincpy�� �������� ����Ϳ� ǥ�õǱ� ���� ������ ������ ���� 
							  //main�� ��ü�� ��� ����Ϳ� ǥ������ �ʰ�(�̷��� �ϸ� ����Ͱ� �����Ÿ�) 
							  //main_cpy�� �迭�� ���ؼ� ���� �޶��� ���� ����Ϳ� ��ħ 

int this_x = 0; // x�� ���� ��ġ
int this_y = 0; // y�� ���� ��ġ
int goal_x = MAIN_X - 1; //x�� ��ǥ ��ġ
int goal_y = MAIN_Y - 1; //y�� ��ǥ ��ġ

#define PLAYER_BLOCK 1 // �÷��̾� ��
#define FIELD_BLOCK 0 // �ʵ� ��
#define GOAL_BLOCK -1 // ��ǥ ��

int key; //Ű����� �Է¹��� Ű���� ����
		 //Ű���尪�� 
#define LEFT 75 //��
#define RIGHT 77 //��
#define UP 72 //��
#define DOWN 80 //�Ʒ�
#define SPACE 32 //�����̽���
#define p 112 //�Ͻ����� 
#define P 80 //�Ͻ�����
#define ESC 27 //�������� 


void reset();
void reset_goal();
void reset_main_org();
void draw_title();
void draw_main();
void check_key();
void check_success();
void draw_block(int x, int y);

//gotoxy�Լ�
//�ܼ��� Ŀ�� ��ǥ�� ���ϴ� ��ġ�� �̵���Ű�� �Լ�
void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y }; // x�� 2�� ������� ǥ���� ��ġ�� Ȯ���ȴ�. �׳� �ϸ� ��µǴ� ���ڰ� ©��!!
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Ŀ������� �Լ��� ���Ǵ� ������ 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c) { //Ŀ������� �Լ�.. �̰� ���ϸ� Ŀ���� ���������Ÿ�!
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

int main(void) {
	// 1. �ֿܼ� �ٵ��� �׸���
	// 2. (0,0) ��ǥ�� �÷��̾� ǥ���ϱ�
	// 3. Ű�Է� �ޱ�
	// 4. ȭ��ǥ ������ Ŀ�� �̵��ϱ�
	// 5. ��Ʈ��� ��ǥ�� ������ �����ϱ�

	setcursortype(NOCURSOR); //Ŀ�� ���� 
	reset();

	while (1) {
		check_key(); //Ű�Է� Ȯ��
		draw_main(); //������ �׸�
		check_success(); //�������� Ȯ��
		Sleep(100);
	}

	//return 0;
}

void reset(void) {
	system("cls"); //ȭ������
	reset_goal(); //��ǥ ��ġ �ʱ�ȭ
	reset_main_org(); // main_org�� �ʱ�ȭ
	draw_title(); // ùȭ�� �׸�
				  //draw_main(); // �������� �׸�
}

// ��ǥ��ġ ����
void reset_goal(void) {
	srand((unsigned)time(NULL));
	int random_x = (rand() % (goal_x - 1)) + ((goal_x - 2) / 2);
	int random_y = (rand() % (goal_y - 1)) + ((goal_y - 2) / 2);

	//gotoxy(0, 20); printf("��ǥ�� y=%d, x=%d", random_y, random_x);

	goal_x = random_x;
	goal_y = random_y;
}

void reset_main_org(void) { // org �� �� �ʱ�ȭ
	int i, j;

	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			main_org[i][j] = FIELD_BLOCK;
			main_cpy[i][j] = FIELD_BLOCK;
		}
	}

	main_org[this_y][this_x] = PLAYER_BLOCK;
	main_cpy[this_y][this_x] = PLAYER_BLOCK;
	main_org[goal_y][goal_x] = GOAL_BLOCK;
	main_cpy[goal_y][goal_x] = GOAL_BLOCK;
}

void draw_title(void) {
	int i = 0, j = 0;
	for (i = 0; i < MAIN_Y; i++) {
		for (j = 0; j < MAIN_X; j++) {
			draw_block(j, i);
		}
	}
}

void draw_main(void) { //������ �׸��� �Լ� 
	int i, j;

	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			if (main_cpy[i][j] != main_org[i][j]) { //cpy�� ���ؼ� ���� �޶��� �κи� ���� �׷���.
													//�̰� ������ ��������ü�� ��� �׷��� �������� ��¦�Ÿ�
				draw_block(j, i);
			}
		}
	}
	for (i = 0; i<MAIN_Y; i++) { //�������� �׸� �� main_cpy�� ����  
		for (j = 0; j<MAIN_X; j++) {
			main_cpy[i][j] = main_org[i][j];
		}
	}
}

// �� �׸��� �Լ�
void draw_block(int x, int y) {
	gotoxy(x, y);
	switch (main_org[y][x]) {
	case FIELD_BLOCK:
		printf("��");
		break;
	case PLAYER_BLOCK:
		printf("��");
		break;
	case GOAL_BLOCK:
		printf("��");
		break;
	}
}

void check_key(void) {
	key = 0; //Ű�� �ʱ�ȭ  

	if (_kbhit()) { //Ű�Է��� �ִ� ���  
		key = _getch(); //Ű���� ����
		if (key == 224) { //����Ű�ΰ�� 
			do { key = _getch(); } while (key == 224);//����Ű���ð��� ���� 
			switch (key) {
			case LEFT: //����Ű ��������  
					   //�������� �� �� �ִ��� üũ �� �����ϸ� �̵�
				if (this_x - 1 >= 0) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_x = this_x - 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case RIGHT: //������ ����Ű ��������- ���� �����ϰ� ó���� 
				if (this_x + 1 < MAIN_X) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_x = this_x + 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case DOWN: //�Ʒ��� ����Ű ��������-���� �����ϰ� ó���� 
				if (this_y + 1 < MAIN_Y) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_y = this_y + 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case UP: //���� ����Ű �������� 
				if (this_y - 1 >= 0) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_y = this_y - 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			}
		}
		else { //����Ű�� �ƴѰ�� 
			switch (key) {
			case ESC: //ESC�������� 
				system("cls"); //ȭ���� ����� 
				exit(0); //�������� 
			}
		}
	}
	while (_kbhit()) _getch(); //Ű���۸� ��� 
}

// ���� ���� Ȯ��
void check_success() {
	if (this_x == goal_x && this_y == goal_y) {
		gotoxy(SUCCESS_X, SUCCESS_Y + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�"); //���ӿ��� �޼��� 
		gotoxy(SUCCESS_X, SUCCESS_Y + 1); printf("��           Success!           ��");
		gotoxy(SUCCESS_X, SUCCESS_Y + 2); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�\n\n\n"); //���ӿ��� �޼���

		gotoxy(0, SUCCESS_Y + 5); printf("Press any key to exit!");

		_getch(); //Ű�Է½ñ��� ��� 

		exit(0); //�������� 
	}
}
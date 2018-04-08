#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define MAIN_X 8 //게임판 가로크기 
#define MAIN_Y 8 //게임판 세로크기 
#define MAIN_X_ADJ 0 //게임판 위치조정 
#define MAIN_Y_ADJ 0 //게임판 위치조정
#define SUCCESS_X 10 //성공문구 뜨는 X 위치
#define SUCCESS_Y 10 //성공문구 뜨는 Y 위치

int main_org[MAIN_Y][MAIN_X]; //게임판의 정보를 저장하는 배열 모니터에 표시후에 main_cpy로 복사됨 
int main_cpy[MAIN_Y][MAIN_X]; //즉 maincpy는 게임판이 모니터에 표시되기 전의 정보를 가지고 있음 
							  //main의 전체를 계속 모니터에 표시하지 않고(이렇게 하면 모니터가 깜빡거림) 
							  //main_cpy와 배열을 비교해서 값이 달라진 곳만 모니터에 고침 

int this_x = 0; // x축 현재 위치
int this_y = 0; // y축 현재 위치
int goal_x = MAIN_X - 1; //x축 목표 위치
int goal_y = MAIN_Y - 1; //y축 목표 위치

#define PLAYER_BLOCK 1 // 플레이어 블럭
#define FIELD_BLOCK 0 // 필드 블럭
#define GOAL_BLOCK -1 // 목표 블럭

int key; //키보드로 입력받은 키값을 저장
		 //키보드값들 
#define LEFT 75 //좌
#define RIGHT 77 //우
#define UP 72 //위
#define DOWN 80 //아래
#define SPACE 32 //스페이스바
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료 


void reset();
void reset_goal();
void reset_main_org();
void draw_title();
void draw_main();
void check_key();
void check_success();
void draw_block(int x, int y);

//gotoxy함수
//콘솔의 커서 좌표를 원하는 위치로 이동시키는 함수
void gotoxy(int x, int y) {
	COORD pos = { 2 * x,y }; // x에 2를 곱해줘야 표시할 위치가 확보된다. 그냥 하면 출력되는 문자가 짤림!!
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서숨기는 함수에 사용되는 열거형 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c) { //커서숨기는 함수.. 이거 안하면 커서가 깜빡깜빡거림!
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
	// 1. 콘솔에 바둑판 그리기
	// 2. (0,0) 좌표에 플레이어 표시하기
	// 3. 키입력 받기
	// 4. 화살표 방향대로 커서 이동하기
	// 5. 하트모양 목표점 도착시 종료하기

	setcursortype(NOCURSOR); //커서 없앰 
	reset();

	while (1) {
		check_key(); //키입력 확인
		draw_main(); //게임판 그림
		check_success(); //성공여부 확인
		Sleep(100);
	}

	//return 0;
}

void reset(void) {
	system("cls"); //화면지움
	reset_goal(); //목표 위치 초기화
	reset_main_org(); // main_org를 초기화
	draw_title(); // 첫화면 그림
				  //draw_main(); // 게임판을 그림
}

// 목표위치 설정
void reset_goal(void) {
	srand((unsigned)time(NULL));
	int random_x = (rand() % (goal_x - 1)) + ((goal_x - 2) / 2);
	int random_y = (rand() % (goal_y - 1)) + ((goal_y - 2) / 2);

	//gotoxy(0, 20); printf("목표는 y=%d, x=%d", random_y, random_x);

	goal_x = random_x;
	goal_y = random_y;
}

void reset_main_org(void) { // org 축 값 초기화
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

void draw_main(void) { //게임판 그리는 함수 
	int i, j;

	for (i = 0; i<MAIN_Y; i++) {
		for (j = 0; j<MAIN_X; j++) {
			if (main_cpy[i][j] != main_org[i][j]) { //cpy랑 비교해서 값이 달라진 부분만 새로 그려줌.
													//이게 없으면 게임판전체를 계속 그려서 느려지고 반짝거림
				draw_block(j, i);
			}
		}
	}
	for (i = 0; i<MAIN_Y; i++) { //게임판을 그린 후 main_cpy에 복사  
		for (j = 0; j<MAIN_X; j++) {
			main_cpy[i][j] = main_org[i][j];
		}
	}
}

// 블럭 그리는 함수
void draw_block(int x, int y) {
	gotoxy(x, y);
	switch (main_org[y][x]) {
	case FIELD_BLOCK:
		printf("□");
		break;
	case PLAYER_BLOCK:
		printf("■");
		break;
	case GOAL_BLOCK:
		printf("♥");
		break;
	}
}

void check_key(void) {
	key = 0; //키값 초기화  

	if (_kbhit()) { //키입력이 있는 경우  
		key = _getch(); //키값을 받음
		if (key == 224) { //방향키인경우 
			do { key = _getch(); } while (key == 224);//방향키지시값을 버림 
			switch (key) {
			case LEFT: //왼쪽키 눌렀을때  
					   //왼쪽으로 갈 수 있는지 체크 후 가능하면 이동
				if (this_x - 1 >= 0) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_x = this_x - 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case RIGHT: //오른쪽 방향키 눌렀을때- 위와 동일하게 처리됨 
				if (this_x + 1 < MAIN_X) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_x = this_x + 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case DOWN: //아래쪽 방향키 눌렀을때-위와 동일하게 처리됨 
				if (this_y + 1 < MAIN_Y) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_y = this_y + 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			case UP: //위쪽 방향키 눌렀을때 
				if (this_y - 1 >= 0) {
					main_org[this_y][this_x] = FIELD_BLOCK;
					this_y = this_y - 1;
					main_org[this_y][this_x] = PLAYER_BLOCK;
				}
				break;
			}
		}
		else { //방향키가 아닌경우 
			switch (key) {
			case ESC: //ESC눌렀을때 
				system("cls"); //화면을 지우고 
				exit(0); //게임종료 
			}
		}
	}
	while (_kbhit()) _getch(); //키버퍼를 비움 
}

// 성공 여부 확인
void check_success() {
	if (this_x == goal_x && this_y == goal_y) {
		gotoxy(SUCCESS_X, SUCCESS_Y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤"); //게임오버 메세지 
		gotoxy(SUCCESS_X, SUCCESS_Y + 1); printf("▤           Success!           ▤");
		gotoxy(SUCCESS_X, SUCCESS_Y + 2); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤\n\n\n"); //게임오버 메세지

		gotoxy(0, SUCCESS_Y + 5); printf("Press any key to exit!");

		_getch(); //키입력시까지 대기 

		exit(0); //게임종료 
	}
}
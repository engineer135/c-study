#include <stdio.h>
#include <Windows.h>
#include <conio.h>

char getKey();
typedef enum bool { false, true } bool;

int main(void) {
	char key;
	while (1) {
		key = getKey();
		if (key != '\0') {
			printf("char %c\n", key);
			printf("decimal %d\n", key);
			printf("unsigned int %u\n", key);
			printf("hexa %x\n", key);
			printf("pointer %p\n", &key);
			printf("string %s\n", &key);
			printf("\n");
		}
	}
	
	return 0;
}

char getKey() {
	if (_kbhit()) {
		return _getch();
	}
	return '\0';
}
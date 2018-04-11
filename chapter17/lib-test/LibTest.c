#include <stdio.h>

// 이 코드에는 main() 함수가 없다! 굉장히 중요한 부분!
// 빈프로젝트를 만들고, 속성에서 구성 형식을 exe가 아닌 정적라이브러리(.lib)로 설정하면 됨
// 미리 정해두고 (설계) 만들어서 갖다 쓰면 좋음. 모듈화!
// 필요할때 라이브러리만 갖다 쓰면 되니까!
void PrintValue(int nParam) {
	printf("PrintValue() : %d\n", nParam);
}

void PrintString(const char *pszParam) {
	printf("PrintValue() : %s\n", pszParam);
}

// 드디어 마지막 강의
// 정적 라이브러리 생성

// obj 대신 lib 파일로 만들면 좋은점은
// 모든 .c 파일에서 obj로 링크과정 없이 재사용이 가능
// .lib 파일은 공구상자라고 보면 된다. 공구는 함수.
// 사용할때 함수를 콜만 하면 되니 편리하다.
// .lib 파일은 .obj 파일과 유사하다.

// sdk software development kit 이런게 보면 거의 lib 형태임
// 동적 Lib는 뭐지?
// dll 같은 거..

// Q&A
// 여러 라이브러리 끌어다 쓰는데 이때 함수 이름이 중복되면 충돌 나지 않나요?
// 난다!!
// 이럴때는?
// c에서는 함수 이름을 변경해야함
// c++에서는 NameSpace라는게 있어서 변경이 간단.
// 그러므로 사전 협의해서 설계에 반영을 해야 한다.

// 요즘엔 동적 라이브러리 .dll 이 대다수다.
// 정적인 경우 a.exe, b.exe 각각의 파일에 lib파일이 링크돼서 결합이 된다. (obj와 비슷)
// 이런 경우 라이브러리 수정하면, exe 파일도 새로 만들어야 한다는 단점이 있음
// 하지만 dll은 exe 파일에 결합되지 않고,
// 실행할때 dll 라이브러리를 로드한다. 그러므로 수정시 dll 파일만 교체하면 됨.
// 좋은 기능이네


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void choice_Word(int n);


int main()
{
    choice_Word(5);
}

//파일입출력 함수
/*
void open_noun()
{
    FILE* fp = fopen("명사.txt", "r");

    fclose(fp);

    return 0;
}

void open_adjective()
{
    FILE* fp = fopen("형용사.txt", "r");
    fclose(fp);

    return 0;
}
*/

 choice_Word(int n) //void x return 값이 있기때문 //확률 배열
{
    int choice=56; //choice가 랜덤하게 선택되게 변경 sum 범위 안에서
    n = 5;
    int ary_tmp[5] = {12,10,12,12,10}; //동적할당으로 바꿔야 함. 파일입출력으로 입력받아야 함.

    int sum = 56; //배열에 들어가있는 수에 맞게 계속 설정. 배열을 넘겨주고 sum을 반환받는 함수 생성.

    for (int i = 0; i < n; i++) { //함수로 뺌.
        choice -= ary_tmp[i];
        if (choice <= 0) {
            printf("%d번째 단어 선택됨", i + 1);
            break;
        }
    }
}

//명사 배열 생성
//형용사 배열 생성

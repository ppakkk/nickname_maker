// 개인 맞춤형 닉네임 생성기
// 컴퓨터는 사용자에게 추천을 함. 어느 유형을 할 것인지? -> 사용자에게 디폴드값을 주어주고 사용자가 선택하는 함수사용 
// 창-> 1.행복 2.슬픈 등등 이렇게 추천을 하면 사용자는 숫자를 입력해 선택을 함. ->사용자 입력함수
// 그러면 프로그램은 행복을 고른 사용자에게는 행복에 들어있는 파일을 출력해줌. ->파일입출력
// 사용자는 파일에 들어있는 단어를 선택함. 1.기쁘다 2.날뛸 것 같다 등등 
// 맨 처음 프로그램은 랜덤하게 5개의 단어를 주어주고 만약 사용자가 마음에드는 단어가 없으면 추가를 선택(랜덤으로)
// 사용자는 단어를 선택하고 두 번째 단어를 선택해야 함. ->두 번째 단어 추천 함수
// 다른 유형의 단어 예)명사, 형용사, 부사 등등 ->프린트
// 그럼 사용자는 저번과 같이 숫자를 입력하고 프로그램은 출력해줌. ->파일입출력
// 그리고 프로그램은 둘을 조합해 닉네임을 만들어줌. 
// 유형(감정, 인물, 사물, 지명, ) ->웅진 백과사전에서 빼오기.
// 첫 단어는 감정 중에서 선택
// 두 번째 단어는 일차적으로 인물, 사물, 지명 중 선택
// 그 다음 선택한 유형에서 세부적인 단어로 감.
// 함수 -> 배열, 파일입출력
// 종료조건 단어를 조합해 결과물을 도출하면 종료
// 화면을 출력하는 함수를 모두 빼고
// 출력하고 스크린 클리어 
// 똑같은 위치에 출력(함수로 뺌.)
// 파일 입출력하는 함수, 창 출력하는 함수, 파일 열어서 어떤 파일을 열고 몇 개만큼 출력를 하는 함수, 
// 텍스트 파일 7개 생성 (한 줄에 한 단어씩) 감정에서 4개, 사물, 지명, 인물
// 파일을 열고 닫을 수 있는 파일 생성.
// 파일 열어서 5개 랜덤으로 출력가는 한지 확인. 
// 랜덤으로 5개의 단어를 출력할 수 있도록. 

// #define _CRT_SECURE_NO_WARNINGS


// //랜덤함수 생성 0~파일 길이

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    char result[60] = "\0";
    FILE *fp = fopen("감정_화남.txt", "r");
    char str[100];
    int i, acc=0, lines =0, Lbegin[100] = {0};
    while(! feof(fp))
    if(fgets(str,sizeof(str), fp)!=NULL){
        if(lines>0)
        Lbegin[lines]=acc;
        acc += strlen(str) +1;
        lines++;
    }

    int random_index[5];
    srand(time(NULL));
    for(int i=0; i<5; i++){
        
        int random;
        random = rand() % lines;
        random_index[i]=random;
    }
    char choosen_str[5][20];
    for(int i=0; i<5; i++){
        fseek(fp, Lbegin[random_index[i]],SEEK_SET);
        strcpy(choosen_str[i],fgets(str, sizeof(str), fp));
        printf("%s", choosen_str[i]);
    }
    
    fclose(fp);

    printf("다음 제시된 단어 중에 선택하시거나 6 을 입력해 원하는 단어를 추가하십시오.");
    char in_str[20];
    scanf("%s", in_str);
    if(in_str[0] == ':'){
        printf("test \n ");
        strcat(result, choosen_str[(int)in_str[1]-48]);
        
    }
    printf("%s nnn test ",result);
    return 0;
};


//lines수 기준으로 0~lines 랜덤값
// fseek 활용
// 랜덤 5개 뽑기
// 닉네임-> 구조체
// 확률, 글자수 제한
// 라인으로 받기하되 출력할때 엔터가 있으면 안 됨.
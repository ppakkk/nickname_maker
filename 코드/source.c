// <개인 맞춤형 닉네임 생성기>
// 프로그램 진행 순서
// 맨 처음 사용자에게 1. 설명글 보기 2. 생성한 닉네임 리스트 보기 3. 닉네임 생성기 중 사용자가 숫자 입력해 프린트
// 창-> 1.행복 2.슬픈 등등 이렇게 추천을 하면 사용자는 숫자를 입력해 선택을 함. ->사용자 입력함수
// 그러면 프로그램은 행복을 고른 사용자에게는 행복에 들어있는 파일을 출력해줌. ->파일입출력
// 사용자는 파일에 들어있는 단어를 선택함. 1.기쁘다 2.날뛸 것 같다 등등 (완료)
// 맨 처음 프로그램은 랜덤하게 5개의 단어를 주어주고 만약 사용자가 마음에드는 단어가 없으면 추가를 선택(랜덤으로)아니면 단어 추가 
// 사용자는 단어를 선택하고 두 번째 단어를 선택해야 함. ->두 번째 단어 추천 함수
// 다른 유형의 단어 예)사물,인물,지명이라는 보기를 주어주고 사용자는 선택
// 그럼 사용자는 저번과 같이 숫자를 입력하고 프로그램은 출력해줌. ->파일입출력
// 두 번째 단어는 일차적으로 인물, 사물, 지명 중 선택
// 그 다음 선택한 유형에서 세부적인 단어로 감.
// 그리고 프로그램은 둘을 조합해 닉네임을 만들어줌. 
// 조합된 닉네임은 리스트라는 파일에 저장
// 종료조건 -> 사용자가 단어를 두 개 선택하고 선택한 단어를 조합해 프린트하면 종료


// 유형(감정, 인물, 사물, 지명, ) ->웅진 백과사전에서 빼오기.
// 첫 단어는 감정 중에서 선택
// 함수 -> 배열, 파일입출력
// 화면을 출력하는 함수를 모두 빼고
// 출력하고 스크린 클리어 
// 똑같은 위치에 출력(함수로 뺌.)
// 파일 입출력하는 함수, 창 출력하는 함수, 파일 열어서 어떤 파일을 열고 몇 개만큼 출력를 하는 함수, 
// 텍스트 파일 7개 생성 (한 줄에 한 단어씩) 감정에서 4개, 사물, 지명, 인물
// 파일을 열고 닫을 수 있는 파일 생성.
// 파일 열어서 5개 랜덤으로 출력가는 한지 확인. 
// 랜덤으로 5개의 단어를 출력할 수 있도록. 
//lines수 기준으로 0~lines 랜덤값


// fseek 활용
// 랜덤 5개 뽑기
// 닉네임-> 구조체
// 확률, 글자수 제한
// 라인으로 받기하되 출력할때 엔터가 있으면 안 됨.
// //랜덤함수 생성 0~파일 길이


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_KLEN 15 //키워드 최대 길이
#define MAX_NLEN 30 //닉네임 최대 길이

void run(); //실행
int selectMenu();//첫 화면
void printMenual(); //1.설명글
void listNickname(); //2. 닉네임 목록
void createNickname(); //3.닉네임 생성
FILE* selectEFile(int j); //감정파일선택
void selectRandomWords(FILE*fp); //랜덤 추출
void selectEWord(int j); //추출된 5개 단어 중 선택


int main()
{
    run(); 
    return 0;
};




void run()
{
    int key;
    while((key=selectMenu())!=0){
        switch(key) {
            case 1: printf("11"); break; //printmenual();
            case 2: printf("11"); break; //listNickname();
            case 3: createNickname();  break; //
        };
    };
    
};

int selectMenu()
{
    int i;
    printf("****** 닉네임 생성기 ******");
    printf("\n\n");
    printf("1. 설명\n2. 닉네임 목록\n3. 닉네임 생성기");
    scanf("%d",&i);
    return i;
};

void printMenual(){
    printf("집 가서 설명글 써오기");
};

void listNickname(){
    // 저장된 닉네임 파일을 불러와서 출력하는 기능 짜올 것
    
};

void createNickname(){
    int j;
    printf("첫 번째 닉네임으로 사용할 감정을 선택하십시오.\n");
    printf("1.감정_슬픔\n2.감정_행복\n3.감정_화남\n");
    scanf("%d", &j);// 사용자로부터 감정 키워드 선택할 수 있게 하고
    selectEWord(j);
    
     // 선택한 번호 바탕으로 관련된 파일 여는 함수 실행
}

void selectEWord(int j){
    FILE *fp=selectEFile(j); //사용자가 선택한 감정유형의 파일 열기
    selectRandomWords(fp);
    //랜덤추출 함수 실행
}

FILE* selectEFile(int j){
    FILE* fp;
    switch(j){
        case 1: // 슬픔 파일 출력
        fp = fopen("감정_슬픔","r");
        case 2: // 행복 파일 출력
        fp = fopen("감정_행복", "r");
        case 3: // 화남 파일 출력
        fp = fopen("감정_화남", "r");
    }// 조건문이나 switch문을 통해서 텍스트 이름 가져와서, 파일 open
    return fp;
}


void selectRandomWords(FILE *fp){
    char str[100];
    int i, acc=0, lines =0, Lbegin[100] = {0};
    while(! feof(fp)){
        if(fgets(str,sizeof(str), fp)!=NULL){
        if(lines>0)
        Lbegin[lines]=acc;
        acc += strlen(str) +1;
        lines++;
    }
    }
    
    int random_index[5];
    srand(time(NULL));
    for(int i=0; i<5; i++){
        
        int random;
        random = rand() % lines;
        random_index[i]=random;
    }

    for (int i=0; i<5; i++){
        printf("%d",random_index[i]);
    }
    // char choosen_str[5][20];
    // for(int i=0; i<5; i++){
    //     fseek(fp, Lbegin[random_index[i]],SEEK_SET);
    //     // strcpy(choosen_str[i],fgets(str, sizeof(str), fp));
    //     // printf("%s", choosen_str[i]);
    // }
    
    // fclose(fp);

}
// void printFrist_name() <-이 함수 필요없음
// {
//     int j;
//     printf("첫 번째 단어의 주제를 선택하십시오.\n");
//     printf("1. 행복 2. 슬픔 3. 화남");
//     scanf("%d", &j);
//     get_Fiveword(j);
    // switch(j){
    //     case 1: // 행복 파일 출력
    //     FILE *fr;
    //     fr = fopen("감정_행복","r");
    //     case 2: // 슬픔 파일 출력
    //     FILE *fw;
    //     fw = fopen("감정_슬픔", "r");
    //     case 3: // 화남 파일 출력
    //     fw = fopen("감정_화남", "r");
    //     Angry_word();
    // }
// }

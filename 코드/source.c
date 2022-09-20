// <개인 맞춤형 닉네임 생성기>
// 프로그램 진행 순서
// 맨 처음 사용자에게 1. 설명글 보기 2. 생성한 닉네임 리스트 보기 3. 닉네임 생성기 중 사용자가 숫자 입력해 프린트 ->완료
// 창-> 1.행복 2.슬픈 등등 이렇게 추천을 하면 사용자는 숫자를 입력해 선택을 함. ->사용자 입력함수 ->완료
// 그러면 프로그램은 행복을 고른 사용자에게는 행복에 들어있는 파일을 출력해줌. ->파일입출력
// 맨 처음 프로그램은 랜덤하게 5개의 단어를 주어주고 만약 사용자가 마음에드는 단어가 없으면 추가를 선택(랜덤으로)아니면 단어 추가 
// 사용자는 파일에 들어있는 단어를 선택함. 1.기쁘다 2.날뛸 것 같다 등등 (완료)
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

#define MAX_KLEN 20 //키워드 최대 길이
#define MAX_NLEN 30 //닉네임 최대 길이

void run(); //실행
int selectMenu();//첫 화면
void printMenual(); // 1.설명글
void listNickname(); // 2. 닉네임 목록
void createNickname(); // 3.닉네임 생성
FILE* selectFirstFile(int j); // 첫번째 파일 선택
FILE* selectSecondFile(int j); // 두번째 파일 선택
void* selectRandomWords(FILE*fp); // 선택된 파일에 대하여 랜덤 키워드 5개 추출
char* selectKeyword(int j, FILE *fp); // 추출된 5개 단어 중 선택


int main()
{
    run(); // 메인 함수에서는 run 함수만 실행
    return 0;
};


void run()
{
    int key=0;
    while((key=selectMenu())!=0){
        switch(key) {
            case 1: 
                printMenual(); 
                break; 
            case 2: 
                listNickname(); 
                break; 
            case 3: 
                createNickname();  
                break; 
            default: 
                printf("1-3 사이의 숫자를 입력해주세요.\n"); break;
        };
    };
    printf("프로그램 종료\n");
    
};

int selectMenu()
{
    int i;
    printf("=================== 닉네임 생성기 =================== (0:종료)");
    printf("\n\n");
    printf("    1: 사용 설명서\n");
    printf("    2: 닉네임 목록\n");
    printf("    3: 닉네임 생성하기\n");
    scanf("%d",&i);
    return i;
};

void printMenual(){
    printf("이 개인맞춤화 닉네임 생성기는 어느 사이트, 어플리케이션을 가도 회원가입이 필수가 된 사회에서 닉네임을 고민할 시간을 줄여주자라는 취지에서 만들게 되었습니다.\n");
    printf("첫 번째로 선택해야할 키워드는 감정입니다. 두 번째로 선택할 키워드는 사물,지명,인물입니다. 이 두 키워드가 합쳐서 하나의 닉네임을 이루게 됩니다.");
    printf("생성된 닉네임은 닉네임 목록에서 다시 보기가 가능하며 확률 기능을 통해 이 키워드를 몇퍼센트 선택했는지 알 수 있습니다.\n");
    printf("이 닉네임 생성기로 닉네임을 고민하는 시간이 줄어들었으면 좋겠습니다. 그럼 재미있게 사용하시길 바랍니다:)\n\n");
};

void listNickname(){
    FILE *fp;
    fp=fopen("닉네임 목록/닉네임 목록.txt","r");
    fclose(fp);
    // [ 저장된(저장되어있다고 가정)닉네임 파일을 불러와서 그래도 출력하는 기능 짜올 것 ]
    // 닉네임 목록 파일을 열러서 읽어들일 수 있어야함 
};

// 랜덤 추출 하는거 추가하는 기능까지 


void createNickname(){
    FILE *fp;
    int j,i;
    char buffer[100];
    printf("=====================================================\n");
    printf("첫 번째 키워드으로 사용될 [감정_유형]을 선택하십시오.\n\n");
    printf("    1: 감정_슬픔\n    2: 감정_행복\n    3: 감정_화남\n");
    scanf("%d", &j);// 사용자로부터 감정 키워드 번호 선택
    fp=selectFirstFile(j); // 첫번째 단계 : 감정 키워드 추출
    const char* _first_keyword = selectKeyword(j,fp); //return된 첫번째 키워드 저장되어 있음.
    // printf("%s",_first_keyword);
    strcpy(buffer,_first_keyword);

    printf("=====================================================\n");
    printf("두 번째 키워드으로 사용될 [감정_유형]을 선택하십시오.\n\n");
    printf("    1: 사물\n    2: 인물\n    3: 지명\n");
    scanf("%d", &i);// 사용자로부터 두번째 키워드 번호 선택
    fp=selectSecondFile(i); // 두번째 단계 : 두번째 키워드 추출
    const char* _second_keyword = selectKeyword(i,fp); //return된 첫번째 키워드 저장되어 있음.
    // printf("%s",_second_keyword);
    strcat(buffer,_second_keyword);

    

    // 줄바꿈 제거
    for(int i=0;buffer[i]!=0;i++){
        if(buffer[i]=='\n'){
            buffer[i]=' ';
            break;
        }
    }
    printf("%s",buffer);

    // 최종 키워드를 닉네임 목록 파일에 저장
    
    
}

char* selectKeyword(int j, FILE *fp){
    int i;
    char (*p)[MAX_KLEN]=(char(*)[MAX_KLEN])selectRandomWords(fp); //랜덤추출 함수 실행을통해 키워드 5개 반환
    // 배열 포인터를 사용하여 2차원 배열에 저장된 문자열 출력
    for (int i=0;i<5;i++){
        printf("%d. %s",i,*(p+i));
    }
    printf("\n마음에 드는 키워드의 순서를 선택하십시오: ");
    scanf("%d", &i);

    return p+i;

    //[ 유저에게 보기 좋게 다섯 키워드 보여주고 선택할 수 있게끔 만들기 ]
    //[ 선택한 단어를 구조체의 first_keyword 변수에 저장하기 ]
}

FILE* selectFirstFile(int j){
    FILE* fp;
    // switch문을 통해 텍스트 이름 가져와서 파일 open
    switch(j){
        case 1: // 슬픔 파일 출력
        fp = fopen("감정_슬픔.txt","r");

        case 2: // 행복 파일 출력
        fp = fopen("감정_행복.txt", "r");

        case 3: // 화남 파일 출력
        fp = fopen("감정_화남.txt", "r");
    }
    return fp;
}

FILE* selectSecondFile(int j){
    FILE* fp;
    // switch문을 통해 텍스트 이름 가져와서 파일 open
    switch(j){
        case 1: // 슬픔 파일 출력
        fp = fopen("사물.txt","r");

        case 2: // 행복 파일 출력
        fp = fopen("인물txt", "r");

        case 3: // 화남 파일 출력
        fp = fopen("지명.txt", "r");
    }
    return fp;
}


void *selectRandomWords(FILE *fp){
    char str[100];
    int i, acc=0, lines =0, Lbegin[100] = {0};
    while(! feof(fp)){
        if(fgets(str,sizeof(str), fp)!=NULL){
        if(lines>0)
        Lbegin[lines]=acc-lines; 
        acc += strlen(str) +1;
        // printf("%s",str);
        lines++;
    }
    }
    
    int random_index[5];
    srand((unsigned)time(NULL));
    



    // 랜덤 값 생성 - 중복 제거 기능 추가
    for (int i = 0; i < 5; i++) {
		random_index[i]=rand() % lines;
		for (int j = 0; j < i; j++) {
			if (random_index[i] == random_index[j]) i--;
		}
	}

    printf("\n");
    static char choosen_str[5][MAX_KLEN];
    for(int i=0; i<5; i++){
        fseek(fp, Lbegin[random_index[i]],SEEK_SET); // 랜덤 라인으로 fp 위치 이동
        strcpy(choosen_str[i],fgets(str,sizeof(str),fp)); //해당 라인 문자열 읽은 후 복사 
        // printf("%s",choosen_str[i]);
    }


    fclose(fp);

    return choosen_str;

    
}//랜덤 5가지 단어 추출
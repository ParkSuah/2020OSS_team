nclude <stdio.h>

typedef struct _score{
	int kor;
	int eng;
	int math;
	char name[20];
	float avg;
	int sum;
}Score;

int scoreMenu(); //전체 메뉴(선택지)를 보여주는 함수

void readScore(Score s); //하나의 데이터를 읽는 함수

void listScore(Score *s, int count); //전체 리스트를 보여주는 함수

int addData(Score *s); //새로운 식당을 추가하는 함수

int updateData(Score *s, int count); //기존 등록된 식당을 수정하는 함수

int deleteData(Score *s, int count); //등록된 식당을 제거하는 함수

void SaveData(Score *s, int count); //File에 저장하는 함수

int loadData(Score *s); //저장된 파일을 불러오는 함수

void SearchData(Score *s, int count); //검색하는 함수

void SearchAvg(Score s[], int count);//평균으로 검색하기

void SearchName(Score s[], int count);//이름으로 검색하기

void sortRank(Score *s, int count); //등수를 정렬하는 함수

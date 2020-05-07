#include <stdio.h>
#include <string.h>
typedef struct _score{
	int kor;
	int eng;
	int math;
	char name[20];
	float avg;
	int sum;
}Score;

void readScore(Score s); //하나의 데이터를 읽는 함수

int addScore(Score *s); //새로운 식당을 추가하는 함수

int updateScore(Score *s, int count); //기존 등록된 식당을 수정하는 함수

int deleteScore(Score *s, int count); //등록된 식당을 제거하는 함수


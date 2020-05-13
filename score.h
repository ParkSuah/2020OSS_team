#include <stdio.h>
#include <string.h>
typedef struct _score{
	int kor;
	int eng;
	int math;
	char name[20];
	float avg;
	int sum;
	int rank;
}Score;

void readScore(Score s); //하나의 데이터를 읽는 함수

int addScore(Score *s); //새로운 식당을 추가하는 함수

int updateScore(Score *s); //기존 등록된 식당을 수정하는 함수

int deleteScore(Score *s); //등록된 식당을 제거하는 함수

<<<<<<< HEAD
void rankScore(Score *s, int count); //등수매기기
=======
void rankScore(Score* s, int count); // 학생들의 등수 매기기
>>>>>>> 94b3e797a5fca562bd6f3610c57014aea7ea6555

void listByScore(Score* s, int count); // 등수에 따라 나열

#include "score.h"

int addScore(Score *s){
	printf("학생의 이름: ");
	scanf("%s\n", s->name);
	printf("국어점수: ");
	scanf("%d\n", &s->kor);
	printf("수학점수: ");
	scanf("%d\n", &s->math);
	printf("영어점수: ");
	scanf("%d\n", &s->eng);
	printf("==> 추가됨!\n");
	
	return 1;
}

void readScore(Score s){
	if(s.kor == -1 && s.math == -1 && s.eng == -1) return;
	s.sum = s.kor + s.math + s.eng;
	s.avg = s.sum/3.0;
	printf("%s %d %d %d %d %.1f", s.name, s.kor, s.eng, s.math, s.sum, s.avg);
}

int updateScore(Score *s){
	printf("학생의 이름: ");
	scanf("%s\n", s->name);
	printf("국어점수: ");
	scanf("%d\n", &s->kor);
	printf("수학점수: ");
	scanf("%d\n", &s->math);
	printf("영어점수: ");
	scanf("%d\n", &s->eng);
	printf("==> 수정됨!\n");
	
	return 1;
}

int deleteScore(Score *s){
	s->kor = -1;
	s->math = -1;
	s->eng = -1;
	printf("==> 삭제됨!\n");
	return 1;
}

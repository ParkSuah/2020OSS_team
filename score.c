#include "score.h"

void listByScore(Score* s, int count){
	for(int i=0; i<count; i++){
		for(int j=0; j<count; j++){
			if(s[j].rank == i+1)
				readScore(s[j]);
		}
	}
}

void rankScore(Score *s, int count){
	int cnt;
	for(int i = 0; i < count; i++){
		cnt = 0;
		for(int j = 0; j < count; j ++){
			if(s[i].sum < s[j].sum){
				cnt++;
			}
		}
		s[i].rank = cnt + 1;
	}
}

char getGrade(float avg){
	char g;
	if(avg>=90 && avg <=100) g = 'A';
	else if(avg>80) g = 'B';
	else if(avg>70) g = 'C';
	else if(avg>60) g = 'D';
	else g = 'F';
	return g;
}

int addScore(Score *s){
	printf("학생의 이름: ");
	scanf("%s", s->name);
	printf("국어점수: ");
	scanf("%d", &s->kor);
	printf("수학점수: ");
	scanf("%d", &s->math);
	printf("영어점수: ");
	scanf("%d", &s->eng);
	printf("==> 추가됨!\n");

	s->sum = s->kor+s->math+s->eng;
	s->avg = s->sum/3.0;
	return 1;
}

void readScore(Score s){
	if(s.kor == -1 && s.math == -1 && s.eng == -1) return;
	s.sum = s.kor + s.math + s.eng;
	s.avg = s.sum/3.0;
					
	char r = getGrade(s.avg);
	printf("%-8s    %4d    %4d    %4d    %4d     %5.1f      %2d      %2c\n", 
		s.name, s.kor, s.eng, s.math, s.sum, s.avg, s.rank, r);
}

int updateScore(Score *s){
	printf("학생의 이름: ");
	scanf("%s", s->name);
	printf("국어점수: ");
	scanf("%d", &s->kor);
	printf("수학점수: ");
	scanf("%d", &s->math);
	printf("영어점수: ");
	scanf("%d", &s->eng);
	printf("==> 수정됨!\n");
	s->sum = s->kor+s->math+s->eng;
	s->avg = s->sum/3.0;

	return 1;
}

int deleteScore(Score *s){
	s->kor = -1;
	s->math = -1;
	s->eng = -1;
	s->rank = -1;
	//printf("==> 삭제됨!\n");
	return 1;
}

int deleteAllScore(Score* s, int count){
	int deleteOK;
	printf("정말 모든 데이터를 삭제하시겠습니까(네 : 1)? ");
	scanf("%d", &deleteOK);
	if(deleteOK == 1){
		for(int i=0; i<count; i++){
			deleteScore(&s[i]);
		}
		printf("모든 데이터가 삭제되었습니다.\n");
	}else{
		printf("==> 취소됨 !\n");
	}
}

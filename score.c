#include "score.h"


/*
void rankScore(Score* s, int count){
	for(int i=0; i<count; i++)
		s[i].rank = 1;
	//Score rank[count];
	for(int i=0; i<count; i++){
		for(int j=0; j<count; j++){
			if(s[i].kor == -1) s[i].rank == -1;
			if(s[i].sum < s[j].sum){
				printf("ranking...\n");
				s[i].rank++;
				printf("%s 의 등수 : %d\n", s[i].name, s[i].rank);
			}
		}
	}
}
*/
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
	printf("%-8s    %4d    %4d    %4d    %4d     %5.1f       %2c\n", 
		s.name, s.kor, s.eng, s.math, s.sum, s.avg, r);
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
	printf("==> 삭제됨!\n");
	return 1;
}

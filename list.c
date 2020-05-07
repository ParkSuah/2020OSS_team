#include "score.h"

void listScore(Score *s, int count){
	printf("\n등록번호   이름    국어    영어    수학    총점    평균\n");
	for(int i = 0; i < count; i++){
		if(s[i].kor == -1 && s[i].eng == -1 && s[i].math == -1) continue;
		printf("%d", i + 1);
		readScore(s[i]);
	}
	printf("\n");
}

int selectDataNo(Score *s, int count){
	int num;
	listScore(s, count);
	printf("작업할 제품번호(취소: 0): ");
	scanf("%d", &num);
	return num;
}

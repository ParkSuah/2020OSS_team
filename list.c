#include "list.h"

void listScore(Score *s, int count){
	printf("\n등록번호   이름      국어    영어    수학    총점      평균     등수    성적\n");
	printf("=============================================================================||\n");
	for(int i = 0; i < count; i++){
		if(s[i].kor == -1 && s[i].eng == -1 && s[i].math == -1) continue;
		rankScore(s, count);
		printf("%4d       ", i+1);
		readScore(s[i]);
	}
	printf("\n");
}

int selectDataNo(Score *s, int count){
	int num;
	listScore(s, count);
	printf("수정할 정보(취소: 0): ");
	scanf("%d", &num);
	return num;
}

int scoreMenu(){
	int num;
	printf("\n====메뉴목록====\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 이름검색\n");
	printf("7. 평균검색\n");
	printf("8. 등수검색\n");
	printf("9. 등수로 나열\n");
	printf("10. 모든 데이터 한번에 삭제\n");
	printf("0. 종료\n");
	printf("원하는 메뉴는 ? ");
	scanf("%d", &num);
	return num;
}

void saveData(Score* s, int count){
	FILE* fp = fopen("data.txt", "wt");
	for(int i=0; i<count; i++){
		if(s[i].kor == -1) continue;
		fprintf(fp, "%d %d %d %d %.1f %s\n", s[i].kor, s[i].eng, 
			s[i].math, s[i].sum, s[i].avg, s[i].name);
	}
	fclose(fp);
	printf("저장됨!\n");
}

int loadData(Score* s){
	int c = 0;
	FILE* fp = fopen("data.txt", "rt");
	if(fp == NULL){
		printf("파일없음\n");
		return 0;
	}
	for(;;c++){
		fscanf(fp, "%d %d %d %d %f ", &s[c].kor, &s[c].eng, 
			&s[c].math,&s[c].sum, &s[c].avg);
		fgets(s[c].name, 20, fp);
		s[c].name[strlen(s[c].name)-1] = '\0';
		if(feof(fp)) break;
	}
	rankScore(s, c);
	printf("로딩 성공 !\n");
	return c;
}

void searchName(Score *s, int count){
	int nameCount = 0;
	char searchName[20];
	printf("검색할 이름: ");
	scanf("%s", searchName);
	printf("\n========================== [검색한 이름] ===========================||\n");
	printf("이름       국어    영어    수학    총점     평균      등수     성적\n");
	printf("===================================================================||\n");
	for(int i = 0; i < count; i++){
		if(s[i].kor == -1 && s[i].math == -1 && s[i].eng == -1)continue;
		if(strstr(s[i].name, searchName)){
			readScore(s[i]);
			nameCount++;
													}
	}
	if(nameCount == 0){
		printf("==> \"%s\" 는 없습니다.\n", searchName);
	}
}

void searchAvg(Score* s, int count){
	int avgCount = 0;
	float searchAvg ;
	printf("검색할 평균 점수(입력 점수 이상인 평균 출력!): ");
	scanf("%f", &searchAvg);
	printf("\n========================== [검색한 평균] ===========================||\n");
	printf("이름       국어    영어    수학    총점     평균     등수     성적\n");
	printf("===================================================================||\n");
	for(int i=0;i<count;i++){
		if(s[i].kor == -1 && s[i].math == -1 && s[i].eng == -1) continue;
		if(s[i].avg >= searchAvg){
			readScore(s[i]);
			avgCount++;
		}
	}
	if(avgCount == 0)
		printf("==> %.1f 이상의 평균점수를 가진 학생은 없습니다.\n", searchAvg);
}

void searchRank(Score* s, int count){
	int searchRank;
	printf("검색할 등수: ");
	scanf("%d", &searchRank);
	int c = 0;
	if(searchRank > count){
		printf("==>%d등까지 있습니다.\n", count);
	}else{
		printf("\n========================== [검색한 등수] ===========================||\n");
		printf("이름       국어    영어    수학    총점     평균     등수     성적\n");
		printf("===================================================================||\n");
		for(int i=0; i<count; i++){
			if(s[i].rank == searchRank)
				readScore(s[i]);
		}
	}
}

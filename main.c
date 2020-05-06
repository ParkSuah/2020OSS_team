#include "score.h"

int Menu(){
	int num;
	printf("====메뉴목록====\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");	
	printf("4. 삭제\n");
	printf("0. 종료\n");
	printf("원하는 작업: ");
	scanf("%d", &num);
	
	return num;
}

int main(void){
	Score slist[100];
	int choice;
	int count = 0;
	int curcount = 0;
	
	while(1){
		choice = Menu();
		if(choice == 0) break;
		else if(choice == 1){
			if(count > 0){
				listScore(slist, count);
			}
		}
		else if(choice == 2){
			count += addScore(&slist[curcount++]);
		}
		else if(choice == 3){
			if(count > 0){
				int select = selectDataNo(slist, curcount);
				if(select == 0){
					printf("==> 수정이 취소됩니다.\n");
					continue;
				}
				updateScore(&slist[select -1]);	
			}
		}
		else if(choice == 4){
			int deletok;
			if(count > 0){
				int select = selectDataNo(slist, curcount);
				if(select == 0){
					printf("==> 삭제가 취소됩니다.\n");
					continue;
				}
				printf("데이터를 삭제합니다. (삭제:1)");
				scanf("%d", &deletok);
				if(deletok == 1){
					deleteScore(&slist[select - 1]);
					count--;
				}
				else printf("==> 제품삭제 취소");
			}
		}
	}
	printf("==>종료됨!\n");
	return 0;
}

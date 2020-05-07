#include "list.h"

int main(void){
	Score slist[100];
	int choice;
	int count = 0;
	int curcount = 0;
	
	count = loadData(slist);
	curcount = count;	
	while(1){
		choice = scoreMenu();
		if(choice == 0) break;
		else if(choice == 1){
			if(count > 0){
				listScore(slist, count);
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
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
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
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
			}else{
				printf("아무런 정보도 입력되지 않았습니다.\n");
			}
		}else if(choice == 5){
			if(count > 0){
				saveData(slist, curcount);
			}else{
				printf("아무런 정보도 입력되지 않았습니다 .\n");
			}
		}
	}
	printf("==>종료됨!\n");
	return 0;
}

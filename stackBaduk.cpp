#include<stdio.h>
#include<stdlib.h>
const int pannRow=19;//행 
const int pannCol=19;//열 
const int pannSize=pannRow*pannCol;//전체 사이즈 
typedef struct location{
	int row;//행 
	int col;//열 
};
location locate[pannSize];//최근에 둔 돌의 위치를 저장하는 배열구조체 
location T;//쓸모없음 
int pann[pannRow][pannCol];//게임판 
int top=0;//스택의 스택 
int stopFlag=0;//멈추는 플래그 
void pannReset();//판 리셋 
void stack(int,int);//스택
int Condition(int,int,int);
void rollback();//롤백 
void show();

int main(){
	int row;
	int col;
	int color=1;//돌색깔 
	int choice;//무엇을 할지 정하는 변수 
	pannReset();
	printf("게임시작\n");
	while(1){
		if(color==1){
			printf("흑돌차례\n");
			printf("행:"); 
			scanf("%d",&row);
			printf("열:"); 
			scanf("%d",&col);
			printf("\n");
			if(Condition(row-1,col-1,color)==1){//만약에 같은 곳에 돌이 이미 있다면 못두게 함 
				printf("같은 위치에 돌이 이미 있습니다."); 
				continue;
			}
			pann[row-1][col-1]=color;//게임판에 돌을 넣음 
			stack(row-1,col-1);//최근에 어디에 돌을 뒀는지 넣음	
			color=2;//흰색으로 바꿈 
			show();
		}
		else if(color==2){
			printf("백돌차례\n");
			printf("행:"); 
			scanf("%d",&row);
			printf("열:"); 
			scanf("%d",&col);
			printf("\n"); 

			if(Condition(row-1,col-1,color)==1){ 
				printf("같은 위치에 돌이 이미 있습니다.\n");
				continue;
			}
			
			pann[row-1][col-1]=color;//게임판에 돌을 넣음 
			stack(row-1,col-1);//최근에 어디에 돌을 뒀는지 넣음
			color=1;//검은색으로 바꿈
			show();
		}
		printf("1.그만둔다,2.롤백,3.계속한다:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				stopFlag++;
				break;
			case 2:
				rollback();
				if(color==1){
					color=2;
				}
				else if(color==2){
					color=1;
				}
				show();
				break;
			case 3:
				continue;
			default:
				printf("잘못입력하셨습니다.계속 진행합니다.");
		}
		if(stopFlag>0){
			break;
		}
	}
}
void pannReset(){
	for(int i=0; i<pannRow;i++){
		for(int j=0; j<pannCol;j++){
			pann[i][j]=0;
		}
	}
}
void stack(int row,int col){
	if(pannSize-1==top){
		printf("판이 꽉찼습니다.");
		return; 
	}
	locate[top].row=row;
	locate[top++].col=col;
}
void rollback(){
	if(top-1==-1){
		printf("정보가 없습니다.");
		return;
	}
	pann[locate[top].row][locate[top--].col]=0;
}
int Condition(int row, int col, int color){
	int boolean=0;
	if(color==1){
		color=2;
	}
	else if(color==2){
		color=1;
	}
	if(pann[row][col]==color){
		boolean=1;
	}
	return boolean;
}
void show(){
	for(int i=0;i<pannRow;i++){
		for(int j=0;j<pannCol;j++){
			if(pann[i][j]==1){
				printf(" ●");
			}
			else if(pann[i][j]==2){
				printf(" ◎");
			}else{
				printf(" □");
			}
		}
		printf("\n");
	}
}


#include<stdio.h>
#include<stdlib.h>
const int pannRow=19;//�� 
const int pannCol=19;//�� 
const int pannSize=pannRow*pannCol;//��ü ������ 
typedef struct location{
	int row;//�� 
	int col;//�� 
};
location locate[pannSize];//�ֱٿ� �� ���� ��ġ�� �����ϴ� �迭����ü 
location T;//������� 
int pann[pannRow][pannCol];//������ 
int top=0;//������ ���� 
int stopFlag=0;//���ߴ� �÷��� 
void pannReset();//�� ���� 
void stack(int,int);//����
int Condition(int,int,int);
void rollback();//�ѹ� 
void show();

int main(){
	int row;
	int col;
	int color=1;//������ 
	int choice;//������ ���� ���ϴ� ���� 
	pannReset();
	printf("���ӽ���\n");
	while(1){
		if(color==1){
			printf("�浹����\n");
			printf("��:"); 
			scanf("%d",&row);
			printf("��:"); 
			scanf("%d",&col);
			printf("\n");
			if(Condition(row-1,col-1,color)==1){//���࿡ ���� ���� ���� �̹� �ִٸ� ���ΰ� �� 
				printf("���� ��ġ�� ���� �̹� �ֽ��ϴ�."); 
				continue;
			}
			pann[row-1][col-1]=color;//�����ǿ� ���� ���� 
			stack(row-1,col-1);//�ֱٿ� ��� ���� �״��� ����	
			color=2;//������� �ٲ� 
			show();
		}
		else if(color==2){
			printf("�鵹����\n");
			printf("��:"); 
			scanf("%d",&row);
			printf("��:"); 
			scanf("%d",&col);
			printf("\n"); 

			if(Condition(row-1,col-1,color)==1){ 
				printf("���� ��ġ�� ���� �̹� �ֽ��ϴ�.\n");
				continue;
			}
			
			pann[row-1][col-1]=color;//�����ǿ� ���� ���� 
			stack(row-1,col-1);//�ֱٿ� ��� ���� �״��� ����
			color=1;//���������� �ٲ�
			show();
		}
		printf("1.�׸��д�,2.�ѹ�,3.����Ѵ�:");
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
				printf("�߸��Է��ϼ̽��ϴ�.��� �����մϴ�.");
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
		printf("���� ��á���ϴ�.");
		return; 
	}
	locate[top].row=row;
	locate[top++].col=col;
}
void rollback(){
	if(top-1==-1){
		printf("������ �����ϴ�.");
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
				printf(" ��");
			}
			else if(pann[i][j]==2){
				printf(" ��");
			}else{
				printf(" ��");
			}
		}
		printf("\n");
	}
}


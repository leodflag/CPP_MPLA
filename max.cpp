#include <iostream>
#include <limits.h> 

int findMax(int sum[],int sum_len){
	int Max=INT_MIN; //�O�̤j�� 
	int Max_i;    //�̤j����I���Ǹ� 
	int count=1;    //���X�ӳ̤j�� 
	int ccc=100;
	int *Max_iArray; //�h�ӳ̤j�Ȧb�x�}����m 
	Max_iArray = new int[count];
	for(int i=0;i<sum_len;i++){
		if(sum[i]>Max){//���Lsum����A��X�̤j��    �n�P�_������0�����p 
			Max=sum[i];
			Max_i=i;
		}
		else if(sum[i]==Max){
			Max_i=i;
			count++;
			*Max_iArray=Max_i;
		}
	}	
	if(count>=2)
		return ccc;
	else
		return Max_i;	
}
int main(){/*
	int s[6]={0,-4,0,-1,-2,0};
//	int s[6]={2,4,0,1,2,4};
	int Max=INT_MIN;
	int Max_i;  // �̤j�Ȫ���m 
	int count=1;  // �̤j�ȭӼ� 
	int *Max_iArray; //�h�ӳ̤j�Ȧb�x�}����m 
	Max_iArray = new int[count];
	for(int i=0;i<6;i++){
		if(s[i]>Max){
			Max=s[i];
			Max_i=i;
			printf("����count=%d\n",count);
		}
		else if(s[i]==Max){
			Max_i=i;
			count++;
			*Max_iArray=Max_i;
			printf("else if count=%d\n",count);
		}
		printf("Max_iArray=%d\n",Max_i);
	}
	if(count>=2)
		printf("���G�өΤG�ӥH�W�̤j��\n");
	else
		printf("�@�ӳ̤j��\n");
	
	printf("MAX=%d \n Max_i=%d \n count=%d \n ",Max,Max_i,count);
*/
	int w[3][3]={{0,0,0},{0,0,0},{0,0,0}};	
	int new_w[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int data[3][3]={{0,0,1},{1,1,1},{-1,1,1}};
	int SUM[3]={0,0,0};	
	int sum=0;
	int Max_i=0;
	int k=0;
	int c=1;
	int correct=0;
	int count=0;
	while(correct!=3){
		for(int k=0;k<3;k++){
			for(int i=0;i<3;i++){ //�����i��� 
				for(int j=0;j<3;j++){ //�����j���� 
					sum+=w[i][j]*data[k][j];  //�a�J�íp��3�Ӥ�������sum 
					printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
				}
				SUM[i]=sum;
				sum=0;
				printf("======j�浲���A�{�b�bi��=======\n");
				printf("SUM[%d]=%d\n",i,SUM[i]);
				
			}
			Max_i=findMax(SUM,3);  //�o��̤j�� ������SUM�Ǹ� 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){  //�P�_�վ��v�� 
				printf("MAX_I!=K\n");
				for(int i=0;i<3;i++){ //�����i��� 
					for(int j=0;j<3;j++){ //�����j���� 
						if(i==k){
							new_w[i][j]=w[i][j]+c*data[k][j];
							printf("i==K�Anew w %d = old w %d + data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{
					 		new_w[i][j]=w[i][j]-c*data[k][j];
							printf("i!=K�Anew w %d = old w %d - data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("else   data[k][j]=%d\n",data[k][j]);					 		
						 }

						
					}
				}
				printf("===�n����correct=0   Max_i!=k===="); 
			}
			else{
				correct++;
				printf("===�n����correct++   Max_i!=k===="); 
				if(correct==3){
					printf("=====�{�b��%d�����T=======\n\n\n",correct);	
					break;	
				}				
			}
			printf("=====�{�b�b%d��=======\n\n\n",k);
		}
		if(correct==3){
			printf("=====�{�b��%d�����T=======\n\n\n",correct);	
			break;	
		}
		
	}
 
} 



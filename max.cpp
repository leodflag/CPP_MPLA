#include <iostream>
int findMax(int sum[]){
	int Max=sum[0];//�O�̤j������I���Ĥ@�� 
	int Max_i=0;   //�̤j����I���Ǹ� 
	for(int i=0;i<3;i++){
		if(sum[i]>Max)//���Lsum����A��X�̤j�� 
		Max=sum[i];
		Max_i=i;	
	}
	return Max_i;
}
int main(){/*
	int s[6]={0,5,4,9,2,-4};
	int Max=s[0];
	for(int i=0;i<6;i++){
		if(s[i]>Max)
		Max=s[i];
	}*/
	//printf("MAX=%d",Max);
	int w[3][3]={{0,0,0},{0,0,0},{0,0,0}};	
	int new_w[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int data[3][3]={{0,0,1},{1,1,1},{-1,1,1}};
	int SUM[3]={0,0,0};	
	int sum=0;
	int Max_i=0;
	int k=0;
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
			Max_i=findMax(SUM);  //�o��̤j�� ������SUM�Ǹ� 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){
				printf("MAX_I!=K\n");
				for(int i=0;i<3;i++){ //�����i��� 
					for(int j=0;j<3;j++){ //�����j���� 
						if(i==k){
							new_w[i][j]=w[i][j]+data[k][j];
							printf("i==K�Anew w %d = old w %d + data %d\n",new_w[i][j],w[i][j],data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{
					 		new_w[i][j]=w[i][j]-data[k][j];
							printf("i!=K�Anew w %d = old w %d - data %d\n",new_w[i][j],w[i][j],data[k][j]);
							w[i][j]=new_w[i][j];
							printf("else   data[k][j]=%d\n",data[k][j]);
						}
					}
				}
			//	correct--;
				printf("===�n����correct=0   Max_i!=k===="); 
			}
			else{
				correct++;
				printf("===�n����correct++   Max_i!=k===="); 
			}
			printf("=====�{�b�b%d��=======\n\n\n",k);
		}
		count++;	
		printf("=====�{�b��%d��=======\n\n\n",count);	
	}

} 



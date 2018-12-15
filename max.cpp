#include <iostream>
int findMax(int sum[]){
	int Max=sum[0];//令最大的資料點為第一個 
	int Max_i=0;   //最大資料點的序號 
	for(int i=0;i<3;i++){
		if(sum[i]>Max)//跟其他sum比較，找出最大的 
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
			for(int i=0;i<3;i++){ //控制第i橫排 
				for(int j=0;j<3;j++){ //控制第j直行 
					sum+=w[i][j]*data[k][j];  //帶入並計算3個分類器的sum 
					printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
				}
				SUM[i]=sum;
				sum=0;
				printf("======j行結束，現在在i行=======\n");
				printf("SUM[%d]=%d\n",i,SUM[i]);
			}
			Max_i=findMax(SUM);  //得到最大的 分類器SUM序號 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){
				printf("MAX_I!=K\n");
				for(int i=0;i<3;i++){ //控制第i橫排 
					for(int j=0;j<3;j++){ //控制第j直行 
						if(i==k){
							new_w[i][j]=w[i][j]+data[k][j];
							printf("i==K，new w %d = old w %d + data %d\n",new_w[i][j],w[i][j],data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{
					 		new_w[i][j]=w[i][j]-data[k][j];
							printf("i!=K，new w %d = old w %d - data %d\n",new_w[i][j],w[i][j],data[k][j]);
							w[i][j]=new_w[i][j];
							printf("else   data[k][j]=%d\n",data[k][j]);
						}
					}
				}
			//	correct--;
				printf("===要跳離correct=0   Max_i!=k===="); 
			}
			else{
				correct++;
				printf("===要跳離correct++   Max_i!=k===="); 
			}
			printf("=====現在在%d行=======\n\n\n",k);
		}
		count++;	
		printf("=====現在第%d次=======\n\n\n",count);	
	}

} 



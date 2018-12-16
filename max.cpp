#include <iostream>
#include <limits.h> 

int findMax(int sum[],int sum_len){
	int Max=INT_MIN; //令最大值 
	int Max_i;    //最大資料點的序號 
	int count=1;    //有幾個最大值 
	int ccc=100;
	int *Max_iArray; //多個最大值在矩陣的位置 
	Max_iArray = new int[count];
	for(int i=0;i<sum_len;i++){
		if(sum[i]>Max){//跟其他sum比較，找出最大的    要判斷全部為0的情況 
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
	int Max_i;  // 最大值的位置 
	int count=1;  // 最大值個數 
	int *Max_iArray; //多個最大值在矩陣的位置 
	Max_iArray = new int[count];
	for(int i=0;i<6;i++){
		if(s[i]>Max){
			Max=s[i];
			Max_i=i;
			printf("內部count=%d\n",count);
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
		printf("有二個或二個以上最大值\n");
	else
		printf("一個最大值\n");
	
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
			Max_i=findMax(SUM,3);  //得到最大的 分類器SUM序號 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){  //判斷調整權重 
				printf("MAX_I!=K\n");
				for(int i=0;i<3;i++){ //控制第i橫排 
					for(int j=0;j<3;j++){ //控制第j直行 
						if(i==k){
							new_w[i][j]=w[i][j]+c*data[k][j];
							printf("i==K，new w %d = old w %d + data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{
					 		new_w[i][j]=w[i][j]-c*data[k][j];
							printf("i!=K，new w %d = old w %d - data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("else   data[k][j]=%d\n",data[k][j]);					 		
						 }

						
					}
				}
				printf("===要跳離correct=0   Max_i!=k===="); 
			}
			else{
				correct++;
				printf("===要跳離correct++   Max_i!=k===="); 
				if(correct==3){
					printf("=====現在第%d次正確=======\n\n\n",correct);	
					break;	
				}				
			}
			printf("=====現在在%d行=======\n\n\n",k);
		}
		if(correct==3){
			printf("=====現在第%d次正確=======\n\n\n",correct);	
			break;	
		}
		
	}
 
} 



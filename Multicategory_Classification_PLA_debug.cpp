#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
#include <string>
#include <climits>
using namespace std; 
void getDataSize(int size[]){
	ifstream file("data.csv");  //以默認輸入方式打開文件 
	string line;
	getline(file,line);  //從輸入流讀入字符存到string變量，直到沒有讀入字符、返回false 
	stringstream count(line);  //將一個字符串變量的值傳遞給istringstream對象 count
	for(int i=0;i<2;i++){
		string val;
		getline(count,val,',');  //以","當換行符號 
		stringstream convert(val); //轉字串成數字  
		convert>> size[i];  //輸入到矩陣 		
	}		
}

void readData(int ** data, int r, int c){
	ifstream file("data.csv");  //以默認輸入方式打開文件 
	string line1;
	getline(file,line1);
	for(int row=0;row<r;++row){
		string line;
		if(!getline(file,line))  //從輸入流讀入一行到string變量，直到沒有讀入字符、返回false 
			break;
		stringstream iss(line);  //將一個字符串變量的值傳遞給istringstream對象 
		for(int col=0;col<c;++col){
			string val;
			getline(iss,val,',');  //字串分割 
			stringstream convert(val); //轉字串成數字  
			convert>>data[row][col];  //輸入到矩陣 
		}
	}
}
int findMax(int sum[],int sum_len){
	int Max=INT_MIN; //令最大值 
	int Max_i;    //最大資料點的序號 
	int count=1;    //有幾個最大值 
	int ccc=100;    
	int *Max_iArray; //多個最大值在矩陣的位置 
	Max_iArray = new int[count];
	for(int i=0;i<sum_len;i++){
		if(sum[i]>Max){ //跟其他sum比較，找出最大的    
			Max=sum[i];
			Max_i=i;
		}
		else if(sum[i]==Max){ //要判斷多個最大值的情況 
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
void MPLA(int **data,int **w,int data_row,int data_col, int dataSize){
	int SUM[dataSize]={0};	//三個分類器各自的總和 
	int sum=0;
	int correct=0; //分類正確的分類器個數 
	int Max_i=0; //最大值索引 
	int **new_w;//宣告w矩陣
	new_w=new int *[data_row];
	for(int i=0;i<data_row;i++)
		new_w[i]=new int[data_col]; 	
	int c=1; //學習速率 
	while(correct!=dataSize){
		for(int k=0;k<dataSize;k++){
			for(int i=0;i<data_row;i++){ //控制第i橫排 
				for(int j=0;j<data_col;j++){ //控制第j直行 
					sum+=w[i][j]*data[k][j];  //帶入並計算3個分類器的sum 
					printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
				}
				SUM[i]=sum;
				sum=0;
				printf("======j_end,   row_%d=======\n",i );
				printf("SUM[%d]=%d\n",i,SUM[i]);
			}
			Max_i=findMax(SUM,dataSize);  //得到最大的 分類器SUM序號 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){  //如果資料類別判斷錯誤，調整權重
				printf("MAX_I!=K\n");
				for(int i=0;i<data_row;i++){ //控制第i橫排 
					for(int j=0;j<data_col;j++){ //控制第j直行 
						if(i==k){ // 第k個資料點調整權重方法  
							new_w[i][j]=w[i][j]+c*data[k][j];
							printf("i==K,  new w %d = old w %d + data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{ //其他資料點調整權重之方法  
					 		new_w[i][j]=w[i][j]-c*data[k][j];
							printf("i!=K,  new w %d = old w %d - data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("else   data[k][j]=%d\n",data[k][j]);					 		
						 }
					}
				}
				printf("===out  correct=0   Max_i!=k====\n"); 
			}
			else{
				correct++; // 正確分類器  
				printf("===out  correct++   Max_i!=k====\n"); 
				if(correct==dataSize){ //跳離for迴圈，表示3個分類器都正確，不用再更新  
					printf("=====%d  correct=======\n",correct);	
					break;	
				}				
			}
			printf("=====row_%d=======\n",k);
		}
		if(correct==dataSize){ //跳離while迴圈，表示3個分類器都正確，不用再更新   
			printf("=====%d  correct=======\n",correct);	
			break;	
		}
	}		
}
int main(int argc, char** argv){ 
	int size[]={}; //檔案size 
	int data_row;  //資料筆數 
	int data_col;  //資料參數
	getDataSize(size); //取得資料內容大小 
	data_row=size[0];
	data_col=size[1];
	int dataSize=data_row;
	printf("data_row=%d,data_col=%d\n,dataSize=%d\n",data_row,data_col,dataSize);
	int **w;//宣告w矩陣
	w=new int *[data_row];
	for(int i=0;i<data_row;i++)
		w[i]=new int[data_col];     
	for(int i=0;i<data_row;i++){  //初始化權重 
		for(int j=0;j<data_col;j++){
			w[i][j]=0;
			printf("%d\n",w[i][j]);
		}
	}	
	
	int **data; //宣告data矩陣 
	data=new int *[data_row];
	for(int i=0;i<data_row;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col);
	MPLA(data,w,data_row,data_col,data_row);
	for(int i=0;i<data_row;i++){  //分類器各自權重 
		printf("%dW=",i);
		for(int j=0;j<data_col;j++){
			printf("%d,",w[i][j]);
		}
		printf("\n");
	}	
  	return 0;
}

#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
#include <string> 
using namespace std; 
void getDataSize(int size[]){
	//stringstream url,string url
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
void findMax(int sum[]){
	int Max=sum[0];//令最大的資料點為第一個 
	int Max_i=0;   //最大資料點的序號 
	for(int i=0;i<3;i++){
		if(sum[i]>Max)//跟其他sum比較，找出最大的 
		Max=sum[i];
		Max_i=i;	
	}
}
void W_updata(int SUM[],){
	Max_i=findMax(SUM);  //得到最大的 分類器SUM序號 
	if(Max_i!=k){
		printf("MAX_I!=K\n");
		for(int i=0;i<3;i++){ //控制第i橫排 
			for(int j=0;j<3;j++){ //控制第j直行 
				if(i==k){
					new_w[i][j]=w[i][j]+w[i][j]*data[k][j];
					printf("i==K，new w %d = old w %d + old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
					w[i][j]=new_w[i][j];
					printf("if    data[k][j]=%d\n",data[k][j]);
				} 
			 	else{
			 		new_w[i][j]=w[i][j]-w[i][j]*data[k][j];
					printf("i!=K，new w %d = old w %d - old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
					w[i][j]=new_w[i][j];
					printf("else   data[k][j]=%d\n",data[k][j]);
				}
			}
		}
		correct++;
		printf("===要跳離correct=0   Max_i!=k===="); 
	}
	else{
		correct++;
		printf("===要跳離correct++   Max_i!=k===="); 
	}	
}
void MPLA(int**data,int**w,int dataSize){
	for(int k=0;k<dataSize;k++){
		for(int i=0;i<dataSize;i++){ //控制第i橫排 
			for(int j=0;j<dataSize;j++){ //控制第j直行 
				sum+=w[i][j]*data[k][j];  //帶入並計算3個分類器的sum 
				printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
			}
			SUM[i]=sum;
			printf("======j行結束，現在在i行=======\n");
			printf("SUM[%d]=%d\n",i,SUM[i]);
		}
		Max_i=findMax(SUM);  //得到最大的 分類器SUM序號 
		if(Max_i!=k){
			printf("MAX_I!=K\n");
			for(int i=0;i<dataSize;i++){ //控制第i橫排 
				for(int j=0;j<dataSize;j++){ //控制第j直行 
					if(i==k){
						new_w[i][j]=w[i][j]+w[i][j]*data[k][j];
						printf("i==K，new w %d = old w %d + old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
						w[i][j]=new_w[i][j];
						printf("if    data[k][j]=%d\n",data[k][j]);
					} 
				 	else{
				 		new_w[i][j]=w[i][j]-w[i][j]*data[k][j];
						printf("i!=K，new w %d = old w %d - old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
						w[i][j]=new_w[i][j];
						printf("else   data[k][j]=%d\n",data[k][j]);
					}
				}
			}
			correct++;
			printf("===要跳離correct=0   Max_i!=k===="); 
		}
		else{
			correct++;
			printf("===要跳離correct++   Max_i!=k===="); 
		}
		printf("=====現在在%d行=======\n\n\n",k);
	}		
}
int main(int argc, char** argv){ 
	int w[3][3]={{1,2,3},{4,5,6},{7,8,9}};	
	int new_w[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int data[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int SUM[3]={0,0,0};	
	int sum=0;
	int Max_i=0;
	int k=0;
	int correct=0;
	
	
	int size[]={}; //檔案size 
	int data_row,data_col;  //資料筆數 //資料參數 
	//string url="w.csv";
	getDataSize(size); //取得資料內容大小 
	data_row=size[0];
	data_col=size[1];
	int **data; 
	data=new int *[data_row];
	for(int i=0;i<data_col;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col);
	MPLA(data,w,3);
  	return 0;
}

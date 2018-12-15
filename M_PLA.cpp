#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
#include <string> 
using namespace std; 
void getDataSize(int size[]){
	//stringstream url,string url
	ifstream file("data.csv");  //�H�q�{��J�覡���}��� 
	string line;
	getline(file,line);  //�q��J�yŪ�J�r�Ŧs��string�ܶq�A����S��Ū�J�r�šB��^false 
	stringstream count(line);  //�N�@�Ӧr�Ŧ��ܶq���ȶǻ���istringstream��H count
	for(int i=0;i<2;i++){
		string val;
		getline(count,val,',');  //�H","����Ÿ� 
		stringstream convert(val); //��r�ꦨ�Ʀr  
		convert>> size[i];  //��J��x�} 		
	}		
}
void readData(int ** data, int r, int c){
	ifstream file("data.csv");  //�H�q�{��J�覡���}��� 
	string line1;
	getline(file,line1);
	for(int row=0;row<r;++row){
		string line;
		if(!getline(file,line))  //�q��J�yŪ�J�@���string�ܶq�A����S��Ū�J�r�šB��^false 
			break;
		stringstream iss(line);  //�N�@�Ӧr�Ŧ��ܶq���ȶǻ���istringstream��H 
		for(int col=0;col<c;++col){
			string val;
			getline(iss,val,',');  //�r����� 
			stringstream convert(val); //��r�ꦨ�Ʀr  
			convert>>data[row][col];  //��J��x�} 
		}
	}
}
void findMax(int sum[]){
	int Max=sum[0];//�O�̤j������I���Ĥ@�� 
	int Max_i=0;   //�̤j����I���Ǹ� 
	for(int i=0;i<3;i++){
		if(sum[i]>Max)//���Lsum����A��X�̤j�� 
		Max=sum[i];
		Max_i=i;	
	}
}
void W_updata(int SUM[],){
	Max_i=findMax(SUM);  //�o��̤j�� ������SUM�Ǹ� 
	if(Max_i!=k){
		printf("MAX_I!=K\n");
		for(int i=0;i<3;i++){ //�����i��� 
			for(int j=0;j<3;j++){ //�����j���� 
				if(i==k){
					new_w[i][j]=w[i][j]+w[i][j]*data[k][j];
					printf("i==K�Anew w %d = old w %d + old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
					w[i][j]=new_w[i][j];
					printf("if    data[k][j]=%d\n",data[k][j]);
				} 
			 	else{
			 		new_w[i][j]=w[i][j]-w[i][j]*data[k][j];
					printf("i!=K�Anew w %d = old w %d - old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
					w[i][j]=new_w[i][j];
					printf("else   data[k][j]=%d\n",data[k][j]);
				}
			}
		}
		correct++;
		printf("===�n����correct=0   Max_i!=k===="); 
	}
	else{
		correct++;
		printf("===�n����correct++   Max_i!=k===="); 
	}	
}
void MPLA(int**data,int**w,int dataSize){
	for(int k=0;k<dataSize;k++){
		for(int i=0;i<dataSize;i++){ //�����i��� 
			for(int j=0;j<dataSize;j++){ //�����j���� 
				sum+=w[i][j]*data[k][j];  //�a�J�íp��3�Ӥ�������sum 
				printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
			}
			SUM[i]=sum;
			printf("======j�浲���A�{�b�bi��=======\n");
			printf("SUM[%d]=%d\n",i,SUM[i]);
		}
		Max_i=findMax(SUM);  //�o��̤j�� ������SUM�Ǹ� 
		if(Max_i!=k){
			printf("MAX_I!=K\n");
			for(int i=0;i<dataSize;i++){ //�����i��� 
				for(int j=0;j<dataSize;j++){ //�����j���� 
					if(i==k){
						new_w[i][j]=w[i][j]+w[i][j]*data[k][j];
						printf("i==K�Anew w %d = old w %d + old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
						w[i][j]=new_w[i][j];
						printf("if    data[k][j]=%d\n",data[k][j]);
					} 
				 	else{
				 		new_w[i][j]=w[i][j]-w[i][j]*data[k][j];
						printf("i!=K�Anew w %d = old w %d - old w * data %d\n",new_w[i][j],w[i][j],w[i][j]*data[k][j]);
						w[i][j]=new_w[i][j];
						printf("else   data[k][j]=%d\n",data[k][j]);
					}
				}
			}
			correct++;
			printf("===�n����correct=0   Max_i!=k===="); 
		}
		else{
			correct++;
			printf("===�n����correct++   Max_i!=k===="); 
		}
		printf("=====�{�b�b%d��=======\n\n\n",k);
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
	
	
	int size[]={}; //�ɮ�size 
	int data_row,data_col;  //��Ƶ��� //��ưѼ� 
	//string url="w.csv";
	getDataSize(size); //���o��Ƥ��e�j�p 
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

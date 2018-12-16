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
		getline(count,val,',');  //�H","������Ÿ� 
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
int findMax(int sum[],int sum_len){
	int Max=INT_MIN; //�O�̤j�� 
	int Max_i;    //�̤j����I���Ǹ� 
	int count=1;    //���X�ӳ̤j�� 
	int ccc=100;    
	int *Max_iArray; //�h�ӳ̤j�Ȧb�x�}����m 
	Max_iArray = new int[count];
	for(int i=0;i<sum_len;i++){
		if(sum[i]>Max){ //���Lsum����A��X�̤j��    
			Max=sum[i];
			Max_i=i;
		}
		else if(sum[i]==Max){ //�n�P�_�h�ӳ̤j�Ȫ����p 
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
void MPLA(int**data,int w[][3],int dataSize){
	int SUM[3]={0,0,0};	//�T�Ӥ������U�۪��`�M 
	int sum=0;
	int correct=0; //�������T���������Ӽ� 
	int Max_i=0; //�̤j�ȯ��� 
	int new_w[3][3]={{0,0,0},{0,0,0},{0,0,0}}; //��s���v�� 
	int c=1; //�ǲ߳t�v 
	while(correct!=3){
		for(int k=0;k<3;k++){ //��k�Ӹ���I 
			for(int i=0;i<3;i++){ //�����i��� 
				for(int j=0;j<3;j++){ //�����j���� 
					sum+=w[i][j]*data[k][j];  //�a�J�íp��3�Ӥ�������sum 
				}
				SUM[i]=sum;
				sum=0;
			}
			Max_i=findMax(SUM,3);  //�o��̤j�� ������SUM�Ǹ� 
			if(Max_i!=k){  //�p�G������O�P�_���~�A�վ��v��
				for(int i=0;i<3;i++){ //�����i��� 
					for(int j=0;j<3;j++){ //�����j���� 
						if(i==k){  // ��k�Ӹ���I�վ��v����k 
							new_w[i][j]=w[i][j]+c*data[k][j];  
							w[i][j]=new_w[i][j];
						} 
					 	else{ //��L����I�վ��v������k 
					 		new_w[i][j]=w[i][j]-c*data[k][j];
							w[i][j]=new_w[i][j];				 		
						 }
					}
				}
			}
			else{
				correct++;  // ���T������ 
				if(correct==3) //����for�j��A����3�Ӥ����������T�A���ΦA��s 
					break;	
			}
		}
		if(correct==3) //����while�j��A����3�Ӥ����������T�A���ΦA��s 
			break;	
	}		
}
int main(int argc, char** argv){ 
	int w[3][3]={{0,0,0},{0,0,0},{0,0,0}};	//��l�v�� 
	int new_w[3][3]={{0,0,0},{0,0,0},{0,0,0}};  //�s�v�� 
	int size[]={}; //�ɮ�size 
	int data_row;  //��Ƶ��� 
	int data_col;  //��ưѼ�
	getDataSize(size); //���o��Ƥ��e�j�p 
	data_row=size[0];
	data_col=size[1];
	int **data; //�ŧidata�x�} 
	data=new int *[data_row];
	for(int i=0;i<data_col;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col);
	MPLA(data,w,3);
	for(int i=0;i<data_row;i++){  //�������U���v�� 
		printf("%dW=",i);
		for(int j=0;j<data_col;j++){
			printf("%d,",w[i][j]);
		}
		printf("\n");
	}
  	return 0;
}
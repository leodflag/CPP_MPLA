#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
#include <string>
#include <climits>
using namespace std; 
void getDataSize(int size[]){
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
void MPLA(int **data,int **w,int data_row,int data_col, int dataSize){
	int SUM[dataSize]={0};	//�T�Ӥ������U�۪��`�M 
	int sum=0;
	int correct=0; //�������T���������Ӽ� 
	int Max_i=0; //�̤j�ȯ��� 
	int **new_w;//�ŧiw�x�}
	new_w=new int *[data_row];
	for(int i=0;i<data_row;i++)
		new_w[i]=new int[data_col]; 	
	int c=1; //�ǲ߳t�v 
	while(correct!=dataSize){
		for(int k=0;k<dataSize;k++){
			for(int i=0;i<data_row;i++){ //�����i��� 
				for(int j=0;j<data_col;j++){ //�����j���� 
					sum+=w[i][j]*data[k][j];  //�a�J�íp��3�Ӥ�������sum 
					printf("sum+=w*x=:%d+=%d*%d\n",sum,w[i][j],data[k][j]);
				}
				SUM[i]=sum;
				sum=0;
				printf("======j_end,   row_%d=======\n",i );
				printf("SUM[%d]=%d\n",i,SUM[i]);
			}
			Max_i=findMax(SUM,dataSize);  //�o��̤j�� ������SUM�Ǹ� 
			printf("Max_i=%d\n",Max_i);
			if(Max_i!=k){  //�p�G������O�P�_���~�A�վ��v��
				printf("MAX_I!=K\n");
				for(int i=0;i<data_row;i++){ //�����i��� 
					for(int j=0;j<data_col;j++){ //�����j���� 
						if(i==k){ // ��k�Ӹ���I�վ��v����k  
							new_w[i][j]=w[i][j]+c*data[k][j];
							printf("i==K,  new w %d = old w %d + data %d\n",new_w[i][j],w[i][j],c*data[k][j]);
							w[i][j]=new_w[i][j];
							printf("if    data[k][j]=%d\n",data[k][j]);
							
						} 
					 	else{ //��L����I�վ��v������k  
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
				correct++; // ���T������  
				printf("===out  correct++   Max_i!=k====\n"); 
				if(correct==dataSize){ //����for�j��A���3�Ӥ����������T�A���ΦA��s  
					printf("=====%d  correct=======\n",correct);	
					break;	
				}				
			}
			printf("=====row_%d=======\n",k);
		}
		if(correct==dataSize){ //����while�j��A���3�Ӥ����������T�A���ΦA��s   
			printf("=====%d  correct=======\n",correct);	
			break;	
		}
	}		
}
int main(int argc, char** argv){ 
	int size[]={}; //�ɮ�size 
	int data_row;  //��Ƶ��� 
	int data_col;  //��ưѼ�
	getDataSize(size); //���o��Ƥ��e�j�p 
	data_row=size[0];
	data_col=size[1];
	int dataSize=data_row;
	printf("data_row=%d,data_col=%d\n,dataSize=%d\n",data_row,data_col,dataSize);
	int **w;//�ŧiw�x�}
	w=new int *[data_row];
	for(int i=0;i<data_row;i++)
		w[i]=new int[data_col];     
	for(int i=0;i<data_row;i++){  //��l���v�� 
		for(int j=0;j<data_col;j++){
			w[i][j]=0;
			printf("%d\n",w[i][j]);
		}
	}	
	
	int **data; //�ŧidata�x�} 
	data=new int *[data_row];
	for(int i=0;i<data_row;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col);
	MPLA(data,w,data_row,data_col,data_row);
	for(int i=0;i<data_row;i++){  //�������U���v�� 
		printf("%dW=",i);
		for(int j=0;j<data_col;j++){
			printf("%d,",w[i][j]);
		}
		printf("\n");
	}	
  	return 0;
}

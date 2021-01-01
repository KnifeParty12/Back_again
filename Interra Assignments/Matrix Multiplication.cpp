#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Matrix{
	int **mata;
	int **matb;
	int rowa,cola;
	int rowb,colb;
	int **res;
public:
	void inputA(){
		fstream fin;
		fin.open("C:\\Users\\8nikhils\\Documents\\inputa.csv");
		char s;
		fin>>rowa;
		fin>>s;
		fin>>cola;
		mata=new int*[rowa];
		for(int i=0;i<rowa;i++){
			mata[i]=new int[cola];
		}
		for(int i=0;i<rowa;i++){
			for(int j=0;j<cola;j++){
				fin>>mata[i][j];
				if(j<cola-1)
					fin>>s;
			}
		}
		fin.close();
	}
	void inputB(){
		fstream fin;
		fin.open("C:\\Users\\8nikhils\\Documents\\inputb.csv");
		char s;
		fin>>rowb;
		fin>>s;
		fin>>colb;
		matb=new int*[rowb];
		for(int i=0;i<rowb;i++){
			matb[i]=new int[colb];
		}
		for(int i=0;i<rowb;i++){
			for(int j=0;j<colb;j++){
				fin>>matb[i][j];
				if(j<colb-1)
					fin>>s;
			}
		}
		fin.close();
	}
	void multiply(){
		res=new int*[rowa];
		for(int i=0;i<rowa;i++){
			res[i]=new int[colb];
		}
		for (int i = 0; i < rowa; i++)
		{
			for (int j = 0; j < colb; j++)
			{
				res[i][j] = 0;
				for (int x = 0; x < rowb; x++)
				{
					res[i][j] += mata[i][x] * matb[x][j];
				}
			}
		}
		fstream fout;
		fout.open("C:\\Users\\8nikhils\\Documents\\output.csv");
		char s=',';
		fout<<rowa;
		fout<<s;
		fout<<colb;
		for(int i=0;i<rowa;i++){
			for(int j=0;j<colb;j++){
				fout<<matb[i][j];
				fout<<s;

			}
		}
		fout.close();
	}

};
int main(){
	Matrix m;
	m.inputA();
	m.inputB();
	m.multiply();
	system("pause");
	return 0;
}

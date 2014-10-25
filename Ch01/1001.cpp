#include <iostream>
#include <string>

using namespace std;
/*
假如该字符串为25114
Sp为251的可能数
Sc为2511的可能数
现在求25114的可能数Sn
将当前数和它前面的数组成新的数进行判断
当新的数在11到19和21到26时，Sn可以由Sp和Sc的可能数组成
当新的数为10或者20时，Sn为Sp的值
当为其他时，则Sn的值为Sc的值
设置初值Sp=1,Sc=1
若只有一个位数，则Sn=1,否则进行上面的运算
*/
int main(){
	string line;

	while((cin>>line) && (line.compare("0")!=0)){
		int Sp =1,Sc=1,Sn=0;

		if(line.length() == 1){
			Sn = 1;
		}else{
				for(int i=1;i<line.length();i++){
				int num = (line[i-1]-'0')*10 + (line[i]-'0');
				if((11<= num && num<=19) || (21<= num && num <=26))
				Sn = Sp + Sc;
				else if(num == 10 || num == 20)
				Sn = Sp;
				else 
				Sn = Sc;
				
				Sp = Sc;
				Sc = Sn;
			}
		}

		cout<<Sn<<endl;
	}

	return 0;
}

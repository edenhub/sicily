#include <iostream>

using namespace std; 

class numCal{
private:
	int size;
	int *arr;

public:
	numCal(int staticArr[],int staticSize);
	numCal(const numCal &cal);
	~numCal();

	int sum();
	numCal& operator=(const numCal &cal);
	numCal& operator++();
	numCal operator++(int);

	void print() const;
	void println() const;
};

numCal::numCal(int staticArr[],int staticSize){
	this->size = staticSize;
	this->arr = staticArr;
}

numCal::numCal(const numCal &cal){
	this->size = cal.size;
	this->arr = new int[cal.size];
	for(int i=0;i<cal.size;i++)
		this->arr[i] = cal.arr[i];
}

numCal::~numCal(){
	delete this->arr;
	// for(int i=0;i<this->size;i++)
	// 	delete this->arr[i];
}

int numCal::sum(){
	int sum=0;
	for(int i=0;i<this->size;i++)
		sum += this->arr[i];

	return sum;
}

numCal& numCal::operator=(const numCal &cal){
	this->size = cal.size;
	this->arr = cal.arr;

	return *this;
}

numCal& numCal::operator++(){
	for(int i=0;i<this->size;i++){
		this->arr[i]++;
	}

	return *this;
}

numCal numCal::operator++(int){
	numCal cal(*this);
	this->operator++();

	return cal;
}

void numCal::print() const{
	cout<<"{ ";
	for(int i=0;i<this->size;i++)
		cout<<this->arr[i]<<" " ;
	cout<<"}";
}

void numCal::println() const{
	this->print();
	cout<<endl;
}

int main(){
	int arr[5] = {1,2,3,4,5};
	int size = 5;

	numCal cal(arr,size);
	cal.println();

	numCal cal2(cal);
	cal.println();

	cout<<cal.sum()<<endl;

	// numCal cal3;
	// cal3 = cal;
	// cal3.println();

	numCal cal3 = cal++;
	cal.println();
	cal3.println();

	numCal cal4 = ++cal;
	cal.println();
	cal4.println();

	cal2 = cal;
	cal2.println();

	return 0;
}
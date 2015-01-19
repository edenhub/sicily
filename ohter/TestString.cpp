#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void testFunChar(const char *str){
	cout<<str<<endl;
}

void testFunChar2(const char str[]){
	cout<<str<<endl;
}

int main(){
	char a[] = "adam";
	string b = "adam2";
	string c = a;
	testFunChar(a);
	testFunChar(b.c_str());
	testFunChar(c.c_str());
	cout<<strlen(a)<<endl;
	testFunChar2(a);
}
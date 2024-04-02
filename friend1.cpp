#include<iostream>
using namespace std;
class A{
	int x;
	public :
		void getdata(){
			cout <<"enter the value"<<endl;
			cin>>x;
		}
		
		friend void sum(A ,B);
};
class B{
	int y;
	public:
		void getdata(){
			cout <<"enter the value of y"<<endl
			cin>>y;
		}
		friend void sum(A ,B);
		
};
void sum(A aa,B bb){
	cout <<"the aditioon of the number us"<<endl
	cout << aa.x+bb.y;
	cout <<endl;
}
int main(){
	A aa;
	B bb;
	aa.getdata();
	bb.getdata();
	sum(&aa,&bb);
	return 0;
}
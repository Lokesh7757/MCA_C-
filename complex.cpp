#include<iostream>
using namespace std;

class Complex
{
private:
float real,img;

public:
Complex()
{
  real=0;
  img=0;
}

void accept()
{
cout<<"Enter the complex number:"<<"\n";
cout<<"Real Value :";
cin>>real;
cout<<"Imaginary Value:";
cin>>img;
}


void display()
{
cout<<"complex number is:";
cout<<real<<"+"<<img<<"i"<<"\n";
}


Complex(float a,float b)
{
real=a;
img=b;
}

friend Complex operator +(Complex c1,Complex c2)
{
c1.real=c1.real+c2.real;
c1.img=c1.img+c2.img;
return c1;
}

friend Complex operator -(Complex c1,Complex c2)
{
c1.real=c1.real-c2.real;
c1.img=c1.img-c2.img;
return c1;
}

Complex operator *(Complex c2);
Complex operator /(Complex c2);
};

Complex Complex::operator *(Complex c2)
{
Complex c3;
c3.real=(real*c2.real)-(img*c2.img);
c3.img=(real*c2.img)+(img*c2.real);
return c3;
}

Complex Complex::operator /(Complex c2)
{
Complex c3;
c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
c3.img=((real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
return c3;
}

int main()
{
int ch;
Complex c3;
Complex c4(4,5);
Complex c5;
c5.accept();
cout<<"1st";
c4.display();
cout<<"\n";
cout<<"2nd";
c5.display();
cout<<"\n";

do
{
cout<<"\n"<<"Enter your choice:";
cout<<"1.Addition"<<"\n"<<"2.Substraction"<<"\n"<<"3.Multiplication"<<"\n"<<"4.Division"<<"\n";
cin>>ch;


switch(ch)
{
case 1: cout<<"Addition:";
c3=operator+(c4,c5);
c3.display();
cout<<"\n";
break;

case 2: cout<<"Substraction:";
c3=operator-(c4,c5);
c3.display();
cout<<"\n";
break;

case 3: cout<<"Multication:";
c3=c4*c5;
c3.display();
cout<<"\n";
break;

case 4: cout<<"Division:";
c3=c4.operator/(c5);
c3.display();
cout<<"\n";
break;

default:

cout<<"PROGRAM IS END";

}
}while(ch<=4);
return 0;
}

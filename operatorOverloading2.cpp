//Operator Overloading
#include<iostream>
using namespace std;

class Complex;
class External
{
	public:
	int a;
	External(int i): a(i){}
	friend class Complex;
	friend ostream& operator<<(ostream& out, const External& ex)
	{   
		out << ex.a;
		return out;
	}  
};
class Complex
{
	public:
		int a,b;
		void input(string s)
		{   
			int v1=0;
			int i=0;
			while(s[i]!='+')
			{   
				v1=v1*10+s[i]-'0';
				i++;
			}   
			while(s[i]==' ' || s[i]=='+'||s[i]=='i')
			{   
				i++;
			}   
			int v2=0;
			while(i<s.length())
			{   
				v2=v2*10+s[i]-'0';
				i++;
			}   
			a=v1;
			b=v2;
		}   

		Complex operator+(const Complex& iComplex)
		{   
			Complex temp;
			temp.a = a+iComplex.a;
			temp.b = b+iComplex.b;
			return temp;
		}   

		friend ostream& operator<<(ostream& out, const Complex& iComplex)
		{   
			out << iComplex.a << "+i" << iComplex.b;
			return out;
		}  

		Complex& operator=(const Complex& iComplex)
		{
			if (this == &iComplex)
			{
				//self
				return *this;
			}
			a=iComplex.a;
			b=iComplex.b;
			return *this;
		}

		friend class External;
		friend External& operator+(External& ex, const Complex& iComplex)
		{
			ex.a = ex.a+iComplex.a;
			return ex;
		}
		
};



int main()
{
	Complex x,y;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	x.input(s1);
	y.input(s2);
	Complex z=x+y;
	cout<<z<<endl;

	External aEx(10);

	aEx=aEx+x;
	cout<<aEx<<endl;
}

//**Note also that when you overload operators, at least one operand must be a class object

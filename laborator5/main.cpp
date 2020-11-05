#include<iostream>
using namespace std;


class Constr_Destr{
		protected:
			Constr_Destr(){}
			~Constr_Destr(){}

		private:
			Constr_Destr(const Constr_Destr&);
			Constr_Destr& operator=(const Constr_Destr&);
};


class Car : private Constr_Destr
{
	public:
		Car(const string name, const int an):
		name(name),
		an(an){};

	void accelereaza()
	{
		cout<<"Accelereaza"<<"\n";

	}

	protected:
		const string name;
		const int an;

};


class BMW: public Car
{
	public:
		BMW(const string name, const int an):
		Car(name,an){};

		void semnalizeaza()
		{
			cout<<"Bmw semnalizeaza"<<"\n";
		}

};

class Audi: public Car
{
	public:
		Audi(const string name, const int an):
		Car(name,an){};

		void franeaza()
		{
			cout<<"Audi franeaza"<<"\n";
		}


};

int main()
{
	BMW b("Seria 5", 2005);
	b.accelereaza();
	b.semnalizeaza();

	Audi a("A4", 2010);
	a.accelereaza();
	a.franeaza();

	return 0;

}
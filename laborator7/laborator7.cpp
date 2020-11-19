#include<iostream>
#include <memory>
using namespace std;

//18
struct Age{
	explicit Age(int varsta)
	: nr(varsta) {}
	int nr;
};


class Buyer{
	public:
		Buyer(const Age& varsta)
			: varsta(varsta)
			{};
	private:
		Age varsta;

};
//18




class Car
{
public:
	Car() { ; }
	Car(string name, int an) {
		this->name = name;
		this->an = an;
	}
	~Car() { ; }
	string getName()
	{
		return this->name;
	}
	Car operator=(const Car& elem)
	{
		this->name = elem.name;
		this->an = elem.an;
	}
	void accelereaza()
	{
		cout << name << " accelereaza" << "\n";
	}
	void semnalizeaza()
	{
		cout << name << " semnalizeaza" << "\n";
	}
	void franeaza()
	{
		cout << name << " franeaza" << "\n";
	}

	void copy(Car* elem)
	{
		this->name = elem->name;
		this->an = elem->an;
	}

	
	//item 22
	int getAn() const{
		return an;
	}

	string getName() const{
		return name;
	};




	private:
					string name;
					int an;

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

void function1()
{
	std::auto_ptr<Audi> a1(new Audi("A8", 2012)); //item13
	a1.get()->franeaza(); //item15

}


void verifica_ITP(const Car& masina)
{
	if(masina.getAn()<2010)
		{
			cout<<"ITP ANUAL"<<"\n";
		}
	else
	    {
	        cout<<"ITP la 2 ani"<<"\n";
	    }
}


int main()
{
	BMW b("Seria 5", 2005);
	b.accelereaza();
	b.semnalizeaza();

	Audi a("A4", 2011);
	a.accelereaza();
	a.franeaza();


	Car* audi = new Car("Audi", 2000);
	Car* bmw = new Car("Bmw", 1999);
	Car* masina = new Car();
	audi->accelereaza();
	bmw->accelereaza();
	audi->franeaza();
	masina = audi;
	masina->accelereaza();
	cout << masina->getName() << "\n";
	masina->copy(bmw);
	masina->accelereaza();
	
	cout<<"LAB6"<<"\n";
	function1();

	//item 18
	Buyer *buyer = new Buyer(Age(18));

	//item 22
	cout<<masina->getName();
	
	//item 20
	cout<<"\n";
	verifica_ITP(*audi);


	return 0;

}
#include<iostream>
#include <memory>
#include <mutex>
using namespace std;

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

void function2(std::auto_ptr<Audi> a) //item14
{
	std::mutex mutexPtr
	mutexPtr.lock();
	a->franeaza();
	mutexPtr.unlock();
	
}

void function1()
{
	std::auto_ptr<Audi> a1(new Audi("A8", 2012)); //item13
	a1.get()->franeaza(); //item15
	cout<<"..."<<"\n";
	function2(a1);

}


int main()
{
	BMW b("Seria 5", 2005);
	b.accelereaza();
	b.semnalizeaza();

	Audi a("A4", 2010);
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
	return 0;

}
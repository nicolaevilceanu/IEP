#include<iostream>
using namespace std;


class MyClass {
	public: 
			MyClass(const int number)
			: number(number)
			{};

			~MyClass(){
				cout<<"Destruct";
			};


			MyClass& operator=(const MyClass& copy) {
				number = copy.number;
				return *this;
			};


			void printInfo(){
				cout<<number<<"\n";

			}



	private:
			int number;

			MyClass(MyClass& copy)
			{
				number=copy.number;

			};


};


int main(){
		MyClass* first = new MyClass(12);
		MyClass* second = new MyClass(5);

		first->printInfo();
		second->printInfo();


		*first = *second;
		first->printInfo();

		delete first;
		delete second;
		return 0;

}

#include <iostream>
#include<list>
#include<string>
#include<iterator>
using namespace std;


class Pasare
{
public:
    int countGaini=0;
    int countGainiStrut=0;
    virtual void zboara() = 0;
    virtual void sunet() = 0;
    Pasare &operator+(const Pasare& elem);
    int getCountGaini()const{
        return countGaini;
    }
    int getCountGainiStrut()const{
        return countGainiStrut;
    }

};


class Papagal : public Pasare
{
    list<string> wordList;
    int distanta;
    string sunetFacut;
public:
    Papagal(int distanta, string sunetFacut){
        this->distanta=distanta;
        this->sunetFacut=sunetFacut;
    }

    void addWords(string Word)
    {
        wordList.push_front(Word);
    }

    void showWords()
    {
        list<string>::iterator iter;
        for(iter=wordList.begin(); iter!=wordList.end();iter++)
        {
         cout<<*iter<<"\n";
        }
    }

    void zboara()
    {
        cout<<"Distanta posibila de zbor a papagalului: "<<distanta<<"\n";
    }

    void sunet()
    {
        cout<<"Sunetul pe care il face: "<<sunetFacut<<"\n";
    }
    Papagal &operator+(const Pasare& elem){
        return *this;
    }

};




class Gaina : public Pasare{
int distanta;
string sunetFacut;
public:
    Gaina(int distanta, string sunetFacut){
        if(countGaini<30)
        {
            if(distanta>=10)
                throw string("Eroare: distanta prea mare de zbor pentru Gaina");
            this->distanta=distanta;
            this->sunetFacut=sunetFacut;
            countGaini++;
        }
        else
            throw string("Eroare: out of instances range for Gaina");
    }

    ~Gaina(){
        countGaini--;
    }

    void zboara()
    {
        cout<<"Distanta posibila de zbor a papagalului: "<<distanta<<"\n";
    }

    void sunet()
    {
        cout<<"Sunetul pe care il face: "<<sunetFacut<<"\n";
    }

    void decrement()
    {
        countGaini--;
    }
    Gaina &operator+(const Pasare& elem){
        return *this;
    }

};



class Strut : public Pasare
{
int distanta;
string sunetFacut;
static Strut *instance;
Strut(){;}
 Strut(int distanta, string sunetFacut){
        this->distanta=distanta;
        this->sunetFacut=sunetFacut;
    }
~Strut(){;}
public:
    static Strut *getInstance(int distanta, string sunet)
    {
        if(!instance){
            instance=new Strut(distanta,sunet);
        }
        return instance;
    }
    static void Destroy(){
        if(!instance)
            delete(instance);
    }
    void zboara()
    {
        cout<<"Distanta posibila de zbor a papagalului: "<<distanta<<"\n";
    }

    void sunet()
    {
        cout<<"Sunetul pe care il face: "<<sunetFacut<<"\n";
    }

    Strut &operator+(const Gaina& elem){
        this->countGainiStrut++;
        this->countGaini=elem.countGaini;
        this->countGaini--;
        return *this;
    }


};

Strut* Strut::instance=NULL;

int main()
{
    try{
    Papagal p(10,"Krrr");
    p.zboara();
    p.sunet();
    p.addWords("Masina");
    p.addWords("Ceva");
    p.addWords("Alooo");
    p.showWords();
    Gaina g(5,"Cucucucu");
    Gaina g2(7,"sdfsdfasdf");
    Gaina g3(3,"dhfdghdfghfdgh");
    g.zboara();
    g.sunet();


    Strut *instance=Strut::getInstance(10,"fgegeagae");

    cout<<instance->getCountGaini()<<endl;
    cout<<instance->getCountGainiStrut()<<endl;
    instance->sunet();
    *instance=*instance+g;
    cout<<instance->getCountGaini()<<endl;
    cout<<instance->getCountGainiStrut()<<endl;
    }
    catch(string& e)
    {
        cout<<e<<"\n";
    }

    return 0;
}

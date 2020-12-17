#include<iostream>
#include<list>
#include<iterator>
#include<math.h>

class Punct {
    int x;
    int y;

public:
    Punct() { ; }
    Punct(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX()const { return x; }
    int getY()const { return y; }

    void setPuncte(int x, int y)
    {
        this->x=x;
        this->y=y;

    }
};



class Figura {
public:
    std::list<Punct> puncte;
    virtual float perimetru()=0;
    float muchie(Punct elem1, Punct elem2) {
        int xval = elem2.getX() - elem1.getX();
        int yval = elem2.getY() - elem1.getY();
        return sqrt(pow(xval, 2) + pow(yval, 2));
    }

    void adaugaPunct(int x,int y){
        Punct *elem = new Punct(x,y);
        puncte.push_back(*elem);
    }

    template<typename T>
    T pantaDreptei()
    {
        std::list<Punct>::iterator it = puncte.begin();
        Punct aux1 = *it;
        std::advance(it,1);
        Punct aux2 = *it;
        return (aux2.getY()-aux1.getY()) / (aux2.getX()-aux1.getX());

    }


    std::list<Punct> getPuncte()const{
        return puncte;
    }

};
class Dreptunghi : public Figura {

public:
    float a;
    float b;
    float sum=0;
    float perimetru() {
        std::list<Punct>::iterator it = puncte.begin();
        Punct aux1 = *it;
        std::advance(it,1);
        Punct aux2 = *it;
        std::advance(it,1);
        Punct aux3 = *it;
        a = muchie(aux1,aux2);
        b = muchie(aux2,aux3);
        sum = 2*a+2*b;
        return sum;
    }
};


class Triunghi : public Figura {
public:
    float a;
    float b;
    float c;
    float sum=0;
    float perimetru() {
        std::list<Punct>::iterator it = puncte.begin();
        Punct aux1 = *it;
        std::advance(it,1);
        Punct aux2 = *it;
        std::advance(it,1);
        Punct aux3 = *it;

        a = muchie(aux1,aux2);
        b = muchie(aux2,aux3);
        c = muchie(aux1,aux3);
        sum = a+b+c;
        return sum;
    }
};

class Pentagon : public Figura {
public:
    float a;
    float b;
    float c;
    float d;
    float e;
    float sum = 0;
    float perimetru() {
        std::list<Punct>::iterator it = puncte.begin();
        Punct aux1 = *it;
        std::advance(it,1);
        Punct aux2 = *it;
        std::advance(it,1);
        Punct aux3 = *it;
        std::advance(it,1);
        Punct aux4 = *it;
        std::advance(it,1);
        Punct aux5 = *it;
        a = muchie(aux1,aux2);
        b = muchie(aux2,aux3);
        c = muchie(aux3,aux4);
        d = muchie(aux4,aux5);
        e = muchie(aux1,aux5);
        sum = a+b+c+d+e;
        return sum;
    }
};


class Cerc {
    Punct centru;
    int raza;
    static Cerc* instance;
    Cerc() { ; }
    Cerc(Punct elem,int raza){
        this->centru = elem;
        this->raza = raza;
    }
public:
    static Cerc* getInstance(Punct elem, int raza) {
        try{
        if (instance == NULL)
            instance = new Cerc(elem, raza);
        else{
            throw "Cercul este deja creat";
        }
        return instance;
        }

        catch(const char *elem){
            std::cout<<elem<<std::endl;
        }
    }
    static void destroy() {
        if (instance != NULL)
            delete(instance);
        instance = NULL;
    }

    template<typename T>
    void verificaCerc(T elem){
    int aux = 0;
    bool check = true;
    std::list<Punct> puncte = elem.getPuncte();
    std::list<Punct>::iterator iter;
    for(iter=puncte.begin(); iter!=puncte.end();iter++)
    {
        aux = pow(iter->getX() - centru.getX(),2) + pow(iter->getY() - centru.getY(),2);
        if(aux != pow(raza,2))
        {
            check = false;
        }

    }

    if(check == false)
    {
        std::cout<<"Figura nu apartine cercului"<<std::endl;
    }
    else{

        std::cout<<"Figura apartine cercului"<<std::endl;
    }

    }

};

Cerc* Cerc::instance=NULL;

int main()
{
    //Triunghi *t = new Triunghi();
    //t->adaugaPunct(0,1);
    //t->adaugaPunct(0,1);
    //t->adaugaPunct(1,0);
    //std::cout<<"Perimetru triunghi :  "<<t->perimetru()<<std::endl;
    //std::cout<<"Panta dreptei triunghi :"<<t->pantaDreptei<float>()<<std::endl;

    //Punct *cerc = new Punct(0,0);
    //Cerc *c = Cerc::getInstance(*cerc,1);
    //c->verificaCerc<Triunghi>(*t);
    Triunghi *t;
    Dreptunghi *d;
    Pentagon *p;
    Cerc *c;
    int choose;
    bool loop = true;

    while(loop)
    {
        std::cout<<"Optiuni\n"<<std::endl;
        std::cout<<"1.Adauga triunghi"<<std::endl;
        std::cout<<"2.Adauga dreptunghi"<<std::endl;
        std::cout<<"3.Adauga pentagon"<<std::endl;
        std::cout<<"4.Adauga cerc"<<std::endl;
        std::cout<<"5.Afisare panta triunghi"<<std::endl;
        std::cout<<"6.Afisare panta dreptunghi"<<std::endl;
        std::cout<<"7.Afisare panta pentagon"<<std::endl;
        std::cout<<"8.Verificare figura are punctele pe cerc"<<std::endl;
        std::cout<<"0.Exit"<<std::endl;
        std::cin>>choose;
        switch(choose){
            case 1:
                {t = new Triunghi();
                int x;
                int y;
                std::cout<<"Dati coordonatele celor 3 puncte"<<std::endl;
                for(int i=0;i<3;i++)
                {
                    std::cout<<"x=";
                    std::cin>>x;
                    std::cout<<"y=";
                    std::cin>>y;
                    t->adaugaPunct(x,y);
                }
                }
                break;

            case 2:
                {d = new Dreptunghi();
                int x;
                int y;
                std::cout<<"Dati coordonatele celor 3 puncte"<<std::endl;
                for(int i=0;i<3;i++)
                {
                    std::cout<<"x=";
                    std::cin>>x;
                    std::cout<<"y=";
                    std::cin>>y;
                    d->adaugaPunct(x,y);
                }
                }
                break;

            case 3:
                {p = new Pentagon();
                int x;
                int y;
                std::cout<<"Dati coordonatele celor 5 puncte"<<std::endl;
                for(int i=0;i<5;i++)
                {
                    std::cout<<"x=";
                    std::cin>>x;
                    std::cout<<"y=";
                    std::cin>>y;
                    p->adaugaPunct(x,y);
                }
                }
                break;

            case 4:
                {
                    int x;
                    int y;
                    int r;
                    std::cout<<"Coordonatele centrului cercului:"<<std::endl;
                    std::cout<<"x=";
                    std::cin>>x;
                    std::cout<<"y=";
                    std::cin>>y;
                    std::cout<<"Raza cercului: "<<std::endl;
                    std::cin>>r;
                    Punct *cerc = new Punct(x,y);
                    c = Cerc::getInstance(*cerc,r);
                }
                break;

            case 5:
                std::cout<<"Panta dreptei triunghi :"<<t->pantaDreptei<float>()<<std::endl;
                break;
            case 6:
                std::cout<<"Panta dreptei dreptunghi :"<<d->pantaDreptei<float>()<<std::endl;
                break;
            case 7:
                std::cout<<"Panta dreptei pentagon :"<<p->pantaDreptei<float>()<<std::endl;
                break;
            case 8:
                std::cout<<"Triunghi:"<<std::endl;
                c->verificaCerc<Triunghi>(*t);
                std::cout<<"Dreptunghi:"<<std::endl;
                c->verificaCerc<Dreptunghi>(*d);
                std::cout<<"Pentagon:"<<std::endl;
                c->verificaCerc<Pentagon>(*p);

            default:
                std::cout<<"default"<<std::endl;

        }


    }




    return 0;
}

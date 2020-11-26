#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>


MODULE_DESCRIPTION("Modul pentru mancare");
MODULE_AUTHOR("Vilceanu Nicolae");
MODULE_LICENSE("GPL");

typedef struct Food{
	int calories;
	int price;
	char *name;
}Food;


void Constr(Food *food, int cal, int p, char *n){
	food->calories=cal;
	food->price=p;	
	food->name=n;
}

void Copy(Food *food1, Food *food2){
	food1->calories=food2->calories;
	food1->price=food2->price;
	food1->name=food2->name;
}



void Info(Food *prep)
{
	printk(KERN_INFO "%s  %d   %d\n", prep->name, prep->calories, prep->price);	
}


static int my_init(void){

	Food food1;
	Food food2;
	Constr(&food1, 200,50,"Shoarma");
	Constr(&food2, 150, 40, "Burger");
	
	Info(&food1);
	Info(&food2);
	
	Copy(&food1, &food2);
	return 0;

}

static void my_exit(void)
{
	printk(KERN_ALERT "Finish!");

}


module_init(my_init);
module_exit(my_exit);




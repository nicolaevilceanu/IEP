obj-m += food.o

KDIR = /usr/src/linux-headers-$(shell uname -r)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order

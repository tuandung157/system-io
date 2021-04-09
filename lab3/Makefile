obj-m := lab3.o
all :
make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean :
make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
do:
sudo insmod lab3.ko
rm:
sudo rmmod lab3.ko
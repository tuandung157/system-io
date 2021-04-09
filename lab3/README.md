# Лабораторная работа 3

**Название:** "Разработка драйверов сетевых устройств"

**Цель работы:** ...

## Описание функциональности драйвера

...

## Инструкция по сборке

sudo make 
## Инструкция пользователя

sudo make do/sudo insmod lab3.ko

dmesg
```
[ 154.017868] lab3: create link vni0
[ 154.017869] lab3: registered rx handler for enp0s3
[ 154.052927] IPv6: ADDRCONF(NETDEV_UP): vni0: link is not ready
[ 154.052964] lab3: device opened: name=vni0
```
## Примеры использования
ip a
```
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
inet 127.0.0.1/8 scope host lo
valid_lft forever preferred_lft forever
inet6 ::1/128 scope host
valid_lft forever preferred_lft forever
2: enp0s3: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UP group default qlen 1000
link/ether 08:00:27:b2:e7:19 brd ff:ff:ff:ff:ff:ff
inet 192.168.8.101/24 brd 192.168.8.255 scope global dynamic noprefixroute enp0s3
valid_lft 85680sec preferred_lft 85680sec
inet6 fe80::774c:cebf:bb73:b65c/64 scope link noprefixroute
valid_lft forever preferred_lft forever
3: vni0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc fq_codel state UNKNOWN group default qlen 1000
link/ether 08:00:27:b2:e7:19 brd ff:ff:ff:ff:ff:ff
```

Send packets to interface 'enp0s3'
```
ping -c 1 -p 7472756E670a -s 6 192.168.8.101
ping -c 1 -p 6475630a -s 4 192.168.8.101
```

Check file '/proc/var1'
```
xoai@xoai-VirtualBox:~/Desktop/Work/system-io/lab3$ cat /proc/var1
trung
duc
```

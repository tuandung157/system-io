# Лабораторная работа 2

**Название:** "Разработка драйверов блочных устройств"

**Цель работы:** получить знания и навыки разработки драйверов блочных устройств для операционной системы Linux. 

## Описание функциональности драйвера

Один первичный раздел размером 10Мбайт и один  расширенный раздел, содержащий два логических раздела  размером 20Мбайт каждый.

## Инструкция по сборке

git clone https://github.com/tuandung157/system-io.git

cd lab1

make


## Инструкция пользователя

После успешной сборки загрузить полученный модуль:

insmod main.ko

## Примеры использования
 ---   lsblk -l /dev/mydisk
 
 
xoai@xoai-VirtualBox:~/Downloads/block_device$ lsblk -l /dev/mydisk

NAME MAJ:MIN RM SIZE RO TYPE MOUNTPOINT

mydisk 252:0 0 30M 0 disk

mydisk1 252:1 0 10M 0 part /mnt/mydisk1

mydisk2 252:2 0 1K 0 part

mydisk5 252:5 0 20M 0 part /mnt/mydisk5

mydisk6 252:6 0 10M 0 part /mnt/mydisk6

 --- fdisk -l /dev/mydisk
  
xoai@xoai-VirtualBox:~/Downloads/block_device$ fdisk -l /dev/mydisk

Disk /dev/mydisk: 30 MiB, 31457280 bytes, 61440 sectors

Units: sectors of 1 * 512 = 512 bytes

Sector size (logical/physical): 512 bytes / 512 bytes

I/O size (minimum/optimal): 512 bytes / 512 bytes

Disklabel type: dos

Disk identifier: 0x36e5756d


Device Boot Start End Sectors Size Id Type

/dev/mydisk1 1 20479 20479 10M 83 Linux

/dev/mydisk2 20480 102399 81920 40M 5 Extended

/dev/mydisk5 20481 61439 40959 20M 83 Linux

/dev/mydisk6 40961 81919 40959 20M 83 Linux

--- mount 
xoai@xoai-VirtualBox:~/Downloads/block_device$ sudo mkfs.vfat -F16 /dev/mydisk5

mkfs.fat 4.1 (2017-01-24)

xoai@xoai-VirtualBox:~/Downloads/block_device$ sudo mkdir -p /mnt/mydisk5

xoai@xoai-VirtualBox:~/Downloads/block_device$ sudo mount /dev/mydisk5 /mnt/mydisk5

xoai@xoai-VirtualBox:~/Downloads/block_device$ mount -l |grep "/dev/mydisk"

--- umount

xoai@xoai-VirtualBox:~/Downloads/block_device$ sudo umount /mnt/mydisk5

--- скорости копирования
root@xoai-VirtualBox:/mnt/mydisk5#  fallocate -l 5242880 /mnt/mydisk/tmp // file 5megabyte

root@xoai-VirtualBox:/mnt/mydisk5# pv -pr /mnt/mydisk5/tmp > /mnt/mydisk5/temp

[ 185MiB/s] [====================================================================================>] 100%

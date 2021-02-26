# Лабораторная работа 1

**Название:** "Разработка драйверов символьных устройств"

**Цель работы:**  получить знания и навыки разработки драйверов символьных устройств для операционной системы Linux.


## Описание функциональности драйвера

При записи текста в файл символьного устройства должен осуществляться подсчет введенных символов. Последовательность полученных результатов (количество символов) с момента загрузки модуля ядра должна выводиться при чтении созданного файла /proc/varN в консоль пользователя.
При чтении из файла символьного устройства в кольцевой буфер ядра должен осуществляться вывод тех же данных, которые выводятся при чтении файла /proc/varN.

## Инструкция по сборке

git clone https://github.com/tuandung157/system-io.git

cd lab1

make

## Инструкция пользователя

Для загрузки драйвера необходимо запустить комманду:
sudo insmod lab1.ko
Для записи данных в символьное устройство необходимо использовать комманду:
echo "test" > /dev/lab11
Для чтения proc файл:
chat /proc/var1
Для чтения символьного устройства:
cat /dev/lab11
Для проверки кольцевого буфера:
dmesg
Для выгрузки драйвера:
sudo rmmod lab1
## Примеры использования

xoai@xoai-VirtualBox:~/Desktop/io-systems$ cd lab1
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ make
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ sudo insmod lab1.ko
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ sudo chmod 0666 /dev/lab11
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ echo "tran" > /dev/lab11
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ cat /dev/lab11
xoai@xoai-VirtualBox:~/Desktop/io-systems/lab1$ cat /proc/var1
4

### Вычисление свёртки (0, 1, 2, 8)

Для того чтобы собрать проект необходимо установить компилятор GCC, систему сборки CMake,  а так же библиотеки для языка Python для отображения результата (Numpy, Scipy, Matplotlib).

На Debian-подобной системе это можно сделать так:

```
sudo apt install gcc cmake python3-numpy python3-scipy python3-matplotlib
```

Сборка проекта:

```bash
# В папке проекта Convolution:
mkdir build
cd build 
cmake ..
make -j4
```

Запуск проекта:

```bash
./conv
```

Для отображения результат используйте соответствующий скрипт файл (описано в материалах).




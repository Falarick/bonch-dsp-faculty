### Рекурсивные структуры данных (6)

Для того чтобы собрать проект необходимо установить компилятор GCC, систему сборки CMake.

На Debian-подобной системе это можно сделать так:

```
sudo apt install gcc cmake
```

Сборка проекта:

```bash
# В папке проекта Tree:
mkdir build
cd build 
cmake ..
make -j4
```

Запуск проекта:

```bash
./tree
```




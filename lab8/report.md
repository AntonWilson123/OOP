# Отчет по лабораторной работе №8
## по курсу "Объектно-ориентированное программирование"

### Студент: Вильсон А.Ю.
### Группа: М80-208Б

### Цель работы:
1. Знакомство с параллельным программированием в С++.

### Задача
Используя структуры данных, разработанные для предыдущей лабораторной работы ЛР №6(контейнер 1-ого уровня и классы-фигуры) разработать алгоритм быстрой сортировки для класс-контейнера.

Необходимо разработать два вида алгоритма:
1. Обычный, без параллельных вызовов.
2. С использованием параллельных вызовов. В этом случае, каждый рекурсивный вызов сортировки должен создаваться в отдельном потоке.

Для создания потоков использовать механизмы:
* future
* packaged task/async

Для обеспечения потокобезопасности структур использовать механизмы:
* mutex
* lock quard

Программа должны позволять:
* Вводить произовльное количество фигур и добавлять их в контейнер.
* Распечатывать содержимое контейнера.
* Удалять фигуры из контейнера.
* Произовдить сортировку контейнера.

### Фигура: квадрат,прямоугольник, трапеция.
### Контейнер 1: очередь. Контейнер 2: список.

### Описание

Параллельное программирование - это техника программирования, которая использует преимущества многоядерных или многопроцессорных компьютеров и являвется подноможеством более широкого понятия многопоточности (multithreading).

Параллельное программирование может быть сложным, по его легче понять, если считать его не "трудным", а просто "немного иным". Оно выключает в себя все черты более традиционного, последовательного программирования, но в параллельном программировании имеются три дополнительных, четко опреденных этапа:
* Определение параллелизма: анализ задачи с целью выделить подзадачи, которые могут выполняться одновременно.
* Выявление параллелизма: измение структуры задачи таким образом, чтобы можно было эффективно выполнять подзадачи. Для этого часто требуетя найти зависимости между подзадачами и организовать исходный код так, чтобы ими можно было эффективно управлять.
* Выражение параллелизма: реализация параллельного алгоритма в исходном коде с помощьъ системы обозначений параллельного программироваения.


### Консоль
           tohess@tohess-VirtualBox:~/Лабораторные работы/2kurs/OOP/lab8$ ./lab8 
    -------Прямоугольник со сторонами:1, 132

    -------Прямоугольник со сторонами:756, 459

    -------Прямоугольник со сторонами:533, 219

    -------Прямоугольник со сторонами:48, 679

    -------Прямоугольник со сторонами:680, 935

    -------Прямоугольник со сторонами:384, 520

    -------Прямоугольник со сторонами:831, 35

    -------Прямоугольник со сторонами:54, 530

    -------Прямоугольник со сторонами:672, 8

    -------Прямоугольник со сторонами:384, 67

    Sort starting....
    -------Прямоугольник со сторонами:1, 132

    -------Прямоугольник со сторонами:672, 8

    -------Прямоугольник со сторонами:384, 67

    -------Прямоугольник со сторонами:54, 530

    -------Прямоугольник со сторонами:831, 35

    -------Прямоугольник со сторонами:48, 679

    -------Прямоугольник со сторонами:533, 219

    -------Прямоугольник со сторонами:384, 520

    -------Прямоугольник со сторонами:756, 459

    -------Прямоугольник со сторонами:680, 935



### Выводы

В этой лабораторной необходимо была релизована обычная быстрая сортировка и быстрая сортировка с использованием потоков. Лабораторная помогла лучше разобраться в том, что такое потоки, как их представить, как проверить с помощью стороннего ПО.

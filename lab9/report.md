# Отчет по лабораторной работе №9
## по курсу "Объектно-ориентированное программирование"

### Студент: Вильсон А.Ю.
### Группа: М80-208Б

### Цель работы:
1. Знакомство с лямбда-выражениями.

### Задача
Используя структуры данных, разработанные для предыдущей лабораторной работы ЛР №6(контейнер 1-ого уровня и классы-фигуры) необходимо разработать:

* Контейнер второго уровня с использованием шаблонов.
* Реализовать с помощью лямбда-выражений набор команд, совершающих операции над контейнером 1-ого уровня: генерация фигур со случайными значениями параметров, печать контейнера на экран, удаление элементов со значением площади меньше определенного числа.
* В контейнер второго уровня поместить цепочку команд.
* Реализовать цикл , который проходит по всем командам в контейнере второго уровня и вополняет их, применяя к контейнеру первого уровня. Для создания потоков использовать механизмы:
* future
* packaged task/async

Для обеспечения потокобезопасности структур использовать механизмы:
* mutex
* lock quard

### Фигура: квадрат,прямоугольник, трапеция.
### Контейнер 1: очередь. Контейнер 2: список.

### Описание

Лямбда-выражение - это удобный способ опредения анонимного объекта-функции непосредственно в месте его вызова или передачи в функцию в качестве аргумента. Обычно лямба-выражения используются для инкапсуляции нескольких строк кода, передаваемых алгоритмам или асинхронным методам. В итоге, мы получаем крайне удобную конструкцию, которая позвояет сделать код более лаконичным и устойчивым к изменениям.

Непосредственное объявление лямбда-функции состоит из трех частей. Первая часть (квадратные скобки) позволяет привязывать переменные, доступные в текущей областа видимости. Вторая часть (круглые скобки) указывает список принимаемых параметров лямбда-функции. Третья часть(фигурные скобки) содержит тело лямбда функции.

В настоящее время, учитывая, что достигли практически потолко по тактовой частоте и дальше идет рост количество ядер, появился запрос на параллелизм. В результате снова в моде стал функциональный подход, так как он очень хорошо работает в условиях параллелизма и не требует явных синхронизаций. Поэтому сейчас усиленно думают, как задействовать растущее число ядер процессора и как обеспечить атоматическое распараллеливание. А в функциональном программировании практически основа всего - лямбда. Учитывая, что функциональные языки переживают второе рождение, было бы странным, если бы функциональный подход не добавляли во все популярные языки. С++ - язык, поддерживающий много парадигм, поэтому нет ничего странного в использовании лямбда-функций и лямбда-выражений в нем.  
### Консоль
       tohess@tohess-VirtualBox:~/Лабораторные работы/2kurs/OOP/lab9$ ./lab9
      Command: print queue
      ERROR: QUEUE IS EMPTY
      Command: create quadrates
      Command: print queue
      -------Квадрат со стороной:1

      -------Квадрат со стороной:14

      -------Квадрат со стороной:76

      -------Квадрат со стороной:46

      -------Квадрат со стороной:54

      -------Квадрат со стороной:22

      -------Квадрат со стороной:5

      -------Квадрат со стороной:68

      -------Квадрат со стороной:68

      -------Квадрат со стороной:94

### Выводы

В этой лабораторной необходимо было реализовать лямбда-выражения.

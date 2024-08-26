# Решение квадратных уравнений
Мой проект умеет решать квадратные уравнения. Вы можете ввести коэффициенты уравнения типа a * x^2 + b * x + c  = 0 и программа выдаст ответ.Программа полезна тем, что коэффициенты не обязательно вводить вручную. У вас может быть файл с коэффициентами и программа сможет их все прочитать и выдать ответы.

## Содержание
- [Использование](#использование)
- [Тестирование](#тестирование)
- [FAQ](#FAQ)
- [Команда проекта](#команда-проекта)


## Использование
Чтобы начать работу с проектом, вы должны скачать все файлы из папки "square" (5 файлов типа cpp, 5 файлов типа hpp и 1 Makefile). Для работы с файлами вы должны либо скачать мой файл "coefficients_square.txt", поменять в нём коэффициенты на свои или иметь свой готовый файл. Сначала вам нужно скомпилировать файлы через Makefile командой терминале  "make all". Затем получается файл (в моём случае "result)". После этого в том же терминале вводите "./ресулт" и команды. Их 4 штуки: хелп, тест, солютион и филе <наме>. 


Например, вычисление дискриминанта:
```typescript
double count_discriminant (double *coefficient) 
{
    return coefficient[1] * coefficient[1] - 4 * coefficient[0] * coefficient[2];
}
```

### Требования
Для установки и запуска проекта, необходим [Makefile](https://sourceforge.net/projects/makefilecreator/)


### Создание билда
Чтобы выполнить компиляцию, выполните команду: 
```sh
make all
```

## Тестирование
Какие инструменты тестирования использованы в проекте и как их запускать. Например:

Наш проект покрыт юнит-тестами. Для их запуска выполните команду:
```sh
./result test
```
![image](https://github.com/user-attachments/assets/28d19e39-d861-415a-be75-b8202ace610f)


## FAQ 
Скоро здесь будут ваши вопросы и ответы на них.



## Команда проекта
Оставьте пользователям контакты и инструкции, как связаться с командой разработки.

- [Дед](https://t.me/ded_32) — глава
- [Андрей Житников](https://t.me/azhkov) — помощник главы
- [Олег Донцов](https://t.me/olleeg06) — подчинённый 

## Источники
- С. Прата "Язык Си, лекции и упражнения", 6-е изд. - https://vk.com/doc44301783_593010761

- Б. Керниган, Д. Ритчи "Язык Программирования Си", 3-е изд. - https://www.r-5.org/files/books/computers/languages/c/kr/Brian_Kernighan_Dennis_Ritchie-The_C_Programming_Language-RU.pdf

- М. Уэйт, С. Прата, Д. Мартин, "Язык Си для начинающих" - http://storage.ded32.net.ru/Lib/TX/CPrimerPlus.pdf

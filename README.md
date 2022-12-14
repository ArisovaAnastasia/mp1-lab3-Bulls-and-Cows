# Репозиторий для сдачи лабораторной работы №3 по курсу Основы программирования

## Разработать программу, реализующую игру «Быки и коровы».
Требования (правила).<br/>
•	Играют два игрока (человек и компьютер).<br/>
•	Игрок выбирает длину загадываемого числа – **n** (от 2 до 5 включительно).<br/>
•	Компьютер «задумывает» n-значное число с **неповторяющимися цифрами** (цифра 0 может стоять на любой позиции кроме первой).<br/>
•	Игрок делает попытку отгадать число – вводит n-значное число с неповторяющимися цифрами.<br/>
•	Компьютер сообщает количество коров и быков для введенного числа:<br/>
> **количество коров** - сколько цифр есть и в загаданном, и введенном числе, но при этом их позиции не совпадают (Например, 5239 и 2735. Здесь 2 коровы - это цифры 2    и 5);<br/>
> **количество быков** - сколько цифр угадано с точностью до позиции в загаданном числе (Например, 5239 и 2735. Здесь 1 бык - это цифра 3).<br/>
**Важно:** компьютер не сообщает к каким цифрам относятся быки и коровы! <br/>
•	Игрок делает попытки, пока не отгадает всю последовательность. <br/>
<br/>
Пример.<br/>
•	Пусть n = 4.<br/>
•	Пусть задумано число «3594».<br/>
•	Игрок ввел число «1568».<br/>
•	Результат: один «бык» (одна цифра «5» угадана вплоть до позиции).<br/>
• Игрок делает следующее предположение, основываясь на текущем количестве коров и быков.<br/>

<br/>

![image](https://user-images.githubusercontent.com/43183124/195835227-ea367e1e-0c75-4ed8-97e0-00a5193139e2.png)

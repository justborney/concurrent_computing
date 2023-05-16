### 1
Напишите многопоточную программу, находящую сумму минимальных элементов столбцов матрицы

- Матрица генерируется в потоках
- Матрица разбивается на блоки по столбцам (размерность матрицы делится на количество потоков, получается число столбцов на соответствующий поток)
- В каждом потоке, который обрабатывает свой блок находим сумму минимальных элементов столбцов

- Испольозвать std::vector
- Расчеты выполнять для 1, 4, 8, 16 потоков

- Расчет ускорения: время выполнения одним потоком делится на время выполнения n потоками
- Расчет эффективности: ускорение делится на количество потоков

Почему эффективность больше чем в 4 раза?
Помимо вычислений в каждом потоке отдельно ищется минимальная сумма, что так же дает ускорение.

### 2
Напишите многопоточную программу, умножающую две матрицы методом Кэннона

- Матрица генерируется в потоках
- Расчеты выполнять для 1, 4, 8, 16 потоков

- Расчет ускорения: время выполнения одним потоком делится на время выполнения n потоками
- Расчет эффективности: ускорение делится на количество потоков

- Подобрать размерность матриц такую, чтобы время выполнения одного потока было 3-4 секунды
- Нужно реализовать вывод матрицы результата умножения дву матриц 4x4


Материалы: https://intuit.ru/studies/courses/1156/190/lecture/4954?page=1

### 3
Напишите многопоточную программу, для параллельного решения СЛАУ методом Гаусса


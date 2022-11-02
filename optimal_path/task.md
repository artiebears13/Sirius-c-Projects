# Задача: Поиск оптимального маршрута

Робот движется по двумерной прямоугольной карте размером $N \times M$. Карта состоит из клеток, каждая клетка имеет высоту в диапазоне $[0,255]$. Из каждой клетки робот может перемещаться в трёх направлениях -- налево, направо или вниз (за исключением находящихся на границе клеток). При перемещении в новую клетку робот затрачивает энергию, равную 1 + высота этой клетки. Робот начинает своё движение из заданной точки $x_s$ самой верхней строки и должен прийти в заданную точку $x_f$ самой нижней строки карты. Необходимо написать программу, которая для заданной карты найдёт наименее энергозатратный маршрут для робота.

Карта -- изображение 3-x канальное в формате png, отрисовка карты делается синим цветом, и в программе выбирается только синий канал, в выходном изображении отрисовка пути производится красным цветом. В качестве входных изображений можно создавать изображания  в MS Paint или в любом растровом редакторе. При выборе цвета R и G значения должны равняться нулю, а B можно менять от 0 до 255. Пример изображения приведён ниже, красный путь не есть решение задачи, а просто иллюстрация того как он будет отрисован программой.

![Example](https://github.com/artiebears13/Sirius-c-Projects/blob/main/optimal_path/testImage/example.png)



## Входные данные:
Изображение в формате png, отрисовано оттенками синенго цвета (R=0, G=0, B=[0 ... 255]), количество строк (rows) и столбцов (cols) в изображение (в пикселях), а также пиксельная координата столбца начальной точки (x_s) в первой строке, и координата столбца финальной точки (x_f) в последней строке.

## Выходные данные:
Картинка  в формате png с прочерченным оптимальным путём из начальной точки в конечную.

## Запуск программы:
```
$ program_name input_img.png <rows> <cols> <x_s> <x_f> output_img.png
```
Например
```
$ program_name input_img.png 450 250 0 249 output_img.png
```
, где начальная точка в данном случае в левом верхнем углу, а конечная в правом нижнем (нумерация строк и столбцов начинатется с 0, как и у массивов).


---------------------------

# Task: Finding the best route

The robot moves along a two-dimensional rectangular map of size $N \times M$. 
The map consists of cells, each cell has a height in the range of $[0,255]$.
From each cell, the robot can move in three directions - to the left, to the right or down (with the exception of cells located on the border). 
When moving to a new cell, the robot expends energy equal to 1 + the height of this cell.
The robot starts its movement from the given point $x_s$ of the uppermost row and must come to the given point $x_f$ of the lowermost row of the map.
It is necessary to write a program that for a given map will find the least energy-consuming route for the robot.

The map is a 3-channel image in png format, the map is drawn in blue, and only the blue channel is selected in the program, in the output image the path is drawn in red. As input images, you can create images in MS Paint or any raster editor.
When choosing a color, R and G values ​​must be zero, and B can be changed from 0 to 255. An example image is given below, the red path is not a solution to the problem, but simply an illustration of how it will be drawn by the program.

![Example](https://github.com/artiebears13/Sirius-c-Projects/blob/main/optimal_path/testImage/example.png)
#include <iostream>
#include <lodepng.h>
#include <vector>
#include <cstdint>
#include <string>
#include <limits>
#include "datas.h"
#include "min_search.h"


using namespace std;

void decodeFromPng(std::vector<unsigned char> &image, const char *filename, unsigned height, unsigned width) {
    /*
     * Функция для чтения png файла
     */
    std::vector<unsigned char> png;
    //load and decode
    unsigned error = lodepng::load_file(png, filename);
    if (!error) error = lodepng::decode(image, width, height, png);

    //if there's an error, display it
    if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ... 
}

void getBlueChannel(const std::vector<unsigned char> &image, int **arr, int rows, int cols) {
    /*
     * Функция, которая выделяет синий канал из одномерного вектора и
     * заполняет им двумерный массив
     */
    for (int i = 2, j = 0, k = 0; i < image.size(); i += 4, ++k) {
        if (k == cols) {
            k = 0; // обнуляем номер столбца
            ++j; // увеличиваем номер строки
        }
        arr[j][k] = int(image[i]);
    }
}

void printArray(int **arr, int rows, int cols) {
    /*
     * Функция для вывода массива в консоль
     */
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void drawPath(const vector<int> &path, vector<unsigned char> &image, int rows, int cols, const char *output_file) {
    int i = 0, j = -1;
    int previousPoint = -1;
    for (auto &e: path) {
        if (previousPoint == e)
            ++i;
        else
            j = e;
        previousPoint = e;
        // draw red path R = 255, G = 0, B = 0
        int index = (i * cols + j) * 4;
        image[index] = (unsigned char) 255;
        image[++index] = (unsigned char) 0;
        image[++index] = (unsigned char) 0;
    }



    //Encode the image
    unsigned error = lodepng::encode(output_file, image, cols, rows);

    //if there's an error, display it
    if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

void findOptimalPath(int **arr, vector<int> &path, int x_i, int x_f, int rows, int cols) {
    //--------------------------------------------------------------------------------
    // Напишите ваш код здесь

    Vertice p[rows][cols];
    path.clear();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            p[i][j].own_weight = arr[i][j];
            p[i][j].visited = false;
            p[i][j].path_weight = std::numeric_limits<int>::max();
            p[i][j].previous = none;
        }
    }
    p[0][x_i].path_weight = 0;


    output_matrix(&p[0][0], rows, cols);

    bool end = false;  //end=true if all points was visited
    while (!end) {


//      searching min weight not visited point

        std::pair<int, int> min_ind;
        min_ind = min_search(&p[0][0], rows, cols);

        //if min_i!=-1 we found min point and can check neighbours
        if (min_ind.first != -1) {

//-----------------checking bottom point (if bottom element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.first != rows - 1)
                && (!p[min_ind.first + 1][min_ind.second].visited)
                && (p[min_ind.first + 1][min_ind.second].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first + 1][min_ind.second].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first + 1][min_ind.second].previous = up;
            }

//----------------checking right point (if right element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.second != cols - 1)
                && (!p[min_ind.first][min_ind.second + 1].visited)
                && (p[min_ind.first][min_ind.second + 1].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first][min_ind.second + 1].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first][min_ind.second + 1].previous = lleft;
            }
//----------------checking left point (if left element exist and not visited and its path_weight>now element path weight + own weight)
            if ((min_ind.second != 0)
                && (!p[min_ind.first][min_ind.second - 1].visited)
                && (p[min_ind.first][min_ind.second - 1].path_weight >
                    p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight)) {

                p[min_ind.first][min_ind.second - 1].path_weight =
                        p[min_ind.first][min_ind.second].path_weight + p[min_ind.first][min_ind.second].own_weight;
                p[min_ind.first][min_ind.second - 1].previous = rright;
            }

            p[min_ind.first][min_ind.second].visited = true;  //after checked all neighbours dot became visited

        } else {
            end = true;   //if didnt found min = all points visited
        }
    }

    std::cout << std::endl << "PATH WEIGHT:" << p[rows - 1][4].path_weight << std::endl;

    std::pair<std::vector<int>, std::vector<int>> path_back;
    path_back = get_path(&p[0][0], rows, cols, x_i, x_f);
    std::cout << "PATH: ";

    for (int l = path_back.second.size() - 1; l >= 0; --l) {
        path_back.first[l] = rows - 1 - path_back.first[l];
        path.push_back(path_back.second[l]); // path_back.second[l] << " " << path_back.first[l] << std::endl;
    }
//    plot(file_path);

    //path.push_back();
    //--------------------------------------------------------------------------------
}

int main(int argc, char *argv[]) {

    if (argc != 7) {
        cerr << "Wrong input arguments" << endl;
        return -1;
    }
    int rows = stoi(argv[2]), cols = stoi(argv[3]); // определение строк и столбцов как у матрицы в математике
    int x_i = stoi(argv[4]), x_f = stoi(argv[5]);
    char *input_file = argv[1], *output_file = argv[6];
    // читаем png изображение
    std::vector<unsigned char> image; // vector to store value of pixels with all 4 channels RGBA
    decodeFromPng(image, input_file, rows, cols); // read png file

    // способ 3 стр. 115 создания двумерного массива
    // выделяем память

    int **arr = new int *[rows];
    for (int row = 0; row < rows; ++row)
        arr[row] = new int[cols];

    // инициализируем выделенный массив arr синим каналом нашего изображения
    getBlueChannel(image, arr, rows, cols);

    // можно опционально выводить массив в консоль для отладки 
    printArray(arr, rows, cols);

    //функцию ниже вам нужно реализовать
    //-----------------------------------------------------------------------------
    vector<int> path;  // вектор к которому нужно делать push_back для добавления точек пути 
    findOptimalPath(arr, path, x_i, x_f, rows, cols);
    //------------------------------------------------------------------------------


    // далее можно отрисовать path используя фукцию ниже
    drawPath(path, image, rows, cols, output_file);

    // очищаем память
    for (int row = 0; row < rows; ++row)
        delete[] arr[row];
    delete arr;
    getchar();
}


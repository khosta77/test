#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <map>
#include <algorithm>

#include "./test/test.h"

int test1();
int test2();
int test3();
int test4();
int test5();
int test6();
int test7();
int test8();
int test9();
int test10();


std::pair<int, int> getTwoMaxElementFromVector(const std::vector<int> &arr) {
    // 1. Проверка на размер массива
    //    Она должна быть в любом случае, в варианте где я коворил про 3 строчки,
    //    то эти две строки должны были быть как:
    //      assert((arr.size() < 2));
    if (arr.size() < 2)
        return std::pair<int, int>(-1, -1);

    // 2. Алгоритма поиска ДВУХ максимальных значений
    //    Предлагаю несколько вариантов
#if 0
    // Обзначим этот вариант как stupid, идея максимально простая - 
    // отсортировать массив и взять два максимальных элемента, НО так как
    // Массив константный, то это не вариант, его надо дополнительно скопировать, 
    // в буфер. Если честно, я и предполагал это решение. Так как я считаю что код
    // Должен быть легко читаемым, и три строки(первая проверка, вторая сортировка и 
    // третья возврат значения) читаются легко + в книгах пишут максимально короткие функции.
    // Но Денис Алексеевич добавил const тогда решение не подходит. Хотя я бы такое принял.
#elif 1
    // Второй вариант: Идея заключается в том, что мы сразу берем первый и второй элемент массива,
    // И сравниваем их с последующими. Сложность O(N), так как обход только 1. Явлется весьма оптимальным
    auto Max = (arr[0] > arr[1]) ? std::pair<int, int>(arr[0], arr[1]) : std::pair<int, int>(arr[1], arr[0]);
    for (size_t i = 2; i < arr.size(); i++) {
        if (Max.first < arr[i]) {
            Max.second = Max.first;
            Max.first = arr[i];
        } else if (Max.second < arr[i]) {
            Max.second = arr[i];
        }
    }
    return Max;
#elif 0
    // Есть еще третий способ решить эту задачу, спомощью указателей идти слева и справа по вектору.
    // Буду честен, я не очень понял этот способ, в пример привести не смогу. 
    // Но как сказал Денис Алексеевич, такой способ есть.
#endif
	return std::pair<int, int>(0, 0);
}

int main() {
	MyTest tt;
	tt.add(*test1);
	tt.add(*test2);
	tt.add(*test3);
	tt.add(*test4);
	tt.add(*test5);
	tt.add(*test6);
	tt.add(*test7);
	tt.add(*test8);
	tt.add(*test9);
	tt.add(*test10);
	return tt.make();
}

// Проверка массива равно 0
int test1() {
    std::vector<int> arr;
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == -1) && (res.second == -1))
		return 0;
	return 1;
}

// Проверка ммасива с одним элементом
int test2() {
    std::vector<int> arr = { 10};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == -1) && (res.second == -1))
		return 0;
	return 1;
}

// Проверка массива с двумя элементами
int test3() {
    std::vector<int> arr = { 10, 1};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 10) && (res.second == 1))
		return 0;
	return 1;
}

int test4() {
    std::vector<int> arr = { 10, 1, 0, 5};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 10) && (res.second == 5))
		return 0;
	return 1;
}

int test5() {
    std::vector<int> arr = { -3, -2, -1, 0};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 0) && (res.second == -1))
		return 0;
	return 1;
}

int test6() {
    std::vector<int> arr = { -3, -2, -6};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == -2) && (res.second == -3))
		return 0;
	return 1;
}

int test7() {
    std::vector<int> arr = { 10, 1, 100, 5};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 100) && (res.second == 10))
		return 0;
	return 1;
}

int test8() {
    std::vector<int> arr = { 10, 1, 8, 11, 0, 5};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 11) && (res.second == 10))
		return 0;
	return 1;
}

int test9() {
    std::vector<int> arr = { 8, 1, 11, 9, 5};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 11) && (res.second == 9))
		return 0;
	return 1;
}

int test10() {
    std::vector<int> arr = { -1, -6, -3,  -2, 0, 5};
    auto res = getTwoMaxElementFromVector(arr);
	if ((res.first == 5) && (res.second == 0))
		return 0;
	return 1;
}



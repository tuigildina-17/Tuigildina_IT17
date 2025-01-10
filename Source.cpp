#include "Header.h"

// Функция для проверки корректности ввода
bool is_correct(const string& str) {

    // Проверяем длину
    if (str.length() <= 20) {
        return false; // Если длина 20 или меньше - некорректно
    }

    // Проверяем, что все символы - цифры
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // Если найден символ, не являющийся цифрой - некорректно
        }
    }

    return true; // Если прошел все проверки, корректно
}


// Функция для нахождения остатка от деления большого числа на другое большое число
string ost_ot_del(const string& num1, const string& num2) {

    string ost = ""; // Вводим переменную для хранения остатка на каждом этапе (инициализируется пустой строкой)

    // Сравниваем все разряды числа
    for (int i = 0; i < num1.length(); i++) {
        ost += num1[i]; // Добавляем каждый символ к ost

        // Удаляем незначащие нули в начале
        while (ost.length() > 1 && ost[0] == '0') {
            ost.erase(ost.begin());
        }

        // Если текущий остаток меньше делителя, просто продолжаем
        if (ost.length() < num2.length() || (ost.length() == num2.length() && ost < num2)) {
            continue;
        }

        // Если текущий остаток больше или равен делителю, вычитаем делитель
        while (ost.length() > 0 && (ost.length() > num2.length() || (ost.length() == num2.length() && ost >= num2))) {
            string vr_ost = ""; // Переменная для хранения временного результата вычитания
            int per = 0; // Переменная для хранения переноса, если результат вычитания отрицательный

            for (int j = 0; j < ost.length(); j++) {
                int digit1 = ost[ost.length() - 1 - j] - '0'; // digit1 - это текущая цифра из ost
                int digit2 = (j < num2.length() ? num2[num2.length() - 1 - j] - '0' : 0); // digit2 - это текущая цифра из num2

                int sub = digit1 - digit2 - per;
                if (sub < 0) {
                    sub += 10; // Берем со следующего разряда
                    per = 1; // Устанавливаем перенос (добавляем 1 к след. разряду)
                }
                else {
                    per = 0; // Нет переноса
                }

                vr_ost = char(sub + '0') + vr_ost; // Результат каждого шага добавляем к vr_ost и преобразуем число sub в символ
            }

            // Удаляем ведущие нули у временного остатка
            while (vr_ost.length() > 1 && vr_ost[0] == '0') {
                vr_ost.erase(vr_ost.begin());
            }

            ost = vr_ost; // Новый остаток после вычитания
        }
    }

    // Если остаток пустой, то возвращаем 0
    if (ost.empty()) {
        return "0";
    }

    return ost;
}

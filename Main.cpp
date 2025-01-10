#include "Header.h"

int main() {

    setlocale(LC_ALL, "ru");

    string num1, num2;
    
    // Ввод первого числа
    do {
        cout << "Введите m-значное число (m > 20): ";
        cin >> num1;
        if (!is_correct(num1)) {
            cout << "Ошибка: число должно быть более 20 знаков и содержать только цифры!" << endl;
        }
    } while (!is_correct(num1)); // Цикл продолжается, пока функция не вернёт true

    // Ввод второго числа
    do {
        cout << "Введите n-значное число (n > 20): ";
        cin >> num2;
        if (!is_correct(num2)) {
            cout << "Ошибка: число должно быть более 20 знаков и содержать только цифры!" << endl;
        }
    } while (!is_correct(num2));

    // Находим остаток
    string result = ost_ot_del(num1, num2);

    // Выводим результат
    cout << "Остаток от деления: " << result << endl;

    return 0;
}


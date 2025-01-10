#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using namespace std;

// Функция для проверки корректности ввода
bool is_correct(const string& str);

// Функция для нахождения остатка от деления большого числа на другое большое число
string ost_ot_del(const string& num1, const string& num2);

#endif
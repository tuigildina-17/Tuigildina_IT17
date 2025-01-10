#include "Header.h"

// ������� ��� �������� ������������ �����
bool is_correct(const string& str) {

    // ��������� �����
    if (str.length() <= 20) {
        return false; // ���� ����� 20 ��� ������ - �����������
    }

    // ���������, ��� ��� ������� - �����
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // ���� ������ ������, �� ���������� ������ - �����������
        }
    }

    return true; // ���� ������ ��� ��������, ���������
}


// ������� ��� ���������� ������� �� ������� �������� ����� �� ������ ������� �����
string ost_ot_del(const string& num1, const string& num2) {

    string ost = ""; // ������ ���������� ��� �������� ������� �� ������ ����� (���������������� ������ �������)

    // ���������� ��� ������� �����
    for (int i = 0; i < num1.length(); i++) {
        ost += num1[i]; // ��������� ������ ������ � ost

        // ������� ���������� ���� � ������
        while (ost.length() > 1 && ost[0] == '0') {
            ost.erase(ost.begin());
        }

        // ���� ������� ������� ������ ��������, ������ ����������
        if (ost.length() < num2.length() || (ost.length() == num2.length() && ost < num2)) {
            continue;
        }

        // ���� ������� ������� ������ ��� ����� ��������, �������� ��������
        while (ost.length() > 0 && (ost.length() > num2.length() || (ost.length() == num2.length() && ost >= num2))) {
            string vr_ost = ""; // ���������� ��� �������� ���������� ���������� ���������
            int per = 0; // ���������� ��� �������� ��������, ���� ��������� ��������� �������������

            for (int j = 0; j < ost.length(); j++) {
                int digit1 = ost[ost.length() - 1 - j] - '0'; // digit1 - ��� ������� ����� �� ost
                int digit2 = (j < num2.length() ? num2[num2.length() - 1 - j] - '0' : 0); // digit2 - ��� ������� ����� �� num2

                int sub = digit1 - digit2 - per;
                if (sub < 0) {
                    sub += 10; // ����� �� ���������� �������
                    per = 1; // ������������� ������� (��������� 1 � ����. �������)
                }
                else {
                    per = 0; // ��� ��������
                }

                vr_ost = char(sub + '0') + vr_ost; // ��������� ������� ���� ��������� � vr_ost � ����������� ����� sub � ������
            }

            // ������� ������� ���� � ���������� �������
            while (vr_ost.length() > 1 && vr_ost[0] == '0') {
                vr_ost.erase(vr_ost.begin());
            }

            ost = vr_ost; // ����� ������� ����� ���������
        }
    }

    // ���� ������� ������, �� ���������� 0
    if (ost.empty()) {
        return "0";
    }

    return ost;
}

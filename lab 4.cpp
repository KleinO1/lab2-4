#include <iostream>
using namespace std;

float dayAverage(float* row, int h) {
    float sum = 0.0f;
    for (int j = 0; j < h; ++j) {
        sum += *(row + j);
    }
    return sum / h;
}

float overallAverage(float** p, int d, int h) {
    float sum = 0.0f;
    int total = d * h;

    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < h; ++j) {
            sum += *(*(p + i) + j);
        }
    }
    return sum / total;
}

void showHotDays(float** p, int d, int h) {
    float overall = overallAverage(p, d, h);

    cout << "Общая средняя температура: " << overall << endl;
    cout << "Теплые дни:" << endl;

    int countHot = 0;

    for (int i = 0; i < d; ++i) {
        float avgDay = dayAverage(*(p + i), h);
        if (avgDay > overall) {
            cout << "День " << (i + 1) << " (среднее = " << avgDay << ")" << endl;
            countHot++;
        }
    }

    if (countHot == 0) {
        cout << "Нет дней с температурой выше общей средней." << endl;
    }
}


int main() {
    int d, h;

    cout << "Введите количество дней: ";
    cin >> d;

    cout << "Введите количество измерений в дне: ";
    cin >> h;

    if (d < 1 || d > 30 || h < 1 || h > 24) {
        cout << "Ошибка: максимум 30 дней и максимум 24 измерения." << endl;
        return 0;
    }

    float** data = new float*[d];
    for (int i = 0; i < d; ++i) {
        *(data + i) = new float[h];
    }

    for (int i = 0; i < d; ++i) {
        cout << "День " << (i + 1) << ": ";
        for (int j = 0; j < h; ++j) {
            cin >> *(*(data + i) + j);
        }
    }

    showHotDays(data, d, h);

    for (int i = 0; i < d; ++i) {
        delete[] *(data + i);
    }
    delete[] data;

    return 0;
}

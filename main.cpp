#include <iostream>
using namespace std;

void inputData(float* p, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> *(p + i);
    }
}

float average(const float* p, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        sum += *(p + i);
    }
    return sum / n;
}

float minValue(const float* p, int n) {
    float minVal = *p;
    for (int i = 1; i < n; ++i) {
        if (*(p + i) < minVal) {
            minVal = *(p + i);
        }
    }
    return minVal;
}

float maxValue(const float* p, int n) {
    float maxVal = *p;
    for (int i = 1; i < n; ++i) {
        if (*(p + i) > maxVal) {
            maxVal = *(p + i);
        }
    }
    return maxVal;
}

float* filterAboveAverage(float* p, int n, int& newCount) {
    float avg = average(p, n);

    newCount = 0;
    for (int i = 0; i < n; ++i) {
        if (*(p + i) > avg) {
            ++newCount;
        }
    }

    float* result = new float[newCount];
    int index = 0;

    for (int i = 0; i < n; ++i) {
        if (*(p + i) > avg) {
            *(result + index) = *(p + i);
            ++index;
        }
    }

    return result;
}

int main() {
    cout << "=== Анализ сенсора ===" << endl;

    int n;
    cout << "Введите количество измерений: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректный размер массива." << endl;
        return 0;
    }

    float* data = new float[n];

    cout << "Введите значения: ";
    inputData(data, n);

    float avg = average(data, n);
    float mn = minValue(data, n);
    float mx = maxValue(data, n);

    cout << "Среднее значение: " << avg << endl;
    cout << "Минимум: " << mn << endl;
    cout << "Максимум: " << mx << endl;

    int newCount = 0;
    float* above = filterAboveAverage(data, n, newCount);

    cout << "Значения выше среднего: ";

    if (newCount == 0) {
        cout << "Нет значений выше среднего.";
    } else {
        for (int i = 0; i < newCount; ++i) {
            cout << *(above + i) << " ";
        }
    }

    cout << endl;

    delete[] data;
    delete[] above;

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 50

int cay[MAX];
int dem = 0;

bool cayRong() {
    return dem == 0;
}

void themGoc(int x) {
    cay[1] = x;
    dem = 1;
}

void themTrai(int cha, int x) {
    cay[cha * 2] = x;
    if (cha * 2 > dem) dem = cha * 2;
}

void themPhai(int cha, int x) {
    cay[cha * 2 + 1] = x;
    if (cha * 2 + 1 > dem) dem = cha * 2 + 1;
}

void duyetTruoc(int i) {
    if (i <= dem) {
        cout << cay[i] << " ";
        duyetTruoc(i * 2);
        duyetTruoc(i * 2 + 1);
    }
}

void duyetGiua(int i) {
    if (i <= dem) {
        duyetGiua(i * 2);
        cout << cay[i] << " ";
        duyetGiua(i * 2 + 1);
    }
}

void duyetSau(int i) {
    if (i <= dem) {
        duyetSau(i * 2);
        duyetSau(i * 2 + 1);
        cout << cay[i] << " ";
    }
}


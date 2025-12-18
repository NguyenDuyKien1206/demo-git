#include <iostream>
using namespace std;

#define MAX 50
int cay[MAX];
int dem = 0;

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

void duyetTruocMang(int i) {
    if (i <= dem) {
        cout << cay[i] << " ";
        duyetTruocMang(i * 2);
        duyetTruocMang(i * 2 + 1);
    }
}


struct Nut {
    int gt;
    Nut* trai;
    Nut* phai;
};

Nut* taoNut(int x) {
    Nut* n = new Nut;
    n->gt = x;
    n->trai = NULL;
    n->phai = NULL;
    return n;
}

void duyetTruocConTro(Nut* n) {
    if (n != NULL) {
        cout << n->gt << " ";
        duyetTruocConTro(n->trai);
        duyetTruocConTro(n->phai);
    }
}

int main() {
    cout << "Cay tuan tu: ";
    themGoc(1);
    themTrai(1, 2);
    themPhai(1, 3);
    duyetTruocMang(1);

    cout << "\nCay moc noi: ";
    Nut* goc = taoNut(1);
    goc->trai = taoNut(2);
    goc->phai = taoNut(3);
    duyetTruocConTro(goc);

    return 0;
}


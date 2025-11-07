#include <iostream>
#include <vector>
using namespace std;
void inCaiMang(vector<int> &mang, string ghiChu = "");
void sapXepNhanh(vector<int> &mang, int trai, int phai);
int tachMang(vector<int> &mang, int trai, int phai);
void tronHaiMang(vector<int> &mang, int trai, int giua, int phai);
void sapXepTron(vector<int> &mang, int trai, int phai);
void inCaiMang(vector<int> &mang, string ghiChu) {
    cout << ghiChu;
    for (int x : mang) cout << x << " ";
    cout << endl;
}
int tachMang(vector<int> &mang, int trai, int phai) {
    int chot = mang[phai]; 
    int i = trai - 1;
    for (int j = trai; j < phai; j++) {
        if (mang[j] < chot) {
            i++;
            swap(mang[i], mang[j]);
        }
    }
    swap(mang[i + 1], mang[phai]);
    inCaiMang(mang, "Trang thai hien tai (Quick Sort): ");
    return i + 1;
}

void sapXepNhanh(vector<int> &mang, int trai, int phai) {
    if (trai < phai) {
        int pi = tachMang(mang, trai, phai);
        sapXepNhanh(mang, trai, pi - 1);
        sapXepNhanh(mang, pi + 1, phai);
    }
}
void tronHaiMang(vector<int> &mang, int trai, int giua, int phai) {
    int n1 = giua - trai + 1;
    int n2 = phai - giua;
    vector<int> benTrai(n1), benPhai(n2);

    for (int i = 0; i < n1; i++) benTrai[i] = mang[trai + i];
    for (int j = 0; j < n2; j++) benPhai[j] = mang[giua + 1 + j];

    int i = 0, j = 0, k = trai;
    while (i < n1 && j < n2) {
        if (benTrai[i] <= benPhai[j]) {
            mang[k] = benTrai[i++];
        } else {
            mang[k] = benPhai[j++];
        }
        k++;
        inCaiMang(mang, "Tron tam thoi: ");
    }

    while (i < n1) {
        mang[k++] = benTrai[i++];
        inCaiMang(mang, "Them phan con lai ben trai: ");
    }

    while (j < n2) {
        mang[k++] = benPhai[j++];
        inCaiMang(mang, "Them phan con lai ben phai: ");
    }
}

void sapXepTron(vector<int> &mang, int trai, int phai) {
    if (trai < phai) {
        int giua = (trai + phai) / 2;
        sapXepTron(mang, trai, giua);
        sapXepTron(mang, giua + 1, phai);
        tronHaiMang(mang, trai, giua, phai);
    }
}
int main() {
    vector<int> caiMang1 = {7, 2, 1, 6, 8, 5, 3, 4};
    vector<int> caiMang2 = caiMang1;

    cout << "Mang ban dau: ";
    inCaiMang(caiMang1);

    cout << "\n=== Sap xep nhanh (Quick Sort) ===\n";
    sapXepNhanh(caiMang1, 0, caiMang1.size() - 1);
    inCaiMang(caiMang1, "Mang sau khi sap xep nhanh: ");

    cout << "\n=== Sap xep tron (Merge Sort) ===\n";
    sapXepTron(caiMang2, 0, caiMang2.size() - 1);
    inCaiMang(caiMang2, "Mang sau khi sap xep tron: ");

    cout << "\n===== DO PHUC TAP =====\n";
    cout << "Quick Sort: Trung binh O(n log n), toi da O(n^2)\n";
    cout << "Merge Sort: Luon luon O(n log n)\n";

    return 0;
}

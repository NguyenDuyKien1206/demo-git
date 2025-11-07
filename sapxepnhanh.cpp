#include <iostream>
#include <vector>
using namespace std;
void inCaiMang(vector<int> &mang, string GhiChu = "") {
    cout << GhiChu;
    for (int so : mang) cout << so << " ";
    cout << endl;
}
int chiaMang(vector<int> &mang, int trai, int phai) {
    int moc = mang[phai]; 
    int i = trai - 1;
    for (int j = trai; j < phai; j++) {
        if (mang[j] < moc) {
            i++;
            swap(mang[i], mang[j]);
            inCaiMang(mang, "Sau khi doi cho trong ChiaMang: ");
        }
    }
    swap(mang[i + 1], mang[phai]);
    inCaiMang(mang, "Sau khi doi cho phan tu chot: ");
    return i + 1;
}

void sapXepNhanh(vector<int> &mang, int trai, int phai) {
    if (trai < phai) {
        int viTriMoc = chiaMang(mang, trai, phai);
        sapXepNhanh(mang, trai, viTriMoc - 1);
        sapXepNhanh(mang, viTriMoc + 1, phai);
    }
}

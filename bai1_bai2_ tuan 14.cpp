#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cau trúc mot nut tren cay
struct Nut {
    int duLieu;
    Nut *trai, *phai;
    Nut(int giaTri) {
        duLieu = giaTri;
        trai = phai = NULL;
    }
};

// --- CÁC HÀM DUYET CÂY ---
void duyetTruoc(Nut* goc) {
    if (goc) {
        cout << goc->duLieu << " ";
        duyetTruoc(goc->trai);
        duyetTruoc(goc->phai);
    }
}

void duyetGiua(Nut* goc) {
    if (goc) {
        duyetGiua(goc->trai);
        cout << goc->duLieu << " ";
        duyetGiua(goc->phai);
    }
}

void duyetSau(Nut* goc) {
    if (goc) {
        duyetSau(goc->trai);
        duyetSau(goc->phai);
        cout << goc->duLieu << " ";
    }
}

// --- GIAI THUAT VUN ÐONG (HEAPIFY) ---
void layGiaTri(Nut* goc, vector<int>& danhSach) {
    if (!goc) return;
    danhSach.push_back(goc->duLieu);
    layGiaTri(goc->trai, danhSach);
    layGiaTri(goc->phai, danhSach);
}

void ganGiaTri(Nut* goc, vector<int>& danhSach, int& chiSo) {
    if (!goc || chiSo >= danhSach.size()) return;
    goc->duLieu = danhSach[chiSo++];
    ganGiaTri(goc->trai, danhSach, chiSo);
    ganGiaTri(goc->phai, danhSach, chiSo);
}

void vunDongCay(Nut* goc) {
    vector<int> mangPhu;
    layGiaTri(goc, mangPhu);
    // Sap xep giam dan de tao Max-Heap
    sort(mangPhu.begin(), mangPhu.end(), greater<int>());
    int id = 0;
    ganGiaTri(goc, mangPhu, id);
}

// --- KIEM TRA 2 CÂY GIONG NHAU (BÀI 2) ---
bool kienTraGiongNhau(Nut* c1, Nut* c2) {
    if (!c1 && !c2) return true; // Ca 2 cùng rong
    if (c1 && c2) {
        return (c1->duLieu == c2->duLieu) && 
               kienTraGiongNhau(c1->trai, c2->trai) && 
               kienTraGiongNhau(c1->phai, c2->phai);
    }
    return false; // Mot ben rong, mot ben có du lieu
}

int main() {
    // Dung cay 
    Nut* gocCay = new Nut(4);
    gocCay->trai = new Nut(1);
    gocCay->phai = new Nut(3);
    gocCay->trai->trai = new Nut(2);
    gocCay->trai->phai = new Nut(16);
    gocCay->phai->trai = new Nut(9);
    gocCay->phai->phai = new Nut(10);
    gocCay->trai->trai->trai = new Nut(14);
    gocCay->trai->trai->phai = new Nut(8);
    gocCay->trai->phai->trai = new Nut(7);

    cout << "Duyet truoc: "; duyetTruoc(gocCay); cout << endl;
    
    vunDongCay(gocCay);
    cout << "Sau khi vun dong (Duyet truoc): "; duyetTruoc(gocCay); cout << endl;

    return 0;
}

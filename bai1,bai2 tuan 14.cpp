#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// C?u trúc m?t nút trên cây
struct Nut {
    int duLieu;
    Nut *trai, *phai;
    Nut(int giaTri) {
        duLieu = giaTri;
        trai = phai = NULL;
    }
};

// --- CÁC HÀM DUY?T CÂY ---
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

// --- GI?I THU?T VUN Ð?NG (HEAPIFY) ---
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
    // S?p x?p gi?m d?n d? t?o Max-Heap
    sort(mangPhu.begin(), mangPhu.end(), greater<int>());
    int id = 0;
    ganGiaTri(goc, mangPhu, id);
}

// --- KI?M TRA 2 CÂY GI?NG NHAU (BÀI 2) ---
bool kienTraGiongNhau(Nut* c1, Nut* c2) {
    if (!c1 && !c2) return true; // C? 2 cùng r?ng
    if (c1 && c2) {
        return (c1->duLieu == c2->duLieu) && 
               kienTraGiongNhau(c1->trai, c2->trai) && 
               kienTraGiongNhau(c1->phai, c2->phai);
    }
    return false; // M?t bên r?ng, m?t bên có d? li?u
}

int main() {
    // D?ng cây theo dúng so d? ?nh
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

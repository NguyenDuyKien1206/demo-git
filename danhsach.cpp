#include <iostream>
#include <string>
using namespace std;
struct SinhVien {
    string hoten;
    string mssv;
    int namsinh;
    float gpa;
};
struct NutSinhVien {
    SinhVien dulieu;
    NutSinhVien* tieptheo;
};
struct CaiList {
    NutSinhVien* thangdau;
};
void KhoiTao(CaiList* ds) {
    ds->thangdau = 0;  // NULL
}
void ThemCuoi(CaiList* ds, SinhVien sv) {
    NutSinhVien* nutmoi = new NutSinhVien;
    nutmoi->dulieu = sv;
    nutmoi->tieptheo = 0;

    if (ds->thangdau == 0) {
        ds->thangdau = nutmoi;
        return;
    }

    NutSinhVien* p = ds->thangdau;
    while (p->tieptheo != 0)
        p = p->tieptheo;

    p->tieptheo = nutmoi;
}
void InDanhSach(CaiList* ds) {
    NutSinhVien* p = ds->thangdau;

    if (p == 0) {
        cout << "\n--- Danh sach rong ---\n";
        return;
    }

    cout << "\n===== DANH SACH SINH VIEN =====\n";
    while (p != 0) {
        cout << "Ho ten : " << p->dulieu.hoten << endl;
        cout << "MSSV   : " << p->dulieu.mssv << endl;
        cout << "Nam sinh: " << p->dulieu.namsinh << endl;
        cout << "GPA    : " << p->dulieu.gpa << endl;
        cout << "---------------------------\n";
        p = p->tieptheo;
    }
}
int DoDai(CaiList* ds) {
    int dem = 0;
    NutSinhVien* p = ds->thangdau;

    while (p != 0) {
        dem++;
        p = p->tieptheo;
    }
    return dem;
}
int DemGPAHon32(CaiList* ds) {
    int dem = 0;
    NutSinhVien* p = ds->thangdau;

    while (p != 0) {
        if (p->dulieu.gpa > 3.2)
            dem++;
        p = p->tieptheo;
    }
    return dem;
}
void SapXepTangGPA(CaiList* ds) {
    for (NutSinhVien* p = ds->thangdau; p != 0; p = p->tieptheo) {
        NutSinhVien* minNode = p;
        for (NutSinhVien* q = p->tieptheo; q != 0; q = q->tieptheo) {
            if (q->dulieu.gpa < minNode->dulieu.gpa)
                minNode = q;
        }
        SinhVien tam = p->dulieu;
        p->dulieu = minNode->dulieu;
        minNode->dulieu = tam;
    }
}
void ChenTheoThuTu(CaiList* ds, SinhVien sv) {
    NutSinhVien* nutmoi = new NutSinhVien;
    nutmoi->dulieu = sv;
    if (ds->thangdau == 0 || sv.gpa < ds->thangdau->dulieu.gpa) {
        nutmoi->tieptheo = ds->thangdau;
        ds->thangdau = nutmoi;
        return;
    }

    NutSinhVien* p = ds->thangdau;
    while (p->tieptheo != 0 && p->tieptheo->dulieu.gpa < sv.gpa)
        p = p->tieptheo;

    nutmoi->tieptheo = p->tieptheo;
    p->tieptheo = nutmoi;
}
int main() {
    CaiList ds;
    KhoiTao(&ds);
    SinhVien sv1 = {"Nguyen Duy Kien", "SV001", 202414197, 3.4};
    SinhVien sv2 = {"Nguyen Duy Hoang", "SV002", 202414576, 2.9};
    SinhVien sv3 = {"Nguyen Duy Quang", "SV003", 202419850, 3.8};
    ThemCuoi(&ds, sv1);
    ThemCuoi(&ds, sv2);
    ThemCuoi(&ds, sv3);

    cout << "\n--- Danh sach ban dau ---\n";
    InDanhSach(&ds);

    cout << "\nDo dai danh sach: " << DoDai(&ds) << endl;
    cout << "So SV GPA > 3.2: " << DemGPAHon32(&ds) << endl;

    SapXepTangGPA(&ds);
    cout << "\n--- Sau khi sap xep ---\n";
    InDanhSach(&ds);

    SinhVien sv24 = {"Vuong Ba Long", "SV999", 202415789, 2.4};
    ChenTheoThuTu(&ds, sv24);

    cout << "\n--- Sau khi chen GPA = 2.4 ---\n";
    InDanhSach(&ds);

    return 0;
}


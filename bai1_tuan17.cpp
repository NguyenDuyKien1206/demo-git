#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct NutMucLuc {
    string tieuDe;      
    int soTrang;       
    int trangBatDau;    
    vector<NutMucLuc*> danhSachCon; 
    NutMucLuc(string td, int st, int tbd) {
        tieuDe = td;
        soTrang = st;
        trangBatDau = tbd;
    }
};
int demSoChuong(NutMucLuc* goc) {
    if (!goc) return 0;
    return goc->danhSachCon.size();
}

NutMucLuc* timChuongDaiNhat(NutMucLuc* goc) {
    if (!goc || goc->danhSachCon.empty()) return NULL;
    NutMucLuc* chuongMax = goc->danhSachCon[0];
    for (NutMucLuc* chuong : goc->danhSachCon) {
        if (chuong->soTrang > chuongMax->soTrang) {
            chuongMax = chuong;
        }
    }
    return chuongMax;
}

bool xoaMuc(NutMucLuc* cha, string mucCanXoa) {
    for (auto it = cha->danhSachCon.begin(); it != cha->danhSachCon.end(); ++it) {
        if ((*it)->tieuDe == mucCanXoa) {
            int trangGiam = (*it)->soTrang;
            delete *it; 
            cha->danhSachCon.erase(it);
            cha->soTrang -= trangGiam; 
            return true;
        }
        if (xoaMuc(*it, mucCanXoa)) {
            
            int trangHienTai = 0;
            for(auto con : (*it)->danhSachCon) trangHienTai += con->soTrang;
            (*it)->soTrang = trangHienTai;
            return true;
        }
    }
    return false;
}

void inDeMuc(NutMucLuc* nut, int cap Do = 0) {
    if (!nut) return;
    for (int i = 0; i < capDo; ++i) cout << "  "; 
    cout << "- " << nut->tieuDe << " (" << nut->soTrang << " trang)" << endl;
    for (NutMucLuc* con : nut->danhSachCon) {
        inDeMuc(con, capDo + 1);
    }
}

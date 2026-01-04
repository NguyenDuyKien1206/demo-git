#include <iostream>
#include <string>

using namespace std;

struct NutSach {
    int maSo;        
    string tenMuc;    
    NutSach *trai, *phai;

    NutSach(int id, string ten) {
        maSo = id;
        tenMuc = ten;
        trai = phai = NULL;
    }
};


bool laBanCopy(NutSach* s1, NutSach* s2) {
   
    if (s1 == NULL && s2 == NULL) return true;
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->maSo != s2->maSo || s1->tenMuc != s2->tenMuc) return false;
    return laBanCopy(s1->trai, s2->trai) && laBanCopy(s1->phai, s2->phai);
}

void ketLuan(NutSach* s1, NutSach* s2) {
    if (laBanCopy(s1, s2)) {
        cout << "Hai cuon sach la ban copy cua nhau" << endl;
    } else {
        cout << "Hai cuon sach khac nhau" << endl;
    }
}

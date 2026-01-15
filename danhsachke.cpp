#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> danhSachKe[12];
string tenDiaPhuong[] = {"", "Ha Noi", "Hai Duong", "Hai Phong", "Uong Bi", "Bac Giang", 
                         "Bac Ninh", "Thai Nguyen", "Son Tay", "Hoa Binh", "Phu Ly", "Hung Yen"};

void noiTuyenDuong(int u, int v) {
    danhSachKe[u].push_back(v);
    danhSachKe[v].push_back(u);
}

int main() {
    noiTuyenDuong(1, 2); noiTuyenDuong(2, 11); noiTuyenDuong(10, 11);
    noiTuyenDuong(1, 10); noiTuyenDuong(1, 9); noiTuyenDuong(1, 8);
    noiTuyenDuong(1, 7); noiTuyenDuong(1, 6); noiTuyenDuong(6, 5);
    noiTuyenDuong(5, 4); noiTuyenDuong(6, 4); noiTuyenDuong(4, 3);
    noiTuyenDuong(2, 3);

    cout << "DANH SACH CAC TUYEN DUONG KET NOI:" << endl;
    for (int i = 1; i <= 11; i++) {
        cout << "[" << tenDiaPhuong[i] << "] co duong di den: ";
        for (int tinhLanCan : danhSachKe[i]) {
            cout << tenDiaPhuong[tinhLanCan] << ", ";
        }
        cout << endl;
    }

    return 0;
}

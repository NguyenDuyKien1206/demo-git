#include <iostream>
#include <string>

using namespace std;
int maTranKe[12][12] = {0};
string tenTinh[] = {"", "Ha Noi", "Hai Duong", "Hai Phong", "Uong Bi", "Bac Giang", 
                    "Bac Ninh", "Thai Nguyen", "Son Tay", "Hoa Binh", "Phu Ly", "Hung Yen"};
void themDuongDi(int tinhA, int tinhB) {
    maTranKe[tinhA][tinhB] = 1;
    maTranKe[tinhB][tinhA] = 1; 
}

int main() {
    int tongSoTinh = 11;
    themDuongDi(1, 2);  
    themDuongDi(2, 11); 
    themDuongDi(10, 11);
    themDuongDi(1, 10); 
    themDuongDi(1, 9);  
    themDuongDi(1, 8);  
    themDuongDi(1, 7);  
    themDuongDi(1, 6);  
    themDuongDi(6, 5);  
    themDuongDi(5, 4);  
    themDuongDi(6, 4);  
    themDuongDi(4, 3);  
    themDuongDi(2, 3);  

    cout << "BIEU DIEN DO THI BANG MA TRAN KE:" << endl;
    for (int hang = 1; hang <= tongSoTinh; hang++) {
        for (int cot = 1; cot <= tongSoTinh; cot++) {
            cout << maTranKe[hang][cot] << " ";
        }
        cout << endl;
    }

    return 0;
}

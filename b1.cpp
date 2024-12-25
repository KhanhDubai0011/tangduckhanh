#include <bits/stdc++.h>
using namespace std;
bool kiemTraTinhHopLe(const string& bieuThuc) {
    int canBang = 0;
    for (char kyTu : bieuThuc) {
        if (kyTu == '(') canBang++;
        else if (kyTu == ')') canBang--;
        if (canBang < 0) return false;
    }
    return canBang == 0;
}
bool danhGiaBieuThuc(const string& bieuThuc, const unordered_map<char, bool>& giaTriBien) {
    stack<bool> nganXep;
    stringstream ss(bieuThuc);
    string token;

    while (ss >> token) {
        if (token == "T" || token == "F") {
            nganXep.push(token == "T");
        } else if (token == "?") {  
            bool b = nganXep.top(); nganXep.pop();
            bool a = nganXep.top(); nganXep.pop();
            nganXep.push(a && b);
        } else if (token == "?") {  
            bool b = nganXep.top(); nganXep.pop();
            bool a = nganXep.top(); nganXep.pop();
            nganXep.push(a || b); 
        } else if (token == "¬") {  
            bool a = nganXep.top(); nganXep.pop();
            nganXep.push(!a);
        } else if (token == "?") { 
            bool b = nganXep.top(); nganXep.pop();
            bool a = nganXep.top(); nganXep.pop();
            nganXep.push(!a || b);
        } else if (giaTriBien.count(token[0])) {
            nganXep.push(giaTriBien.at(token[0])); 
        } else {
            return false;  
        }
    }

    return nganXep.top();
}

int main() {
    string bieuThuc;
    unordered_map<char, bool> giaTriBien;
    cout << "Nhap bieu thuc logic: ";
    getline(cin, bieuThuc);
    if (!kiemTraTinhHopLe(bieuThuc)) {
        cout << "Bieu thuc khong hop le." << endl;
        return 0;
    }
    int soBien;
    cout << "Nhap so luong bien logic: ";
    cin >> soBien;
    cout << "Nhap gia tri cho cac bien (A, B, C,...):" << endl;

    for (int i = 0; i < soBien; ++i) {
        char bien;
        bool giaTri;
        cout << "Nhap gia tri cho bien (A, B, C,...): ";
        cin >> bien >> giaTri;
        giaTriBien[bien] = giaTri;
    }
    bool ketQua = danhGiaBieuThuc(bieuThuc, giaTriBien);
    cout << "Ket qua bieu thuc: " << (ketQua ? "True" : "False") << endl;
    return 0;
}



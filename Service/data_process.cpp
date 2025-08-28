#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../Repository/LinkedList.cpp"
using namespace std;

bool kiemtra(string ma,List L){
        Node*p = L;
        while(p){
            if (p->Data.manv == ma)
                return true;
            p = p->Next;
        }
        return false;
}
int safe_stoi(const string &s) {
    try {
        return s.empty() ? 0 : stoi(s);
    } catch (...) { return 0; }
}

float safe_stof(const string &s) {
    try {
        return s.empty() ? 0 : stof(s);
    } catch (...) { return 0; }
}


void ImportNhanVien(List &L,NhanVien Employee){
    if(kiemtra(Employee.manv,L)){
        cout << "Ma nhan vien da ton tai!" << endl;
        return;
    }
    InsTail(L,Employee);
    cout<< "Import thanh cong\n";
}

void ImportFile(string file_path,List &L){
    ifstream fin(file_path);
    if (!fin.is_open()) {
        cout << "Khong the mo file: " << file_path << endl;
        return;
    }
    string line;
    getline(fin, line);
    while (getline(fin, line)) {
        stringstream ss(line);
        string ma, ten, ns, email, dc, sdt;
        int songay;
        float luong;
        getline(ss, ma, ',');
        getline(ss, ten, ',');
        getline(ss, ns, ',');
        getline(ss, email, ',');
        getline(ss, dc, ',');
        getline(ss, sdt, ',');
        
        string songayStr, luongStr;
        getline(ss, songayStr, ',');
        getline(ss, luongStr, ',');
        
        songay = safe_stoi(songayStr);
        luong = safe_stof(luongStr);

        NhanVien nv(ma, ten, ns, email, dc, sdt, songay, luong);
        ImportNhanVien(L, nv); // dùng luôn hàm đã kiểm tra trùng
    }
    fin.close();
    cout << "File readed"<<endl;
}

void ExportFile(string file_path, List &L) {
    ofstream fout(file_path); // mở file để ghi

    if (!fout.is_open()) {
        cout << "Khong mo duoc file de ghi!" << endl;
        return;
    }

    // Ghi tiêu đề cột
    fout << "MaNV,HoTen,NgaySinh,Email,DiaChi,SoDT,SoNgayCong,LuongNgay,ThuNhap\n";

    // Duyệt danh sách và ghi dữ liệu
    Node* p = L;
    while(p) {
        NhanVien nv = p->Data;
        fout << nv.manv << "," 
             << nv.hotennv << "," 
             << nv.ngaysinh << "," 
             << nv.email << "," 
             << nv.diachi << "," 
             << nv.sodt << "," 
             << nv.songaycong << "," 
             << nv.luongngay << "," 
             << nv.thuclinh << "\n";
        p = p->Next;
    }
    fout.close();
    cout << "Xuat file thanh cong!" << endl;
}

void print_list(List &L){
    Node* p = L;
    while(p){
        cout << p->Data.manv << " - " 
             << p->Data.hotennv << " - " 
             << p->Data.ngaysinh << " - " 
             << p->Data.email << " - " 
             << p->Data.diachi << " - " 
             << p->Data.sodt << " - " 
             << p->Data.songaycong << " - " 
             << p->Data.luongngay << " - " 
             << p->Data.thuclinh 
             << endl;
        p = p->Next;
    }
    system("pause");    
}
void print_node(Node* p){
    if(!p) return;
    cout << "Ma NV: " << p->Data.manv << "\n";
    cout << "Ho ten: " << p->Data.hotennv << "\n";
    cout << "Ngay sinh: " << p->Data.ngaysinh << "\n";
    cout << "Email: " << p->Data.email << "\n";
    cout << "Dia chi: " << p->Data.diachi << "\n";
    cout << "So DT: " << p->Data.sodt << "\n";
    cout << "So ngay cong: " << p->Data.songaycong << "\n";
    cout << "Luong ngay: " << p->Data.luongngay << "\n";
    cout << "Thuclinh: " << p->Data.thuclinh << "\n";   
    system("pause"); 
}
Node* SortByMa4(List &L,string ma){
    Node* p = L;
    while(p){
        if(p->Data.manv == ma)
            return p; // tìm thấy
        p = p->Next;
    }
    
    return nullptr; 
}

static string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

Node* SortNVByTen(string ten,List &L){
    Node* p = L;
    string tenthuong = toLower(ten);

    while(p){
        if(toLower(p->Data.hotennv).find(tenthuong)!= string::npos){
            return p;
        } // tìm thấy
        p = p->Next;
    }
    return nullptr; 
}

Node* SortThucLinhfind(List &L){
    Node* p = L;
    if (!p) {
        cout << "Danh sach rong.\n";
        return nullptr;
    }
    Node* maxNode = p;
    while(p){
        if(p->Data.thuclinh > maxNode->Data.thuclinh){
            maxNode = p;
        }
        p = p->Next;
    }
    return maxNode;
}

void SortThucLinhDesc(List &L) {
    if (!L || !L->Next) {
        cout << "Danh sach rong hoac chi co 1 phan tu.\n";
        return;
    }

    for (Node* i = L; i; i = i->Next) {
        for (Node* j = i->Next; j; j = j->Next) {
            if (i->Data.thuclinh < j->Data.thuclinh) { // giảm dần
                swap(i->Data, j->Data);
            }
        }
    }
    cout << "Da sap xep danh sach theo thuc linh giam dan.\n";
    system("pause");
}

void deleteNVma4(string ma, List &L) {
    if (!L) {
        cout << "Danh sach rong. Can not xoa\n";
        return;
    }

    if (L->Data.manv == ma) {
        Node* temp = L;
        L = L->Next;
        delete temp;
        cout << "Da xoa nhan vien co ma " << ma << "\n";
        return;
    }

    Node* p = L;

    while (p->Next && p->Next->Data.manv != ma) {
        p = p->Next;
    }

    if (p->Next) { // Tìm thấy node
        Node* temp = p->Next;
        p->Next = temp->Next;
        delete temp;
        cout << "Da xoa nhan vien co ma " << ma << "\n";
    } else {
        cout << "Khong tim thay nhan vien co ma " << ma << "\n";
    }
}

void SuaThongTinTheoMa4(List &L) {
    if (!L) {
        cout << "Danh sach rong. Khong co nhan vien de sua.\n";system("pause");

        return;
    }

    string ma;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> ma;

    Node* p = L;
    while (p && p->Data.manv != ma) {
        p = p->Next;
    }

    if (!p) {
        cout << "Khong tim thay nhan vien voi ma " << ma << ".\n";
        return;
    }

    cout << "Nhap thong tin moi (nhap 'keep' de giu gia tri cu):\n";
    string temp;
    cin.ignore(); // xoa '\n' trong buffer

    cout << "Ho va ten: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.hotennv = temp;

    cout << "Ngay sinh: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.ngaysinh = temp;

    cout << "Dia chi: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.diachi = temp;

    cout << "Email: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.email = temp;

    cout << "So dien thoai: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.sodt = temp;

    cout << "So ngay cong: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.songaycong = safe_stoi(temp);

    cout << "Luong ngay: ";
    getline(cin, temp);
    if (temp != "keep") p->Data.luongngay = safe_stof(temp);

    // Tinh lai thuc linh
    p->Data.thuclinh = p->Data.songaycong * p->Data.luongngay;

    cout << "Da cap nhat thong tin nhan vien.\n";
}

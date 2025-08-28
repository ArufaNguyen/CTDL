#include <iostream>
#include <thread>
#include <chrono>
#include "data_process.cpp"
using namespace std;
void wait(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}
void Database(List &L){

}
void ThemNhanVien(List &L) {
    NhanVien nv; 

    cout << "Nhap ma nhan vien: ";
    cin >> nv.manv;

    cout << "Nhap ho ten nhan vien: ";
    cin.ignore();
    getline(cin, nv.hotennv);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, nv.ngaysinh);

    cout << "Nhap email: ";
    getline(cin, nv.email);

    cout << "Nhap dia chi: ";
    getline(cin, nv.diachi);

    cout << "Nhap so dien thoai: ";
    getline(cin, nv.sodt);

    cout << "Nhap so ngay cong: ";
    cin >> nv.songaycong;

    cout << "Nhap luong ngay: ";
    cin >> nv.luongngay;

    // Tính lương thực lĩnh
    nv.thuclinh = nv.songaycong * nv.luongngay;

    // Gọi hàm import (có kiểm tra trùng mã nv)
    ImportNhanVien(L, nv);
    system("pause");
}


void XoaNhanVien(List &L) {
    if (!L) {
        cout << "Danh sach rong. Khong co gi de xoa!\n";
        system("pause");
        return;
    }
    string ma;
    cout << "Nhap ma nhan vien can xoa: ";
    getline(cin, ma);

    deleteNVma4(ma, L);
    wait(1);
}

void SuaThongTinNhanvien(List &L){
    SuaThongTinTheoMa4(L);
    wait(1);
}

void HienThiThongTinNhanVien(List &L){
    cout << "MaNV - HoTen - NgaySinh - Email - DiaChi - SoDT - SoNgayCong - LuongNgay - ThuNhap\n";
    print_list(L);
    wait(1);
}
void SortTheoThucLinh(List &L){
    SortThucLinhDesc(L);
    wait(1);
}

void SearchByMa(List &L){
    if (!L) {
        cout << "Danh sach rong. Khong co gi de tim!\n";
        system("pause");
        return;
    }
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    cin.ignore();
    getline(cin, ma);
    Node* result = SortByMa4(L,ma);
    if (result){print_node(result);}else{cout<<"404 not found\n";system("pause");}
    
}


void SearchByTen(List &L){
    if (!L) {
        cout << "Danh sach rong. Khong co gi de tim!\n";
        system("pause");
        return;
    }
    string ma;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, ma);
    Node* result = SortNVByTen(ma,L);
    if (result){print_node(result);}else{cout<<"404 not found\n";system("pause");}
    
}


void ImportData(List &L){
    string ma;
    cout << "Nhap ten file: ";
    // cin.ignore();
    getline(cin, ma);
    ImportFile(ma,L);
    system("pause");
}

void ExportData(List &L){
    string ma;
    cout << "Nhap ten file: ";
    // cin.ignore();
    getline(cin, ma);
    ExportFile(ma,L);
    system("pause");
}
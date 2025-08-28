#include <iostream>
#include <cstdlib>
#include "modified_function.cpp"
using namespace std;

struct EmployeeUI {
    void printMenu() {
        system("cls");
        cout << "================ QUAN LY NHAN VIEN ================\n";
        cout << "1. Quan li nhan vien:\n";
        cout << "2. Sap xep:\n";
        cout << "3. Tim kiem:\n";
        cout << "4. Misc:\n";
        cout << "0. Thoat\n";
        cout << "===================================================\n";
        cout << "Vui long nhap so: ";
    }
    
    void Case_1() {
        system("cls");
        cout << "============= QUAN LY NHAN VIEN =============\n";
        cout << "1. Them nhan vien\n";
        cout << "2. Xoa nhan vien\n";
        cout << "3. Sua thong tin nhan vien\n";
        cout << "4. Hien thi danh sach nhan vien\n";
        cout << "0. Quay lai\n";
        cout << "=============================================\n";
        cout << "Vui long nhap so: ";
    }

    void Case_2() {
        system("cls");
        cout << "================= SAP XEP =================\n";
        cout << "1. Sap xep theo thuc linh giam dan\n";
        cout << "0. Quay lai\n";
        cout << "===========================================\n";
        cout << "Vui long nhap so: ";
    }

    void Case_3() {
        system("cls");
        cout << "================= TIM KIEM =================\n";
        cout << "1. Tim theo ma nhan vien\n";
        cout << "2. Tim theo ten (khong phan biet hoa thuong)\n";
        cout << "0. Quay lai\n";
        cout << "============================================\n";
        cout << "Vui long nhap so: ";
    }

    void Case_4() {
        system("cls");
        cout << "================= MISC =================\n";
        cout << "1. Export Data\n";
        cout << "2. Import Data\n";
        cout << "0. Quay lai\n";
        cout << "============================================\n";
        cout << "Vui long nhap so: ";
    }
    void remote_func(int choice,int choice2,List &L){
        cout << "remote";
        if (choice ==1){Case_1_func(choice2,L);}
        if (choice ==2){Case_2_func(choice2,L);}
        if (choice ==3){Case_3_func(choice2,L);}
        if (choice ==4){Case_4_func(choice2,L);}
    }
    void Case_1_func(int choice2,List &L){
        if (choice2 ==1){system("cls");ThemNhanVien(L);}
        if (choice2 ==2){system("cls");XoaNhanVien(L);}
        if (choice2 ==3){system("cls");SuaThongTinNhanvien(L);}
        if (choice2 ==4){system("cls");HienThiThongTinNhanVien(L);}

    }
    void Case_2_func(int choice2,List &L){
        if (choice2 ==1){system("cls");SortTheoThucLinh(L);}
    }
    void Case_3_func(int choice2,List &L){
        if (choice2 ==1){system("cls");SearchByMa(L);}
        if (choice2 ==2){system("cls");SearchByTen(L);}
    }
    void Case_4_func(int choice2,List &L){
        if (choice2 ==1){system("cls");ExportData(L);}
        if (choice2 ==2){system("cls");ImportData(L);}
    }

    int Render(void (EmployeeUI::*func)()) { // i dunno render(void employeeui) thì k work
        int choice;
        (this->*func)();   // gọi hàm thành viên
        cin >> choice;
        cin.ignore();
        return choice;
    }
    void run(List &L) {
        int choice;
        do {
            choice = Render(&EmployeeUI::printMenu);
            switch(choice) {
                case 1: case 2: case 3: case 4: {
                    int choice2;
                    do {
                        switch(choice) {
                            case 1: choice2 = Render(&EmployeeUI::Case_1); break;
                            case 2: choice2 = Render(&EmployeeUI::Case_2); break;
                            case 3: choice2 = Render(&EmployeeUI::Case_3); break;
                            case 4: choice2 = Render(&EmployeeUI::Case_4); break;
                        }
                        // remote_func(choice,choice2,L); // thoát menu con
                        if(choice2 == 0) break;
                        remote_func(choice,choice2,L); // thoát menu con
                    } while(true);
                    break;
                }
                case 0:
                    cout << "Thoat chuong trinh.\n";
                    return;
                default:
                    cout << "Lua chon khong hop le.\n";
            }
        } while(choice != 0);
    }
};

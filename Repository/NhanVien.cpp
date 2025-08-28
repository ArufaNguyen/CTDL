#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string manv;
    string hotennv;
    string ngaysinh;
    string email;
    string diachi;
    string sodt;
    int songaycong;
    float luongngay;
    float thuclinh;
    
    NhanVien() {
        manv = "";
        hotennv = "";
        ngaysinh = "";
        email = "";
        diachi = "";
        sodt = "";
        songaycong = 0;
        luongngay = 0;
        thuclinh = 0;
    }
    NhanVien(string ma, string ten, string ns, string eml, string dc, string sdt, int ngay, double luong){
        manv = ma;
        hotennv = ten;
        ngaysinh = ns;
        email = eml;
        diachi = dc;
        sodt = sdt;
        songaycong = ngay;
        luongngay = luong;
        thuclinh = songaycong * luongngay;
    }

};




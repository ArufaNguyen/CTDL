#include <iostream>
#include "Service/GUI.cpp"
using namespace std;

int main(){
    List L;
    InitList(L);
    EmployeeUI gui;
    gui.run(L);
    return 0;
}

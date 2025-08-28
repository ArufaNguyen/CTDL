#include <iostream>
#include <string>
#include "Nhanvien.cpp"

using namespace std;

struct Node{

    NhanVien Data;
    Node *Next;

};

Node *MakeNode (NhanVien x) {
    Node *P=new Node; 
    P->Next=NULL; 
    P->Data=x; 
    return P;
}
typedef Node* List;

void InitList(List &L) {
    L=NULL;
}

void InsFirst (List &L, NhanVien x) {
    Node *P=MakeNode(x);//tạo Node P chứa dữ liệu x
    P->Next=L;//cho P trỏ đến Node mà L đang trỏ
    L=P;//cho L trỏ về P
}

void InsTail (Node* &head,NhanVien x){
    Node *P=MakeNode(x);
    if (head == NULL) {      // nếu danh sách rỗng
        head = P;
    } else {
        Node *Q = head;
        while (Q->Next != NULL) { // duyệt đến node cuối
            Q = Q->Next;
        }
        Q->Next = P;
    }
}
// int main(){}


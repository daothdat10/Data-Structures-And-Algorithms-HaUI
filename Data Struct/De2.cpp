#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    int maMon;
    string tenMon;
    double stc;
};

struct node {
    SinhVien infor;
    node* next;
};

node* makeNode(SinhVien x) {
    node* newNode = new node();
    newNode->infor = x;
    newNode->next = NULL;
    return newNode;
}

typedef node* TRO;

void create(TRO& L) {
    L = NULL; // Initialize L to NULL for an empty list
}

int empty(TRO L) {
    return L == NULL; // Check if L is NULL (empty)
}

void NhapSV(SinhVien& SV) {
    cout << "Nhap Ma Mon: ";
    cin >> SV.maMon;

    cout << "Nhap ten: ";
    cin.ignore(); // Clear input buffer before getline
    getline(cin, SV.tenMon);

    cout << "Nhap diem tong ket: ";
    cin >> SV.stc;
}

void NhapDS(TRO& L) {
    create(L);
    SinhVien X;
    TRO P, Q;
    int n;

    do {
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        if (n < 5) {
            cout << "\nSo luong khong hop le vui long nhap lai.\n";
        }
    } while (n < 5);

    int i = 1;
    while (i <= n) {
        cout << "Nhap sinh vien thu " << i << endl;
        NhapSV(X);
        P = makeNode(X);

        if (L == NULL) {
            L = P; 
        } else {
            Q->next = P; 
        }
        Q = P;
        i++;
    }
}

void display(SinhVien x){
	cout<<setw(5)<<x.maMon;
	cout<<setw(20)<<x.tenMon;
	cout<<setw(20)<<setprecision(2)<<right<<x.stc;
	cout<<endl;
}
void show_disPlay(TRO L){
	if(L==0){
		cout<<"Danh Sach Rong"<<endl;
	}
	TRO Q =L;
//	cout<<setw(5)<<left<<"Ma Mon \n";
//	cout<<setw(20)<<"Ten Mon \n";
//	cout<<setw(20)<<setprecision(2)<<right<<"So Tin Chi \n";
	int i=1;
	while(Q->next !=NULL){
		SinhVien x = Q->infor;
		cout<<"Mon Thu "<<i<<endl;
		i++;
		cout<<setw(5)<<"Ma Mon ";
		cout<<setw(20)<<"Ten Mon ";
		cout<<setw(20)<<setprecision(2)<<"So Tin Chi "<<endl;
		display(x);
		Q=Q->next;
	}
}

void TimKiem(TRO &L,string &ten){
	if(L==0){
		cout<<"Khong tim thay mon hoc";
	}
	int dem =0;
	TRO Q = L;
	while(Q->next != NULL ){
		if(Q->infor.tenMon == ten){
		
		cout<<setw(5)<<"Ma Mon ";
		cout<<setw(20)<<"Ten Mon ";
		cout<<setw(20)<<setprecision(2)<<"So Tin Chi "<<endl;
		cout<<setw(5)<<Q->infor.maMon;
		cout<<setw(20)<<Q->infor.tenMon;
		cout<<setw(20)<<setprecision(2)<<right<<Q->infor.stc;
		dem++;
		}
		Q=Q->next;
	}
	if(dem==0){
		cout<<"Khong tim thay ten nao \n";
	}
}
void remove(TRO &L,string &ten){
	TRO P,Q;
	Q=L;
	P=NULL;
	while(Q->next !=NULL && Q->infor.tenMon != ten){
		Q=P;
		Q=Q->next;	
	}
	if(Q->next !=NULL){
		if(P==NULL){
			L=Q->next;
		}else
			Q->next = P->next;
		delete Q;
	}
}
void chen_sv(TRO &L, SinhVien &svMoi){
	TRO P=L;
	int dem = 0;
	while(P->next !=NULL && dem<3){
		P=P->next;
		dem++;
	}
	if(P->next!=NULL){
		TRO Q = new node;
		Q->infor = svMoi;
		Q->next = P->next;
		P->next = Q;
	}else{
		cout<<"Khong tim thay vi tri de chen";
	}
}

int main(){
	TRO L;
	NhapDS(L);	
	cout<<"=====Danh Sach Sinh Vien Vua Nhap La======= \n";
	show_disPlay(L);
	string ten;
		cout<<"Nhap Ten Can Tim \n";
		cin.ignore();
		getline(cin,ten);
		cout<<"Tim Kiem Thong Tin Theo Ten \n";
		TimKiem(L,ten);
		
	remove(L,ten);
		cout<<" \n Danh Sach Sinh Vien Sau Khi Xoa La \n"<<endl;
		show_disPlay(L);	
		
		
	SinhVien svMoi= {1,"Su",5};
		chen_sv(L,svMoi);
		cout<<" \n Danh Sach Sinh Vien Sau KHi Chen La \n "<<endl;
		show_disPlay(L);
	
	return 0;
	
}


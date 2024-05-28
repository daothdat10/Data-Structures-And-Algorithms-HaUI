#include<bits/stdc++.h>
using namespace std;

#define MAX 100

struct SinhVien {
    int maMon;
    string tenMon;
    double stc;
};

struct List {
    int count;
    SinhVien e[MAX];
};




void create(List & L) {
    L.count = -1;
}


int empty(List L) {
    return L.count == -1;
}


int full(List L) {
    return L.count == MAX - 1;
}


int add(List &L, SinhVien sv) {
    if (full(L)) {
       
        return 0;
    } else {
        L.count++;
        L.e[L.count] = sv;
        return 1; 
    }
}

void nhapsv(SinhVien &sv){
	cout<<"\t Nhap ma Mon: ";
	cin>>sv.maMon;
	
	cout<<"\t Nhap Ten Mon: ";
	cin.ignore();
	getline(cin,sv.tenMon);
	
	cout<<"\t Nhap So Tin Chi: ";
	cin>>sv.stc;
}


void NhapDS(List &L) {
	create(L);
	SinhVien x;
    int n;
   

    do{
    	 cout << "Nhap So Luong Mon Hoc Can Them: ";
   		 cin >> n;
   		 if(n<5){
   			cout<<"So Phan Tu Nhap Khong Hop Le"<<endl; 	
		}
	}while(n<5);
	int d=1;
	while(d<=n && !full(L)){
		cout<<"Mon Hoc Thu"<<d<<endl;
		d++;
    	nhapsv(x);
    	add(L,x);
    	
	}
}
void hien_thi_DS(List L) {
  cout << setw(5) << "STT" << setw(10) << "Ma Mon" << setw(10) << "Ten Mon"
       << setw(25) << "So Tin Chi" << endl;
  for (int i = 0; i <= L.count; ++i) { // Change to i <= L.count
    cout << setw(5) << (i + 1);
    cout << setw(10) << L.e[i].maMon;
    cout << setw(10) << L.e[i].tenMon;
    cout << setw(25) << L.e[i].stc;
    cout << endl;
  }
}
void timKiem(List L, string &ten) {
  if (empty(L)) {
    cout << "Khong Tim Thay Mon Hoc Nao " << endl;
  } else {
    int dem = 0;
    cout << setw(10) << "Ma Mon" << setw(10) << "Ten Mon" << setw(25) << "So Tin Chi" << endl;
    for (int i = 0; i <= L.count; ++i) { // 
      if (strcmp(L.e[i].tenMon.c_str(), ten.c_str()) == 0) { 
        cout << setw(10) << L.e[i].maMon;
        cout << setw(10) << L.e[i].tenMon;
        cout << setw(25) << L.e[i].stc;
        cout << endl;
        dem++;
      }
    }
    if (dem == 0) {
      cout << "Khong Tim Thay Mon Hoc Nao" << endl;
    }
  }
}
void remove(List &L, string &ten) {
  if (empty(L)) {
    cout << "Danh sach rong. Khong the xoa mon hoc." << endl;
    return;
  }
  int dem=0; 
  for (int i = 0; i <= L.count; i++) {
    if (strcmp(L.e[i].tenMon.c_str(), ten.c_str()) == 0) {
      dem= i;
      
    }
  }
  if (dem == -1) {
    cout << "Mon hoc " << ten << " khong tim thay trong danh sach." << endl;
    return;
  }
  for (int i = dem; i < L.count; i++) {
    L.e[i] = L.e[i + 1];
  }
  L.count--; 
  cout << "Mon hoc " << ten << " da bi xoa." << endl;
}
int chen_vtr(List &L,int k){
	int dem = 0;
	SinhVien x;
	if(!full(L) && k<=L.count +1 &&k>1){
		cout<<"\n Nhap Sinh Vien Can Bo Sung \n";
		nhapsv(x);
		for(int i = k;i<L.count;i++){
			L.e[i+1]=L.e[i];
			L.count = L.count+1;
			L.e[k-1]=x;
			return 1;
			
		}
	}else 
		return 0;
	
}
int main() {
    List L;
    NhapDS(L);
    cout<<"Danh Sach Vua Nhap La\n";
    hien_thi_DS(L);
    
    string ten;
    	cout<<"Nhap Ten Mon Can Tim: "<<endl;
		cin>>ten;
		timKiem(L,ten);
		
		
	remove(L,ten);
		cout<<"danh sach sau khi xoa ten la"<<endl;
		hien_thi_DS(L);
		
	chen_vtr(L,3);
		cout<<"danh sach sau khi them la"<<endl;
		hien_thi_DS(L);
		
}


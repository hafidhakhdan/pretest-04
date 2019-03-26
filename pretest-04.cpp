/*
Nama		: Hafidh Akhdan Najib
Kelas		: A
NPM			: 140810180061
Tanggal		: 26/03/2019
Pretest 04
*/

#include <iostream>

using namespace std;

struct Mahasiswa{
    char npm[12];
    char nama[40];
    float ipk;
    Mahasiswa* next;
};

typedef Mahasiswa* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void createElmt (pointer& pBaru){
    pBaru = new Mahasiswa;
    cout<<"Nama : "; cin>>pBaru->nama;
    cout<<"NPM  : "; cin>>pBaru->npm;
    cout<<"IPK	: "; cin>>pBaru->ipk;
    pBaru->next=NULL;
    cout<<endl;
}

void insertSortNPM (List& First, pointer pBaru){
     pointer Last;

    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void traversal (List First){
    pointer pBantu;
    pBantu=First;
    int i=0;
    cout<<"DATA MAHASISWA\n";
    cout<<"=============================\n";
    cout<<"No\tNPM\t\tNama\tIPK\n";
    do{
        cout<<i+1<<"\t"<<pBantu->npm<<"\t\t";
        cout<<pBantu->nama<<"\t";
        cout<<pBantu->ipk<<"\t\n";
        pBantu=pBantu->next;
        i++;
    } while(pBantu != NULL);
}

int main (){
	pointer pBaru;
    List first;
    int pilihan,n;

    createList(first);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Tambah Data Mahasiswa"<<endl;
        cout<<"2. Hasil"<<endl;
        cout<<"3. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
        	cout<<"Banyak data : "; cin>>n;
        	for (int i=0; i<n; i++){	
            createElmt(pBaru);
            insertSortNPM(first, pBaru);
        }
        break;

        case 2:
           traversal(first);
        break;

        case 3:
            return 0;
            break;
        }
        system("pause");
    }
}

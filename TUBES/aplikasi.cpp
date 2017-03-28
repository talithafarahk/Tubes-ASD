
#include <conio.h>

#include "aplikasi.h"
#include "parent.h"
#include "child.h"
#include "relasi.h"

List Lp;
List_c Lc;
List_relasi Lr;


address P;
address_c Q;
address_relasi R;


address_relasi AB;
address search_p;
address_c search_c;


negara x;
orang xx;

void main_menu()
{
    int pilihan;
    create_list(Lp);
    create_list(Lc);
    create_list(Lr);
    do
    {
        cout<<"===  M E N U  ==="<<endl;
        cout<<" 1. Input Destinasi Tujuan"<<endl;
        cout<<" 2. Input Informasi Turis"<<endl;
        cout<<" 3. Tampilkan Data Destinasi Tujuan"<<endl;
        cout<<" 4. Tampilkan Data Informasi Turis"<<endl;
        cout<<" 5. Cari Destinasi Tujuan"<<endl;
        cout<<" 6. Cari Informasi Turis"<<endl;
        cout<<" 7. Delete Data Tujuan"<<endl;
        cout<<" 8. Delete Data Turis"<<endl;
        cout<<" 9. Relasi Berdasarkan ID"<<endl;
        cout<<" 10. Tampilkan Data Relasi"<<endl;
        cout<<" 11. Cari Relasi"<<endl;
        cout<<" 12. Delete Relasi"<<endl;
        cout<<" 13. Tampilkan Relasi Sesuai Urutan"<<endl;

        cout<<" 0. Exit"<<endl;
        cout<< "Masukkan pilihan Anda : ";
        cin>>pilihan;
        switch (pilihan)
        {
        case 1:
            insertParent();
            break;
        case 2:
            insertChild();
            break;
        case 3:
            printInfo(Lp);
            break;
        case 4:
            printInfo(Lc);
            break;
        case 5:
            search_parent();
            break;
        case 6:
            search_child();
            break;
        case 7:
            deleteparent_p();
            break;
        case 8:
            deletechild_c();
            break;
        case 9:
            relasiID();
            break;
        case 10:
            printInfo(Lr);
            break;
        case 11:
            cari_relasi();
            break;
        case 12:
            delete_relasi();
            break;
        case 13:
            tampil_relasi();
            break;
        }

        cout<<"\npress enter\n";
        getch();
        cout<<endl;
        system("cls");
    }
    while(pilihan!=0);
}

address insertParent()
{
    cout<<"Masukkan Kode Negara : ";
    cin>>x.id;
    cout<<"Masukkan Benua-nya: ";
    cin>>x.benua;
    cout<<"Masukkan Nama Negara: ";
    cin>>x.nama;
    cout<<"Lokasi Wisata: ";
    cin>>x.lokasi;
    cout<<"Visa Negara: ";
    cin>>x.visa;
    P=alokasi(x);
    insertAscending(Lp,P);
    return P;
}

address_c insertChild()
{
    cout<<"Masukkan ID  : ";
    cin>>xx.id_c;
    cout<<"Masukkan Nama: ";
    cin>>xx.nama_c;
    cout<<"Masukkan Umur Anda : ";
    cin>>xx.umur;
    cout<<"Masukkan Jenis Kelamin : ";
    cin>>xx.kelamin;
    cout<<"Estimasi Tujuan: ";
    cin>>xx.tujuan;
    Q=alokasi(xx);
    insertAscending(Lc,Q);
    return Q;
}

void deleteparent_p()
{
    cout<<"Masukkan ID Yang Ingin Di Hapus :";
    cin>>x.id;
    deleteParent(Lp,x);
}

void deletechild_c()
{
    cout<<"Masukkan ID Yang Ingin Di Hapus :";
    cin>>xx.id_c;
    deletechild(Lc,xx);
}

void search_parent()
{
    cout<<"Masukkan Kode Negara Yang Ingin Di Cari :";
    cin>>x.id;
    search_p = findElm(Lp,x);
    if (search_p!=NULL)
    {
        cout<<"K O D E       N E G A R A  : "<<info(search_p).id<<endl;
        cout<<"N A M A       N E G A R A  : "<<info(search_p).nama<<endl;
        cout<<"N A M A       B E N U A    : "<<info(search_p).benua<<endl;
        cout<<"L O K A S I   W I S A T A  : "<<info(search_p).lokasi<<endl;
        cout<<"H A R G A     V I S A      : "<<info(search_p).visa<<endl;
    }
    else
    {
        cout<<"ID Tidak Ditemukan"<<endl;
    }

}

void search_child()
{
    cout<<"Masukkan ID Turis Yang Ingin Di Cari :";
    cin>>xx.id_c;
    search_c = findElm(Lc,xx);
    if (search_c!=NULL)
    {
        cout<<"I D           T U R I S      : "<<info(search_c).id_c<<endl;
        cout<<"N A M A       T U R I S      : "<<info(search_c).nama_c<<endl;
        cout<<"U M U R       T U R I S      : "<<info(search_c).umur<<endl;
        cout<<"J E N I S     K E L A M I N  : "<<info(search_c).kelamin<<endl;
        cout<<"N E G A R A   T U J U A N    : "<<info(search_c).tujuan<<endl;
    }
    else
    {
        cout<<"ID Tidak Ditemukan"<<endl;
    }
}

void relasiID()
{
    cout<<"Relasi Berdasarkan ID"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";
    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if (search_c==NULL || search_p ==NULL)
    {

        cout<<"Tidak Terdapat ID Negara / ID Turis"<<endl;
    }

    else if(search_p != NULL && search_c != NULL)
    {
        AB = alokasi(search_p,search_c);
        insertLast(Lr,AB);
        cout<<"ID NEGARA : "<<info(search_p).id<<endl;
        cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        cout<<"STATUS : Berhasil Berelasi"<<endl;

    }

}

void cari_relasi()
{
    cout<<"~~~~~~~   Mencari Relasi Berdasarkan ID   ~~~~~~~"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";

    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if (search_c != NULL && search_p != NULL)
    {
        AB=search_relasi(Lr, search_p,search_c);
        if (AB!=NULL)
        {

            cout<<"Relasi Ditemukan"<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"======== B E R E L A S I ========="<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
        else
        {
            cout<<"Relasi TIDAK Ditemukan "<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;

            cout<<"****** T I D A K     B E R E L A S I ******"<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
    }
    else
    {
        cout<<"Tidak Dapat ditemukan"<<endl;
        cout<<"LIST MASIH KOSONG"<<endl;
    }

}

void delete_relasi()
{
    cout<<"******** Delete Relasi Berdasarkan ID *********"<<endl;
    cout<<"Masukkan ID Negara: ";
    cin>>x.id;
    cout<<"Masukkan ID Turis :";
    cin>>xx.id_c;

    search_p = findElm(Lp,x);
    search_c = findElm(Lc,xx);

    if (search_c == NULL && search_p == NULL)
    {
        cout<<"Tidak Dapat ditemukan"<<endl;
        cout<<"LIST MASIH KOSONG"<<endl;
    }
    else
    {
        AB=search_relasi(Lr, search_p,search_c);
        if (AB!=NULL)
        {
            cout<<"Relasi Ditemukan"<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"======== B E R E L A S I ========="<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
            deleteRelasi(Lr,AB);

            cout<<"RELASI  BERHASIL  DIHAPUS"<<endl;
        }
        else
        {
            cout<<"Relasi TIDAK Ditemukan "<<endl;
            cout<<"ID NEGARA : "<<info(search_p).id<<endl;
            cout<<"****** T I D A K     B E R E L A S I ******"<<endl;
            cout<<"ID TURIS : "<<info(search_c).id_c<<endl;
        }
    }
}

void tampil_relasi()
{
    sortrelasi(Lr);
    printInfo(Lr);
}



//by 1301164262

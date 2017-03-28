#include "relasi.h"
#include "parent.h"
#include "child.h"

#include <iostream>
using namespace std;

void create_list(List_relasi &L)
{
    first(L)=NULL;

}
address_relasi alokasi(address Q, address_c C)
{
    address_relasi P;
    P = new elmlist_relasi;
    child(P)= C;
    parent(P)= Q;
    return P;
}
void dealokasi(address_relasi &P)
{
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    if (first(L)!=NULL)
    {
        next(P)=first(L);
        first(L)=P;
    }
    else
    {
        first(L)=P;
        next(P) = NULL;
    }

}
void insertLast(List_relasi &L, address_relasi P)
{
    address_relasi q;
    if (first(L)!=NULL)
    {
        q=first(L);
        while (next(q)!= NULL)
        {
            q=next(q);
        }
        next(q)=P;
        next(P) = NULL;
    }
    else
    {
        insertFirst(L,P);
    }
}

void insertAfter(List_relasi &L,address_relasi Q,address_relasi P)
{
    if (first(L)!=NULL)
    {
        next(P)=next(Q);
        next(Q)=P;
    }
    else
    {
        insertFirst(L,P);
    }
}


address_relasi findElm(List_relasi L, address P,address_c Q)
{
    address_relasi R;
    R=first(L);
    while(R!= NULL)
    {
        if(parent(R)==P && child(R)== Q)
        {
            return R;
        }
        R = next(R);
    }
    return NULL;
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    P=first(L);
    if (first(L)==NULL)
    {
        first(L)==NULL;
    }
    else if (next(P)==NULL)
    {
        first(L)==NULL;
    }
    else
    {
        first(L)=next(first(L));
        next(P)=NULL;
    }

}
void deleteLast(List_relasi &L, address_relasi &P)
{
    P = first(L);
    if (first(L)== NULL)
    {
        delete P;
    }
    else
    {
        while (next(next(P))!=NULL)
        {
            P=next(P);
        }
        next(P)=NULL;
    }
}
void deleteAfter(List_relasi &L, address_relasi prec, address_relasi &P)
{
    if (next(prec)== NULL)
    {
    }
    else
    {
        P=next(prec);
        next(first(L))=next(P);
        next(P)=NULL;
    }
}

void printInfo(List_relasi L)
{
    address_relasi R;

    if (first(L) == NULL)
    {
        cout<<"TIDAK TERDAPAT RELASI";
    }
    else
    {
        R= first(L);
        while (R != NULL)
        {
            cout<<"ID NEGARA : "<<info(parent(R)).id<<endl;
            cout<<"NAMA NEGARA : "<<info(parent(R)).nama<<endl;

            cout<<"=====  B E R E L A S I   D E N G A N  ====="<<endl;

            cout<<"ID TURIS : "<<info(child(R)).id_c<<endl;
            cout<<"NAMA TURIS : "<<info(child(R)).nama_c<<endl;
            cout<<endl;
            R=next(R);
        }

    }
    cout<<endl;
}

address_relasi search_relasi(List_relasi L, address P, address_c Q)
{
    address_relasi R;
    R=first(L);
    if (first(L)==NULL)
    {
        return NULL;
    }
    else
    {
        while (next(R) != NULL)
        {
            if(parent(R) != P && child(R) != Q)
            {
                R = next(R);
            }
        }
        if(child(R) == Q && parent(R) == P)
        {
            return R;
        }
        else
        {
            return NULL;
        }
    }
}

void deleteRelasi(List_relasi &L, address_relasi P)
{
    child(P)=NULL;
    parent(P)=NULL;
    dealokasi(P);
}
void del_relasi(List_relasi L,address_relasi &P)
{
    address_relasi Q;
    if(P!= NULL)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);

        }
        else if(next(P) ==NULL)
        {
            deleteLast(L,P);

        }
        else
        {
            next(Q)=next(P);
            next(P)=NULL;
            deleteRelasi(L,P);
    }
    }
    else
    {

        cout<<"ID TIDAK DITEMUKAN"<<endl;
    }
}


address_relasi find_min(List_relasi &L)
{
    address_relasi P,min;
    P=NULL;
    if (first(L)==NULL)
    {
        return NULL;
    }
    else
    {
        P=first(L);
        min = P;
        if (info(parent(P)).id < info(parent(min)).id)
        {
            min=P;
        }
        P=min;
    }
    return P;
}


void sortrelasi(List_relasi &L)

{
    address_relasi P,Q;
    address A;
    address_c B;
    List_relasi R;
    create_list(R);
    while (first(L)!=NULL)
    {
        P = find_min(L);
        A = parent(P);
        B = child(P);
        del_relasi(L,P);
        Q = alokasi(A,B);
        insertLast(R,Q);
    }
    L=R;
}

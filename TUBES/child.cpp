#include "child.h"

void create_list(List_c L)
{
    first(L) = NULL;
    last(L) = NULL;
}
address_c alokasi(orang x)
{
    address_c P;
    P= new elmlist_c;
    info(P).id_c=x.id_c;
    info(P).nama_c=x.nama_c;
    info(P).umur=x.umur;
    info(P).kelamin=x.kelamin;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}
void dealokasi(address_c &P)
{
    delete P;
}

void insertFirst(List_c &L, address_c P)
{
    if(first(L) == NULL)
    {
        first(L)=P;
        last(L)=P;
    }
    else
    {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLast(List_c &L, address_c P)
{
    if(first(L) == NULL)
        insertFirst(L,P);
    else
    {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void insertAfter(List_c &L,address_c prec,address_c P)
{
    if(prec!=NULL)
    {
        if(prec==last(L))
        {
            insertLast(L,P);
        }
        else
        {
            next(P) = next(prec);
            prev(P)=prec;
            prev(next(prec))=P;
            next(prec)=P;
        }
    }
    else
    {
        cout<<"Gagal insert after"<<endl;
    }
}

address_c findElm(List_c L, orang x)
{
    address_c P;
    if (first(L) == NULL)
    {
        return NULL;
    }
    else
    {
        P = first(L);
        while(info(P).id_c!= x.id_c && next(P)!=NULL)
        {
            P = next(P);
        }
        if (info(P).id_c != x.id_c)
        {
            return NULL;
        }
        else
        {
            return P;
        }
    }
}

void deleteFirst(List_c &L, address_c &P)
{
    if(first(L) == last(L))
    {
        P = first(L);
        first(L)=NULL;
        last(L)=NULL;
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(List_c &L, address_c &P)
{

    if(first(L)!= last(L))
    {
        address_c Q;
        P = last(L);
        Q=prev(P);
        last(L) = Q;
        next(Q)=NULL;
        prev(P)=NULL;
    }
    else
    {
        deleteFirst(L,P);
    }
}

void deleteAfter(List_c &L, address_c prec, address_c &P)
{
    if(first(L) != NULL)
    {
        if(prec != NULL)
        {
            if(next(prec) == first(L))
            {
                deleteFirst(L,P);
            }
            else
            {
                P = next(prec);
                next(prec) = next(P);
                next(P) = NULL;
            }
        }
        else
        {
            cout<<"Gagal delete after"<<endl;
        }
    }
    else
    {
        cout<<"List kosong"<<endl;
    }
}

void printInfo(List_c L)
{
    address_c P;
    P = first(L);
    if (first(L) == NULL)
    {
        cout<<"List Kosong";
    }
    else
    {
        do
        {
            cout<<"I D       T U R I S     : "<<info(P).id_c<<endl;
            cout<<"N A M A   T U R I S     : "<<info(P).nama_c<<endl;
            cout<<endl;
            P=next(P);
        }
        while (P !=NULL);
    }
    cout<<endl;

}

address_c deletechild(List_c &L, orang x)
{
    address_c P,P2;

    P = findElm(L,x);

    if(P!= NULL)
    {
        if(P == first(L))
        {
            deleteFirst(L,P);
            cout<<"Data Berhasil Dihapus"<<endl;
            return P;
        }

        else if(next(P) == NULL)
        {
            deleteLast(L,P);
            cout<<"Data Berhasil Dihapus"<<endl;
            return P;
        }
        else
        {
            address_c Q = first(L);
            while (next(Q) != NULL)
            {
                Q = next(Q);
            }
            deleteAfter(L,Q,P);
            cout<<"Data Berhasil Dihapus"<<endl;
            return P;
        }
    }
    else
    {
        cout<<"ID TIDAK DITEMUKAN"<<endl;
        return NULL;
    }
}
void insertAscending(List_c &L,address_c P)
{
    address_c Q,R;
    if (first(L)!=NULL)
    {
        Q=first(L);
        R=next(Q);
        if (info(P).id_c < info(Q).id_c)
        {
            insertFirst(L,P);
        }
        else if (next(Q) == NULL)
        {
            insertLast(L,P);
        }
        else if (info(P).id_c > info(Q).id_c && info(P).id_c < info(R).id_c)
        {
            insertAfter(L,Q,P);
        }
        else
        {
            while (info(P).id_c > info(Q).id_c && next(R) != NULL )
            {
                Q=next(Q);
                R=next(R);
            }
            if (info(P).id_c > info(Q).id_c && info(P).id_c < info(R).id_c)
            {
                insertAfter(L,Q,P);
            }
            else
            {
                insertLast(L,P);
            }
        }
    }
    else
    {
        insertFirst(L,P);
    }

}

//by 1301164461

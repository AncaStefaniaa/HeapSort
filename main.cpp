#include <iostream>
using namespace std;

//todo HEAPSORT

void heapify(int v[], int n, int i)
{
    int maximul = i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n && v[left]>v[maximul])//verific daca fiul stang e mai mare decat paintele
        maximul = left;

    if (right<n && v[right]>v[maximul])//verific daca fiul drept e mai mare decat fiul
        maximul=right;//daca da el devine maximul


    if (maximul!=i)//daca am gasit un alt maxim printre fii
    {
        int aux=v[i];
        v[i]=v[maximul];
        v[maximul]=aux;
        heapify(v,n,maximul);//apelez pentru urmarorul subarbore
    }
}

void heapSort(int v[],int n)//functia principala pentru heapsort
{
    for (int i=n/2-1;i>=0;i--)//rearanjam vectorul
        heapify(v,n,i);

    for (int i=n-1;i>=0;i--)//stergem ultimul element maxim gasit din vector dupa ce am efectuat interschimbarea
    {
        int aux=v[0];//interchimbare
        v[0]=v[i];
        v[i]=aux;

        //apelez iar functia pentru heapul fara cel mai mare element gasit
        heapify(v,i,0);
    }
}


int main()
{
    int v[100],i,n;

    cout<<"n=";cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"v["<<i<<"]=";
        cin>>v[i];
    }

    heapSort(v,n);

    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

}
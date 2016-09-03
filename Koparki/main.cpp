#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include<conio.h>
#include<windows.h>
using namespace std;

/*--------------------------FUNKCJA ODPOWIEDZIALNA ZA DRUKOWANIE MENU--------------------------*/
void drukmenu(){
    cout<<"-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-MENU-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-\n1-Wyswietl\n2-Dodaj\n3-Rezerwacja\n9-Wgraj Domyslna Baze\n-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-=-=-=-=-=-=-=-=--=-=-=--=-=-=--=-=-=--=-=-=-\nESC-Exit\n";
    cout<<"Nacisnij odpowiedni klawisz.";
}
/*--------------------------FUNKCJA ODPOWIEDZIALNA ZA REZERWACJE KOPARKI-------------------------*/
void reazeroj(){
system("cls");
FILE * plik;
plik = fopen( "c:\\temp\\koparki.txt", "a+" );
char S[ 100 ];
string tablica [1000][2];
int kolumna=0;
int wiersz=1;
int i=0;
while(fscanf( plik, "%s", S)!= EOF){
    string text = S;
    if(i==0){
        tablica[wiersz][kolumna]=text;
        kolumna=1;
        i++;
    }else if(i==1){
        tablica[wiersz][kolumna]=text;
        kolumna=0;
        wiersz++;
        i=0;
    }
}
cout.setf(ios::left,ios::adjustfield);
cout.width(5);
cout<<"ID |";
cout.width(20);
cout<<"Nazwa Koparki |";
cout.width(18);
cout<<" Stan";
cout<<endl;
cout<<"-----------------------------------------"<<endl;
tablica[0][0]="zapelniacz";
cout<<" 0 - powrot do menu"<<endl<<endl;
for(int xc=1;xc<100;xc++){

    string textorek = tablica[xc][0];
    if(textorek==""){
        break;
    }
    cout.width(5);
    cout<<xc;
    cout.width(20);
    cout<<tablica[xc][0];
    cout.width(18);
    cout<<tablica[xc][1]<<endl;
}
cout<<"Prosze wpisac id koparki ktora chcesz zarezerwowac i potwierdzi naciskajac enter"<<endl;
int wybranakoparka;
cin>>wybranakoparka;
if(wybranakoparka==0){
    system("cls");
    drukmenu();
     //<----Jesli ktos nacisnie zero to cofnie sie do menu
}
if(!wybranakoparka<=0){
    if(tablica[wybranakoparka][1]!="ZAREZERWOWANA"){
        tablica[wybranakoparka][1]="ZAREZERWOWANA";
        FILE * plik;
        plik = fopen( "c:\\temp\\koparki.txt", "w" );
            if(!plik)
            {
                cout<<"Przykro nam, ale usluga jest chwilowo niedostepna"<<endl;
            }
            for(int tt=1;tt<1000;tt++){
                fputs(tablica[tt][0].c_str(), plik);
                fputs("\n", plik);
                fputs(tablica[tt][1].c_str(), plik);
                fputs("\n", plik);
            }
        fclose( plik );
        cout<<"Zarezerwowano koparke "<<tablica[wybranakoparka][0]<<endl;
        Sleep(4000);
        system("cls");
        drukmenu();
    }else{
        cout<<"Ta koparka jest zarezerwowana lub nie istnieje";
        Sleep(2000);
        reazeroj();
    }
}else{
    cout<<"BLAD Tylko liczby";
}
fclose( plik );
}
/*--------------------------FUNKCJA ODPOWIEDZIALNA ZA WYSWIETLANIE BAZY KOPAREK--------------------------*/
void wyswietl()
{
system("cls");
FILE * plik;
plik = fopen( "c:\\temp\\koparki.txt", "a+" );
    if(!plik)
    {
        cout<<"Przykro nam, ale usluga jest chwilowo niedostepna"<<endl;
    }
char S[ 100 ];
int i=0;
cout.setf(ios::left,ios::adjustfield);
cout.width(16);
cout<<"Nazwa Koparki |";
cout.width(10);
cout<<" Stan";
cout<<endl;
cout<<"-----------------------------------------"<<endl;
while(fscanf( plik, "%s", S)!= EOF){
    string text = S;
    if(i==0){
        cout.width(20);
        cout<<text;
        i++;
    }else if(i==1){
        cout.width(18);
        cout<<text<<endl;
        cout<<"---------------------------------------"<<endl;
        i=0;
    }
}
fclose(plik);
drukmenu();
}
/*--------------------------FUNKCJA ODPOWIEDZIALNA ZA DODAWANIE KOPAREK DO BAZY--------------------------*/
void dodaj()
{
system("cls");
    cout<<"\n\nPodaj nazwe koparki, ktora chcialbys dodac"<<endl;
    string nazwakoparki;
    string wynajeta;

   /* scanf("%s", ( char * ) nazwakoparki.c_str()); */
    cin>>nazwakoparki;
    cout<<"\nCzy wynajeta?(tak/nie) odp t lub n"<<endl;
    while(wynajeta!="ZAREZERWOWANA" && wynajeta!="WOLNA" ){
        char znak;
        znak = getch();
        switch(znak){
            case 116: wynajeta="ZAREZERWOWANA";break;
            case 110: wynajeta="WOLNA";break;
            default: system("cls");cout<<"Poprawna odpowiedz to t lub n";break;
        }
    }
system("cls");
FILE * plik;
plik = fopen( "c:\\temp\\koparki.txt", "a+" );
    if(!plik)
    {
        cout<<"Przykro nam, ale usluga jest chwilowo niedostepna"<<endl;
    }
fputs("\n", plik);
fputs(nazwakoparki.c_str(), plik);
fputs("\n", plik);
fputs(wynajeta.c_str(), plik);
fclose( plik );
cout<<"Pomyslnie dodano koparke "<<nazwakoparki<< " do bazy danych";
Sleep(4000);
system("cls");
drukmenu();
}


/*--------------------------FUNKCJA ODPOWIEDZIALNA ZA EXIT PROGRAMU--------------------------*/
void exit(){
    system("cls");
    cout<<" >->->->->->->->->->EXIT<-<-<-<-<-<-<-<-<-<"<<endl;
    cout<<endl;
    cout<<"   Dziekujemy za korzystanie z programu"<<endl;
    cout<<"   Program wykonali:"<<endl;
    cout<<"   Konrad Broniszewski"<<endl;
    cout<<"   Kamil Daniewski"<<endl;
    cout<<"   Piotr Ciotucha"<<endl;
    Sleep(4000);
    exit(0);
}
/*--------------------------FUNKCJA INSTALACYJNA--------------------------*/
void installfun(){
FILE * plik;
plik = fopen( "c:\\temp\\koparki.txt", "w+" );
    if(!plik)
    {
        cout<<"Przykro nam, ale usluga jest chwilowo niedostepna"<<endl;
    }
fputs("Cat336EH\n", plik);
fputs("ZAREZERWOWANA\n", plik);
fputs("CAT5110B\n", plik);
fputs("ZAREZERWOWANA\n", plik);
fputs("LiebherrR944C\n", plik);
fputs("WOLNA\n", plik);
fputs("CaseWX168\n", plik);
fputs("ZAREZERWOWANA\n", plik);
fputs("KomatsuPC490LC10\n", plik);
fputs("WOLNA\n", plik);
fputs("JCB8086CTS\n", plik);
fputs("WOLNA\n", plik);
fputs("VolvoEC220D\n", plik);
fputs("WOLNA\n", plik);
fputs("CaseCX800\n", plik);
fputs("ZAREZERWOWANA\n", plik);
fputs("CASE250CX\n", plik);
fputs("WOLNA\n", plik);
fputs("Mustang5003ZT\n", plik);
fputs("WOLNA\n", plik);
fputs("NewHollandE215\n", plik);
fputs("ZAREZERWOWANA", plik);
fclose( plik );
system("cls");
cout<<"Instalacja przebiegla pomyslnie";
Sleep(3000);
system("cls");
drukmenu();
}
/*--------------------------GLOWNA FUNKCJA MAIN--------------------------*/
int main()
{
drukmenu();
while(true){
        char znak;
        znak = getch();
        switch(znak){
            case '1': wyswietl();break;
            case '2': dodaj();break;
            case '3': reazeroj();break;
            case '9': installfun();break;//<-Ukryty przysicko do instalacji
            case 27: exit() ;break;
            default: system("cls");cout<<"To nie jest poprawna funkcja"<<endl;drukmenu();break;
        }
    }
    return 0;
}

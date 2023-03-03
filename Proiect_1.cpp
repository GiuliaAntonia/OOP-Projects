#include <bits/stdc++.h>
using namespace std;

class Angajat{
private:
    string numAngajat;
    int varsta;
    int nrLuniAngajare;
    float salariu;
    float* cheltuieli;

public:
    Angajat();
    Angajat(string numAngajat, int varsta, int nrLuniAngajare, float salariu, float* cheltuieli);
    Angajat(const Angajat& angajat);
    Angajat& operator = (const Angajat& angajat);

    ~Angajat();

    friend istream& operator>>(istream& in, Angajat& angajat);
    friend ostream& operator<<(ostream& out, const Angajat& angajat);

    void afisareAngajat();
    void citireAngajat();
    void marireSalariu();

    // supraincarcarea operatorului ==
    bool operator==(const Angajat& angajat){
        if(this->numAngajat == angajat.numAngajat && this->varsta == angajat.varsta &&
           this->nrLuniAngajare == angajat.nrLuniAngajare && this->salariu == angajat.salariu)
            return true;
        return false;
    }

    // supraincarcarea operatorului >=
    bool operator>=(const Angajat &angajat){
        if(this->nrLuniAngajare >= angajat.nrLuniAngajare)
            return true;
        return false;
    }

    // supraincarcarea operatorului <
    bool operator < (const Angajat& angajat){
        if(this->salariu < angajat.salariu)
            return true;
        return false;
    }

    //supraincarcarea operatorului +
    bool operator+(Angajat angajat){
        angajat.salariu = this->salariu + angajat.salariu;
    }

    //supraincarcarea operatorului *
    bool operator*(Angajat angajat){
        angajat.salariu = this->salariu * angajat.salariu;
    }

    // operatorul cast explicit
    explicit operator int() const{
        return (int)this->salariu;
    }

    // supraincarcarea operatorului +=
    Angajat operator += (int x){
        this->salariu += x;
        return *this;
    }

    // supraincarcarea operatorului ++ post-incrementare
    Angajat operator++(int){
        Angajat aux(*this);
        this->salariu++;
        return *this;
    }

    // supraincarcarea operatorului ++ pre-incrementare
    Angajat operator++(){
        Angajat aux(*this);
        this->salariu++;
        return aux;
    }

    // getters & setters
    void setNumeAngajat(){
        this->numAngajat = numAngajat;
    }
    string getNumeAngajat(){
        return this->numAngajat;
    }

    void setVarsta(){
        this->varsta = varsta;
    }
    int getVarsta(){
        return this->varsta;
    }

    void setNrLuniAngajare(){
        this->nrLuniAngajare = nrLuniAngajare;
    }
    int getNrLuniAngajare(){
        return this->nrLuniAngajare;
    }

    void setSalariu(){
        this->salariu = salariu;
    }

    float getSalariu(){
        return this->salariu;
    }

    void setCheltuieli(){
        this->cheltuieli = cheltuieli;
    }
    float* getCheltuieli(){
        return this->cheltuieli;
    }
};

// constructorul fara parametrii
Angajat::Angajat() {
    this->numAngajat = "Anonim";
    this->varsta = 0;
    this->nrLuniAngajare = 0;
    this->salariu = 0;
    this->cheltuieli = NULL;
}

// constructor cu toti parametrii
Angajat::Angajat(string numAngajat, int varsta, int nrLuniAngajare, float salariu, float* cheltuieli) {
    this->numAngajat = numAngajat;
    this->varsta = varsta;
    this->nrLuniAngajare = nrLuniAngajare;
    this->salariu = salariu;
    this->cheltuieli = new float[this->nrLuniAngajare];
    for(int i = 0; i < this->nrLuniAngajare; i++)
        this->cheltuieli[i] = cheltuieli[i];
}

// copy constructor
Angajat::Angajat(const Angajat &angajat) {
    this->numAngajat = angajat.numAngajat;
    this->varsta = angajat.varsta;
    this->nrLuniAngajare = angajat.nrLuniAngajare;
    this->salariu = angajat.salariu;
    this->cheltuieli = new float[this->nrLuniAngajare];
    for(int i = 0; i < angajat.nrLuniAngajare; i++)
        this->cheltuieli[i] = angajat.cheltuieli[i];
}

// supraincarcarea operatorului =
Angajat &Angajat::operator=(const Angajat& angajat) {
    if(this != &angajat)
    {
        if(this->cheltuieli != NULL)
            delete [] this->cheltuieli;

        this->numAngajat = angajat.numAngajat;
        this->varsta = angajat.varsta;
        this->nrLuniAngajare = angajat.nrLuniAngajare;
        this->salariu = angajat.salariu;
        this->cheltuieli = new float[this->nrLuniAngajare];
        for(int i = 0; i < this->nrLuniAngajare; i++)
            this->cheltuieli[i] = angajat.cheltuieli[i];
    }
    return *this;
}
// destructorul
Angajat::~Angajat() {
    if(this->cheltuieli != NULL)
        delete [] this->cheltuieli;
}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, Angajat& angajat){
    cout<<"Introduceti numele angajatului: ";
    in>>angajat.numAngajat;

    cout<<"Introduceti varsta angajatului: ";
    in>>angajat.varsta;

    cout<<"Introduceti nr luni de munca: ";
    in>>angajat.nrLuniAngajare;

    cout << "Introduceti salariul pe luna: ";
    in >> angajat.salariu;

    if(angajat.cheltuieli != NULL)
        delete [] angajat.cheltuieli;
    angajat.cheltuieli = new float[angajat.nrLuniAngajare];
    for(int i = 0; i < angajat.nrLuniAngajare; i++){
        cout<<"Cheltuielile pe luna "<<i+1<<" sunt: ";
        in>>angajat.cheltuieli[i];

    }
    return in;
}

// supraincarcarea operatorului <<
ostream& operator<< (ostream& out, const Angajat& angajat){
    out<<"Nume: "<<angajat.numAngajat<<'\n';
    out<<"Varsta: "<<angajat.varsta<<'\n';
    out<<"Numarul de luni de lucru: "<<angajat.nrLuniAngajare<<'\n';
    out<<"Salariul pe luna este: "<<angajat.salariu<<'\n'<<'\n';

    for(int i = 0; i < angajat.nrLuniAngajare; i++)
        out<<"In luna "<<i+1<<" au fost cheltuielile: "<<angajat.cheltuieli[i]<<'\n';

    return out;
}

/*Angajat Angajat:: operator[](int index){
    if(0 <= index && index < this->nrLuniAngajare)
        return this
}*/

void Angajat::afisareAngajat() {
    cout<<"Nume: "<<this->numAngajat<<'\n';
    cout<<"Varsta: "<<this->varsta<<'\n';
    cout<<"Numarul de luni de lucru: "<<this->nrLuniAngajare<<'\n';
    cout<<"Salariul pe luna este: "<<this->salariu<<'\n'<<'\n';
    for(int i = 0; i < this->nrLuniAngajare; i++)
        cout<<"In luna "<<i+1<<" au fost cheltuielile: "<<this->cheltuieli[i]<<'\n';
}

void Angajat::citireAngajat() {
    cout<<"Introduceti numele angajatului: ";
    cin>>this->numAngajat;

    cout<<"Introduceti varsta angajatului: ";
    cin>>this->varsta;

    cout<<"Introduceti nr luni de munca: ";
    cin>>this->nrLuniAngajare;

    cout << "Introduceti salariul pe luna: ";
    cin >> this->salariu;

    for(int i = 0; i < this->nrLuniAngajare; i++){
        cout<<"Cheltuielile pe luna "<<i+1<<" sunt: ";
        cin>>this->cheltuieli[i];
    }
}

// se va mari cu 15% salariul angajatilor care lucreaza de 1 an
// si cu 2/1000 salariul angajatilor care lucreaza de mai mult de
// 5 ani si se vor pensiona(au 60 ani)
void Angajat::marireSalariu() {
    if(this->nrLuniAngajare == 12)
        this->salariu = this->salariu + this->salariu*15/100;
    else
    if(this->nrLuniAngajare >= 60 && this->varsta == 60)
        this->salariu = this->salariu + this->salariu*2/1000;
    else
        cout<<"Angajatul "<< this->numAngajat<<" nu respecta conditiile pt marire de salariu";
}

class Biblioteca{
private:
    string oras;
    string anInfiintare;
    int nrAngajati;
    Angajat* listaAngajati;

public:
    Biblioteca();
    Biblioteca(string oras, string anInfiintare, int nrAngajati, Angajat* listaAngajati);
    Biblioteca(const Biblioteca& biblioteca);
    Biblioteca& operator = (const Biblioteca& biblioteca);

    ~Biblioteca();

    friend istream& operator>>(istream& in, Biblioteca& biblioteac);
    friend ostream& operator<<(ostream& out, const Biblioteca& biblioteca);

    void afisareBiblioteca();
    void citireBiblioteca();
    void sorteazaAngajatiDupaSalariu();

    // supraincarcarea operatorului == Biblioteca-Angajat
    bool operator == (string numeAngajat){
        for(int i = 0; i < this->nrAngajati; i++)
            if(this->listaAngajati[i].getNumeAngajat() == numeAngajat)
                return true;
        return false;
    }

    // supraincarcarea operatorului + Biblioteca-Angajat
    Biblioteca operator + (const Angajat& angajat){
        Angajat* aux = NULL;
        if(this->listaAngajati != NULL){
            aux = new Angajat[this->nrAngajati];
            for(int i = 0; i < this->nrAngajati; i++)
                aux[i] = this->listaAngajati[i];
            delete [] this->listaAngajati;
        }

        this->nrAngajati++;
        this->listaAngajati = new Angajat[this->nrAngajati];

        for(int i = 0; i < nrAngajati-1; i++)
            this->listaAngajati[i] = aux[i];
        this->listaAngajati[this->nrAngajati-1] = angajat;
        if(aux != NULL)
            delete [] aux;
        return  *this;
    }

    // supraincarcarea operatorului ==
    bool operator == (const Biblioteca& biblioteca){
        if(this->oras == biblioteca.oras && this->anInfiintare == biblioteca.anInfiintare &&
           this->nrAngajati == biblioteca.nrAngajati && this->listaAngajati == biblioteca.listaAngajati)
            return true;
        return false;
    }

    // supraincarcarea operatorului <
    bool operator < (const Biblioteca& biblioteca){
        if(this->anInfiintare < biblioteca.anInfiintare)
            return true;
        return false;
    }

    // supraincarcarea operatorului +
    Biblioteca operator + (Biblioteca& biblioteca){
        biblioteca.nrAngajati = this->nrAngajati + biblioteca.nrAngajati;
    }

    // supraincarcarea operatorului -
    Biblioteca operator - (Biblioteca& biblioteca){
        biblioteca.nrAngajati = this->nrAngajati - biblioteca.nrAngajati;
    }

    // supraincarcarea operatorului ++ post-incrementare
    Biblioteca operator ++(int){
        Biblioteca aux(*this);
        this->nrAngajati++;
        return *this;
    }

    // supraincarcarea operatorului ++ pre-incrementare
    Biblioteca operator ++(){
        Biblioteca aux(*this);
        this->nrAngajati++;
        return  aux;
    }

    // operator de indexare
    Angajat& operator[] (int index){
        if(index >= 0 && index < this->nrAngajati)
            return this->listaAngajati[index];
        cout<<"Index gresit";
    }

    // operator cast explicit
    explicit  operator float()const{
        return (float) this->nrAngajati;
    }

    // setters & getters
    void setMarireSalariu(Angajat& angajat, float newSalariu){
        angajat += newSalariu;
    }

    int getIndexAngajat(string numeAngajat){
        for(int i = 0; i < this->nrAngajati; i++)
            if(this->listaAngajati[i].getNumeAngajat() == numeAngajat)
                return i;
        return -1;
    }

};

// constructorul fara parametrii
Biblioteca::Biblioteca() {
    this->oras = "Unknown location";
    this->anInfiintare = "yyyy";
    this->nrAngajati = 0;
    this->listaAngajati = 0;
}
// constructorul cu toti parametrii
Biblioteca::Biblioteca(string oras, string anInfiintare, int nrAngajati, Angajat *listaAngajati) {
    this->oras = oras;
    this->anInfiintare = anInfiintare;
    this->nrAngajati = nrAngajati;
    this->listaAngajati = new Angajat[nrAngajati];
    for(int i = 0; i < nrAngajati; i++)
        this->listaAngajati[i] = listaAngajati[i];
}

// copy constructor
Biblioteca::Biblioteca(const Biblioteca &biblioteca) {
    this->oras = biblioteca.oras;
    this->anInfiintare = biblioteca.anInfiintare;
    this->nrAngajati = biblioteca.nrAngajati;
    this->listaAngajati = new Angajat[biblioteca.nrAngajati];
    for(int i = 0; i < biblioteca.nrAngajati; i++)
        this->listaAngajati[i] = biblioteca.listaAngajati[i];
}

// supraincarcarea operatorului =
Biblioteca& Biblioteca::operator=(const Biblioteca &biblioteca) {
    if(this != &biblioteca){
        if(this->listaAngajati != NULL)
            delete [] listaAngajati;

        this->oras = biblioteca.oras;
        this->anInfiintare = biblioteca.anInfiintare;
        this->nrAngajati = biblioteca.nrAngajati;
        this->listaAngajati = new Angajat[biblioteca.nrAngajati];
        for(int i = 0; i < biblioteca.nrAngajati; i++)
            this->listaAngajati[i] = biblioteca.listaAngajati[i];
    }
}

// destructorul
Biblioteca::~Biblioteca(){
    if(this->listaAngajati != NULL)
        delete [] listaAngajati;
}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, Biblioteca& biblioteca){
    cout<<"Introduceti orasul: ";
    in>>biblioteca.oras;

    cout<<"Introduceti anul infiintarii: ";
    in>>biblioteca.anInfiintare;

    cout<<"Introduceti nr de angajati: ";
    in>>biblioteca.nrAngajati;

    if(biblioteca.listaAngajati != NULL)
        delete [] biblioteca.listaAngajati;
    biblioteca.listaAngajati = new Angajat[biblioteca.nrAngajati];
    for(int i = 0; i < biblioteca.nrAngajati; i++){
        cout<<"Angajatul "<<i+1<<" este: ";
        in>>biblioteca.listaAngajati[i];
    }

    return in;
}

// supraincarcarea operatorului >>
ostream& operator<<(ostream& out, const Biblioteca& biblioteca){
    out<<"Orasul: "<<biblioteca.oras<<'\n';
    out<<"An infiintare: "<<biblioteca.anInfiintare<<'\n';
    out<<"Nr angajati: "<<biblioteca.nrAngajati<<'\n';
    for(int i = 0; i < biblioteca.nrAngajati; i++)
        out<<"Angajatul "<<i+1<<" este: "<<biblioteca.listaAngajati[i]<<'\n';

    return out;
}

// afisare
void Biblioteca::afisareBiblioteca() {
    cout<<"Orasul: "<<this->oras<<'\n';
    cout<<"An infiintare: "<<this->anInfiintare<<'\n';
    cout<<"Nr angajati: "<<this->nrAngajati<<'\n';
    for(int i = 0; i < this->nrAngajati; i++)
        cout<<"Angajatul "<<i+1<<" este: "<<this->listaAngajati[i]<<'\n';

}

// citire
void Biblioteca::citireBiblioteca() {
    cout<<"Introduceti orasul: ";
    cin>>this->oras;

    cout<<"Introduceti anul infiintarii: ";
    cin>>this->anInfiintare;

    cout<<"Introduceti nr de angajati: ";
    cin>>this->nrAngajati;

    if(this->listaAngajati != NULL)
        delete [] this->listaAngajati;
    this->listaAngajati = new Angajat[this->nrAngajati];
    for(int i = 0; i < this->nrAngajati; i++){
        cout<<"Angajatul "<<i+1<<" este: ";
        cin>>this->listaAngajati[i];
    }
}

// sortare angajati dupa salariu
void Biblioteca::sorteazaAngajatiDupaSalariu() {
    for(int i = 0; i < this->nrAngajati-1; i++)
        for(int j = i+1; j < this->nrAngajati; j++)
            if(!(this->listaAngajati[i] < this->listaAngajati[j])){
                Angajat aux = this->listaAngajati[i];
                this->listaAngajati[i] = this->listaAngajati[j];
                this->listaAngajati[j] = aux;
            }
}

class Carte{
private:
    string titlu;
    string numeAutor;
    int cantitate;
    bool disponibilitate;
    double pretCump;

public:
    Carte();
    Carte(string titlu, string numeAutor, int cantitate, bool disponibilitate, double pretCump);
    Carte(const Carte& carte);
    Carte& operator = (const Carte& carte);

    ~Carte();

    friend istream& operator>>(istream& in, Carte& carte);
    friend ostream& operator<<(ostream& out, const Carte& carte);

    void afisareCarte();
    void adaugaNrCarti();

    // supraincarcarea operatorului ==
    bool operator == (const Carte& carte){
        if(this->titlu == carte.titlu && this->numeAutor == carte.numeAutor &&
           this->cantitate == carte.cantitate && this->disponibilitate == carte.disponibilitate &&
           this->pretCump == carte.pretCump)
            return true;
        return false;
    }

    // supraincarcarea operatorului <
    bool operator < (const Carte& carte){
        if(this->cantitate < carte.cantitate)
            return true;
        return false;
    }

    // supraincarcarea operatorului -
    bool operator - (Carte& carte){
        carte.cantitate = this->cantitate - carte.cantitate;
    }

    // supraincarcarea operatorului +
    bool operator + (Carte& carte){
        carte.cantitate = this->cantitate + carte.cantitate;
    }

    // operatorul cast explicit
    explicit  operator int() const{
        return (int) this->pretCump;
    }

    // supraincarcarea operatorului ++ post-incrementare
    Carte operator++(int){
        Carte acx(*this);
        this->cantitate++;
        return *this;
    }

    // supraincarcarea operatorului ++ pre-incrementare
    Carte operator++(){
        Carte aux(*this);
        this->cantitate++;
        return aux;
    }

    // getters & setters
    void setTitlu(){
        this->titlu = titlu;
    }
    string getTitlu(){
        return this->titlu;
    }

    void setNumeAutor(){
        this->numeAutor = numeAutor;
    }
    string  getNumeAutor(){
        return this->numeAutor;
    }

    void setDisponibilitate(){
        this->disponibilitate = disponibilitate;
    }
    bool getDisponibilitate(){
        return this->disponibilitate;
    }
    void setPretCump(){
        this->pretCump = pretCump;
    }
    double getPretCump(){
        return this->pretCump;
    }
};

// constructorul fara parametrii
Carte::Carte(){
    this->titlu = "Necunoscut";
    this->numeAutor = "Anonim";
    this->cantitate = 0;
    this->disponibilitate = false;
    this->pretCump = 0;
}

// constructorul cu toti parametrii
Carte::Carte(string titlu, string numeAutor, int cantitate, bool disponibilitate, double pretCump) {
    this->titlu = titlu;
    this->numeAutor = numeAutor;
    this->cantitate = cantitate;
    this->disponibilitate = disponibilitate;
    this->pretCump = pretCump;
}

// copy constructor
Carte::Carte(const Carte &carte) {
    this->titlu = carte.titlu;
    this->numeAutor = carte.numeAutor;
    this->cantitate = carte.cantitate;
    this->disponibilitate = carte.disponibilitate;
    this->pretCump = carte.pretCump;
}
// supraincarcarea operatorului =
Carte& Carte::operator=(const Carte &carte) {
    if(this != &carte){
        this->titlu = carte.titlu;
        this->numeAutor = carte.numeAutor;
        this->cantitate = carte.cantitate;
        this->disponibilitate = carte.disponibilitate;
        this->pretCump = carte.pretCump;
    }
    return *this;
}

// destructor
Carte::~Carte() {}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, Carte& carte){
    cout<<"\nIntroduceti titlul cartii: ";
    in>>carte.titlu;

    cout<<"\nIntroduceti numele autorul: ";
    in>>carte.numeAutor;

    cout<<"\nIntroduceti nr de exemplare: ";
    in>>carte.cantitate;

    cout<<"\nIntroduceti disponibilitatea cartii(1-disponibil/0-imprumutata): ";
    in>>carte.disponibilitate;

    cout<<"\nIntroduceti pretul cu care a fost cumparata cartea: ";
    in>>carte.pretCump;
    cout<<'\n';

    return in;
}

// supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Carte& carte){
    out<<"Titlu: "<<carte.titlu<<'\n';
    out<<"Nume autor: "<<carte.numeAutor<<'\n';
    out<<"Cantitate: "<<carte.cantitate<<'\n';
    out<<"Disponibilitate: "<<carte.disponibilitate<<'\n';
    out<<"Pretul cumpararii: "<<carte.pretCump<<'\n'<<'\n';

    return out;
}

// afisare
void Carte::afisareCarte() {
    cout<<"Titlu: "<<this->titlu<<'\n';
    cout<<"Nume autor: "<<this->numeAutor<<'\n';
    cout<<"Cantitate: "<<this->cantitate<<'\n';
    cout<<"Disponibilitate: "<<this->disponibilitate<<'\n';
    cout<<"Pretul cumpararii celor "<< this->cantitate<<" cartii: "<<this->pretCump<<'\n'<<'\n';
}
// la carti trebuie sa existe minim 10 exemplare, daca nu sunt
// se vor cumpara exemplarele lipsa
void Carte::adaugaNrCarti() {
    if(this->cantitate < 10) {
        this->cantitate = (10 - this->cantitate) + this->cantitate;
    }
}

class Abonat{
private:
    char* numeAbonat;
    char elevStudent; // e-elev s-student a-angajat u-unknown
    int nrCarti;
    Carte* listaCarti;
    int nrCartiImprumutate;
    int nrCartiNereturnate;

public:
    Abonat();
    Abonat(char* numeAbonat, char elevStudent, Carte* listaCarti, int nrCarti, int nrCartiImprumutate, int nrCartiNereturnate);
    Abonat(const Abonat& abonat);
    Abonat& operator = (const Abonat& abonat);

    ~Abonat();

    friend istream& operator>>(istream& in, Abonat& abonat);
    friend ostream& operator<<(ostream& out, Abonat& abonat);

    void afisareAbonat();
    void citireAbonat();
    void abonatFidel();
    void stergereCarti(const Carte& carte);
    void sortareCartiDupaPret();

    // supraincarcarea operatorului ==
    bool operator == (string carte){
        for(int i = 0; i < this->nrCarti; i++)
            if(this->listaCarti[i].getTitlu()==carte)
                return true;
        return false;
    }

    // supraincarcarea operatorului ==
    bool operator == (const Abonat& abonat){
        if(this->numeAbonat == abonat.numeAbonat && this->elevStudent == abonat.elevStudent &&
           this->nrCartiImprumutate == abonat.nrCartiImprumutate && this->nrCartiNereturnate == abonat.nrCartiNereturnate)
            return true;
        return false;
    }

    // supraincarcarea operatorului >=
    bool operator >= (const Abonat& abonat){
        if(this->nrCartiImprumutate >= abonat.nrCartiImprumutate)
            return true;
        return false;
    }

    // supraincaracrea operatorului <
    bool operator < (const Abonat& abonat){
        if(this->nrCartiImprumutate < abonat.nrCartiImprumutate)
            return true;
        return false;
    }

    // supraincarcarea operatorului +
    bool operator + (Abonat abonat){
        abonat.nrCartiImprumutate = this->nrCartiImprumutate + abonat.nrCartiImprumutate;
    }

    // supraincarcarea operatorului /
    bool operator / (Abonat abonat){
        abonat.nrCartiImprumutate = this->nrCartiImprumutate / abonat.nrCartiImprumutate;
    }

    // supraincarcarea operatorului ++ post-incrementare
    Abonat operator++(int){
        Abonat aux(*this);
        this->nrCartiImprumutate++;
        return *this;
    }

    // supraincarcarea operatorului ++ pre-incrementare
    Abonat operator++(){
        Abonat aux(*this);
        this->nrCartiImprumutate++;
        return aux;
    }

    // supraincarcarea operatorului +=
    Abonat operator += (int x){
        this->nrCartiImprumutate += x;
        return *this;
    }

    // operatorului cast explicit
    explicit operator float() const{
        return(float)this->nrCartiImprumutate;
    }

    // operatorul de indexare
    Carte operator[] (int index){
        if(0 <= index && index < this->nrCarti)
            return this->listaCarti[index];
        cout<<"Index introdus gresit";
    }

    // getters & setters
    void setNumeAbonat(){
        this->numeAbonat = numeAbonat;
    }
    char* getNumeAbonat(){
        return this->numeAbonat;
    }

    void setElevStudent(){
        this->elevStudent = elevStudent;
    }
    char getElevStudent(){
        return this->elevStudent;
    }

    int getIndexCarte(string carte){
        for(int i = 0; i < this->nrCarti; i++)
            if(this->listaCarti[i].getTitlu()==carte)
                return i;
        return -1;
    }

};
// constructorul fara parametrii
Abonat::Abonat(){
    numeAbonat = new char[strlen("Anonim") + 1];
    strcpy(this->numeAbonat, "Anonim");
    this->elevStudent = 'u';
    this->listaCarti = 0;
    this->nrCarti = 0;
    this->nrCartiImprumutate = 0;
    this->nrCartiNereturnate = 0;
}

// constructorul cu toti parametrii
Abonat::Abonat(char *numeAbonat, char elevStudent, Carte *listaCarti, int nrCarti, int nrCartiImprumutate,
               int nrCartiNereturnate) {
    this->numeAbonat = new char[strlen(numeAbonat) + 1];
    strcpy(this->numeAbonat, numeAbonat);

    this->elevStudent = elevStudent;
    this->nrCartiImprumutate = nrCartiImprumutate;
    this->nrCartiNereturnate = nrCartiNereturnate;

    this->nrCarti = nrCarti;
    this->listaCarti = new Carte[nrCarti];
    for(int i = 0; i < nrCarti; i++)
        this->listaCarti[i] = listaCarti[i];
}

// copy constructor
Abonat::Abonat(const Abonat &abonat) {
    this->numeAbonat = new char[strlen(abonat.numeAbonat) + 1];
    strcpy(this->numeAbonat, abonat.numeAbonat);

    this->elevStudent = abonat.elevStudent;
    this->nrCartiImprumutate = abonat.nrCartiImprumutate;
    this->nrCartiNereturnate = abonat.nrCartiNereturnate;

    this->nrCarti = abonat.nrCarti;
    this->listaCarti = new Carte[abonat.nrCarti];
    for(int i = 0; i < abonat.nrCarti; i++)
        this->listaCarti[i] = abonat.listaCarti[i];
}

// supraincarcarea operatorului =
Abonat& Abonat::operator=(const Abonat &abonat) {
    if(this != &abonat){
        if(this->numeAbonat != NULL)
            delete [] this->numeAbonat;
        if(this->listaCarti !=NULL)
            delete [] this->listaCarti;

        this->numeAbonat = new char[strlen(abonat.numeAbonat) + 1];
        strcpy(this->numeAbonat, abonat.numeAbonat);

        this->elevStudent = abonat.elevStudent;
        this->nrCartiImprumutate = abonat.nrCartiImprumutate;
        this->nrCartiNereturnate = abonat.nrCartiNereturnate;

        this->nrCarti = abonat.nrCarti;
        this->listaCarti = new Carte[abonat.nrCarti];
        for(int i = 0; i < abonat.nrCarti; i++)
            this->listaCarti[i] = abonat.listaCarti[i];
    }
    return *this;
}

// destructor
Abonat::~Abonat(){
    if(this->numeAbonat != NULL)
        delete [] this->numeAbonat;
    if(this->listaCarti !=NULL)
        delete [] this->listaCarti;
}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, Abonat& abonat){
    cout<<"Introduceti numele abonatului: ";
    in>>abonat.numeAbonat;

    cout<<"Introduceti e-elev/ s-student/ a-angajat/ u-unknown: ";
    in>>abonat.elevStudent;

    cout<<"Introduceti nr carti imprumutate in total: ";
    in>>abonat.nrCartiImprumutate;

    cout<<"Introduceti nr carti nereturnate: ";
    in>>abonat.nrCartiNereturnate;

    cout<<"Introduceti nr carti imprumutate acum: ";
    in>>abonat.nrCarti;

    if(abonat.nrCarti != 0){
        cout<<"Introduceti cartile imprumutate: ";
        if(abonat.listaCarti != NULL)
            delete [] abonat.listaCarti;
        abonat.listaCarti = new Carte[abonat.nrCarti];
        for(int i = 0; i < abonat.nrCarti; i++)
            cin>>abonat.listaCarti[i];
    }

    return in;
}

// supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Abonat& abonat){
    out<<"Numele: "<<abonat.numeAbonat<<'\n';
    out<<"Tip abonament: "<<abonat.elevStudent<<'\n';
    out<<"Total nr carti imprumutate: "<<abonat.nrCartiImprumutate<<'\n';
    out<<"Total nr carti nereturnate: "<<abonat.nrCartiNereturnate<<'\n';
    out<<"Nr carti imprumutate acum: "<<abonat.nrCarti<<'\n';
    for(int i = 0; i < abonat.nrCarti; i++)
        out<<"Cartea "<<i+1<<": "<<abonat.listaCarti[i]<<'\n';

    return out;
}

// afisare
void Abonat::afisareAbonat() {
    cout<<"Numele: "<<this->numeAbonat<<'\n';
    cout<<"Tip abonament: "<<this->elevStudent<<'\n';
    cout<<"Total nr carti imprumutate: "<<this->nrCartiImprumutate<<'\n';
    cout<<"Total nr carti nereturnate: "<<this->nrCartiNereturnate<<'\n';
    cout<<"Nr carti imprumutate acum: "<<this->nrCarti<<'\n'<<'\n';
    if(this->nrCarti != 0){
        for(int i = 0; i < this->nrCarti; i++)
            cout<<"Cartea "<<i+1<<": "<<this->listaCarti[i]<<'\n';
    }
}

// citire
void Abonat::citireAbonat(){
    cout<<"Introduceti numele abonatului: ";
    cin>>this->numeAbonat;

    cout<<"Introduceti e-elev/ s-student/ a-angajat/ u-unknown: ";
    cin>>this->elevStudent;

    cout<<"Introduceti nr carti imprumutate in total: ";
    cin>>this->nrCartiImprumutate;

    cout<<"Introduceti nr carti nereturnate: ";
    cin>>this->nrCartiNereturnate;

    cout<<"Introduceti nr carti imprumutate acum: ";
    cin>>this->nrCarti;

    if(this->nrCarti != 0){
        cout<<"Introduceti cartile imprumutate: ";
        if(this->listaCarti != NULL)
            delete [] this->listaCarti;
        this->listaCarti = new Carte[this->nrCarti];
        for(int i = 0; i < nrCarti; i++) {
            cout<<"Cartea "<<i+1<<" este: ";
            cin >> this->listaCarti[i];
        }
    }
}

// un abonat fidel e abonatul care a citit peste 100 de carti si a
// returnat toate cartiile citite
void Abonat::abonatFidel() {
    if(nrCartiImprumutate >=100 && nrCartiNereturnate == 0)
        cout<<this->numeAbonat<<" este un abonat fidel!"<<'\n'<<'\n';
    else
    if(nrCartiNereturnate == 0)
        cout<< this->numeAbonat<<" mai are de citit "<<100-nrCartiImprumutate<<" carti pentru a deveni un abonat fidel."<<'\n'<<'\n';
    else
        cout<<this->numeAbonat<<" nu a returnat toate cartile imprumutate!! Nu poate fi un abonat fidel pana nu le inapoiaza."<<'\n'<<'\n';
}

// stergerea unei carti
void Abonat::stergereCarti(const Carte &carte) {
    Carte* listaCartiAux;
    int contor = 0;
    listaCartiAux = new Carte[nrCarti];
    for(int i = 0; i < nrCarti; i++){
        if(listaCarti[i] == carte)
            contor++;
        listaCartiAux[i] = listaCarti[i];
    }
    cout<<contor;
    if(listaCarti != NULL)
        delete [] listaCarti;
    nrCarti = nrCarti - contor;
    int j = 0;
    listaCarti = new Carte[nrCarti];
    for(int i = 0; i < nrCarti; i++){
        if(!(listaCartiAux[i] == carte)){
            listaCarti[j] = listaCartiAux[i];
            j++;
        }
    }
    if(listaCartiAux != NULL)
        delete [] listaCartiAux;
}

void Abonat::sortareCartiDupaPret() {
    for(int i = 0; i < this->nrCarti-1; i++)
        for(int j = i+1; j < this->nrCarti; j++){
            if(!(this->listaCarti[i] < this->listaCarti[j])){
                Carte aux = this->listaCarti[i];
                this->listaCarti[i] = this->listaCarti[j];
                this->listaCarti[j] = aux;
            }
        }
}

class Imprumut{
private:
    int nrAbonati;
    Abonat* listaAbonati;
    string dataImprumut;
    int idImprumut;
    static int contorId;

public:
    Imprumut();
    Imprumut(int nrAbonati, Abonat* listaAbonati, string dataImpumut);
    Imprumut(const Imprumut& imprumut);
    Imprumut& operator = (const Imprumut& imprumut);

    ~Imprumut();

    friend istream& operator>>(istream& in, Imprumut& imprumut);
    friend ostream& operator<<(ostream& out, Imprumut& imprumut);

    void afisareImprumut();
    void citireImprumut();
    void sorteazaDupaNumeAbonati();
    void stergereAbonati(const Abonat& abonat);
    void sorteazaDupaSalariuAngajat();

    // supraincarcare operator == Imprumut-Abonat
    bool operator == (string numeAbonat){
        for(int i = 0; i < this->nrAbonati; i++)
            if(this->listaAbonati[i].getNumeAbonat() == numeAbonat)
                return true;
        return false;
    }

    // supraincarcare operator + Imprumut-Abonat
    Imprumut operator + (const Abonat& abonat){
        Abonat* aux = NULL;
        if(this->listaAbonati!=NULL){
            aux = new Abonat[this->nrAbonati];
            for(int i = 0; i < this->nrAbonati; i++)
                aux[i] = this->listaAbonati[i];
            delete [] this->listaAbonati;
        }

        this->nrAbonati++;
        this->listaAbonati = new Abonat[this->nrAbonati];

        for(int i = 0; i < this->nrAbonati-1; i++)
            this->listaAbonati[i] = aux[i];
        this->listaAbonati[this->nrAbonati-1] = abonat;
        if(aux != NULL)
            delete [] aux;
        return *this;
    }

    // supraincarcarea operatorului ==
    bool operator == (const Imprumut& imprumut){
        if(this->listaAbonati == imprumut.listaAbonati && this->nrAbonati == imprumut.nrAbonati &&
           this->dataImprumut == imprumut.dataImprumut)
            return true;
        return false;
    }

    // supraincarcarea operatorului <
    bool operator < (const Imprumut& imprumut){
        if(this->dataImprumut < imprumut.dataImprumut)
            return true;
        return false;
    }

    // supraincarcarea operatorului +
    Imprumut operator + (Imprumut &imprumut){
        imprumut.nrAbonati = this->nrAbonati + imprumut.nrAbonati;
    }

    // supraincarcarea operatorului -
    bool operator - (Imprumut& imprumut){
        imprumut.nrAbonati = this->nrAbonati - imprumut.nrAbonati;
    }

    // supraincarcarea operatorului ++ post-incrementare
    Imprumut operator ++(int){
        Imprumut aux(*this);
        this->contorId++;
        return *this;
    }

    // supraincarcarea operatorului ++ pre-incrementare
    Imprumut operator ++(){
        Imprumut aux(*this);
        this->contorId++;
        return aux;
    }

    // operator de indexare
    Abonat& operator[](int index){
        if(index >= 0 && index < this->nrAbonati)
            return this->listaAbonati[index];
        cout<<"Index gresit";
    }

    // operatorul cast explicit
    explicit operator float() const{
        return (float)this->nrAbonati;
    }

    // setters & getters
    void getNrAbonati(){
        this->nrAbonati = nrAbonati;
    }
    int getNrAbonati() const{
        return this->nrAbonati;
    }

    void getContorId(){
        this->contorId = contorId;
    }

    int setContorId(){
        return this->contorId;
    }

    int getIdImprumut(){
        return this->idImprumut;
    }

    void setNrCartiImprumutate(Abonat& abonat, int newNrCartiImprumutate){
        abonat += newNrCartiImprumutate;
    }

    int getIndexAbonat(string numeAbonat){
        for(int i = 0; i < this->nrAbonati; i++)
            if(this->listaAbonati[i].getNumeAbonat()==numeAbonat)
                return i;
        return -1;
    }

};

int Imprumut::contorId = 1000;
//constructur fara parametrii
Imprumut::Imprumut() :idImprumut(contorId++){
    this->listaAbonati = 0;
    this->nrAbonati = 0;
    this->dataImprumut = 'ddmmyyyy';
}

// constructorul cu toti parametrii
Imprumut::Imprumut(int nrAbonati, Abonat *listaAbonati, string dataImpumut) :idImprumut(contorId++){
    this->nrAbonati = nrAbonati;
    this->listaAbonati = new Abonat[nrAbonati];
    for(int i = 0; i < nrAbonati; i++)
        this->listaAbonati[i] = listaAbonati[i];
    this->dataImprumut = dataImpumut;
}

//copy constructor
Imprumut::Imprumut(const Imprumut &imprumut) :idImprumut(imprumut.idImprumut){
    this->nrAbonati = imprumut.nrAbonati;
    this->listaAbonati = new Abonat[imprumut.nrAbonati];
    for(int i = 0; i < imprumut.nrAbonati; i++)
        this->listaAbonati[i] = imprumut.listaAbonati[i];
    this->dataImprumut = imprumut.dataImprumut;
}

// supraincarcarea operatorului =
Imprumut& Imprumut::operator=(const Imprumut &imprumut) {
    if(this != &imprumut){
        if(this->listaAbonati != NULL)
            delete [] this->listaAbonati;

        this->nrAbonati = imprumut.nrAbonati;
        this->listaAbonati = new Abonat[imprumut.nrAbonati];
        for(int i = 0; i < imprumut.nrAbonati; i++)
            this->listaAbonati[i] = imprumut.listaAbonati[i];
        this->dataImprumut = imprumut.dataImprumut;
    }
}

// destructorul
Imprumut::~Imprumut() {
    if(this->listaAbonati != NULL)
        delete [] this->listaAbonati;
}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, Imprumut& imprumut){
    cout<<"Introduceti data: ";
    in>>imprumut.dataImprumut;
    cout<<"Introduceti nr de abonati care au imprumutata carti pe data "<<imprumut.dataImprumut<<": ";
    in>>imprumut.nrAbonati;

    if(imprumut.listaAbonati != NULL)
        delete [] imprumut.listaAbonati;
    imprumut.listaAbonati = new Abonat[imprumut.nrAbonati];
    for(int i = 0; i < imprumut.nrAbonati; i++){
        cout<<"Abonatul "<<i+1<<" este: ";
        in>>imprumut.listaAbonati[i];
    }

    return in;
}

// supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Imprumut& imprumut){
    out<<"Data: "<<imprumut.dataImprumut<<'\n';
    out<<"Numar abonati: "<<imprumut.nrAbonati<<'\n';
    for(int i = 0; i < imprumut.nrAbonati; i++)
        out<<"Abonatul "<<i+1<<" este: "<<imprumut.listaAbonati[i]<<'\n';

    return out;
}

// afisare
void Imprumut::afisareImprumut() {
    cout<<"Data: "<<this->dataImprumut<<'\n';
    cout<<"Numar abonati: "<<this->nrAbonati<<'\n';
    for(int i = 0; i < this->nrAbonati; i++)
        cout<<"Abonatul "<<i+1<<" este: "<<this->listaAbonati[i]<<'\n';
}

// citire
void Imprumut::citireImprumut() {
    cout << "Introduceti data: ";
    cin >> this->dataImprumut;
    cout << "Introduceti nr de abonati care au imprumutata carti pe data " << this->dataImprumut<<": ";
    cin >> this->nrAbonati;

    if (this->listaAbonati != NULL)
        delete[] this->listaAbonati;
    this->listaAbonati = new Abonat[this->nrAbonati];
    for (int i = 0; i < this->nrAbonati; i++) {
        cout << "Abonatul " << i + 1 << " este: ";
        cin >> this->listaAbonati[i];
    }
}

// sortarea imprumuturilor efectuate dupa nr carti imprumutate ale abonatului
void Imprumut::sorteazaDupaNumeAbonati() {
    for(int i = 0; i < this->nrAbonati-1; i++)
        for(int j = i +1; j < this->nrAbonati; j++)
            if(!(this->listaAbonati[i] < this->listaAbonati[j])){
                Abonat aux = this->listaAbonati[i];
                this->listaAbonati[i] = this->listaAbonati[j];
                this->listaAbonati[j] = aux;
            }
}

void Imprumut::stergereAbonati(const Abonat& abonat) {
    Abonat* listaAbonatiAux;
    int contor = 0;
    listaAbonatiAux = new Abonat[nrAbonati];
    for(int i = 0; i < nrAbonati; i++){
        if(listaAbonati[i] == abonat)
            contor++;
        listaAbonatiAux[i] = listaAbonati[i];
    }
    cout<<contor;
    if(listaAbonati != NULL)
        delete [] listaAbonati;
    nrAbonati = nrAbonati - contor;
    int j = 0;
    listaAbonati = new Abonat[nrAbonati];
    for(int i = 0; i < nrAbonati + contor; i++)
        if(!(listaAbonatiAux[i] == abonat)){
            listaAbonati[j] = listaAbonatiAux[i];
            j++;
        }
    if(listaAbonatiAux != NULL)
        delete [] listaAbonatiAux;
}

int main() {

    Imprumut im = Imprumut();
    Biblioteca bb = Biblioteca();

    string input;

    while(true)
    {
        cout<<"\nComenzi(introduceti extit pentru iesire): "<<'\n';
        cout<<"Optiunea 1: Adaugare date(abonat/carti) "<<'\n';
        cout<<"Optiunea 2: Adaugare date(angajat) "<<'\n';
        cout<<"Optiunea 3: Afisarea angajatilor crescator dupa salariu "<<'\n';
        cout<<"Optiunea 4: Afisarea abonatilor crescator dupa nr de carti imprumutate "<<'\n';
        cout<<"Optiunea 5: Stergerea unei carti "<<'\n';
        cout<<"Optiunea 6: Afisarea cartilor sortate dupa cantitate "<<'\n';
        cout<<"Optiunea 7: Marire de salariu angajat "<<'\n';
        cout<<"Optiunea 8: Modificare nr carti imprumutate abonat "<<'\n';
        cout<<"Optiunea 9: Afisare abonat fidel "<<'\n';


        cout<<"Optiunea: ";
        cin>>input;
        if(input == "exit"){
            break;
        }
        if(input == "1"){
            Abonat ab = Abonat();
            cin>>ab;
            // v.push_back(impr);
            im = im + ab;
        }
        else if(input == "2"){
            Angajat an = Angajat();
            cin>>an;
            bb = bb + an;
        }
        else if(input == "3"){
            bb.sorteazaAngajatiDupaSalariu();
            bb.afisareBiblioteca();
        }
        else if(input == "4"){
            im.sorteazaDupaNumeAbonati();
            im.afisareImprumut();
        }
        else if(input == "5"){
            string numeAbonat;
            cout<<"Abonatul a carui carte va fi stearsa: ";
            cin >> numeAbonat;
            if (im == numeAbonat) {
                cout << "\nAbonatul: \n";
                cout << im[im.getIndexAbonat(numeAbonat)] << '\n';

                Abonat a = im[im.getIndexAbonat(numeAbonat)];
                string carte;
                cout<<"Introduceti cartea care vreti sa fie stearsa: ";
                cin>>carte;
                if(im[im.getIndexAbonat(numeAbonat)] == carte){
                    cout<<"\nCartea care urmeaza sa fie stearsa: \n";
                    cout<<a[a.getIndexCarte(carte)];
                    im[im.getIndexAbonat(numeAbonat)].stergereCarti(a[a.getIndexCarte(carte)]);
                    cout<<"Dupa stergere: ";
                    cout << im[im.getIndexAbonat(numeAbonat)] << '\n';
                }
            }
        }
        else if(input == "6") {
            string numeAbonat;
            cout<<"Abonatul ale carui carti vor fi sortate: ";
            cin >> numeAbonat;
            if (im == numeAbonat) {
                cout << "\nAbonatul: \n";
                cout << im[im.getIndexAbonat(numeAbonat)] << '\n';

                Abonat a = im[im.getIndexAbonat(numeAbonat)];
                a.sortareCartiDupaPret();
                cout<<"Dupa sortare: "<<'\n';
                a.afisareAbonat();
            }
        }
        else if(input == "7"){
            string numeAngajat;
            cout<<"Numele: ";
            cin>>numeAngajat;
            if(bb == numeAngajat){
                cout<<"\nAngajatul: \n";
                cout<<bb[bb.getIndexAngajat(numeAngajat)]<<'\n';
                bb[bb.getIndexAngajat(numeAngajat)].marireSalariu();
                bb[bb.getIndexAngajat(numeAngajat)].afisareAngajat();
            }


        }
        else if(input == "8"){
            string numeAbonat;
            cout<<"Numele abonatului caruia i se va modifica nr de carti imprumutate";
            cin>>numeAbonat;
            if(im == numeAbonat){
                cout<<"\nAbonatul: \n";
                cout<<im[im.getIndexAbonat(numeAbonat)];

                int newNrCartiImprumutate = 0;

                cout<<"\nIntroduceti cate carti a mai imprumutat: ";
                cin>>newNrCartiImprumutate;
                im.setNrCartiImprumutate(im[im.getIndexAbonat(numeAbonat)], newNrCartiImprumutate);
                cout<<"Dupa modificare: "<<'\n';
                cout<<im[im.getIndexAbonat(numeAbonat)];
            }
        }
        else if(input == "9") {
            string numeAbonat;
            cout<<"Introduceti numele abonatului: ";
            cin >> numeAbonat;
            if (im == numeAbonat) {
                cout << "\nAbonatul: \n";
                cout << im[im.getIndexAbonat(numeAbonat)]<<'\n';
                im[im.getIndexAbonat(numeAbonat)].abonatFidel();
            }
        }
    }

    return 0;
}
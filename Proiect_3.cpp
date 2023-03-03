#include <bits/stdc++.h>

using namespace std;

class Exceptie1: public exception{
public:
    virtual const char* what() const throw(){
        return "\n!! ATI INTRODUS GRESIT !! \n --Incercati din nou--\n";
    }
}exceptie1;

// citire si afisare virtuala
class IoInterface{
public:
    virtual istream& citire(istream& in) = 0;
    virtual ostream& afisare(ostream& out) const = 0;
};

class detaliiProdus: public IoInterface{
protected:
    string nume;
    float pret;
    int reducere;
    int cantitate;

public:
    detaliiProdus();
    detaliiProdus(string nume, float pret, int reducere, int cantitate);
    detaliiProdus(const detaliiProdus& produs);
    detaliiProdus& operator = (const detaliiProdus& produs);

    ~detaliiProdus();

    virtual istream& citire(istream& in);
    virtual ostream& afisare(ostream& out) const;

    friend istream& operator>>(istream& in, detaliiProdus& produs);
    friend ostream& operator<<(ostream& out, const detaliiProdus& produs);

    string getNume() const;
    int getReducere();
    float getPret();
    int getCantitate() const;

    virtual float calculeazaPretInitial() = 0;
};

// constructorul fara parametrii
detaliiProdus::detaliiProdus() {
    this->nume = "Necunoscut";
    this->pret = 0;
    this->reducere = 0;
    this->cantitate = 0;
}

// constructorul cu toti parametrii
detaliiProdus::detaliiProdus(string nume, float pret, int reducere, int cantitate) {
    this->nume = nume;
    this->pret = pret;
    this->reducere = reducere;
    this->cantitate = cantitate;
}

// copy constructor
detaliiProdus::detaliiProdus(const detaliiProdus &produs) {
    this->nume = produs.nume;
    this->pret = produs.pret;
    this->reducere = produs.reducere;
    this->cantitate = produs.cantitate;
}

// supraincarcarea operatorului =
detaliiProdus &detaliiProdus::operator=(const detaliiProdus &produs) {
    if(this != &produs)
    {
        this->nume = produs.nume;
        this->pret = produs.pret;
        this->reducere = produs.reducere;
        this->cantitate = produs.cantitate;
    }
    return *this;
}

// destructor
detaliiProdus::~detaliiProdus() {

}

// citire virtuala
istream& detaliiProdus::citire(istream &in) {
    cout<<"Introduceti numele articolului: ";
    in>> this->nume;

    cout<<"Introduceti pretul: ";
    in>> this->pret;

    cout<<"Introduceti numarul de procente cu care e redus: ";
    in>> this->reducere;

    cout<<"Introduceti nr de exemplare: ";
    in>> this->cantitate;

    return in;
}

// afisare virtuala
ostream& detaliiProdus::afisare(ostream &out) const {
    out<<"Nume: "<< this->nume<<'\n';
    out<<"Pret: "<< this->pret<<'\n';
    out<<"Reducere: "<< this->reducere<<"%"<<'\n';
    out<<"Cantitate: "<< this->cantitate<<'\n';

    return out;
}

// supraincarcarea operatorului >>
istream& operator>>(istream& in, detaliiProdus& produs){
    return produs.citire(in);
}

// supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const detaliiProdus& produs){
    return produs.afisare(out);
}

// getter pt nume
string detaliiProdus::getNume() const {
    return this->nume;
}

// getter pt reducere
int detaliiProdus::getReducere(){
    return this->reducere;
}

// getter pt pret
float detaliiProdus::getPret(){
    return this->pret;
}

// getter pt cantitate
int detaliiProdus::getCantitate() const {
    return this->cantitate;
}

/*
// functie pt calculare pret
float detaliiProdus::calculeazaPretInitial() {
    return  (float) 100*this->pret/(100 - this->reducere);
}
*/
class Carte:virtual public detaliiProdus{
protected:
    string autor;
    int promotie;
    string codPromotional;   // are 7 caractere

public:
    Carte();
    Carte(string nume, float pret, int reducere, int cantitate, string autor, string codPromotional, int promotie);
    Carte(const Carte& carte);
    Carte& operator = (const Carte& carte);

    ~Carte();

    Carte(string autor, string codPromotional, int promotie);

    istream& citire(istream& in);
    ostream & afisare(ostream& out) const;

    float calculeazaPretInitial();

    int getPromotie() const;
    string getcodPromotie() const;

};

// constructorul fara parametrii
Carte::Carte():detaliiProdus() {
    this->autor = "Necunoscut";
    this->promotie = 0;
    this->codPromotional = "nu exista";
}

// constructorul cu toti parametrii
Carte::Carte(string nume, float pret, int reducere, int cantitate, string autor, string codPromotional, int promotie): detaliiProdus(nume, pret, reducere, cantitate) {
    this->autor = autor;
    this->codPromotional = codPromotional;
    this->promotie = promotie;
}

// copy constructor
Carte::Carte(const Carte &carte):detaliiProdus(carte) {
    this->autor = carte.autor;
    this->codPromotional = carte.codPromotional;
    this->promotie = carte.promotie;
}

// supraincarcarea operatorului =
Carte &Carte::operator=(const Carte &carte) {
    if(this != &carte)
    {
        detaliiProdus::operator=(carte);
        this->autor = carte.autor;
        this->codPromotional = carte.codPromotional;
        this->promotie = carte.promotie;
    }
}

// destructor
Carte::~Carte() {

}

// constructor cu autor & codPromotional
Carte::Carte(string autor, string codPromotional, int promotie) {
    this->autor = autor;
    this->codPromotional = codPromotional;
    this->promotie = promotie;
}

// citire virtuala
istream& Carte::citire(istream &in) {
    cout<<"~Carte~"<<'\n';
    detaliiProdus::citire(in);

    cout<<"Introduceti autorul: ";
    in>> this->autor;

    cout<<"Introduceti 1-promotie/0-fara promotie: ";
    in>> this->promotie;

    try{
        if(promotie > 2)
            throw exceptie1;
    }
    catch (exception &e){
        cout<<e.what();
        cout<<endl;
    }

    if(promotie == 1){
        cout<<"Introduceti codul promotional: ";
        in>> this->codPromotional;

        try{
            if(codPromotional.length() != 2)
                throw exceptie1;
        }
        catch (exception &e){
            cout<<e.what();
            cout<<endl;
        }

    }
    cout<<'\n';

    return in;
}

// afisare virtuala
ostream & Carte::afisare(ostream &out) const {

    detaliiProdus::afisare(out);
    out<<"Autor: "<< this->autor<<'\n';
    out<<"Cod promotional: "<< this->codPromotional<<'\n';

    //try{
    out<<"Promotie: "<< this->promotie<<'\n'<<'\n';
    //}
    //catch (exception &e){
    //   cout<<e.what();
    //    cout<<endl;
    // }

    return out;
}

// getter pt promotie
int Carte::getPromotie() const {
    return promotie;
}

// getter pt codPromotie
string Carte::getcodPromotie() const {
    return codPromotional;
}

// functie pentru calcularea pretului fara reducere
float Carte::calculeazaPretInitial() {
    /*if(this->reducere != 0)
        return  (float) 100*this->pret/(100 - this->reducere); */
    try{
        if(reducere != 0)
            return  (float) 100*this->pret/(100 - this->reducere);
    }
    catch(...){
        cout<<" nu e redus";
    }
}

class Parfum:virtual public detaliiProdus{
protected:
    int nrMl;

public:
    Parfum();
    Parfum(string nume, float pret, int reducere, int cantitate, int nrMl);
    Parfum(const Parfum& parfum);
    Parfum& operator = (const Parfum& parfum);

    ~Parfum();

    Parfum(int nrMl);

    istream& citire(istream& in);
    ostream & afisare(ostream& out) const;

    float calculeazaPretInitial();
};

// constructorul fara parametrii
Parfum::Parfum():detaliiProdus() {
    this->nrMl = 0;
}

// constructorul cu toti parametrii
Parfum::Parfum(string nume, float pret, int reducere, int cantitate, int nrMl):detaliiProdus(nume, pret, reducere, cantitate) {
    this->nrMl = nrMl;
}

// copy constructor
Parfum::Parfum(const Parfum &parfum):detaliiProdus(parfum) {
    this->nrMl = parfum.nrMl;
}

// supraincarcarea operatorului =
Parfum &Parfum::operator=(const Parfum &parfum) {
    if(this != &parfum)
    {
        detaliiProdus::operator=(parfum);
        this->nrMl = parfum.nrMl;
    }
    return *this;
}

// destructor
Parfum::~Parfum() {

}

// constructor cu nrMl
Parfum::Parfum(int nrMl) {
    this->nrMl = nrMl;
}

// citire virtuala
istream& Parfum::citire(istream &in) {
    cout<<"~Parfum~"<<'\n';
    detaliiProdus::citire(in);

    cout<<"Introduceti numarul de ml: ";
    in>> this->nrMl;
    cout<<'\n';

    return in;
}

// afisare virtuala
ostream & Parfum::afisare(ostream &out) const {

    detaliiProdus::afisare(out);
    out<<"Numar ml: "<< this->nrMl<<'\n'<<'\n';

    return out;
}

// functie pt aflarea pretului fara reducere
float Parfum::calculeazaPretInitial() {
    try{
        if(reducere != 0)
            return  (float) 100*this->pret/(100 - this->reducere);
    }
    catch(...){
        cout<<" nu e redus";
    }
}

class Comanda:public Carte{
protected:
    string codComanda;

public:
    Comanda();
    Comanda(string nume, float pret, int reducere, int cantitate, string autor, string codPromotional, int promotie, string codComanda);
    Comanda(const Comanda& comanda);
    Comanda& operator = (const Comanda& comanda);

    ~Comanda();

    Comanda(string codComanda);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    void citireCod();
    void afisareCod();
};

// constructorul fara parametrii
Comanda::Comanda():Carte() {
    this->codComanda = "NULL";
}

// constructorul cu toti parametrii
Comanda::Comanda(string nume, float pret, int reducere, int cantitate, string autor, string codPromotional, int promotie, string codComanda):detaliiProdus(
        nume, pret, reducere, cantitate), Carte(autor, codPromotional, promotie) {
    this->codComanda = codComanda;
}

// copy constructor
Comanda::Comanda(const Comanda &comanda):Carte(comanda) {
    this->codComanda = comanda.codComanda;
}

// supraincarcarea operatorului =
Comanda &Comanda::operator=(const Comanda &comanda) {
    if(this != & comanda)
    {
        Carte::operator=(comanda);
        this->codComanda = comanda.codComanda;
    }
    return *this;
}

// destructor
Comanda::~Comanda() {

}

// constructot pt codComanda
Comanda::Comanda(string codComanda) {
    this->codComanda = codComanda;
}

// citire cod comanda
void Comanda::citireCod() {
    cout<<"Introduceti codul comenzii: ";
    cin>> this->codComanda;
}

// afisare cod comanda
void Comanda::afisareCod() {
    cout<<"Codul comenzii: "<< this->codComanda<<'\n';
}

// citire virtuala
istream& Comanda::citire(istream &in) {

    Carte::citire(in);

    cout<<"Introduceti codul comenzii: ";
    in>> this->codComanda;

    return in;
}

// afisare virtuala
ostream& Comanda::afisare(ostream &out) const {

    Carte::afisare(out);
    out<<"Cod comanda: "<< this->codComanda<<'\n';

    return out;
}

class Client: public Comanda{
private:
    string numeClient;
    string codPostal;

public:
    Client();
    Client(string numeClient, string codPostal);
    Client(const Client& client);
    Client& operator = (const Client& client);

    ~Client();

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;

    string getNumeClient() const;
    string getCodPostal() const;

    bool operator >= (const Client& client){
        if(this->numeClient >= client.numeClient)
            return true;
        return false;
    }

};

// constructorul fara parametrii
Client::Client(){
    this->numeClient = "Anonim";
    this->codPostal = "inexistent";
}

// constructorul cu toti parametrii
Client::Client(string numeClient, string codPostal){
    this->numeClient = numeClient;
    this->codPostal = codPostal;
}

// copy constructor
Client::Client(const Client &client){
    this->numeClient = client.numeClient;
    this->codPostal = client.codPostal;
}

// supraincarcarea operatorului =
Client &Client::operator=(const Client &client) {
    if(this != &client)
    {
        this->numeClient = client.numeClient;
        this->codPostal = client.codPostal;
    }
    return *this;
}

// destructor
Client::~Client() {

}

// getter pt numeClient
string Client::getNumeClient() const{
    return this->numeClient;
}

// getter pt codPostal
string Client::getCodPostal() const {
    return this->codPostal;
}

// citire virtuala
istream& Client::citire(istream &in) {

    cout<<"Introduceti numele clientului: ";
    in>> this->numeClient;

    cout<<"Introduceti codul postal al clientului: ";
    in>> this->codPostal;

    try{
        if(codPostal.length() != 4)
            throw exceptie1;
    }
    catch (exception &e){
        cout<<e.what();
        cout<<endl;
    }

    return in;
}

// afisare virtuala
ostream& Client::afisare(ostream &out) const {

    out<<"Nume client: "<< this->numeClient<<'\n';
    out<<"Cod postal: "<< this->codPostal<<'\n';

    return out;
}

// functie pt a calc pretul fara reducere
template<typename T>
T calcPret(float pret, int reducere){
    return (float) 100*pret/(100 - reducere);
}

// clasa template
template<class T>
class Reducere{
private:
    T pret, reducere;

public:
    // constructorul cu toti paramaterii
    Reducere(T p, T r){
        this->pret = p;
        this->reducere = r;
    }

    // constructorul fara parametrii
    Reducere(){
        this->pret = 0;
        this->reducere = 0;
    }

    // copy constructor
    Reducere(const Reducere& r){
        this->pret = r.pret;
        this->reducere = r.reducere;
    }

    // supraincarcare operator egal
    Reducere operator = (const Reducere& r){
        if(this != &r)
        {
            this->pret = r.pret;
            this->reducere = r.reducere;
        }
        return *this;
    }

    void afisare(){
        if(reducere != 0){
            T rez = calcPret<float>(pret,reducere);
            cout<<" ati economisit "<<rez-pret<<" RON";
        }
        else cout<<" nu aveti reducere";
    }

};

// template pt comparatia >=
template<typename T>
T compar(T art1, T art2){
    if(art1 >= art2)
        return "1";
    return "0";
}

class Meniu {

private:
    static Meniu *ob;
    string titlu;

    // constructor fara parametrii
    Meniu() {
        titlu = "none";
    }

    // copy constructor
    Meniu(const Meniu &meniu) {
        this->titlu = meniu.titlu;
    }

    // supraincarcare operator =
    Meniu &operator=(const Meniu &meniu) {
        if (this != &meniu) {
            this->titlu = meniu.titlu;
        }
        return *this;
    }

public:
    static Meniu *getInstance() {
        if (!ob)
            ob = new Meniu();

        return ob;
    }

    string getTitlu() {
        return this->titlu;
    }

    void setTitlu(string a) {
        this->titlu = a;
    }

    ~Meniu();
    Meniu(string titlu);

    void meniu() {

        vector<detaliiProdus *> listaProduse;
        vector<detaliiProdus *> listaCarti;
        vector<detaliiProdus *> listaParfumuri;
        vector<Client *> listaClient;
        vector<detaliiProdus *> listaComanda;

        set<detaliiProdus *> lsComanda;
        map<int, string> lsProduse;

        int nr = 0;
        string input;

        while (true) {
            //cout<<'\n';
            cout << "Comenzi (introduceti exit pentru iesire):\n";
            cout << "Optiunea 1: adauga carte\n";
            cout << "Optiunea 2: adauga parfum\n";
            cout << "Optiunea 3: adauga client\n";
            cout << "Optiunea 4: afiseaza preturile initiale ale cartilor" << '\n';
            cout << "Optiunea 5: afiseaza preturile initiale ale parfumurilor" << '\n';
            cout << "Optiunea 6: afiseaza cartile crescator dupa pret" << '\n';
            cout << "Optiunea 7: afiseaza parfumurile descrescator dupa reducere" << '\n';
            cout << "Optiunea 8: afiseaza toate articolele disponibile in magazin" << '\n';
            cout << "Optiunea 9: afiseaza clientii ordonati alfabetic" << '\n';
            cout << "Optiunea 10: plaseaza o comanda" << '\n';
            cout << "Optiunea 11: calculeaza transportul" << '\n';
            cout << "Optiunea 12: calc reducere" << '\n' << '\n';

            cout << "Optiunea este: ";
            cin >> input;
            cout << '\n';

            if (input == "exit") {
                break;
            }

            if (input == "1") {

                cout << "---Introduceti detalii carte---" << '\n';
                Carte *c = new Carte();
                cin >> *c;
                if(c->getPromotie() == 1 || c->getPromotie() == 0 || c->getcodPromotie().length() != 2)
                {
                    nr++;
                    listaCarti.push_back(c);
                    listaProduse.push_back(c);
                    lsProduse.insert(pair<int,string>(nr,c->getNume()));
                }

            } else if (input == "2") {
                cout << "---Introduceti detalii parfum---" << '\n';
                Parfum *p = new Parfum();
                cin >> *p;
                nr++;
                listaParfumuri.push_back(p);
                listaProduse.push_back(p);
                lsProduse.insert(pair<int,string>(nr,p->getNume()));
            } else if (input == "3") {
                cout << "---Introduceti detalii client---" << '\n';
                Client *cl = new Client();
                cin >> *cl;
                if(cl->getCodPostal().length() == 4)
                    listaClient.push_back(cl);
            } else if (input == "4") {
                cout << "---Pret carti fara reducere---" << '\n' << '\n';
                for (int j = 0; j < listaCarti.size(); j++)
                    if (listaCarti[j]->getReducere() != 0)
                        cout << "Cartea '" << listaCarti[j]->getNume() << "' costa "
                             << listaCarti[j]->calculeazaPretInitial() << " RON fara reducere" << '\n';
                    else
                        cout << "Cartea '" << listaCarti[j]->getNume() << "' nu e redusa" << '\n';

                cout << '\n' << "-------------------------------" << '\n' << '\n';
            } else if (input == "5") {
                cout << "---Pret parfumuri fara reducere---" << '\n' << '\n';
                for (int j = 0; j < listaParfumuri.size(); j++)
                    if (listaParfumuri[j]->getReducere() != 0)
                        cout << "Parfumul '" << listaParfumuri[j]->getNume() << "' costa "
                             << listaParfumuri[j]->calculeazaPretInitial() << " RON fara reducere" << '\n';
                    else
                        cout << "Parfumul '" << listaParfumuri[j]->getNume() << "' nu e redus" << '\n';

                cout << '\n' << "----------------------------------" << '\n' << '\n';
            } else if (input == "6") {
                cout << "---Cartile crescator dupa pret---" << '\n' << '\n';
                for (int i = 0; i < listaCarti.size() - 1; i++)
                    for (int j = i + 1; j < listaCarti.size(); j++)
                        if (listaCarti[i]->getPret() >= listaCarti[j]->getPret()) {
                            detaliiProdus *aux = listaCarti[i];
                            listaCarti[i] = listaCarti[j];
                            listaCarti[j] = aux;
                        }
                for (int i = 0; i < listaCarti.size(); i++)
                    cout << *listaCarti[i] << '\n';
                cout << "----------------------------------" << '\n' << '\n';
            } else if (input == "7") {
                cout << "---Parfumurile descrescator dupa reducere---" << '\n' << '\n';
                for (int i = 0; i < listaParfumuri.size() - 1; i++)
                    for (int j = i + 1; j < listaParfumuri.size(); j++)
                        if (listaParfumuri[i]->getReducere() <= listaParfumuri[j]->getReducere()) {
                            detaliiProdus *aux = listaParfumuri[i];
                            listaParfumuri[i] = listaParfumuri[j];
                            listaParfumuri[j] = aux;
                        }
                for (int i = 0; i < listaParfumuri.size(); i++)
                    cout << *listaParfumuri[i] << '\n';
                cout << "--------------------------------------------" << '\n' << '\n';
            } else if (input == "8") {
                cout << "-----Articole disponibile-----" << '\n' << '\n';
                /*for (int i = 0; i < listaProduse.size(); i++) {
                    cout << *listaProduse[i];
                }
                 */
                map<int,string>::iterator it;
                for(it = lsProduse.begin(); it != lsProduse.end(); it++)
                    cout<<it->first<<". "<<it->second<<'\n';
                cout << "-------------------------------" << '\n' << '\n';
            } else if (input == "9") {
                cout << "-----Clientii-----" << '\n' << '\n';
                for (int i = 0; i < listaClient.size() - 1; i++)
                    for (int j = i + 1; j < listaClient.size(); j++) {
                        string g = compar<string>(listaClient[i]->getNumeClient(), listaClient[j]->getNumeClient());
                        /*if(g == "1")
                        {
                            Client *aux = listaClient[i];
                            listaClient[i] = listaClient[j];
                            listaClient[j] = aux;
                        }  */

                        try{
                            if(g == "1")
                            {
                                Client *aux = listaClient[i];
                                listaClient[i] = listaClient[j];
                                listaClient[j] = aux;
                            }
                        }
                        catch(...)
                        {
                            continue;
                        }

                    }

                for (int i = 0; i < listaClient.size(); i++)
                    cout << *listaClient[i] << '\n';
                cout << "-------------------" << '\n' << '\n';
            } else if (input == "10") {
                cout << "-----Articole disponibile-----" << '\n' << '\n';
                for (int i = 0; i < listaProduse.size(); i++) {
                    cout << *listaProduse[i] << '\n';
                }
                //cout<<"-------------------------------"<<'\n';

                cout << "---Introduceti detalii comanda---" << '\n' << '\n';
                string numeArticol;
                cout << "Introduceti numele articolului dorit: ";
                cin >> numeArticol;

                while (true) {
                    if (numeArticol == "stop") {
                        Comanda a;
                        a.citireCod();
                        cout << '\n' << "-----Comanda dvs-----" << '\n' << '\n';
                        a.afisareCod();
                        cout << '\n';
                        break;
                    } else {
                        for (int i = 0; i < listaProduse.size(); i++)
                            if (listaProduse[i]->getNume() == numeArticol)
                            {
                                listaComanda.push_back(listaProduse[i]);
                                lsComanda.insert(listaProduse[i]);
                            }

                        cout << "Introduceti numele articolului dorit/ 'stop'- cand ati terminat: ";
                        cin >> numeArticol;
                    }
                }
                /*
                for (int i = 0; i < listaComanda.size(); i++)
                    cout << *listaComanda[i];  */

                set<detaliiProdus *>::iterator  it;
                for(it = lsComanda.begin(); it != lsComanda.end(); it++)
                    cout<< **it;

                cout << "-------------------------" << '\n' << '\n';

            } else if (input == "11") {
                cout << "-----Cost transport-----" << '\n' << '\n';
                float total = 0.0;
                set<detaliiProdus*>::iterator i;
                for (int i = 0; i < listaComanda.size(); i++)
                    total += listaComanda[i]->getPret() * listaComanda[i]->getCantitate();

                if (total >= 200) {
                    cout << "Transportul este gratuit" << '\n';
                    cout << "Totalul comenzii este: " << total << " RON" << '\n' << '\n';
                    cout << "------------------------" << '\n' << '\n';
                } else {
                    cout << "Transportul costa 15 RON" << '\n';
                    cout << "Totalul(comanda + transport) este: " << total + 15 << " RON" << '\n' << '\n';
                    cout << "------------------------" << '\n' << '\n';
                }
            } else if (input == "12") {
                cout << "---Suma economisita carti ---" << '\n' << '\n';
                for (int j = 0; j < listaCarti.size(); j++) {
                    Reducere<float> reducere(listaCarti[j]->getPret(), listaCarti[j]->getReducere());
                    cout << "La cartea '" << listaCarti[j]->getNume()<<"'";
                    reducere.afisare();
                    cout << '\n';
                }
                cout << '\n' << "-------------------------------" << '\n' << '\n';
            }

        }

    }
};
Meniu* Meniu::ob;

// constructorul cu toti parametrii
Meniu::Meniu(string titlu) {
    this->titlu = titlu;
}

// destructor
Meniu::~Meniu() {

}

int main() {

    Meniu* meniulMeu = meniulMeu->getInstance();
    meniulMeu->setTitlu("Meniu");
    meniulMeu->meniu();

    return 0;
}

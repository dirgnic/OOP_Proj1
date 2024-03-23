#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Parfum;
class Angajat;
class Vanzare;
class InventarMagazin;

class Parfum {
private:
  static int PARFCONT; // nr total tipuri de parfum
  const int idParfum;
  char *numeParfum;
  char *brand;
  char rating;
  char *tipAroma;
  bool inStoc;
  double pret;

public:
  // constructori
  Parfum() : idParfum(++PARFCONT) {
    numeParfum = new char[strlen("anonim") + 1];
    strcpy(numeParfum, "anonim");
    brand = new char[strlen("anonim") + 1];
    strcpy(brand, "anonim");
    rating = 'x';
    tipAroma = new char[strlen("anonim") + 1];
    strcpy(tipAroma, "anonim");
    inStoc = false;
    pret = 0;
  }

  Parfum(char *numeParfum, char *brand, char rating, char *tipAroma,
         bool inStoc, double pret)
      : idParfum(++PARFCONT), rating(rating), inStoc(inStoc), pret(pret) {
    this->numeParfum = new char[strlen(numeParfum) + 1];
    strcpy(this->numeParfum, numeParfum);
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->tipAroma = new char[strlen(tipAroma) + 1];
    strcpy(this->tipAroma, tipAroma);
  }

  Parfum(char *numeParfum, bool inStoc, double pret)
      : idParfum(++PARFCONT), inStoc(inStoc), pret(pret) {
    this->numeParfum = new char[strlen(numeParfum) + 1];
    strcpy(this->numeParfum, numeParfum);
    this->brand = new char[strlen("anonim") + 1];
    strcpy(this->brand, "anonim");
    this->rating = 'x';
    this->tipAroma = new char[strlen("anonim") + 1];
    strcpy(this->tipAroma, "anonim");
  }

  Parfum(char *numeParfum, char *tipAroma, double pret)
      : idParfum(++PARFCONT), pret(pret) {
    this->numeParfum = new char[strlen(numeParfum) + 1];
    strcpy(this->numeParfum, numeParfum);
    this->brand = new char[strlen("anonim") + 1];
    strcpy(this->brand, "anonim");
    this->rating = 'x';
    this->inStoc = false;
    this->tipAroma = new char[strlen(tipAroma) + 1];
    strcpy(this->tipAroma, tipAroma);
  }

  Parfum(const Parfum &p)
      : idParfum(p.idParfum), rating(p.rating), inStoc(p.inStoc), pret(p.pret) {
    this->numeParfum = new char[strlen(p.numeParfum) + 1];
    strcpy(this->numeParfum, p.numeParfum);
    this->brand = new char[strlen(p.brand) + 1];
    strcpy(this->brand, p.brand);
    this->tipAroma = new char[strlen(p.tipAroma) + 1];
    strcpy(this->tipAroma, p.tipAroma);
  }

  ~Parfum() {
    if (this->numeParfum != NULL)
      delete[] this->numeParfum;
    if (this->brand != NULL)
      delete[] this->brand;
    if (this->tipAroma != NULL)
      delete[] this->tipAroma;
  }

  // setteri

  void setNumeParfum(char *numeSala) {
    if (this->numeParfum != NULL)
      delete[] this->numeParfum;
    this->numeParfum = new char[strlen(numeParfum) + 1];
    strcpy(this->numeParfum, numeParfum);
  }

  void setBrand(char *numeBrand) {
    if (this->brand != NULL)
      delete[] this->brand;
    this->brand = new char[strlen(numeBrand) + 1];
    strcpy(this->brand, numeBrand);
  }

  void setRating(char rating) { this->rating = rating; }

  void setTipAroma(char *nume_tipAroma) {
    if (this->tipAroma != NULL)
      delete[] this->tipAroma;
    this->tipAroma = new char[strlen(nume_tipAroma) + 1];
    strcpy(this->tipAroma, nume_tipAroma);
  }

  void setInStoc(bool inStoc) { this->inStoc = inStoc; }

  void setPret(double pret) { this->pret = pret; }

  // getteri

  int getIdParfum() { return idParfum; }

  char *getNumeParfum() { return numeParfum; }

  char *getBrand() { return brand; }

  char getRating() { return rating; }

  char *getTipAroma() { return tipAroma; }

  bool isInStoc() { return inStoc; }

  double getPret() { return pret; }

  // functionalitate

  void perioadaDeVarf() // print perioada cand parfumul ar trebui sa se vanda
                        // cel mai bine
  {

    switch (((int)rating - 'a') % 4) {
    case 0:
      cout << "primavara";
      break;
    case 1:
      cout << "vara";
      break;
    case 2:
      cout << "toamna";
      break;
    case 3:
      cout << "iarna";
      break;
    }
  }

  // supraincarcare operatori
  Parfum &operator=(const Parfum &obj) {
    if (this != &obj) {

      if (this->numeParfum != NULL)
        delete[] this->numeParfum;
      if (this->brand != NULL)
        delete[] this->brand;
      if (this->tipAroma != NULL)
        delete[] this->tipAroma;

      this->numeParfum = new char[strlen(obj.numeParfum) + 1];
      strcpy(this->numeParfum, obj.numeParfum);

      this->brand = new char[strlen(obj.brand) + 1];
      strcpy(this->brand, obj.brand);

      this->rating = obj.rating;

      this->tipAroma = new char[strlen(obj.tipAroma) + 1];
      strcpy(this->tipAroma, obj.tipAroma);

      this->inStoc = obj.inStoc;
      this->pret = obj.pret;
    }
    return *this;
  }

  friend ostream &operator<<(
      ostream &,
      const Parfum
          &); // const rezolva eroarea de identificare membrii private pt parfum
              // - pt ca nu vrem ca friend sa modifice membrii private
  friend istream &operator>>(istream &, Parfum &);

  // Operatorul de indexare[]
  int operator[](int index) {
    switch (index) {
    case 0:
      return idParfum;
    case 1:
      return strlen(this->numeParfum);
    case 2:
      return strlen(this->brand);
    case 3:
      return (int)rating;
    case 4:
      return strlen(this->tipAroma);
    case 5:
      return (inStoc == false) ? 0 : 1;
    default:
      throw runtime_error("Index invalid");
    }
  }

  Parfum &operator++() /// pre-incrementare
  {
    this->pret++;

    return *this;
  }

  Parfum operator++(int) /// post-incrementare
  {
    Parfum copie = *this;
    copie.pret++;
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN DREAPTA
  Parfum operator+(char *s) {
    Parfum copie = *this;
    strcat(copie.numeParfum, " ");
    strcat(copie.numeParfum, s);
    return copie;
  }

  Parfum operator*(char *s) {
    Parfum copie = *this;
    strcat(copie.tipAroma, " ");
    strcat(copie.tipAroma, s);
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN STANGA
  friend Parfum operator+(char *s, Parfum obj);
  friend Parfum operator*(char *s, Parfum obj);

  /// CAST
  operator char *() // implicit
  {
    return this->numeParfum;
  }

  bool operator>=(const Parfum &obj) {
    return idParfum >= obj.idParfum || this->pret >= obj.pret;
  }

  bool operator==(const Parfum &obj) {
    return idParfum == obj.idParfum && this->pret == obj.pret;
  }
};

Parfum operator*(char *s, Parfum obj) {
  strcat(obj.tipAroma, " ");
  strcat(obj.tipAroma, s);
  return obj;
}

Parfum operator+(char *s, Parfum obj) {
  strcat(obj.numeParfum, " ");
  strcat(obj.numeParfum, s);
  return obj;
}

ostream &operator<<(ostream &out, const Parfum &obj) {
  out << "ID Parfum: " << obj.idParfum << endl;
  out << "Nume Parfum: " << obj.numeParfum << endl;
  out << "Brand: " << obj.brand << endl;
  out << "Rating: " << obj.rating << endl;
  out << "Tip Aroma: " << obj.tipAroma << endl;
  out << "In Stoc: " << std::boolalpha << obj.inStoc << endl;
  out << "Pret: " << obj.pret << endl;
  return out;
}

istream &operator>>(istream &in, Parfum &obj) {
  // id ul apare la crearea obiectului
  char nume[100];
  cout << "Nume Parfum: ";
  in.get();
  in.getline(nume, 100);
  if (obj.numeParfum != NULL)
    delete[] obj.numeParfum;
  obj.numeParfum = new char[strlen(nume) + 1];
  strcpy(obj.numeParfum, nume);

  char brand[100];
  cout << "Brand: ";
  in.getline(brand, 100);
  if (obj.brand != NULL)
    delete[] obj.brand;
  obj.brand = new char[strlen(brand) + 1];
  strcpy(obj.brand, brand);

  cout << "Rating: ";
  in >> obj.rating;

  char tip[100];
  cout << "Tip Aroma: ";
  in.get();
  in.getline(tip, 100);
  if (obj.tipAroma != NULL)
    delete[] obj.tipAroma;
  obj.tipAroma = new char[strlen(tip) + 1];
  strcpy(obj.tipAroma, tip);

  cout << "In Stoc: ";
  char boolVal[2];
  in >> boolVal;
  obj.inStoc = strcmp(boolVal, "da")==0;

  cout << "Pret: ";
  in >> obj.pret;

  return in;
};

int Parfum::PARFCONT = 0;

class Angajat {
private:
  static int ANGCONT;
  const int idAngajat;
  char *nume;
  char *post;
  bool inActivitate;
  float salariuLunar;

public:
  // constructori
  Angajat() : idAngajat(++ANGCONT) {
    nume = new char[strlen("anonim") + 1];
    strcpy(nume, "anonim");
    post = new char[strlen("anonim") + 1];
    strcpy(post, "anonim");
    inActivitate = false;
    salariuLunar = 0;
  }

  Angajat(char *nume, char *post, bool inActivitate, float salariuLunar)
      : idAngajat(++ANGCONT), inActivitate(inActivitate),
        salariuLunar(salariuLunar) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->post = new char[strlen(post) + 1];
    strcpy(this->post, post);
  }

  Angajat(char *nume, bool inActivitate, float salariuLunar)
      : idAngajat(++ANGCONT), inActivitate(inActivitate),
        salariuLunar(salariuLunar) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    post = new char[strlen("anonim") + 1];
    strcpy(post, "anonim");
  }

  Angajat(char *nume, bool inActivitate)
      : idAngajat(++ANGCONT), inActivitate(inActivitate) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    post = new char[strlen("anonim") + 1];
    strcpy(post, "anonim");
    salariuLunar = 0;
  }

  Angajat(char *nume, char *post) : idAngajat(++ANGCONT) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->post = new char[strlen(post) + 1];
    strcpy(this->post, post);
    salariuLunar = 0;
  }

  Angajat(const Angajat &a)
      : idAngajat(a.idAngajat), inActivitate(a.inActivitate),
        salariuLunar(a.salariuLunar) {
    this->nume = new char[strlen(a.nume) + 1];
    strcpy(this->nume, a.nume);
    this->post = new char[strlen(a.post) + 1];
    strcpy(this->post, a.post);
  }

  ~Angajat() {
    if (this->nume != NULL)
      delete[] this->nume;
    if (this->post != NULL)
      delete[] this->post;
  }

  // setteri
  void setNume(const char *name) {
    if (nume != NULL)
      delete[] nume;
    nume = new char[strlen(name) + 1];
    strcpy(nume, name);
  }

  void setPost(const char *job) {
    if (post != NULL)
      delete[] post;
    post = new char[strlen(job) + 1];
    strcpy(post, job);
  }

  void setInActivitate(bool activ) { inActivitate = activ; }

  void setSalariuLunar(float salary) { salariuLunar = salary; }

  // getteri
  int getIdAngajat() { return idAngajat; }

  char *getNume() { return nume; }

  char *getPost() { return post; }

  bool getInActivitate() { return inActivitate; }

  float getSalariuLunar() { return salariuLunar; }

  float salariuEstimat(int nrLuni, float crestereLunara) {
    if (inActivitate) {
      float salEstim = 0.0;
      float salCresc = this->salariuLunar;

      for (int i = 0; i < nrLuni; i++) {
        salCresc *= crestereLunara;
        salEstim += salCresc;
      }

      return salEstim;
    }

    return 0;
  }

  // supraincarcare operatori

  Angajat &operator=(const Angajat &obj) {
    if (this != &obj) {

      if (this->nume != NULL)
        delete[] this->nume;
      if (this->post != NULL)
        delete[] this->post;

      this->nume = new char[strlen(obj.nume) + 1];
      strcpy(this->nume, obj.nume);

      this->post = new char[strlen(obj.post) + 1];
      strcpy(this->post, obj.post);

      this->inActivitate = obj.inActivitate;
      this->salariuLunar = obj.salariuLunar;
    }
    return *this;
  }

  friend ostream &operator<<(
      ostream &,
      const Angajat
          &); // const rezolva eroarea de identificare membrii private pt parfum
              // - pt ca nu vrem ca friend sa modifice membrii private
  friend istream &operator>>(istream &, Angajat &);

  int operator[](int index) {
    switch (index) {
    case 0:
      return idAngajat;
    case 1:
      return strlen(this->nume);
    case 2:
      return strlen(this->post);
    case 3:
      return inActivitate;
    case 4:
      return salariuLunar;
    default:
      throw runtime_error("Index invalid");
    }
  }

  Angajat &operator++() /// pre-incrementare
  {
    this->salariuLunar += 100;

    return *this;
  }

  Angajat operator++(int) /// post-incrementare
  {
    Angajat copie = *this;
    copie.salariuLunar += 100;
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN DREAPTA
  Angajat operator+(int sum) {
    Angajat copie = *this;

    copie.salariuLunar += sum;

    return copie;
  }

  Angajat operator*(char *s) {
    Angajat copie = *this;
    strcat(copie.nume, " ");
    strcat(copie.nume, s);
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN STANGA
  friend Angajat operator+(int sum, Angajat a);
  friend Angajat operator*(char *s, Angajat a);

  /// CAST
  operator char *() // implicit
  {
    return this->nume;
  }

  bool operator>=(const Angajat &obj) {
    return salariuLunar > obj.salariuLunar || idAngajat >= obj.idAngajat;
  }

  bool operator==(const Angajat &obj) {
    return salariuLunar == obj.salariuLunar && idAngajat == obj.idAngajat;
  }
};

Angajat operator+(int sum, Angajat a) {
  a.salariuLunar += sum;
  return a;
}

Angajat operator*(char *s, Angajat a) {
  strcat(a.nume, " ");
  strcat(a.nume, s);
  return a;
}

int Angajat::ANGCONT = 0;

ostream &operator<<(ostream &out, const Angajat &obj) {
  out << "ID Angajat: " << obj.idAngajat << endl;
  out << "Nume: " << obj.nume << endl;
  out << "In Activitate: " << std::boolalpha << obj.inActivitate << endl;
  out << "Salariu: " << obj.salariuLunar << endl;
  return out;
}

istream &operator>>(istream &in, Angajat &obj) {
  // id ul apare la crearea obiectului
  char nume[100];
  cout << "Nume: ";
  in.get();
  in.getline(nume, 100);
  if (obj.nume != NULL)
    delete[] obj.nume;
  obj.nume = new char[strlen(nume) + 1];
  strcpy(obj.nume, nume);

  char post[100];
  cout << "Post: ";
  in.getline(post, 100);
  if (obj.post != NULL)
    delete[] obj.post;
  obj.post = new char[strlen(post) + 1];
  strcpy(obj.post, post);

  cout << "In Activitate: ";

  char boolVal[2];
  in >> boolVal;
  obj.inActivitate = strcmp(boolVal, "da")==0;

  cout << "SalariuLunar: ";
  in >> obj.salariuLunar;

  return in;
}

class Vanzare {
private:
  static int VANZCONT;
  const int idVanzare;
  int idAngajat;
  char *numeClient;
  double sumaTotala;
  int numarAchizitii;
  int *listaIdCumparaturi;

public:
  // constructori
  Vanzare() : idVanzare(++VANZCONT) {
    idAngajat = 0;
    numeClient = new char[strlen("anonim") + 1];
    strcpy(numeClient, "anonim");
    sumaTotala = 0;
    numarAchizitii = 0;
    listaIdCumparaturi = new int[numarAchizitii];
  }

  Vanzare(int idAngajat, char *numeClient, double sumaTotala,
          int numarAchizitii, int *listaIdCumparaturi)
      : idVanzare(++VANZCONT), idAngajat(idAngajat), sumaTotala(sumaTotala),
        numarAchizitii(numarAchizitii) {
    this->numeClient = new char[strlen(numeClient) + 1];
    strcpy(this->numeClient, numeClient);
    this->listaIdCumparaturi = new int[numarAchizitii];
    for (int i = 0; i < numarAchizitii; i++)
      this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
  }

  Vanzare(int idAngajat, double sumaTotala, int numarAchizitii,
          int *listaIdCumparaturi)
      : idVanzare(++VANZCONT), idAngajat(idAngajat), sumaTotala(sumaTotala),
        numarAchizitii(numarAchizitii) {
    this->numeClient = new char[strlen("anonim") + 1];
    strcpy(this->numeClient, "anonim");
    this->listaIdCumparaturi = new int[numarAchizitii];
    for (int i = 0; i < numarAchizitii; i++)
      this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
  }

  Vanzare(int idAngajat, char *numeClient, int numarAchizitii,
          int *listaIdCumparaturi)
      : idVanzare(++VANZCONT), idAngajat(idAngajat),
        numarAchizitii(numarAchizitii) {
    this->numeClient = new char[strlen(numeClient) + 1];
    strcpy(this->numeClient, numeClient);
    this->sumaTotala = 0;
    this->listaIdCumparaturi = new int[numarAchizitii];
    for (int i = 0; i < numarAchizitii; i++)
      this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
  }

  Vanzare(const Vanzare &a)
      : idVanzare(a.idVanzare), idAngajat(a.idAngajat),
        sumaTotala(a.sumaTotala), numarAchizitii(a.numarAchizitii) {
    this->numeClient = new char[strlen(a.numeClient) + 1];
    strcpy(this->numeClient, a.numeClient);
    this->listaIdCumparaturi = new int[numarAchizitii];
    for (int i = 0; i < numarAchizitii; i++)
      this->listaIdCumparaturi[i] = a.listaIdCumparaturi[i];
  }

  ~Vanzare() {
    if (this->numeClient != NULL)
      delete[] this->numeClient;
    if (this->listaIdCumparaturi != NULL)
      delete[] this->listaIdCumparaturi;
  }
  // setteri

  void setidAngajat(int id) { idAngajat = id; }

  void setNumeClient(const char *nume) {
    if (numeClient != NULL)
      delete[] numeClient;
    numeClient = new char[strlen(nume) + 1];
    strcpy(numeClient, nume);
  }

  void setSumaTotala(double total) { sumaTotala = total; }

  void setNumarAchizitii(int num) { numarAchizitii = num; }

  void setListaIdCumparaturi(int *list, int dim) {
    delete[] listaIdCumparaturi;

    listaIdCumparaturi = new int[dim];
    for (int i = 0; i < dim; ++i) {
      listaIdCumparaturi[i] = list[i];
    }
  }

  // getteri

  int getIdVanzare() { return idVanzare; }

  int getIdAngajat() { return idAngajat; }

  double getSumaTotala() { return sumaTotala; }

  int *getListaIdCumparaturi() { return listaIdCumparaturi; }

  // functionalitate

  bool
  parfumCumparat(vector<Parfum> parfumes) // verifica daca parfumurile dintr o
                                          // lista au fost comparate
  {
    for (int i = 0; i < numarAchizitii; i++) {
      bool peLista = false;
      for (auto parfume : parfumes)
        if (parfume.getIdParfum() == listaIdCumparaturi[i])
          peLista = true;
      if (!peLista)
        return false;
    }
    return true;
  }

  // supraincarcare operatori

  Vanzare &operator=(const Vanzare &obj) {
    if (this != &obj) {

      this->idAngajat = obj.idAngajat;
      this->sumaTotala = obj.sumaTotala;
      this->numarAchizitii = obj.numarAchizitii;

      if (this->numeClient != NULL)
        delete[] this->numeClient;

      this->numeClient = new char[strlen(obj.numeClient) + 1];
      strcpy(this->numeClient, obj.numeClient);

      if (this->listaIdCumparaturi != NULL)
        delete[] this->listaIdCumparaturi;

      this->listaIdCumparaturi = new int[numarAchizitii];
      for (int i = 0; i < numarAchizitii; i++)
        this->listaIdCumparaturi[i] = obj.listaIdCumparaturi[i];
    }

    return *this;
  }

  friend ostream &operator<<(
      ostream &,
      const Vanzare
          &); // const rezolva eroarea de identificare membrii private pt parfum
              // - pt ca nu vrem ca friend sa modifice membrii private
  friend istream &operator>>(istream &, Vanzare &);

  int operator[](int index) {
    if (index >= 0 && index < numarAchizitii)
      return this->listaIdCumparaturi[index];
    else
      throw runtime_error("Index invalid");
  }

  Vanzare &operator--() /// pre-incrementare
  {
    this->sumaTotala -= 100;
    this->numarAchizitii--;

    int *listID = new int[this->numarAchizitii];

    for (int i = 0; i < this->numarAchizitii; i++)
      listID[i] = listaIdCumparaturi[i];
    delete[] listaIdCumparaturi;

    listaIdCumparaturi = new int[this->numarAchizitii];
    for (int i = 0; i < this->numarAchizitii; i++)
      listaIdCumparaturi[i] = listID[i];

    delete[] listID;

    return *this;
  }

  Vanzare operator--(
      int) /// post-incrementare, mics de pret/nr prod, int anunta post inc
  {
    Vanzare copie = *this; // this e pointer, * sa fie obiect
    copie.numarAchizitii--;
    copie.sumaTotala -= 100;

    delete[] copie.listaIdCumparaturi;

    copie.listaIdCumparaturi = new int[copie.numarAchizitii];

    for (int i = 0; i < copie.numarAchizitii; i++)
      copie.listaIdCumparaturi[i] = this->listaIdCumparaturi[i];

    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN DREAPTA
  Vanzare operator+(int numarAchiz) {
    Vanzare copie = *this;

    copie.numarAchizitii += numarAchiz;

    return copie;
  }

  Vanzare operator*(int sum) {
    Vanzare copie = *this;
    copie.sumaTotala *= sum;
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN STANGA
  friend Vanzare operator+(int nr, Vanzare v);
  friend Vanzare operator*(int sum, Vanzare v);

  // op + pt obj din Angajat

  int operator+(Angajat a) {
    return (idAngajat == a.getIdAngajat()) ? idAngajat : 0;
  }

  // op + pt obj din Vanzare

  friend int operator+(Angajat, Vanzare);

  /// CAST
  operator char *() // implicit
  {
    return this->numeClient;
  }

  bool operator>=(const Vanzare &obj) {
    return sumaTotala > obj.sumaTotala || sumaTotala >= obj.sumaTotala;
  }

  bool operator==(const Vanzare &obj) {
    return sumaTotala == obj.sumaTotala || sumaTotala == obj.sumaTotala;
  }
};

int operator+(Angajat a, Vanzare v) {
  return a.getIdAngajat() != v.getIdAngajat() ? 0 : v.getIdAngajat();
}

Vanzare operator*(int sum, Vanzare v) {
  v.numarAchizitii *= sum;
  return v;
}

Vanzare operator+(int nr, Vanzare v) {
  v.numarAchizitii += nr;
  return v;
}

ostream &operator<<(ostream &out, const Vanzare &obj) {
  out << "ID Vanzare: " << obj.idVanzare << endl;
  out << "ID Client: " << obj.idAngajat << endl;
  out << "Nume: " << obj.numeClient << endl;
  out << "Suma Totala: " << obj.sumaTotala << endl;
  out << "Numar Achizitii: " << obj.numarAchizitii << endl;
  out << "ID Achizitii: " << endl;

  for (int i = 0; i < obj.numarAchizitii; i++)
    out << obj.listaIdCumparaturi[i] << " ";

  return out;
}

istream &operator>>(istream &in, Vanzare &obj) {
  // id ul apare la crearea obiectului
  cout << "Id Angajat: ";
  in >> obj.idAngajat;

  char nume[100];
  cout << "Nume Client: ";
  in.get();
  in.getline(nume, 100);
  if (obj.numeClient != NULL)
    delete[] obj.numeClient;
  obj.numeClient = new char[strlen(nume) + 1];
  strcpy(obj.numeClient, nume);

  cout << "Suma: ";
  in >> obj.sumaTotala;
  cout << "Nr Achizitii: ";
  in >> obj.numarAchizitii;

  cout << "ID Achizitii: " << endl;
  obj.listaIdCumparaturi = new int[obj.numarAchizitii];
  for (int i = 0; i < obj.numarAchizitii; i++)
    in >> obj.listaIdCumparaturi[i];

  return in;
}

int Vanzare::VANZCONT = 0;

class InventarMagazin {
private:
  int numarTipParfumuri;
  int *listaIdParfumuri;
  int *bucatiInStoc;
  bool perioadaPromotie;
  float profitTotal;

public:
  // constructori
  InventarMagazin() {
    numarTipParfumuri = 0;
    listaIdParfumuri = new int[numarTipParfumuri];
    bucatiInStoc = new int[numarTipParfumuri];
    perioadaPromotie = false;
    profitTotal = 0.0;
  }

  InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc,
                  bool perioadaPromotie, float profit)
      : numarTipParfumuri(numarParfumuri), perioadaPromotie(perioadaPromotie),
        profitTotal(profit) {

    this->listaIdParfumuri = new int[numarParfumuri];
    for (int i = 0; i < numarParfumuri; ++i)
      this->listaIdParfumuri[i] = listaIdParfumuri[i];

    this->bucatiInStoc = new int[numarTipParfumuri];
    for (int i = 0; i < numarTipParfumuri; ++i)
      this->bucatiInStoc[i] = bucatiInStoc[i];
  }

  InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc,
                  float profit)
      : numarTipParfumuri(numarParfumuri), profitTotal(profit) {

    this->perioadaPromotie = false;

    this->listaIdParfumuri = new int[numarParfumuri];
    for (int i = 0; i < numarParfumuri; ++i)
      this->listaIdParfumuri[i] = listaIdParfumuri[i];

    this->bucatiInStoc = new int[numarTipParfumuri];
    for (int i = 0; i < numarTipParfumuri; ++i)
      this->bucatiInStoc[i] = bucatiInStoc[i];
  }

  InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc)
      : numarTipParfumuri(numarParfumuri) {

    this->perioadaPromotie = false;
    this->profitTotal = 0.0;

    this->listaIdParfumuri = new int[numarParfumuri];
    for (int i = 0; i < numarParfumuri; ++i)
      this->listaIdParfumuri[i] = listaIdParfumuri[i];

    this->bucatiInStoc = new int[numarTipParfumuri];
    for (int i = 0; i < numarTipParfumuri; ++i)
      this->bucatiInStoc[i] = bucatiInStoc[i];
  }

  InventarMagazin(const InventarMagazin &obj)
      : numarTipParfumuri(obj.numarTipParfumuri),
        perioadaPromotie(obj.perioadaPromotie), profitTotal(obj.profitTotal) {

    this->listaIdParfumuri = new int[obj.numarTipParfumuri];
    for (int i = 0; i < obj.numarTipParfumuri; ++i)
      this->listaIdParfumuri[i] = obj.listaIdParfumuri[i];

    this->bucatiInStoc = new int[numarTipParfumuri];
    for (int i = 0; i < numarTipParfumuri; ++i)
      this->bucatiInStoc[i] = obj.bucatiInStoc[i];
  }
  // destructor
  ~InventarMagazin() {
    if (this->listaIdParfumuri != NULL)
      delete[] this->bucatiInStoc;
    if (this->bucatiInStoc != NULL)
      delete[] this->bucatiInStoc;
  }

  // setteri
  void setNumarTipParfumuri(int numarParfumuri) {
    numarTipParfumuri = numarParfumuri;
  }

  void setListaIdParfumuri(int *lista, int dim) {
    delete[] listaIdParfumuri;

    listaIdParfumuri = new int[dim];
    for (int i = 0; i < dim; ++i) {
      listaIdParfumuri[i] = lista[i];
    }
  }

  void setBucatiInStoc(int *listBucInStoc, int dim) {
    delete[] bucatiInStoc;

    listaIdParfumuri = new int[dim];
    for (int i = 0; i < dim; ++i) {
      listaIdParfumuri[i] = listBucInStoc[i];
    }
  }

  void setPerioadaPromotie(bool perioadaPromotie) {
    this->perioadaPromotie = perioadaPromotie;
  }

  void setProfitTotal(float profitTotal) { this->profitTotal = profitTotal; }

  // getteri

  int getNumarTipParfumuri() { return numarTipParfumuri; }

  int *getListaIdParfumuric() { return listaIdParfumuri; }

  int *getBucatiInStoc() { return bucatiInStoc; }

  bool getPerioadaPromotie() { return perioadaPromotie; }

  float getProfitTotal() { return profitTotal; }

  // functionalitate
  // returneaza cate bucati dintr un anumit parfum sunt in inventar

  int bucatiInventar(Parfum p) {
    for (int i = 0; i < numarTipParfumuri; ++i) {
      if (p.getIdParfum() == listaIdParfumuri[i])
        return bucatiInStoc[i];
    }
    return 0;
  }

  // supraincarcare operatori

  InventarMagazin &operator=(const InventarMagazin &obj) {
    if (this != &obj) {

      this->numarTipParfumuri = obj.numarTipParfumuri;
      this->perioadaPromotie = obj.perioadaPromotie;
      this->profitTotal = obj.profitTotal;

      if (this->listaIdParfumuri != NULL)
        delete[] this->listaIdParfumuri;

      this->listaIdParfumuri = new int[obj.numarTipParfumuri];
      for (int i = 0; i < numarTipParfumuri; i++)
        this->listaIdParfumuri[i] = obj.listaIdParfumuri[i];

      if (this->bucatiInStoc != NULL)
        delete[] this->bucatiInStoc;

      this->bucatiInStoc = new int[obj.numarTipParfumuri];
      for (int i = 0; i < numarTipParfumuri; i++)
        this->bucatiInStoc[i] = obj.bucatiInStoc[i];
    }

    return *this;
  }

  friend ostream &
  operator<<(ostream &,
             const InventarMagazin
                 &); // const rezolva eroarea de identificare membrii private pt
                     // parfum
                     // - pt ca nu vrem ca friend sa modifice membrii private
  friend istream &operator>>(istream &, InventarMagazin &);

  int operator[](int index) {
    if (index >= 0 && index < numarTipParfumuri)
      return this->listaIdParfumuri[index];
    else
      throw runtime_error("Index invalid");
  }

  InventarMagazin &operator--() /// pre-incrementare
  {
    for (int i = 0; i < numarTipParfumuri; i++)
      if (bucatiInStoc[i] > 0)
        bucatiInStoc[i]--;

    return *this;
  }

  InventarMagazin operator--(int) /// post-incrementare, mics de pret/nr prod
  {
    InventarMagazin copie = *this; // this e pointer, * sa fie obiect
    for (int i = 0; i < numarTipParfumuri; i++)
      if (copie.bucatiInStoc[i] > 0)
        copie.bucatiInStoc[i]--;
    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN DREAPTA
  InventarMagazin operator+(InventarMagazin obj) {
    InventarMagazin copie = *this;

    for (int i = 0; i < this->numarTipParfumuri; i++)
      copie.bucatiInStoc[i] += obj.bucatiInStoc[i];

    return copie;
  }

  InventarMagazin operator*(InventarMagazin obj) {
    InventarMagazin copie = *this;

    for (int i = 0; i < this->numarTipParfumuri; i++)
      copie.bucatiInStoc[i] *= obj.bucatiInStoc[i];

    return copie;
  }

  /// OPERATORUL +, * cu obiect din alta clasa IN STANGA
  friend InventarMagazin operator+(InventarMagazin, InventarMagazin);
  friend InventarMagazin operator*(InventarMagazin, InventarMagazin);

  /// CAST
  operator float() // implicit
  {
    return this->profitTotal;
  }

  bool operator<(const InventarMagazin &obj) {
    return profitTotal < obj.profitTotal;
  }

  bool operator==(const InventarMagazin &obj) {
    return profitTotal == obj.profitTotal;
  }
};

InventarMagazin operator*(InventarMagazin obj1, InventarMagazin obj2) {
  for (int i = 0; i < obj1.numarTipParfumuri; i++)
    obj1.bucatiInStoc[i] *= obj2.bucatiInStoc[i];

  return obj1;
}

InventarMagazin operator+(InventarMagazin obj1, InventarMagazin obj2) {
  for (int i = 0; i < obj1.numarTipParfumuri; i++)
    obj1.bucatiInStoc[i] += obj2.bucatiInStoc[i];

  return obj1;
}

ostream &operator<<(ostream &out, const InventarMagazin &obj) {
  out << "Numar Parfumuri: " << obj.numarTipParfumuri << endl;
  out << "Perioada Promotie: " << obj.perioadaPromotie << endl;
  out << "Total Profit: " << obj.profitTotal << endl;
  out << "Lista ID Parfumuri si daca sunt in stoc: " << endl;

  for (int i = 0; i < obj.numarTipParfumuri; i++)
    out << obj.listaIdParfumuri[i] << " " << obj.bucatiInStoc[i];

  return out;
}

istream &operator>>(istream &in, InventarMagazin &obj) {
  cout << "Numar Parfumuri: ";
  in >> obj.numarTipParfumuri;
  cout << "Perioada Promotie: ";
  
  char boolVal[2];
  cin >> boolVal;
  obj.perioadaPromotie = strcmp(boolVal, "da")==0;
  cout << "Total Profit: ";
  in >> obj.profitTotal;

  cout << "ID Parfumuri si bucati in stoc: " << endl;
  obj.listaIdParfumuri = new int[obj.numarTipParfumuri];
  for (int i = 0; i < obj.numarTipParfumuri; i++)
    in >> obj.listaIdParfumuri[i] >> obj.bucatiInStoc[i];

  return in;
}

int main() {
  vector<Parfum> parfumuri;
  vector<Angajat> angajati;
  vector<Vanzare> vanzari;
  vector<InventarMagazin> inventare;

  while (true) {
    int comanda;
    cout << "Bine ati venit! Alegeti optiuni: \n 1: Creare - 2: Read - 3: Update - 4: Delete - 5: Apel functii \n";
    cin >> comanda;
    switch (comanda) {
    case 1: {
      int alegere = 0;
      cout << "Alegeti optiuni: \n 1: Creare parfum, 2: Creare Angajat, 3: Creare Vanzare, 4: Creare Inventar \n";
      cin >> alegere;
      switch (alegere) {
      case 1: {
        Parfum p;
        cin >> p;
        parfumuri.push_back(p);
        break;
      }
      case 2: {
        Angajat a;
        cin >> a;
        angajati.push_back(a);
        break;
      }
      case 3: {
        Vanzare v;
        cin >> v;
        vanzari.push_back(v);
        break;
      }
      case 4: {
        InventarMagazin i;
        cin >> i;
        inventare.push_back(i);
        break;
      }
      default:
        break;
      }

      break;
    }
    case 2: {
      int alegere = 0, index;
      cout << "Read optiuni: \n 1: Read Parfumuri, 2: Read Angajati, 3: Read Vanzari, 4: Read Inventare \n";
      cin >> alegere;
      cout << "Introduceti index: \n";
      cin >> index;
      switch (alegere) {
      case 1: {
        for(auto parfum:parfumuri)
         cout << parfum;
        break;
      }
      case 2: {
        for(auto angajat:angajati)
         cout << angajat;
        break;
      }
      case 3: {
         for(auto vanzare:vanzari)
          cout << vanzare;
        break;
      }
      case 4: {
        for(auto inventar:inventare)
         cout << inventar;
        break;
      }
      default:
        break;
      }

      break;
    }
    case 3: {
      int alegere = 0, index;
      cout << "Update optiuni: \n 1: Update parfum, 2: Update Angajat, 3: Update Vanzare, 4: Update Inventar \n";
      cin >> alegere;
      cout << "Introduceti index: \n";
      cin >> index;
      switch (alegere) {
      case 1: {
        Parfum p;
        cin >> p;
        parfumuri[index] = p;
        break;
      }
      case 2: {
        Angajat a;
        cin >> a;
        angajati[index] = a;
        break;
      }
      case 3: {
        Vanzare v;
        cin >> v;
        vanzari[index] = v;
        break;
      }
      case 4: {
        InventarMagazin i;
        cin >> i;
        inventare[index] = i;
        break;
      }
      default:
        break;
      }

      break;
    }
    case 4: {
      int alegere = 0, index;
      cout << "Delete optiuni: \n 1: Delete parfum, 2: Delete Angajat, 3: Delete Vanzare, 4: Delete Inventar \n";
      cin >> alegere;
      cout << "Introduceti index: \n";
      cin >> index;
      switch (alegere) {
      case 1: {
        parfumuri.erase(parfumuri.begin() + index);
        break;
      }
      case 2: {
        angajati.erase(angajati.begin() + index);
        break;
      }
      case 3: {
        vanzari.erase(vanzari.begin() + index);
        break;
      }
      case 4: {
        //  delete inventare[index];
        inventare.erase(inventare.begin() + index);
        break;
      }
      default:
        break;
      }

      break;
    }
     case 5: {
      int alegere = 0, index;
      cout << "Functii: \n 1: Cand avem parfumuri in stoc , 2: Estimare salarii, 3: Ce parfumuri contine fiecare vanzare, 4: Cate parfumuri am in fiecare inventar \n";
      cin >> alegere;
      cout << "Introduceti index: \n";
      cin >> index;
      switch (alegere) {
      case 1: {
        for(auto p:parfumuri)
        {
           cout << p.getNumeParfum() << " ";
           p.isInStoc();
           cout << endl;
        }
        break;
      }
      case 2: {
        for(auto a:angajati)
        {
            int nrLuni, crestere;
            cout << "Introduceti numarul de luni si cresterea pe luna a salariului: \n";
            cin >> nrLuni >> crestere;
            cout << "Salariu estimat: " << a.salariuEstimat(nrLuni, crestere);
       
        }
        break;
      }
      case 3: {
        for(auto v:vanzari)
        {
            int nrParfumuri, poz;
            vector <Parfum> p2;
            cout << "Introduceti cate parfumuri se cauta si indexurile parfumurilr de cautat: \n";
            cin >> nrParfumuri;
            for(int i=0; i<nrParfumuri; i++)
            {
                cin >> poz;
                p2.push_back(parfumuri[poz]);
            }

            cout << "Vanzare " << v.getIdVanzare() << ": parufumurile " << (v.parfumCumparat(p2)==true)? "sunt pe bon": "nu sunt pe bon";
            cout << endl;
        }
        break;
      }
      case 4: {
        for(auto i:inventare)
           for(auto p:parfumuri)
             cout <<"Parfumul " << p.getNumeParfum() << " are " << i.bucatiInventar(p) << " in inventarul curent";
        break;
      }
      default:
        break;
      }

      break;
    }
    }
  }

  return 0;
}

// ma uit peste functii

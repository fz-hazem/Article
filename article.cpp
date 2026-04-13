#include <iostream>
#include <string>

using namespace std;

class Article {
private:
    int reference;
    string designation;
    double prixHT;
    double tauxTVA;

public:
    Article() {
        reference = 0;
        designation = "";
        prixHT = 0.0;
        tauxTVA = 0.0;
    }

    Article(int ref, string desig, double prix, double tva) {
        reference = ref;
        designation = desig;
        prixHT = prix;
        tauxTVA = tva;
    }

    Article(int ref, string desig) {
        reference = ref;
        designation = desig;
        prixHT = 0.0;
        tauxTVA = 0.0;
    }

    Article(const Article& a) {
        reference = a.reference;
        designation = a.designation;
        prixHT = a.prixHT;
        tauxTVA = a.tauxTVA;
    }

    ~Article() {
    }

    int getReference() { return reference; }
    void setReference(int ref) { reference = ref; }

    string getDesignation() { return designation; }
    void setDesignation(string desig) { designation = desig; }

    double getPrixHT() { return prixHT; }
    void setPrixHT(double prix) { prixHT = prix; }

    double getTauxTVA() { return tauxTVA; }
    void setTauxTVA(double tva) { tauxTVA = tva; }

    double CalculerPrixTTC() {
        return prixHT + (prixHT * tauxTVA / 100);
    }

    void AfficheArticle() {
        cout << reference << " | " << designation << " | " 
             << prixHT << " | " << tauxTVA << endl;
    }
};

int main() {
    Article* ord1 = new Article();
    
    Article ord2(1, "Ordinateur portable", 2000.0, 19.0);
    
    Article ord3(2, "Ordinateur portable");
    
    Article ord4(ord2);
    
    delete ord1;
    
    ord3.AfficheArticle();
    cout << ord3.CalculerPrixTTC() << endl;

    return 0;
}
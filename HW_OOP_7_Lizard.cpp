#include <iostream>
#include <string>
using namespace std;

class Lizard {

    string animalclass;
    string suborder;
    string family;
    int bodylength;

public:

    Lizard() {
        SetAnimalClass("Reptilia");
        SetSuborder("Iguania");
        SetFamily("Agamidae");
        SetBodyLength(25);
    }

    Lizard(string animalclass, string suborder, string family, int bodylength) {
        SetAnimalClass(animalclass);
        SetSuborder(suborder);
        SetFamily(family);
        SetBodyLength(bodylength);
    }

    ~Lizard() {
        cout << "The lizard ran away\n";
    }

    void CompareSize(const Lizard& other) const {
        if (this->bodylength < other.bodylength) {
            cout << "Lizard " << this->family << " is smaller than lizard " << other.family << "\n";
        }
        else if (other.bodylength < this->bodylength) {
            cout << "Lizard " << other.family << " is smaller than lizard " << this->family << "\n";
        }
        else {
            cout << "Both lizards are equal in size." << "\n";
        }
    }

    void Print() const {
        cout << "Animal class: " << animalclass << "\n";
        cout << "Suborder: " << suborder << "\n";
        cout << "Family: " << family << "\n";
        cout << "Body length: " << bodylength << "\n";
    }

    void SetAnimalClass(const string& animalclass) {
        this->animalclass = animalclass;
    }
    string GetSetAnimalClass() const {
        return animalclass;
    }

    void SetSuborder(const string& suborder) {
        this->suborder = suborder;
    }
    string GetSuborder() const {
        return suborder;
    }

    void SetFamily(const string& family) {
        this->family = family;
    }
    string GetFamily() const {
        return family;
    }

    void SetBodyLength(int bodylength) {
        if (bodylength < 5 || bodylength > 70) throw "ERROR!";
        this->bodylength = bodylength;
    }
    int GetBodyLength() const {
        return bodylength;
    }

    bool operator<(const Lizard& other) const {
        return this->bodylength < other.bodylength;
    }

    bool operator==(const Lizard& other) const {
        return (this->family == other.family &&
            this->suborder == other.suborder &&
            this->bodylength == other.bodylength);
    }

    istream& ReadFromConsole(istream& in) {
        cout << "Welcome!\n";
        cout << "Please, enter the name of lizard family: ";
        in >> family;
        cout << "Please, enter value for lizard body length: ";
        in >> bodylength;
        return in;
    }

    ostream& WriteToConsole(ostream& out) const {
        out << "\n================================\n";
        out << "Lizard state:\n";
        out << "Family: " << family << "\n";
        out << "Body length: " << bodylength << "\n";
        out << "\n================================\n\n";
        return out;
    }
};

istream& operator>>(istream& in, Lizard& lizard) {
    return lizard.ReadFromConsole(in);
}

ostream& operator<<(ostream& out, const Lizard& lizard) {
    return lizard.WriteToConsole(out);
}

int main() {
    Lizard a;
    Lizard b;
    cin >> a;
    cin >> b;
    cout << a << b;
    a.CompareSize(b);

    return 0;
}

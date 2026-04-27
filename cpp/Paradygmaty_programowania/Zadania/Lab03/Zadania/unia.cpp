#include <iostream>
#include <string>
#include <limits>
#include <cctype>
enum StoredType { NONE, USHORT_T, INT_T, LONGLONG_T, FLOAT_T, DOUBLE_T };
union MyUnion {
    unsigned short us;
    int i;
    long long ll;
    float f;
    double d;
};
bool looks_like_integer(const std::string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i = 1;
    for (; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}
bool looks_like_float(const std::string &s) {
    return s.find('.') != std::string::npos || s.find('e') != std::string::npos || s.find('E') != std::string::npos;
}
void print_union(const MyUnion &u, StoredType tag) {
    switch (tag) {
        case USHORT_T:  std::cout << "unsigned short: " << u.us << '\n'; break;
        case INT_T:     std::cout << "int: " << u.i << '\n'; break;
        case LONGLONG_T:std::cout << "long long: " << u.ll << '\n'; break;
        case FLOAT_T:   std::cout << "float: " << u.f << '\n'; break;
        case DOUBLE_T:  std::cout << "double: " << u.d << '\n'; break;
        default:        std::cout << "(brak wartosci)\n";
    }
}
int main() {
    MyUnion u{};
    StoredType tag = NONE;
    std::cout << "Wprowadz wartosc: ";
    std::string s;
    if (!std::getline(std::cin, s)) return 0;
    std::cout << "Tryb: 1) Uzytkownik wybiera typ  2) Program dobiera typ (auto)\nWybór (1/2): ";
    int mode = 0;
    if (!(std::cin >> mode)) return 0;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (mode == 1) {
        std::cout << "Wybierz typ: 1=unsigned short,2=int,3=long long,4=float,5=double\nWybor: ";
        int ch; if (!(std::cin >> ch)) return 0;
        try {
            if (ch == 1) {
                long long v = std::stoll(s);
                if (v < 0 || v > std::numeric_limits<unsigned short>::max()) throw std::out_of_range("poza zakresem");
                u.us = static_cast<unsigned short>(v); tag = USHORT_T;
            } else if (ch == 2) {
                long long v = std::stoll(s);
                if (v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max()) throw std::out_of_range("poza zakresem");
                u.i = static_cast<int>(v); tag = INT_T;
            } else if (ch == 3) {
                long long v = std::stoll(s);
                u.ll = v; tag = LONGLONG_T;
            } else if (ch == 4) {
                double dv = std::stod(s);
                if (dv < std::numeric_limits<float>::lowest() || dv > std::numeric_limits<float>::max())
                    throw std::out_of_range("poza zakresem");
                u.f = static_cast<float>(dv); tag = FLOAT_T;
            } else if (ch == 5) {
                double dv = std::stod(s);
                u.d = dv; tag = DOUBLE_T;
            } else {
                std::cerr << "Niepoprawny wybor\n"; return 0;
            }
        } catch (const std::invalid_argument&) {
            std::cerr << "Blad: niepoprawna konwersja\n"; return 0;
        } catch (const std::out_of_range&) {
            std::cerr << "Blad: wartosc poza zakresem dla wybranego typu\n"; return 0;
        }
    } else { 
        if (looks_like_integer(s)) {
            try {
                long long v = std::stoll(s);
                if (v >= 0 && v <= std::numeric_limits<unsigned short>::max()) {
                    u.us = static_cast<unsigned short>(v); tag = USHORT_T;
                } else if (v >= std::numeric_limits<int>::min() && v <= std::numeric_limits<int>::max()) {
                    u.i = static_cast<int>(v); tag = INT_T;
                } else {
                    u.ll = v; tag = LONGLONG_T;
                }
            } catch (...) {
                std::cerr << "Blad parsowania liczby calkowitej\n"; return 0;
            }
        } else if (looks_like_float(s)) {
            try {
                double dv = std::stod(s);
                if (dv >= std::numeric_limits<float>::lowest() && dv <= std::numeric_limits<float>::max()) {
                    u.f = static_cast<float>(dv); tag = FLOAT_T;
                } else {
                    u.d = dv; tag = DOUBLE_T;
                }
            } catch (...) {
                std::cerr << "Blad parsowania liczby zmiennoprzecinkowej\n"; return 0;
            }
        } else {
            try {
                double dv = std::stod(s);
                u.d = dv; tag = DOUBLE_T;
            } catch (...) {
                std::cerr << "Nie rozpoznano typu automatycznie\n"; return 0;
            }
        }
    }
    std::cout << "\nZapisano wartosc w unii.\n";
    std::cout << "Rozmiar unii (B): " << sizeof(MyUnion) << "  (bitow: " << sizeof(MyUnion)*8 << ")\n";
    switch (tag) {
        case USHORT_T:  std::cout << "Rozmiar typu unsigned short (B): " << sizeof(u.us) << '\n'; break;
        case INT_T:     std::cout << "Rozmiar typu int (B): " << sizeof(u.i) << '\n'; break;
        case LONGLONG_T:std::cout << "Rozmiar typu long long (B): " << sizeof(u.ll) << '\n'; break;
        case FLOAT_T:   std::cout << "Rozmiar typu float (B): " << sizeof(u.f) << '\n'; break;
        case DOUBLE_T:  std::cout << "Rozmiar typu double (B): " << sizeof(u.d) << '\n'; break;
        default:        std::cout << "Brak zapisanego typu\n";
    }
    std::cout << "Zawartosc unii (ponownie):\n";
    print_union(u, tag);
    return 0;
}
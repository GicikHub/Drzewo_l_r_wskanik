🌳 Drzewo binarne w C++

Prosta implementacja binarnego drzewa wyszukiwania (BST) w języku C++.

Projekt pokazuje podstawową obsługę drzewa binarnego przy użyciu struct, klasy oraz dynamicznej alokacji pamięci.

Funkcje

Program umożliwia:

dodawanie elementów do drzewa,

wypisywanie elementów drzewa w kolejności rosnącej,

automatyczne usuwanie całego drzewa w destruktorze,

pomijanie duplikatów.

Struktura drzewa

Każdy węzeł zawiera:

struct drzewo_bin
{
    int a;
    drzewo_bin *l, *p;
};


a – wartość przechowywana w węźle,

l – wskaźnik na lewe dziecko,

p – wskaźnik na prawe dziecko.

Wartości mniejsze od aktualnego węzła trafiają w lewo, a większe w prawo.

Klasa drzewo

Klasa przechowuje wskaźnik na korzeń drzewa:

drzewo_bin *korzen;

dodaj(int x)

Dodaje nową wartość do drzewa.

Przykład:

d.dodaj(50);
d.dodaj(30);
d.dodaj(70);

wypisz()

Wypisuje elementy drzewa w kolejności in-order, dzięki czemu wartości są wyświetlane rosnąco.

Dla przykładowego drzewa:

       50
      /  \
    30    70
   / \    / \
 20  40  60 80


wynik będzie:

20 30 40 50 60 70 80

Destruktor

Po zakończeniu działania programu destruktor:

~drzewo()
{
    usun(korzen);
}


usuwa całe drzewo z pamięci.

Funkcja usun() najpierw usuwa lewe i prawe poddrzewo, a następnie aktualny węzeł:

void usun(drzewo_bin *w)
{
    if (w == NULL)
        return;

    usun(w->l);
    usun(w->p);
    delete w;
}


Dzięki temu wszystkie elementy utworzone przez new zostają zwolnione.

Przykład użycia
int main()
{
    drzewo d;

    d.dodaj(50);
    d.dodaj(30);
    d.dodaj(70);
    d.dodaj(20);
    d.dodaj(40);
    d.dodaj(60);
    d.dodaj(80);

    d.wypisz();

    return 0;
}

Kompilacja

Program można skompilować za pomocą g++:

g++ main.cpp -o drzewo


Uruchomienie:

./drzewo

Technologie

C++

struktury (struct)

klasy

wskaźniki

dynamiczna alokacja pamięci (new / delete)

rekurencja

destruktor

binarne drzewo wyszukiwania (BST)

Cel projektu

Projekt ma charakter edukacyjny i służy do nauki podstawowych struktur danych, wskaźników, klas oraz zarządzania pamięcią w języku C++.

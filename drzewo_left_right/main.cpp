#include <iostream>
using namespace std;

struct drzewo_bin
{
    int a;
    drzewo_bin *l, *p;
};

class drzewo
{
    drzewo_bin *korzen;

    void usun(drzewo_bin *w)
    {
        if (w == NULL)
            return;

        usun(w->l);
        usun(w->p);
        delete w;
    }

public:
    drzewo()
    {
        korzen = NULL;
    }

    void dodaj(int x)
    {
        if (korzen == NULL)
        {
            korzen = new drzewo_bin{x, NULL, NULL};
            return;
        }

        drzewo_bin *w = korzen;

        while (true)
        {
            if (x < w->a)
            {
                if (w->l == NULL)
                {
                    w->l = new drzewo_bin{x, NULL, NULL};
                    return;
                }
                w = w->l;
            }
            else if (x > w->a)
            {
                if (w->p == NULL)
                {
                    w->p = new drzewo_bin{x, NULL, NULL};
                    return;
                }
                w = w->p;
            }
            else
                return;
        }
    }

    void wypisz(drzewo_bin *w)
    {
        if (w == NULL)
            return;

        wypisz(w->l);
        cout << w->a << " ";
        wypisz(w->p);
    }

    void wypisz()
    {
        wypisz(korzen);
    }

    ~drzewo()
    {
        usun(korzen);
    }
};

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

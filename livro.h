#ifndef LIVRO_H
#define LIVRO_H
#include <iostream>
#include <string>

using namespace std;

class Livro
{
private:
            string titulo;
            string autor;
            string isbn;
public:
            Livro();
            void setTitulo (string titulo);
            void setAutor (string autor);
            void setISBN (string isbn);

            string getTitulo();
            string getAutor();
            string getISBN();

};

#endif // LIVRO_H

#include "livro.h"

Livro::Livro()
{
}
void Livro::setTitulo (string titulo) {
    this->titulo = titulo;
}
void Livro::setAutor (string autor) {
    this->autor = autor;
}
void Livro::setISBN (string isbn) {
    this->isbn = isbn;
}

string Livro::getTitulo() {
    return this-> titulo;
}
string Livro::getAutor() {
    return this-> autor;
}
string Livro::getISBN() {
    return this-> isbn;
}

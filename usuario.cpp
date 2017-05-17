#include "usuario.h"

Usuario::Usuario()
{
}

void Usuario::setCpf (string cpf) {
    this->cpf = cpf;
}
void Usuario::setNome (string nome) {
    this->nome = nome;
}
string Usuario::getCpf() {
    return this->cpf;
}
string Usuario::getNome() {
    return this->nome;
}
void Usuario::dev_livro(Livro livro) {
    for (unsigned int i = 0; i < livros.size(); i++) {
        if (livro.getISBN() == livros[i].getISBN()) {
            livros.erase(livros.begin()+i);
        }
    }
}

void Usuario::emp_livro(Livro livro) {
    if (livros.size() <= 3) {
        livros.push_back(livro);
    }
}
float Usuario::getN_livros() {
    float n = livros.size();
    return n;
}

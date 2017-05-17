#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <vector>
#include "livro.h"

using namespace std;

class Usuario
{
private:
            string nome;
            string cpf;
            vector<Livro>livros;
     public:
            Usuario();
            void setCpf (string cpf);
            void setNome (string nome);

            string getCpf();
            string getNome();

            void emp_livro (Livro livro);
            void dev_livro (Livro livro);
            float getN_livros ();
};

#endif // USUARIO_H

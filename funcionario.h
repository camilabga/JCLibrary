#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <string>

using namespace std;

class Funcionario
{
private:
            string func;
            string cpf;
public:
            Funcionario();
            void setCpf (string cpf);
            void setFunc (string func);

            string getCpf();
            string getFunc();

};

#endif // FUNCIONARIO_H

#include "funcionario.h"

Funcionario::Funcionario()
{
}
void Funcionario::setCpf (string cpf){
    this->cpf = cpf;
}
void Funcionario::setFunc (string func){
    this->func = func;
}

string Funcionario::getCpf(){
    return this->cpf;
}
string Funcionario::getFunc(){
    return this->func;
}

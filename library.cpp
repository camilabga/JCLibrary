#include "library.h"
#include "ui_library.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Library::Library(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Library)
{
    ui->setupUi(this);
}

Library::~Library()
{
    delete ui;
}

void Library::on_cadasFunc_clicked()
{
    QString func = ui->nomeFunc->text();
    QString cpffunc = ui->cpfFunc->text();

    Funcionario f;

    f.setFunc(func.toStdString());
    f.setCpf(cpffunc.toStdString());

    funcionarios.push_back(f);

    ui->funcResultado->setText("Funcionario cadastrado com sucesso!");
}

void Library::on_mostrarFunc_clicked()
{
    string txt = "";
    if (funcionarios.size() == 0) {
        ui->funcCadastrados->setText("Nenhum funcionario cadastrado");
    } else {

    for (unsigned int i = 0; i < funcionarios.size(); i++) {
        string func = funcionarios[i].getFunc();
        string cpf = funcionarios[i].getCpf();

        txt += "Nome: " + func + "\n" + "CPF: " + cpf + "\n\n";

            }
    ui->funcCadastrados->setText(QString::fromStdString(txt));
    }
}

void Library::on_limpFunc_clicked()
{
    ui->nomeFunc->setText("");
    ui->cpfFunc->setText("");
    ui->funcResultado->setText("");
}

void Library::on_pushButton_clicked()
{
    QString tit = ui->titulo->text();
    QString aut = ui->autor->text();
    QString is = ui->isbn->text();

    Livro l;

    l.setTitulo(tit.toStdString());
    l.setAutor(aut.toStdString());
    l.setISBN(is.toStdString());

    livro.push_back(l);
    p_emp.push_back(l);
    ui->statusLivro->setText("Livro cadastrado com sucesso!");
}

void Library::on_limparLivro_clicked()
{
    ui->titulo->setText("");
    ui->autor->setText("");
    ui->isbn->setText("");
    ui->statusLivro->setText("");
}



void Library::on_btnSearch_clicked()
{
    QString exc = ui->excludTit->text();
    QString isb = ui->txtExcludISBN->text();
    std::string e = exc.toStdString();
    std::string is = isb.toStdString();
    for (unsigned int i = 0; i < p_emp.size(); i++) {
    string a = p_emp[i].getTitulo();
    string b = p_emp[i].getAutor();
    string c = p_emp[i].getISBN();
    if (e == p_emp[i].getTitulo() || is == p_emp[i].getISBN()) {
                 string t = a;
                 string v = b;
                 string i = c;

                 ui->txtExclud->setText("Titulo: " + QString::fromStdString(t) +
                                        "\n" + "Autor: " +  QString::fromStdString(v) +
                                        "\n" + "ISBN: " +  QString::fromStdString(i) + "\n\n");
                } else {
        ui->txtExclud->setText("Livro nao encontrado!");
    }
            }
         }


void Library::on_btnLimparExclud_clicked()
{
    ui->excludTit->setText("");
    ui->txtExcludISBN->setText("");
    ui->livroExcludOk->setText("");
}

void Library::on_btnExclud_clicked()
{
    QString exc = ui->excludTit->text();
    QString isb = ui->txtExcludISBN->text();
    std::string e = exc.toStdString();
    std::string is = isb.toStdString();
        for (unsigned int i = 0; i < livro.size(); i++) {
            string a = livro[i].getTitulo();
            string b = livro[i].getAutor();
            string c = livro[i].getISBN();
                 if (e == livro[i].getTitulo() || is == livro[i].getISBN()) {
                     livro.erase(livro.begin()+i);
                     ui->txtExclud->setText("");
                     ui->livroExcludOk->setText("Livro excluido!");

                 }
        }
        for (unsigned int i = 0; i < p_emp.size(); i++) {
            string d = p_emp[i].getTitulo();
            string f = p_emp[i].getAutor();
            string g = p_emp[i].getISBN();
                 if (e == p_emp[i].getTitulo() || is == p_emp[i].getISBN()) {
                     p_emp.erase(p_emp.begin()+i);
        }
    }
}
void Library::on_btnCadasUser_clicked()
{
    QString name = ui->txtNomeUser->text();
    QString cpfuser = ui->txtCPFUser->text();

    Usuario u;

    u.setNome(name.toStdString());
    u.setCpf(cpfuser.toStdString());


    usuario.push_back(u);

    ui->cadasUser->setText("Usuario cadastrado com sucesso!");


}
void Library::on_btnLimparUser_clicked()
{
    ui->txtNomeUser->setText("");
    ui->txtCPFUser->setText("");
    ui->cadasUser->setText("");
}

void Library::on_btnSearchUser_clicked()
{
    {
        QString name = ui->txtExcludUser->text();
        QString cpf = ui->txtExcludUserCPF->text();
        std::string n = name.toStdString();
        std::string cp = cpf.toStdString();
            for (unsigned int i = 0; i < usuario.size(); i++) {
                string a = usuario[i].getNome();
                string b = usuario[i].getCpf();
                    if (n == usuario[i].getNome() || cp == usuario[i].getCpf()) {
                        string c = a;
                        string d = b;

                        ui->txtExcludUser_2->setText("Nome: " + QString::fromStdString(c) +
                                                "\n" + "CPF: " +  QString::fromStdString(d) + "\n\n");

                     }
            }
     }
}

void Library::on_btnCleanUser_clicked()
{
    ui->txtExcludUser->setText("");
    ui->txtExcludUserCPF->setText("");
}

void Library::on_btnExcludUser_clicked()
{
    QString name = ui->txtExcludUser->text();
    QString cpf = ui->txtExcludUserCPF->text();
    std::string n = name.toStdString();
    std::string cp = cpf.toStdString();
        for (unsigned int i = 0; i < usuario.size(); i++) {
            string a = usuario[i].getNome();
            string b = usuario[i].getCpf();
                if (n == usuario[i].getNome() || cp == usuario[i].getCpf()) {
                     usuario.erase(usuario.begin()+i);

                     ui->txtExcludUser_2->setText("");
                     ui->userExcludOk->setText("Usuario excluido!");

                 }
        }
}

void Library::on_btnShowUser_clicked()
{
    string show = "";
    if (usuario.size() == 0) {
        ui->txtShowUsers->setText("Nenhum usuario cadastrado");
    } else {

    for (unsigned int i = 0; i < usuario.size(); i++) {
        string name = usuario[i].getNome();
        string cpf = usuario[i].getCpf();

        show += "Nome: " + name + "\n" + "CPF: " + cpf + "\n\n";

            }
    ui->txtShowUsers->setText(QString::fromStdString(show));
    }
}


void Library::on_btnEmpDisp_clicked()
{

    QString li = ui->empISBN->text();
    std::string l = li.toStdString();
    for (unsigned int i = 0; i < p_emp.size(); i++) {

    if (l == p_emp[i].getISBN()) {
        string a = p_emp[i].getTitulo();
        string b = p_emp[i].getAutor();
        string c = p_emp[i].getISBN();

        ui->txtEmp->setText("Titulo: " + QString::fromStdString(a) +
                              "\n" + "Autor: " +  QString::fromStdString(b) +
                              "\n" + "ISBN: " +  QString::fromStdString(c) + "\n\n");


        }

    }
}

void Library::on_btnEmp_clicked()
{
    QString li = ui->empISBN->text();
    QString u = ui->empUser->text();
    std::string li_emp = li.toStdString();
    std::string user = u.toStdString();
    for(unsigned int i = 0; i < p_emp.size(); i++) {
        if (li_emp == p_emp[i].getISBN()) {
            for (unsigned int j = 0; j < usuario.size(); j++) {
                if (user == usuario[j].getCpf() && usuario[j].getN_livros() <= 3) {
                    usuario[j].emp_livro(p_emp[i]);
                    p_dev.push_back(p_emp[i]);
                    p_emp.erase(p_emp.begin()+i);
                    string a = usuario[j].getNome();
                    ui->noEmp->setText("Livro emprestado ao usuario " + QString::fromStdString(a) + "\n" +
                                       "CPF: " + QString::fromStdString(user));
                    ui->txtEmp->setText("");
                    }
                }
            }
        }
    }
void Library::on_btnLimparEmp_clicked()
{
    ui->txtEmp->setText("");
    ui->empISBN->setText("");
    ui->empUser->setText("");
    ui->noEmp->setText("");
}

void Library::on_btnDev_clicked()
{
    QString is = ui->isbnDev->text();
    QString cp = ui->cpfDev->text();
    std::string li_dev = is.toStdString();
    std::string cpf = cp.toStdString();

    for(unsigned int i = 0; i < p_dev.size(); i++) {
        if (li_dev == p_dev[i].getISBN()) {
            for (unsigned int j = 0; j < usuario.size(); j++) {
                if (cpf == usuario[j].getCpf()) {
                    usuario[j].dev_livro(p_dev[i]);
                    p_emp.push_back(p_dev[i]);
                    p_dev.erase(p_dev.begin()+i);
                    ui->devLivro->setText("Operaçao realizada com sucesso!");
                    ui->isbnDev->setText("");
                    ui->cpfDev->setText("");
                } else {
                    ui->devLivro->setText("CPF nao existe!");
                }
            }
        } else {
            ui->devLivro->setText("Livro nao existente!");
        }
    }

}
void Library::on_btnCleanDev_clicked()
{
    ui->isbnDev->setText("");
    ui->cpfDev->setText("");
}
void Library::on_btnAcervo_clicked()
{
    string acervo = "";
    if (livro.size() == 0) {
        ui->txtAcervo->setText("A Biblioteca nao possui nenhum livro");
    } else {
        for (unsigned int i = 0; i < livro.size(); i++) {
        string tit = livro[i].getTitulo();
        string aut = livro[i].getAutor();
        string is = livro[i].getISBN();
        acervo += "Titulo: " + tit + "\n" + "Autor: " + aut + "\n"
                + "ISBN: " + is + "\n\n";

            }

    ui->txtAcervo->setText(QString::fromStdString(acervo));
    ui->txtNumber->setText("Numero de livros: ");
    }
    int n = livro.size();
    QString num = QString::number(n);
    ui->livrosNumber->setText(num);
}




#include "librarymainwindow.h"
#include "ui_librarymainwindow.h"

LibraryMainWindow::LibraryMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibraryMainWindow)
{
    ui->setupUi(this);
};

LibraryMainWindow::~LibraryMainWindow()
{
    delete ui;
}

void LibraryMainWindow::on_btnEntrar_clicked()
{
    QString login = ui->txtLogin_2->text();
    QString senha = ui->txtSenha_2->text();

    if (login == "abc" && senha == "123") {

        Library *lib = new Library(this);
        lib->show();

    } else {
        ui->acesso->setText("Acesso negado!");
    }
}

void LibraryMainWindow::on_btnLimpar_clicked()
{
    ui->txtLogin_2->setText("");
    ui->txtSenha_2->setText("");
}

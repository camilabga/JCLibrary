#ifndef LIBRARY_H
#define LIBRARY_H

#include <QMainWindow>
#include "funcionario.h"
#include "livro.h"
#include "usuario.h"

namespace Ui {
    class Library;
}

class Library : public QMainWindow
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = 0);
    ~Library();

private slots:
    void on_cadasFunc_clicked();

    void on_mostrarFunc_clicked();

    void on_limpFunc_clicked();

    void on_pushButton_clicked();

    void on_limparLivro_clicked();


    void on_btnSearch_clicked();

    void on_btnLimparExclud_clicked();

    void on_btnExclud_clicked();

    void on_btnCadasUser_clicked();

    void on_btnLimparUser_clicked();

    void on_btnSearchUser_clicked();

    void on_btnCleanUser_clicked();

    void on_btnExcludUser_clicked();

    void on_btnShowUser_clicked();

    void on_btnEmpDisp_clicked();

    void on_btnAcervo_clicked();

    void on_btnEmp_clicked();

    void on_btnDev_clicked();

    void on_btnLimparEmp_clicked();

    void on_btnCleanDev_clicked();

private:
    Ui::Library *ui;
    vector<Funcionario> funcionarios;
    vector<Livro> livro;
    vector<Usuario> usuario;
    vector<Livro>p_emp;
    vector<Livro>p_dev;
};

#endif // LIBRARY_H

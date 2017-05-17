#ifndef LIBRARYMAINWINDOW_H
#define LIBRARYMAINWINDOW_H

#include <QMainWindow>
#include "library.h"
#include "funcionario.h"
#include "livro.h"
#include "usuario.h"

namespace Ui {
    class LibraryMainWindow;
}

class LibraryMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibraryMainWindow(QWidget *parent = 0);
    ~LibraryMainWindow();

private slots:
    void on_btnEntrar_clicked();

    void on_btnLimpar_clicked();

private:
    Ui::LibraryMainWindow *ui;
};

#endif // LIBRARYMAINWINDOW_H

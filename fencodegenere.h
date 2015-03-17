#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H
#include <QtGui>
#include <QtWidgets>

class FenCodeGenere : public QDialog
{
public:
    FenCodeGenere(QString &code, QString &codeCPP, QWidget *parent);

private:
    QTextEdit *codeGenere;
    QTextEdit *texteH;
    QTextEdit *texteCPP;
    QPushButton *fermer;
    QTabWidget *onglets;
};

#endif // FENCODEGENERE_H

#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QtGui>
#include <QtWidgets>

class FenCodeGenere : public QDialog
{
public:
    FenCodeGenere(QString &code, QWidget *parent);

private:
    QTextEdit *codeGenere;
    QTextEdit *codeGenereCpp;
    QPushButton *fermer;
};

#endif // FENCODEGENERE_H

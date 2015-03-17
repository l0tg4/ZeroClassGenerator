#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtGui>
#include <QtWidgets>

class FenPrincipale : public QWidget
{
    Q_OBJECT

public:
    FenPrincipale();

private slots:
    void genererCode();

private:
    QCheckBox *protections;
    QCheckBox *genererConstructeur;
    QCheckBox *genererDestructeur;
    QGroupBox *groupComments;
    QLineEdit *nom;
    QLineEdit *classeMere;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *role;
    QPushButton *generer;
    QPushButton *quitter;
};

#endif // FENPRINCIPALE_H

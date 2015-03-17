#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString &code, QWidget *parent = 0) : QDialog(parent)
{
    QTabWidget *onglets = new QTabWidget;
    onglets->setGeometry(30, 20, 240, 160);

    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;

    codeGenere = new QTextEdit();
    codeGenere->setPlainText(code);
    codeGenere->setReadOnly(true);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    codeGenereCpp = new QTextEdit();
    codeGenereCpp->setPlainText(code);
    codeGenereCpp->setReadOnly(true);
    codeGenereCpp->setFont(QFont("Courier"));
    codeGenereCpp->setLineWrapMode(QTextEdit::NoWrap);

    fermer = new QPushButton("Fermer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeGenere);
    layoutPrincipal->addWidget(fermer);
    page1->setLayout(layoutPrincipal);

    QVBoxLayout *layoutSecondaire = new QVBoxLayout;
    layoutSecondaire->addWidget(codeGenereCpp);
    page2->setLayout(layoutSecondaire);

    onglets->addTab(page1, "Test");
    onglets->addTab(page2, "Icule");

    resize(500, 500);
    setLayout(layoutPrincipal);


    connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
}

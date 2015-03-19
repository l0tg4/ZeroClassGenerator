#include "fencodegenere.h"

FenCodeGenere::FenCodeGenere(QString &code, QString &codeCPP, QWidget *parent = 0) : QDialog(parent)
{
/**
    codeGenere = new QTextEdit();
    codeGenere->setPlainText(code);
    codeGenere->setReadOnly(true);
    codeGenere->setFont(QFont("Courier"));
    codeGenere->setLineWrapMode(QTextEdit::NoWrap);

    fermer = new QPushButton("Fermer");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(codeGenere);
    layoutPrincipal->addWidget(fermer);

    resize(500, 500);

    setLayout(layoutPrincipal);

    connect(fermer, SIGNAL(clicked()), this, SLOT(accept()));
**/


    //création QTabWidget
    onglets = new QTabWidget();
    onglets->resize(450,450);

    //création du contenu des pages de widgets

    //page 1
    texteH = new QTextEdit(onglets);
    texteH->setPlainText(code);
    texteH->setReadOnly(true);
    texteH->setFont(QFont("Courier"));
    texteH->setLineWrapMode(QTextEdit::NoWrap);

    //page 2
    texteCPP = new QTextEdit(onglets);
    texteCPP->setPlainText(codeCPP);
    texteCPP->setReadOnly(true);
    texteCPP->setFont(QFont("Courier"));
    texteCPP->setLineWrapMode(QTextEdit::NoWrap);

    //ajout des onglets au QTabWidget en indiquant la page qu'ils contiennent
    onglets->addTab(texteH, "Fichier H");
    onglets->addTab(texteCPP, "Fichier CPP");

    onglets->show();
}

#include "fenprincipale.h"
#include "fencodegenere.h"

FenPrincipale::FenPrincipale()
{

    //Groupe : Définition de la classe
    nom = new QLineEdit;
    classeMere = new QLineEdit;

    QFormLayout *definitionLayout = new QFormLayout;
    definitionLayout->addRow("&Nom :", nom);
    definitionLayout->addRow("Classe &mère", classeMere);

    QGroupBox *groupDefinition = new QGroupBox("Définition de la classe");
    groupDefinition->setLayout(definitionLayout);


    //Groupe : Options

    protections = new QCheckBox("Protéger le &header contre les inclusions multiples");
    protections->setChecked(true);
    genererConstructeur = new QCheckBox("Générer un &constructeur par défaut");
    genererDestructeur = new QCheckBox("Générer un &destructeur");

    QVBoxLayout *optionsLayout = new QVBoxLayout;
    optionsLayout->addWidget(protections);
    optionsLayout->addWidget(genererConstructeur);
    optionsLayout->addWidget(genererDestructeur);

    QGroupBox *groupOptions = new QGroupBox("Options");
    groupOptions->setLayout(optionsLayout);



    //Groupe : Commentaires

    auteur = new QLineEdit;
    date = new QDateEdit;
    date->setDate(QDate::currentDate());
    role = new QTextEdit;

    QFormLayout *commentairesLayout = new QFormLayout;
    commentairesLayout->addRow("&Auteur :", auteur);
    commentairesLayout->addRow("&Date :", date);
    commentairesLayout->addRow("&Rôle de la classe :", role);

    groupComments = new QGroupBox("Ajout des commentaires");
    groupComments->setCheckable(true);
    groupComments->setChecked(false);
    groupComments->setLayout(commentairesLayout);


    //Bouton générer, quitter
    generer = new QPushButton("&Générer");
    quitter = new QPushButton("&Quitter");

    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->setAlignment(Qt::AlignRight);

    boutonsLayout->addWidget(generer);
    boutonsLayout->addWidget(quitter);


    //Définition du layout principal

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(groupDefinition);
    layoutPrincipal->addWidget(groupOptions);
    layoutPrincipal->addWidget(groupComments);
    layoutPrincipal->addLayout(boutonsLayout);

    setLayout(layoutPrincipal);
    setWindowTitle("Zero Class Generator");
    resize(500, 500);

    //Connexion des slots et des signaux
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(generer, SIGNAL(clicked()), this, SLOT(genererCode()));

}


void FenPrincipale::genererCode()
{
    //on vérifie que le nom de la classe n'est pas vide, sinon on arrête
    if(nom->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer au moins un nom de classe");
    return;
    }

    //si tout va bien, on génère le code
    QString code;
    QString codeCPP;

    if (groupComments->isChecked()) //on a demandé à inclure les commentaires
    {
        code += "/*\nAuteur : " + auteur->text() + "\n";
        code += "Date de création : " + date->date().toString() + "\n\n";
        code += "Rôle :\n" + role->toPlainText() + "\n*/\n\n\n";
    }

    if (protections->isChecked())
    {
        code += "#ifndef HEADER_" + nom->text().toUpper() + "\n";
        code += "#define HEADER_" + nom->text().toUpper() + "\n\n\n";
    }

    code += "class " + nom->text();

    if(!classeMere->text().isEmpty())
    {
        code += " : public " + classeMere->text();
    }

    code += "\n{\n      public:\n";

    if(genererConstructeur->isChecked())
    {
        code += "       " + nom->text() + "();\n";
    }

    if(genererDestructeur->isChecked())
    {
        code += "       ~" + nom->text() + "();\n";
    }

    code += "\n\n       protected:\n";
    code += "\n\n       private:\n";
    code += "};\n\n";

    if(protections->isChecked())
    {
        code += "#endif\n";
    }

    //on crée puis affiche la fenêtre qui affichera le code généré, qu'on lui envoie en paramètre
    FenCodeGenere *fenetreCode = new FenCodeGenere(code, codeCPP, this);
//    fenetreCode->exec();
}

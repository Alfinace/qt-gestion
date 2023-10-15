#include "dialogformstudent.h"
#include "ui_dialogformstudent.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

DialogFormStudent::DialogFormStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFormStudent)
{
    ui->setupUi(this);
}

DialogFormStudent::~DialogFormStudent()
{
    delete ui;
}

void DialogFormStudent::on_btnSave_clicked()
{
    QString firstname = this->ui->firstname->text();
    QString lastname = this->ui->lastname->text();
    QString datenaissance = this->ui->datenaissance->text();
    QString sexe = this->ui->sexeCombobox->currentText();
    if(con().open()){
        QSqlQuery query;

       // Prepare the INSERT query with placeholders
       query.prepare("INSERT INTO eleve (prenom, nom, datenaissance, sexe) VALUES (:prenom, :nom, :datenaissance, :sexe)");

       // Bind values to the placeholders
       query.bindValue(":prenom", firstname); // Replace "John" with the actual first name you want to insert
       query.bindValue(":nom",lastname); // Replace "Doe" with the actual last name you want to insert
       query.bindValue(":datenaissance", datenaissance); // Replace with the actual date of birth
       query.bindValue(":sexe", sexe); // Replace with the actual gender

       // Execute the query
       if (query.exec()) {
           qDebug() << "Insertion successful";
           QMessageBox::information(this,"Information","Nouveau elèvé a été bien ajouté avec succès");
           this->ui->firstname->clear();
           this->ui->lastname->clear();
           this->ui->datenaissance->clear();

       } else {
           qDebug() << "Insertion failed: " << query.lastError().text();
           QMessageBox::information(this,"Erreur","Erreur d'ajout elévé");
       }
    }

}

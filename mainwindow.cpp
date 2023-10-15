#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogformstudent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->on_load_student_list();
}

MainWindow::~MainWindow()
{
    con().close();
    delete ui;
}


void MainWindow::on_addbtn_clicked()
{
    DialogFormStudent *dialog = new DialogFormStudent(this);
    connect(dialog, &QDialog::finished, this, &MainWindow::on_load_student_list);
    dialog->show();
}

void MainWindow::on_load_student_list(){
    int row = 0;
    this->ui->StudentList->clear();
    this->ui->StudentList->setRowCount(0);
    if (con().open()) {
        QSqlQuery query;
        query.exec("SELECT * FROM eleve");

        int row = 0;

        // Clear the existing data in the table if needed
        this->ui->StudentList->clear();
        this->ui->StudentList->setRowCount(0);

        // Set header labels
        QStringList headers; // Create a QStringList to hold header labels
        headers << "ID" << "Last Name" << "First Name" << "Sex" << "Date of Birth"; // Add header labels for your columns
        this->ui->StudentList->setHorizontalHeaderLabels(headers);
        int totalWidth = this->ui->StudentList->viewport()->width();
           int columnCount = this->ui->StudentList->columnCount();
           int columnWidth = 200;

           // Set the calculated width for each column
           for (int column = 0; column < columnCount; ++column) {
               this->ui->StudentList->setColumnWidth(column, columnWidth);
           }
        while (query.next()) {
            QString id = query.value("id").toString();
            QString firstname = query.value("prenom").toString();
            QString lastname = query.value("nom").toString();
            QString datenais = query.value("datenaissance").toString();
            QString sexe = query.value("sexe").toString();

            this->ui->StudentList->insertRow(row);

            QTableWidgetItem *idItem = new QTableWidgetItem(id);
            QTableWidgetItem *firstnameItem = new QTableWidgetItem(firstname);
            QTableWidgetItem *lastnameItem = new QTableWidgetItem(lastname);
            QTableWidgetItem *sexeItem = new QTableWidgetItem(sexe);
            QTableWidgetItem *datenaisItem = new QTableWidgetItem(datenais);

            this->ui->StudentList->setItem(row, 0, idItem);
            this->ui->StudentList->setItem(row, 1, lastnameItem);
            this->ui->StudentList->setItem(row, 2, firstnameItem);
            this->ui->StudentList->setItem(row, 3, sexeItem);
            this->ui->StudentList->setItem(row, 4, datenaisItem);

            ++row;
        }

        con().close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->on_load_student_list();
}

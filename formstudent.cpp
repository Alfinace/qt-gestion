#include "formstudent.h"
#include "ui_formstudent.h"

FormStudent::FormStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormStudent)
{
    ui->setupUi(this);
}

FormStudent::~FormStudent()
{
    delete ui;
}

void FormStudent::on_btnClose_clicked()
{
    this->close();
}

#ifndef DIALOGFORMSTUDENT_H
#define DIALOGFORMSTUDENT_H

#include <QDialog>
#include "connection_mysql.h"
#include <QMessageBox>
namespace Ui {
class DialogFormStudent;
}

class DialogFormStudent : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogFormStudent(QWidget *parent = 0);
    ~DialogFormStudent();
    
private slots:
    void on_btnSave_clicked();

private:
    Ui::DialogFormStudent *ui;
};

#endif // DIALOGFORMSTUDENT_H

#ifndef FORMSTUDENT_H
#define FORMSTUDENT_H

#include <QWidget>

namespace Ui {
class FormStudent;
}

class FormStudent : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormStudent(QWidget *parent = 0);
    ~FormStudent();
    
private slots:
    void on_btnClose_clicked();

private:
    Ui::FormStudent *ui;
};

#endif // FORMSTUDENT_H

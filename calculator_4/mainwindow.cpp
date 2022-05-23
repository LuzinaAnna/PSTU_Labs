 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_answer_clicked()//Дествия после нажатия кнопки "Решить систему"
{
    //Заполение матрицы для решения методом Крамера
    double mas[3][4];
            mas[0][0]=this->ui->a1->toPlainText().toDouble();
            mas[1][0]=this->ui->a2->toPlainText().toDouble();
            mas[2][0]=this->ui->a3->toPlainText().toDouble();
            mas[0][1]=this->ui->b1->toPlainText().toDouble();
            mas[1][1]=this->ui->b2->toPlainText().toDouble();
            mas[2][1]=this->ui->b3->toPlainText().toDouble();
            mas[0][2]=this->ui->c1->toPlainText().toDouble();
            mas[1][2]=this->ui->c2->toPlainText().toDouble();
            mas[2][2]=this->ui->c3->toPlainText().toDouble();
            mas[0][3]=this->ui->d1->toPlainText().toDouble();
            mas[1][3]=this->ui->d2->toPlainText().toDouble();
            mas[2][3]=this->ui->d3->toPlainText().toDouble();
            double alpha,alpha_x,alpha_y,alpha_z;
            //Поиск определителей матрицы
            alpha=mas[0][0]*mas[1][1]*mas[2][2]+mas[0][1]*mas[1][2]*mas[2][0]+mas[1][0]*mas[2][1]*mas[0][2]-(mas[0][2]*mas[1][1]*mas[2][0]+mas[1][0]*mas[0][1]*mas[2][2]+mas[2][1]*mas[0][0]*mas[1][2]);
            alpha_x=mas[0][3]*mas[1][1]*mas[2][2]+mas[0][1]*mas[1][2]*mas[2][3]+mas[1][3]*mas[2][1]*mas[0][2]-(mas[0][2]*mas[1][1]*mas[2][3]+mas[1][3]*mas[0][1]*mas[2][2]+mas[2][1]*mas[0][3]*mas[1][2]);
            alpha_y=mas[0][0]*mas[1][3]*mas[2][2]+mas[0][3]*mas[1][2]*mas[2][0]+mas[1][0]*mas[2][3]*mas[0][2]-(mas[0][2]*mas[1][3]*mas[2][0]+mas[1][0]*mas[0][3]*mas[2][2]+mas[2][3]*mas[0][0]*mas[1][2]);
            alpha_z=mas[0][0]*mas[1][1]*mas[2][3]+mas[0][1]*mas[1][3]*mas[2][0]+mas[1][0]*mas[2][1]*mas[0][3]-(mas[0][3]*mas[1][1]*mas[2][0]+mas[1][0]*mas[0][1]*mas[2][3]+mas[2][1]*mas[0][0]*mas[1][3]);
            //Обработка частных случаев
            if (alpha != 0)
            {
                ui->kolichestvo_resheni->setText("Единственное решение");
                ui->x_answer->setText(QString::number(alpha_x/alpha));
                 ui->y_answer->setText(QString::number(alpha_y/alpha));
                 ui->z_answer->setText(QString::number(alpha_z/alpha));
            }
            else
            {
                if((alpha_x != 0)&&(alpha_y != 0)&&(alpha_z != 0))
                {
                    ui->kolichestvo_resheni->setText("Решений нет");
                    ui->x_answer->setText(" ");
                     ui->y_answer->setText(" ");
                     ui->z_answer->setText(" ");
                }
                if((alpha_x == 0)||(alpha_y == 0)||(alpha_z == 0))
                {
                    ui->kolichestvo_resheni->setText("Бесконечное множество решений");
                    ui->x_answer->setText(" ");
                     ui->y_answer->setText(" ");
                     ui->z_answer->setText(" ");
                }
            }
}


void MainWindow::on_answer_2_clicked()//Действия после нажатия кнопки "Очистить"
{
    ui->a1->clear();
    ui->a2->clear();
    ui->a3->clear();
    ui->b1->clear();
    ui->b2->clear();
    ui->b3->clear();
    ui->c1->clear();
    ui->c2->clear();
    ui->c3->clear();
    ui->d1->clear();
    ui->d2->clear();
    ui->d3->clear();
    ui->x_answer->clear();
    ui->y_answer->clear();
    ui->z_answer->clear();
    ui->kolichestvo_resheni->clear();
}


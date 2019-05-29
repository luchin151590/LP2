#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include<QtCore>
#include<QtGui>
#include <QPainter>
#include <QPixmap>
#include <QPen>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    void draw_circle(QPainter *painter);
    void draw_square(QPainter *painter);
    void draw_triangle(QPainter *painter);

private:
    Ui::MainWindow *ui;
    QPixmap *pixmap;//creamo el atributo de area
    QPainter *painter;
    QPen *pen;

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkError_clicked();

    void on_beautifyButton_clicked();

    void on_convertButton_clicked();

    void on_compressButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

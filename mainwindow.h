#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void updateOKButtonState();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    double getGuess() const;
    void setImgName(const QString &name);

private:
    Ui::MainWindow *ui;
    double getWeight(const QString &input);
};

#endif // MAINWINDOW_H

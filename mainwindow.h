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
    void startNewGame();

private slots:
    void updateOKButtonState();
    void handleOKButton();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setImgName(const QString &name);

private:
    Ui::MainWindow *ui;
    int getWeight(const QString &input) const;
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateOKButtonState()
{
    ui->pushButton_ok->setDisabled(ui->lineEdit_guess->text().isEmpty());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateOKButtonState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::getGuess
 * \return
 */
double MainWindow::getGuess() const
{

}

/*!
 * \brief MainWindow::setImgName
 * \param name
 */
void MainWindow::setImgName(const QString &name)
{

}

double MainWindow::getWeight(const QString &input)
{

}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

void MainWindow::startNewGame(){
    qDebug() << "not implemented!";
}

void MainWindow::updateOKButtonState()
{
    ui->pushButton_ok->setDisabled(ui->lineEdit_guess->text().trimmed().isEmpty());
    ui->lineEdit_guess->setStyleSheet(""); //set default StyleSheet
}

void MainWindow::handleOKButton()
{
    int weight = getWeight(ui->lineEdit_guess->text().trimmed());
    if (weight != -1) {

    } else {
        //set lineEdit background lightred
        ui->lineEdit_guess->setStyleSheet("background-color: #F5A9A9");
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_ok, SIGNAL(clicked(bool)), this, SLOT(handleOKButton()));
    connect(ui->actionQuit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(ui->actionNew_game, SIGNAL(triggered(bool)), this, SLOT(startNewGame()));

    updateOKButtonState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::setImgName sets the image lable
 * \param name of the image
 */
void MainWindow::setImgName(const QString &name)
{
    ui->label_imgName->setText(name.trimmed());
}

int MainWindow::getWeight(const QString &input) const
{
    QRegularExpression regex("\\A([1-9][0-9]{0,2})[ ]?(mg|g|kg)\\z");
    regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch match = regex.match(input);

    if (match.hasMatch()) {
        double weight = match.captured(1).toDouble();
        const QString unit = match.captured(2).toLower();
        if (unit == "g") {
            weight *= 1000;
        } else if (unit == "kg") {
            weight *= 1000000;
        }
        return weight;
    }
    return -1; //no valid match
}

#ifndef UDP_RECIVER_H
#define UDP_RECIVER_H

#include "qeventloop.h"
#include <QMainWindow>
#include <QDebug>
#include <QUdpSocket>
#include <QThread>



QT_BEGIN_NAMESPACE
namespace Ui {
class Udp_reciver;
}
QT_END_NAMESPACE

class Udp_reciver : public QMainWindow
{
    Q_OBJECT

public:
    Udp_reciver(QWidget *parent = nullptr);
    ~Udp_reciver();
protected:
    void closeEvent(QCloseEvent *event) override {
        qDebug() << event ;
        allok=-1;
    }
private slots:
    void readDatagrams();
    void sendData();
    void on_pushButton_clicked();
signals:
    void recive_data();
    void sendnewdata();
private:
    Ui::Udp_reciver *ui;
    QUdpSocket *socket2,*socket1;



    QVector <double> f_list;
    QVector <double> yy_data;
    QEventLoop eventLoop;
    quint16 targetPort =6500; // Change to your target port


    int allok=-1;


};
#endif // UDP_RECIVER_H

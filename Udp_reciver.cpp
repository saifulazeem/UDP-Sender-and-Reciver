#include "Udp_reciver.h"
#include "ui_Udp_reciver.h"
#include "QTimer"

Udp_reciver::Udp_reciver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Udp_reciver)
{
    ui->setupUi(this);

    socket2 = new QUdpSocket(this);
    //QString hostid="10.42.0.1";
    //socket2->bind(QHostAddress::LocalHost, 4021); // Bind to localhost on port 2500
    socket2->bind(QHostAddress::Any, 9000); // Bind to the specified local host address and port 7
    //ui->radioButton_2->setStyleSheet("QRadioButton::indicator {width: 15px; height: 15px;border-radius: 7px; background-color: #1bc43a; }");
    qDebug() << " Port set  :  ";
    f_list={400,700,2500,4200};


    connect(socket2, &QUdpSocket::readyRead, this, &Udp_reciver::readDatagrams);

    //QTimer *timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, this, &Udp_reciver::sendData);
    //timer->start(1000); // Send every 1000 milliseconds (1 second)
}

Udp_reciver::~Udp_reciver()
{
    delete ui;
}

void Udp_reciver::sendData() {

    for(int i =0; i<f_list.size(); ++i){

        // if(i==3){
        //     i=0;
        // }
        socket1= new QUdpSocket(this);


        QByteArray datagram;
        QString fq= QString::number(f_list[i]);
        datagram.append(fq.toUtf8());  // Convert QString to QByteArray and append it

        // Define the target address and port
        QHostAddress targetAddress("192.168.18.77"); // Change to your target IP address
        quint16 targetPort =6500; // Change to your target port

        // Send the datagram
        qint64 bytesWritten = socket1->writeDatagram(datagram, targetAddress, targetPort);

        if (bytesWritten == -1) {
            qCritical() << "Failed to send datagram:" << socket1->errorString();
        } else {
            qDebug() << "Datagram sent:" << bytesWritten << "bytes. with data gram"<< datagram;
            socket1->close();
            //QThread::sleep(5);

            //readDatagrams();

        }

    }
}

void Udp_reciver::readDatagrams() {

    while (socket2->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket2->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        socket2->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        //qDebug() << " Recived Complete Data Gram  :  "<< datagram;

        //qDebug() << " Recived Complete Data Gram  :  "<< datagram.size();

        qDebug() << " Recived ------------------------------------------------------------------------";

        datagram=datagram.toHex();
        //qDebug() << " Recived Complete Data Gram  :  "<< datagram;

        int chunkSize = 8;

        for (int i = 0; i < datagram.size(); i += chunkSize) {

            QString chunk = datagram.mid(i, chunkSize);

            QString hexString =chunk;

            bool ok;
            int intValue = hexString.toInt(&ok, 16);  // 16 indicates hexadecimal base

            if (ok) {
                //qDebug() << "The integer value of :"<<chunk << "IS" << intValue;
                yy_data.append(intValue);
            } else {
                qDebug() << "Conversion failed.";
            }

        }
        qDebug()<< "Recive packet :: " <<yy_data;
        yy_data.clear();
        qDebug() << "=====================================================================END of PACKET=======================================================================";
    }
}

void Udp_reciver::on_pushButton_clicked()
{
    //connect(this, &Udp_reciver::recive_data, this, &Udp_reciver::readDatagrams);
    //connect(this, &Udp_reciver::sendnewdata, this, &Udp_reciver::sendData);
    //emit this->sendnewdata();
    sendData();


}


#include <QCoreApplication>
#include <QDebug>

#include "logger.h"

Logger logger;

void logHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMetaObject::invokeMethod(
        &logger,
        "log",
        Qt::AutoConnection,
        Q_ARG(QtMsgType, type),
        Q_ARG(QMessageLogContext, context),
        Q_ARG(QString, msg)
    );
}

int main(int argc, char **argv)
{
    qInstallMessageHandler(logHandler);
    QCoreApplication app(argc, argv);
    qDebug() << "hello world";
    return app.exec();
}

#include <QCoreApplication>
#include <QDebug>

#include "logger.h"

Logger * logger = nullptr;

void logHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logger == nullptr)
        return;

    QMetaObject::invokeMethod(
        logger,
        "log",
        Qt::AutoConnection,
        Q_ARG(QtMsgType, type),
        Q_ARG(QMessageLogContext, context),
        Q_ARG(QString, msg)
    );
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    logger = new Logger(&app);
    qInstallMessageHandler(logHandler);
    qDebug() << "hello world";
    return app.exec();
}

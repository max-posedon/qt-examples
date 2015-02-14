#include "logger.h"

#include <iostream>

Logger::Logger(QObject * parent): QObject(parent)
{
};

void Logger::log(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    std::cout << "[" << type << ":" << qPrintable(context.file) << ":" << context.line << "] " << qPrintable(msg) << std::endl << std::flush;  
};

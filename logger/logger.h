#include <QObject>

class Logger : public QObject
{
    Q_OBJECT

public:
    Logger(QObject * parent = 0);

public slots:
    void log(QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

#ifndef ASCIIART_BACKEND_H
#define ASCIIART_BACKEND_H

#include <QObject>

namespace AsciiArt {

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

public slots:
    QString generateAsciiArt(QString &input);
};

} // namespace AsciiArt

#endif // ASCIIART_BACKEND_H

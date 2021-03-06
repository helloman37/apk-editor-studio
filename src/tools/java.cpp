#include "tools/java.h"
#include "base/application.h"
#include <QRegularExpression>

Java::Java(QObject *parent) : Java(app->getJavaBinaryPath("java"), parent) {}

QString Java::version()
{
    QStringList arguments;
    arguments << "-version";
    auto result = startSync(arguments);
    if (!result.success) {
        return QString();
    }
    QRegularExpression regex("version \"(.+)\"");
    const QString version = regex.match(result.value).captured(1);
    return version;
}

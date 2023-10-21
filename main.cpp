/* Include System Classes*/

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>

/* Include user classes*/

#include "systeminfo.h"
#include "systemtheme.h"
#include "shortcuts.h"
#include "imgprovider.h"
#include "Models/appsmodel.h"



#include <initguid.h>
#include <mmdeviceapi.h>
#include <audiopolicy.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;



    ImgProvider *etcProvider = new ImgProvider();
    etcProvider->setBaseUrl(QUrl("qrc:///images/"));
    engine.addImageProvider("etc", etcProvider);


    /*Register Context Properties */

    SystemInfo *systemInfo = new SystemInfo();
    engine.rootContext()->setContextProperty("gSystemInfo",systemInfo);

    SystemTheme *systemTheme = new SystemTheme();
    engine.rootContext()->setContextProperty("gSystemTheme",systemTheme);

    Shortcuts *shortcuts = new Shortcuts();
    engine.rootContext()->setContextProperty("gShortcuts",shortcuts);


    AppsModel *appsModel = new AppsModel();
    engine.rootContext()->setContextProperty("gAppsModel",appsModel);

    /* Load QML File */

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}

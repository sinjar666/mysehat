#include "mainwidget.h"

#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    g_digicam_init(&argc,&argv);
    app.setAttribute(Qt::AA_NativeWindows);
    app.setApplicationName(QString("My Sehat"));
    app.setApplicationVersion(QString("1.0.0"));
    app.setOrganizationName(QString("Code Demons"));
    MainWidget mainWidget;
    mainWidget.setAttribute(Qt::WA_Maemo5LandscapeOrientation);
    mainWidget.setAttribute(Qt::WA_Maemo5StackedWindow);
    mainWidget.show();
    return app.exec();
}

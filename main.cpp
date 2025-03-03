#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>
#include "parameters.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the main window
    QWidget mainWindow;
    mainWindow.setMinimumHeight(600);
    mainWindow.setMinimumWidth(600);
    QVBoxLayout mainLayout(&mainWindow);

    // Create the stacked widget
    QStackedWidget stackedWidget;
    mainLayout.addWidget(&stackedWidget);

    // Create the first page
    QWidget par;
    QVBoxLayout layout1(&par);
    QLabel label1("Page 1");
    Parameters *pars = new Parameters;
    layout1.addWidget(pars);
    stackedWidget.addWidget(&par);

    // Create the second page
    QWidget page2;
    QVBoxLayout layout2(&page2);
    QLabel label2("Page 2");
    layout2.addWidget(&label2);
    QPushButton button2("Button 2");
    layout2.addWidget(&button2);
    stackedWidget.addWidget(&page2);

    auto switchToPage1 = [&]() { stackedWidget.setCurrentIndex(0); };
    // Function to switch to page 2
    auto switchToPage2 = [&]() { stackedWidget.setCurrentIndex(1); };

    // Connect button1 to switch to page 2
    QObject::connect(&button2, &QPushButton::clicked, switchToPage1);

    // Set the initial page
    stackedWidget.setCurrentIndex(0);

    mainWindow.show();
    return a.exec();
}

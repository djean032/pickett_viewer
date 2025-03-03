#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDebug>
#include <QFileDialog>
#include <QGridLayout>
#include <QWidget>
#include "utils.h"
class Button;

class Parameters : public QWidget
{
    Q_OBJECT
public:
    explicit Parameters(QWidget *parent = nullptr);
    QVector<param> parameters;

private slots:
    void load_param_file();

private:
    template<typename PointerToMemberFunction>
    Button *createButton(const QString &text, const PointerToMemberFunction &member);
};

#endif // PARAMETERS_H

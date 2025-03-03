#include "parameters.h"
#include "button.h"

Parameters::Parameters(QWidget *parent)
    : QWidget{parent}
{
    QGridLayout *mainLayout = new QGridLayout;
    Button *loadParams = createButton(tr("Load Parameters"), &Parameters::load_param_file);
    mainLayout->addWidget(loadParams);
    setLayout(mainLayout);
}

void Parameters::load_param_file()
{
    QString filename = QFileDialog::getOpenFileName(nullptr, tr("Select .par file"));
    qDebug() << filename;
};

template<typename PointerToMemberFunction>
Button *Parameters::createButton(const QString &text, const PointerToMemberFunction &member)
{
    Button *button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}

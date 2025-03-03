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
    QFile file(filename);
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&file);
        // First Line
        QString line = in.readLine();
        line = in.readLine();
        line = in.readLine();
        while (!in.atEnd()) {
            QString line = in.readLine();
            param tmp = process_line(line);
            parameters.append(tmp);
        }
    } else {
        qDebug() << "Error Reading File!\n";
        return;
    }

};

template<typename PointerToMemberFunction>
Button *Parameters::createButton(const QString &text, const PointerToMemberFunction &member)
{
    Button *button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}

param Parameters::process_line(QString &line) {
    param tmp;
    QString tmp_str(line);
    tmp.name = tmp_str.left(13).trimmed();
    tmp_str.remove(0, 13);
    //tmp.value = tmp_str.left(21).trimmed();
    qDebug() << tmp_str.left(24).trimmed().toDouble();
    tmp_str.remove(0, 24);
    //tmp.tolerance = tmp_str.left(10).trimmed();
    qDebug() << tmp.name << "\n" << tmp.value << "\n" << tmp.tolerance << "\n\n";
    return tmp;
}



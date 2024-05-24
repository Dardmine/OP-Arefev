#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>
#ifndef PARENT_H
#define PARENT_H
#include "data.h"
#endif


namespace Ui {
class Diagram;
}

class Diagram : public QDialog
{
    Q_OBJECT

public:
    explicit Diagram(QWidget *parent = nullptr);
    ~Diagram();

public slots:
    void recieveDiagramVector(std::vector<_Data> dataList);

private slots:
    void on_Diagram_finished(int result);

private:
    Ui::Diagram *ui;
};


#endif // DIAGRAM_H

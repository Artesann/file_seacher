#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void scanFile(QString, QString);

    void scanDirectory(QString, QString);

    void push_extend(QString);

    void pop_extend(QString);

    void on_txtCheck_clicked();

    void on_htmlCheck_clicked();

    void on_xmdCheck_clicked();

    void on_xmlCheck_clicked();

    void on_xamlCheck_clicked();

    void on_xmsCheck_clicked();

    void on_addExtend_clicked();

    void on_reset_clicked();

    void on_startSearch_clicked();

    void on_chooseDirectory_clicked();

    void on_xslCheck_clicked();

    void on_jsCheck_clicked();

    void on_cssCheck_clicked();

    void on_phpCheck_clicked();

    void on_jsonCheck_clicked();

    void on_pyCheck_clicked();

    void on_iniCheck_clicked();

    void on_logCheck_clicked();

    void on_htaCheck_clicked();

    void on_batCheck_clicked();

    void on_cCheck_clicked();

    void on_cppCheck_clicked();

private:
    Ui::MainWindow *ui;
    QStringList extends;
    int filesCount;
};

#endif // MAINWINDOW_H

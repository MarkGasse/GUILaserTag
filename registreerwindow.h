#ifndef REGISTREERWINDOW_H
#define REGISTREERWINDOW_H

#include <QDialog>
#include "QString"
/// @file

/// \brief
///
/// \details
///
namespace Ui {
class registreerWindow;
}

/// \brief
///
/// \details
///
class registreerWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::registreerWindow *ui;

private slots:
    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonRegistreer_clicked();

public:
    /// \brief
    ///
    /// \details
    ///
    explicit registreerWindow(QWidget *parent = nullptr);

    /// \brief
    ///
    /// \details
    ///
    ~registreerWindow();

};

#endif // REGISTREERWINDOW_H

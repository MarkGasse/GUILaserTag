//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================
/// @file

#ifndef REGISTREERWINDOW_H
#define REGISTREERWINDOW_H

#include <QDialog>
#include "QString"

namespace Ui {
class registreerWindow;
}

/// \brief
/// registreerWindow class
/// \details
/// implements a pop-up window to register a user, inherits from QDialog.
class registreerWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::registreerWindow *ui;

private slots:
    /// \brief
    /// Register button
    /// \details
    /// Checks if both passwords match and confirms the users' registration.
    void on_pushButtonRegistreer_clicked();

public:
    /// \brief
    /// registreerWindow constructor
    /// \details
    /// default Qt constructor, takes a QWidget as parent which is a nullptr by default.
    explicit registreerWindow(QWidget *parent = nullptr);

    /// \brief
    /// default destructor.
    ~registreerWindow();

};

#endif // REGISTREERWINDOW_H

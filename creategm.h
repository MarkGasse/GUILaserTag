//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================

#ifndef CREATEGM_H
#define CREATEGM_H

#include <QDialog>

/// @file

namespace Ui {
class CreateGM;
}

/// \brief
/// CreateGM class
/// \details
/// implements a pop-up window to create a gamemode, inherits from QDialog.
class CreateGM : public QDialog
{
    Q_OBJECT

private:
    Ui::CreateGM *ui;

private slots:

    /// \brief
    /// Cancel create gamemode
    /// \details
    /// Opens startwindow and deletes creategm window
    void on_pushButtonCancel_clicked();

    /// \brief
    /// create new gamemode
    /// \details
    /// Writes the created gamemode to a file
    /// And writes the new gamemode to the the gamemode file.
    void on_pushButtonCreate_clicked();

public:
    /// \brief
    /// default constructer
    /// \details
    ///  The constructor sets the UI layout.
    ///  Sets the options in the comboboxes.
    explicit CreateGM(QWidget *parent = nullptr);

    /// \brief
    /// deconstructer CreateGM
    /// \details
    /// deletes CreateGM
    ~CreateGM();

};

#endif // CREATEGM_H

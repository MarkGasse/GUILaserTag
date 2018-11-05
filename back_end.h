//==========================================================
// Nico van Bentum | nico.vanbentum@student.hu.nl
// Mark Gasse      | mark.gasse@student.hu.nl
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//==========================================================

#ifndef BACK_END_H
#define BACK_END_H

#include <QMainWindow>

/// @file

extern bool closeUI;

namespace Ui {
class Back_End;
}

/// \brief
/// Back_End class
/// \details
/// Implements a window as background.
class Back_End : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Back_End *ui;

public:
    /// \brief
    /// default constructor
    /// \details
    ///  The constructor sets the UI layout.
    explicit Back_End(QWidget *parent = nullptr);

    /// \brief
    /// deconstructor Back_End
    /// \details
    /// deletes Back_End
    ~Back_End();

};

#endif // BACK_END_H

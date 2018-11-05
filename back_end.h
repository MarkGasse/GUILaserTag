#ifndef BACK_END_H
#define BACK_END_H

#include <QMainWindow>

/// @file

extern bool closeUI;


/// \brief
///
/// \details
///
namespace Ui {
class Back_End;
}

/// \brief
///
/// \details
///
class Back_End : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Back_End *ui;

public:
    /// \brief
    ///
    /// \details
    ///
    explicit Back_End(QWidget *parent = nullptr);
    /// \brief
    ///
    /// \details
    ///
    ~Back_End();

};

#endif // BACK_END_H

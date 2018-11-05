#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "searchplayerwindow.h"
#include "back_end.h"
#include "creategm.h"
#include "QKeyEvent"
#include <QTimer>
/// @file

/// \brief
///
/// \details
///
namespace Ui {
class StartWindow;
}

/// \brief
///
/// \details
///
class StartWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::StartWindow *ui;
    QTimer *timer;
    SearchPlayerWindow *searchW;
    CreateGM *CreateW;
    Back_End *B;

private slots:
    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonStart_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonDelete_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonCreate_clicked();

    /// \brief
    ///
    /// \details
    ///
    void on_CloseGUI_clicked();

protected:
    /// \brief
    ///
    /// \details
    ///
    void keyPressEvent(QKeyEvent *event);

public:
    /// \brief
    ///
    /// \details
    ///
    explicit StartWindow(QWidget *parent = nullptr);

    /// \brief
    ///
    /// \details
    ///
    ~StartWindow();

public slots:

    /// \brief
    ///
    /// \details
    ///
    void timerFunction();

};

#endif // STARTWINDOW_H


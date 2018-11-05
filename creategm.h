#ifndef CREATEGM_H
#define CREATEGM_H

#include <QDialog>

/// @file

/// \brief
///
/// \details
///
namespace Ui {
class CreateGM;
}

/// \brief
///
/// \details
///
class CreateGM : public QDialog
{
    Q_OBJECT

private:
    Ui::CreateGM *ui;

private slots:
    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonCancel_clicked();
    /// \brief
    ///
    /// \details
    ///
    void on_pushButtonCreate_clicked();

public:
    /// \brief
    ///
    /// \details
    ///
    explicit CreateGM(QWidget *parent = nullptr);
    /// \brief
    ///
    /// \details
    ///
    ~CreateGM();

};

#endif // CREATEGM_H

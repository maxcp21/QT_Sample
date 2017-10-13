#include <QtGui/QtGui>
#include "logindlg.h"

CLoginDlg::CLoginDlg(QWidget* parent)
 :	QDialog(parent)
{
        QLabel* usrLabel = new QLabel(tr("�Τ�W"));
        QLabel* pwdLabel = new QLabel(tr("�K�X"));
        usrLineEdit = new QLineEdit;
        pwdLineEdit = new QLineEdit;
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        QGridLayout* gridLayout = new QGridLayout;
        gridLayout->addWidget(usrLabel, 0, 0, 1, 1);
        gridLayout->addWidget(usrLineEdit, 0, 1, 1, 3);
        gridLayout->addWidget(pwdLabel, 1, 0, 1, 1);
        gridLayout->addWidget(pwdLineEdit, 1, 1, 1, 3);

        QPushButton* okBtn = new QPushButton(tr("�T�w"));
        QPushButton* cancelBtn = new QPushButton(tr("����"));
        QHBoxLayout* btnLayout = new QHBoxLayout;
        btnLayout->setSpacing(60);
        btnLayout->addWidget(okBtn);
        btnLayout->addWidget(cancelBtn);

        QVBoxLayout* dlgLayout = new QVBoxLayout;
        dlgLayout->setMargin(40);
        dlgLayout->addLayout(gridLayout);
        dlgLayout->addStretch(40);
        dlgLayout->addLayout(btnLayout);
        setLayout(dlgLayout);

        connect(okBtn, SIGNAL(clicked()), this, SLOT(accept()));
        connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));

        setWindowTitle(tr("�n��"));
        resize(300, 200);
}

CLoginDlg::~CLoginDlg()
{
        delete usrLineEdit;
        delete pwdLineEdit;
}

void CLoginDlg::accept()
{
        if(usrLineEdit->text().trimmed() == tr("lcf")
                && pwdLineEdit->text() == tr("lcf"))
        {
                QDialog::accept();
        }
        else
        {
                QMessageBox::warning(this,
                tr("ĵ�i"),
                tr("�Τ�W�αK�X���~�I"),
                QMessageBox::Yes);
                usrLineEdit->setFocus();
        }

}
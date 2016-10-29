#ifndef __KANARIE_UI_SETTINGS_ACCOUNTS_HPP__
#define __KANARIE_UI_SETTINGS_ACCOUNTS_HPP__

#include "ui_accounts.h"

namespace KanarieUI 
{
    namespace Settings {
        class Accounts : public QWidget
        {
            Q_OBJECT
            public:
                Accounts(QWidget *parent);
            private:
                Ui::AccountSettings ui;
        };
    }
}

#endif

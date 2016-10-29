/*
Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License or (at your option) version 3 or any later version
accepted by the membership of KDE e.V. (or its successor approved
by the membership of KDE e.V.), which shall act as a proxy 
defined in Section 14 of version 3 of the license.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// application headers
#include "kanarie.hpp"

// KDE headers
#include <KActionCollection>
#include <KConfigDialog>

#include "ui/settings/accounts.hpp"

Kanarie::Kanarie()
    : KXmlGuiWindow(),
      postArea(new KanarieUI::PostArea(this))
{
    setCentralWidget(postArea);

    KStandardAction::quit(
        qApp, SLOT(closeAllWindows()), actionCollection()
    );
    KStandardAction::preferences(
        this, SLOT(settingsConfigure()), actionCollection()
    );
    
    setupGUI();
}

Kanarie::~Kanarie()
{
}

void Kanarie::settingsConfigure()
{
    qCDebug(KANARIE) << "Kanarie::settingsConfigure()";
    
    if (KConfigDialog::showDialog(QStringLiteral("settings"))) {
        return;
    }
    
    KConfigDialog *settingsDialog = new KConfigDialog(
        this, 
        QStringLiteral("settings"), 
        KanarieSettings::self()
    );
    
    settingsDialog->addPage(
        new KanarieUI::Settings::Accounts(settingsDialog),
        i18n("Accounts"),
        QStringLiteral("package_setting")
    );
    settingsDialog->setAttribute(Qt::WA_DeleteOnClose);
    settingsDialog->show();
    qCDebug(KANARIE) << "Kanarie::settingsConfigure(): settingsDialog->show()";
    
    /*
    QWidget *generalSettingsDialog = new QWidget;
    settingsBase.setupUi(generalSettingsDialog);
    dialog->addPage(generalSettingsDialog, i18n("General"), QStringLiteral("package_setting"));
    */
    /*
    connect(dialog, SIGNAL(settingsChanged(QString)), m_kanarieView, SLOT(slotSettingsChanged()));
    */
}


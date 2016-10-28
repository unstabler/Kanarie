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

#ifndef KANARIE_H
#define KANARIE_H

#include <QLoggingCategory>
#include <KXmlGuiWindow>

#include "ui_kanarieViewBase.h"
#include "ui_settingsBase.h"
#include "KanarieSettings.h"
#include "kanarieview.h"

Q_DECLARE_LOGGING_CATEGORY(KANARIE)

/**
 * This class serves as the main window for kanarie.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author %{AUTHOR} <%{EMAIL}>
 * @version %{VERSION}
 */
class Kanarie : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    Kanarie();

    /**
     * Default Destructor
     */
    virtual ~Kanarie();

private slots:
    /**
     * Create a new window
     */
    void fileNew();

    /**
     * Open the settings dialog
     */
    void settingsConfigure();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::settingsBase settingsBase;
    Ui::kanarieViewBase kanarieViewBase;
    QAction *m_switchAction;
    KanarieView *m_kanarieView;
};

#endif // KANARIE_H

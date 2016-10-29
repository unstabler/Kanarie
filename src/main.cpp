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

// application header
#include "kanarie.hpp"

// KDE headers
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QLoggingCategory>

#define KANARIE_APP_VERSION  "0"
#define KANARIE_APP_CODENAME "Shirohto"

Q_DECLARE_LOGGING_CATEGORY(KANARIE)
Q_LOGGING_CATEGORY(KANARIE, "kanarie")

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("kanarie");
    KAboutData aboutData(QStringLiteral("kanarie"),
                         i18n("Kanarie"),
                         QString("%1 \"%2\"").arg(KANARIE_APP_VERSION, KANARIE_APP_CODENAME),
                         i18n("ついったーくらいあんと"),
                         KAboutLicense::GPL_V3,
                         i18n("(c) 2016 cheesekun★ <doping.cheese@gmail.com>"),
                         i18n("Inspired by <a href=\"http://azurea.info\">Azurea for Windows</a>"),
                         QStringLiteral("http://kanarie.unstabler.pl"));

    aboutData.addAuthor(QStringLiteral("cheesekun★ (@cheese_rulez)"), 
                        i18n("Author"), 
                        QStringLiteral("doping.cheese@gmail.com"), 
                        QStringLiteral("https://twitter.com/cheese_rulez"));
    
    
    application.setWindowIcon(QIcon::fromTheme("kanarie"));
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(application);
    aboutData.processCommandLine(&parser);
    KAboutData::setApplicationData(aboutData);

    Kanarie *appwindow = new Kanarie;
    appwindow->show();
    return application.exec();
}

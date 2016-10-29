#ifndef __KANARIE_UI_POSTAREA_HPP__
#define __KANARIE_UI_POSTAREA_HPP__

#include "ui_postarea.h"

namespace KanarieUI 
{
    class PostArea : public QWidget 
    {
        Q_OBJECT
        public:
            const static int DEF_STATUS_MAX_LENGTH = 140;
            const static int DEF_DIRECTMESSAGE_MAX_LENGTH = 10000;
            
            PostArea(QWidget* parent, const int maxLength);
            PostArea(QWidget* parent);
            
            void updateLengthBar();
            
        signals:
            /**
             * 
             */
            void requestUpdateStatus();
            
        public slots:
            void contentChanged();
            
            
        private slots:
            /**
             * 
             */
            void requestUpdateStatusInternal();
            
        private:
            QString getStatusText();
            
            Ui::PostArea ui;
            int maxLength;
    };
}

#endif

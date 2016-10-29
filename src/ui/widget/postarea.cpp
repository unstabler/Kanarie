#include "postarea.hpp"

namespace KanarieUI {
    
    PostArea::PostArea(QWidget *parent, const int maxLength)
        : QWidget(parent),
          maxLength(maxLength)
    {
        ui.setupUi(this);
        
        // sets maximum length to statusLengthBar
        ui.statusLengthBar->setMaximum(maxLength);
        
        connect(
            ui.statusTextEdit, SIGNAL(textChanged()),
            this, SLOT(contentChanged())
        );
        connect(
            ui.updateStatusButton, SIGNAL(clicked()),
            this, SLOT(requestUpdateStatusInternal())
        );
    }
    
    PostArea::PostArea(QWidget* parent)
        : PostArea(parent, DEF_STATUS_MAX_LENGTH) 
    {
        
    }
    
    
    void PostArea::requestUpdateStatusInternal() 
    {
        // ' ')?
        emit requestUpdateStatus();
    }
    
    void PostArea::contentChanged() 
    {
        updateLengthBar();
    }
    
    void PostArea::updateLengthBar()
    {
        auto contentLength = getStatusText().length();
        auto lengthDiff    = maxLength - contentLength;
        
        ui.statusLengthBar->setValue(
            (lengthDiff >= 0) ? contentLength : maxLength
        );
        ui.statusLengthBar->setFormat(QString::number(lengthDiff));
        
        if (lengthDiff > 0) {
            // TODO: Plasma에서 색상표를 가져와 NegativeTextColor로 설정하시오
        }
    }
    
    QString PostArea::getStatusText() {
        return ui.statusTextEdit->toPlainText();
    }
    
}

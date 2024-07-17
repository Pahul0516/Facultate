#pragma once
#include <qwidget.h>
#include <qpainter.h>

#include "controller.h"

class Desenare: public QWidget, public Observer
{
private:
    controller* contr;

public:

    Desenare(controller* contr){
        this->contr = contr;
        contr->addObserver(this);
    }

    void update()override
    {
        repaint();
    }

    void paintEvent(QPaintEvent* ev) override
    {
        int i = 0;
        QPainter p{ this };
        repository repo = contr->contr_get_activitati(*contr);
        for (auto ac : repo.get_all())
        {
            if (ac.get_titlu() == "Fotbal")
            {
                QImage image("fotbal.jpg");
                QImage resizedImage = image.scaled(100, 100);
                p.drawImage(i+100, 1, resizedImage);
            }
            else
            {
                if (ac.get_titlu() == "Tenis")
                {
                    QImage image("tenis.jpg");
                    QImage resizedImage = image.scaled(100, 100);
                    p.drawImage(i + 100, 1, resizedImage);
                }
                else
                {
                    if (ac.get_titlu() == "Inot")
                    {
                        QImage image("inot.jpg");
                        QImage resizedImage = image.scaled(100, 100);
                        p.drawImage(i + 100, 1, resizedImage);
                    }
                    else
                    {
                        if (ac.get_titlu() == "Volei")
                        {
                            QImage image("volei.jpg");
                            QImage resizedImage = image.scaled(100, 100);
                            p.drawImage(i + 100, 1, resizedImage);
                        }
                        else
                        {
                            if (ac.get_titlu() == "Cantec")
                            {
                                QImage image("cantec.jpg");
                                QImage resizedImage = image.scaled(100, 100);
                                p.drawImage(i + 100, 1, resizedImage);
                            }
                            else
                            {
                                if (ac.get_titlu() == "Stand_up")
                                {
                                    QImage image("stand_up.jpg");
                                    QImage resizedImage = image.scaled(100, 100);
                                    p.drawImage(i + 100, 1, resizedImage);
                                }
                                else
                                {
                                    if (ac.get_titlu() == "Nunta")
                                    {
                                        QImage image("nunta.jpg");
                                        QImage resizedImage = image.scaled(100, 100);
                                        p.drawImage(i + 100, 1, resizedImage);
                                    }
                                    else
                                    {

                                        QImage image("altceva.jpg");
                                        QImage resizedImage = image.scaled(100, 100);
                                        p.drawImage(i + 100, 1, resizedImage);

                                    }
                                }
                            }
                        }
                    }
                }
            }
            i = i + 100;
        }

    }
};


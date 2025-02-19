//
// Created by vovab on 14.02.2025.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H


#include <QRect>
#include <iostream>
#include <QPoint>
#include <QSize>

 const int cell_width = 4;
 const int cell_height = 4;

 class Cell : public QRect{

public:
    bool is_alive;

    QSize size = QSize(cell_width, cell_height);


    bool isAlive() const;

    void setIsAlive(bool isAlive);

    Cell(const QPoint topleft);

    Cell(const QPoint topleft, bool isAlive);

};


#endif //GAMEOFLIFE_CELL_H

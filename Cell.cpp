//
// Created by vovab on 14.02.2025.
//

#include "Cell.h"


bool Cell::isAlive() const {
    return is_alive;
}

void Cell::setIsAlive(bool isAlive) {
 is_alive = isAlive;
}

Cell::Cell(const QPoint topleft) : QRect(topleft, size){}

Cell::Cell(const QPoint topleft, bool isAlive) : QRect(topleft, size), is_alive(isAlive) {};
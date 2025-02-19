//
// Created by vovab on 13.02.2025.
//

#ifndef GAMEOFLIFE_SIMULATION_H
#define GAMEOFLIFE_SIMULATION_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QColor>
#include <QBrush>
#include <random>
#include <iostream>
#include "Cell.h"

const int window_width = 900;
const int window_height = 700;


class Simulation : public QWidget {
 public:

    Simulation(QWidget *parent = nullptr);

    void fillGrid();

 protected:

    void paintEvent(QPaintEvent *event) override;

private:

    std::vector<std::vector<Cell>> cells;

    bool randomIsAlive();


    bool intsInBounds(int x, int y);

    void delay();

};


#endif //GAMEOFLIFE_SIMULATION_H

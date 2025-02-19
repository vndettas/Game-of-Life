//
// Created by vovab on 13.02.2025.
//

#include "Simulation.h"

Simulation::Simulation(QWidget *parent) : QWidget(parent), cells(window_width, std::vector<Cell>(window_height, Cell(QPoint(0, 0), randomIsAlive()))) {
    setWindowTitle("Convays simulation");
    resize(window_width, window_height);
    setPalette(QPalette(QColor(104, 104, 104), QColor(64, 64, 64)));
    fillGrid();

}

void Simulation::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(QColor(255,255,0)));
    int neighbours_count = 0;
        for (int r = 0; r < cells.size(); r++) {
            for (int i = 0; i < cells[r].size(); i++) {
                neighbours_count = 0;
                Cell cell = cells[r][i];
                if (cell.isAlive()) painter.drawRect(cell);
                if (intsInBounds(r, i - 1) && cells[r][i - 1].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r, i + 1) && cells[r][i + 1].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r + 1, i) && cells[r + 1][i].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r - 1, i) && cells[r - 1][i].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r - 1, i - 1) && cells[r - 1][i - 1].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r - 1, i + 1) && cells[r - 1][i + 1].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r + 1, i + 1) && cells[r + 1][i + 1].isAlive()) {
                    neighbours_count++;
                }
                if (intsInBounds(r + 1, i - 1) && cells[r + 1][i - 1].isAlive()) {
                    neighbours_count++;
                }
                if((!cell.isAlive()) && neighbours_count == 3){
                    cells[r][i].setIsAlive(true);
                }
                if (cell.isAlive() && (neighbours_count < 2 || neighbours_count > 3)) {
                    cells[r][i].setIsAlive(false);
                }
                }
        }
        delay();

        return update();
    }

// 2 itr to track position in 2d vector
//2 for loop to handle where the left top point will be created
//based on this point the square will be created
void Simulation::fillGrid() {
    int itr2 = window_height;
    for(int h = window_width; h >= 0; h -= cell_width){
        itr2--;
        int itr = cells[itr2].size()-1;
        for(int w = window_height; w >= 0;w -=cell_height){
            QPoint tmp = QPoint(h, w);
            Cell cell = Cell(tmp, randomIsAlive());
            cells[itr2][itr] = cell;
            itr--;
        }
    }
}

bool Simulation::randomIsAlive() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 12);
    return (dis(gen) - 1) == 3;   // decrease density
}

bool Simulation::intsInBounds(int x, int y) {
    return (x >= 0 && x <= cells[0].size()) && (y >= 0 && y <= cells.size());
}

void Simulation::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(75);
    while (QTime::currentTime() < dieTime){};
}



//
// Created by Ao on 2020-02-04.
//

#ifndef LAYERED_INFLUENCE_MAP_IMLAYER_H
#define LAYERED_INFLUENCE_MAP_IMLAYER_H


class IMLayer {

public:
    IMLayer(){};

    virtual void init(int start_x, int start_y, int width, int height) {
        set_offset(start_x, start_y);
        set_dimens(width, height);
    }
    virtual void set_offset(int start_x, int start_y) {
        this->start_x = start_x;
        this->start_y = start_y;
    }
    virtual void set_dimens(int width, int height) {
        this->width = width;
        this->height = height;
    }

    virtual double get_value_at(int x, int y) {
        return 0;
    }

    int start_x;
    int start_y;
    int width;
    int height;
};


#endif //LAYERED_INFLUENCE_MAP_IMLAYER_H

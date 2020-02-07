//
// Created by Ao on 2020-02-04.
//

#include "IMLayerConvolve.h"


IMLayerConvolve::IMLayerConvolve() {
}

void IMLayerConvolve::set_inputs(IMLayer* input, IMLayer* kernel) {
    if (kernel->width % 2 == 1 && kernel->height % 2 == 1) {
        this->input = input;
        this->kernel = kernel;
    }
}

double IMLayerConvolve::get_value_at(int x, int y) {
    int rel_x = x - this->start_x;
    int rel_y = y - this->start_y;

    if (rel_x >= 0 && rel_x < this->width && rel_y >= 0 && rel_y < this->height) {
        // For Godot implementation, also need to make sure input->is_valid() && kernel->is_valid()
        double result = 0;

        for (int kern_y = 0; kern_y < kernel->height; kern_y++) {
            for (int kern_x = 0; kern_x < kernel->width; kern_x++) {
                result += input->get_value_at(rel_x + (kern_x - kernel->width / 2), rel_y + (kern_y - kernel->height / 2)) * kernel->get_value_at(kernel->start_x + kern_x, kernel->start_y + kern_y);
            }
        }

        return result;
    } else {
        return 0;
    }
}
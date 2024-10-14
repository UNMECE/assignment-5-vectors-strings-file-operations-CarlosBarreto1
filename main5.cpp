#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "pixel.h"


void read_file(std::string filename, std::vector<Pixel> &pixel_list) {
    std::ifstream infile(filename);
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        Pixel p;

        std::string x_str, y_str, r_str, g_str, b_str;

        std::getline(ss, x_str, ',');
        std::getline(ss, y_str, ',');
        std::getline(ss, r_str, ',');
        std::getline(ss, g_str, ',');
        std::getline(ss, b_str, ',');

        p.x = std::stoi(x_str);
        p.y = std::stoi(y_str);
        p.r = std::stof(r_str);
        p.g = std::stof(g_str);
        p.b = std::stof(b_str);

    
        pixel_list.push_back(p);
    }
}

void average_colors(std::vector<Pixel> &pixel_list) {
    float total_r = 0.0, total_g = 0.0, total_b = 0.0;
    int pixel_count = pixel_list.size();

    for (const auto &p : pixel_list) {
        total_r += p.r;
        total_g += p.g;
        total_b += p.b;
    }

    std::cout << "Average R: " << total_r / pixel_count << std::endl;
    std::cout << "Average G: " << total_g / pixel_count << std::endl;
    std::cout << "Average B: " << total_b / pixel_count << std::endl;
}

void flip_vertically(std::vector<Pixel> &pixel_list) {
    int height = 256; 

    for (auto &p : pixel_list) {
        
        p.y = (height-1) - p.y;

        }
      
}

void save_to_file( const std::string &filename,const std::vector<Pixel> &pixel_list) {
    std::ofstream outfile(filename);

    for (auto &p : pixel_list) {
        outfile << p.x << "," << p.y << "," << p.r << "," << p.g << "," << p.b << std::endl;
    }

    outfile.close();

}


int main(int argc, char *argv[]){


    std::vector<Pixel> pixel_list;
    std::string input_file = argv[1];

    read_file(input_file, pixel_list);

    average_colors(pixel_list);

    flip_vertically(pixel_list);

    save_to_file("flipped.dat", pixel_list);


return 0;
}
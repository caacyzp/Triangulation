#include <iostream>
#include <glm/glm.hpp>
#include "triangulation.h"
#include "LinkedList.hpp"

#include <vector>


int main(int, char**) {
    glm::vec2 p[11] = {
        glm::vec2(1.9036,1.16768), // 0
        glm::vec2(1.69276,0.97371),  // 8
        glm::vec2(1.79396,0.72913),  // 8
        glm::vec2(1.51565,0.65323),  // 7
        glm::vec2(1.25421,0.7713),  // 6
        glm::vec2(0.73132,0.57732),  // 6
        glm::vec2(1.68432,0.33275),  // 5
        glm::vec2(1.42288,0.07974),  // 4
        glm::vec2(1.6, 0), // 3
        glm::vec2(1.34698,-0.22387), // 2
        glm::vec2(1.83613,-0.69616), // 1
    };

    std::vector<unsigned int> indices;

    Triangulation(p, 11, &indices);

}

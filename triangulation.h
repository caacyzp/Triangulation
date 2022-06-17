#include <glm/glm.hpp>
#include <vector>

bool isAntiClock(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3);
bool isWithinTriangle(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 testPoint);
int  Triangulation(glm::vec2* pointList, unsigned int lenth, std::vector<unsigned int>* index);
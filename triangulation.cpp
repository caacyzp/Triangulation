#include "triangulation.h"
#include "LinkedList.hpp"


bool isAntiClock(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3)
{
    glm::vec2 p1p2 = p2 - p1;
    glm::vec2 p1p3 = p3 - p1;

    float cross = p1p2.x * p1p3.y - p1p2.y * p1p3.x;

    if (cross > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isWithinTriangle(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3, glm::vec2 testPoint)
{
    bool triangleByP1P2P3IsAntiClock = isAntiClock(p1, p2, p3);

    glm::vec2 p1p2 = p2 - p1;
    glm::vec2 p2p3 = p3 - p2;
    glm::vec2 p3p1 = p1 - p3;

    if (triangleByP1P2P3IsAntiClock)
    {
        if (isAntiClock(p1,p2,testPoint) && isAntiClock(p2, p3, testPoint) && isAntiClock(p3, p1, testPoint))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (!isAntiClock(p1,p2,testPoint) && !isAntiClock(p2, p3, testPoint) && !isAntiClock(p3, p1, testPoint))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int Triangulation(glm::vec2* pointList, unsigned int lenth, std::vector<unsigned int>* indices)
{
    if (lenth < 3)
    {
        return -1;
    }
    else if (lenth == 3)
    {
        if (isAntiClock(pointList[0], pointList[1], pointList[2]))
        {
            *indices = {0, 1, 2};
        }
        else
        {
            *indices = {2, 1, 0};
        }
        return 0;
    }
    else
    {
        CustomeLinkedList::CircleLinkedList<glm::vec2> PolygonVerticies;
        for (unsigned int i = 0; i < lenth; i++)
        {
            PolygonVerticies.AddNodeToTail(pointList[i]);
        }

        bool firstRound = true;
        CustomeLinkedList::Node<glm::vec2>*  p1;
        CustomeLinkedList::Node<glm::vec2>*  p0;
        CustomeLinkedList::Node<glm::vec2>*  p2;
        while (PolygonVerticies.size() >=3)
        {
            if (firstRound)
            {
                p1 = PolygonVerticies.at(0);
                p0 = p1->previous;
                p2 = p1->next;
            }
            else
            {
                p1 = p2;
                p0 = p1->previous;
                p2 = p1->next;
            }

            bool hasPointInside = false;
            bool AntiClock      = isAntiClock(p0->data, p1->data, p2->data);
            CustomeLinkedList::Node<glm::vec2>* OtherNodeToTest = p2->next;
            while (OtherNodeToTest != p0)
            {
                hasPointInside = isWithinTriangle(p0->data, p1->data, p2->data, OtherNodeToTest->data);
                if (hasPointInside)
                {
                    break;
                }
                OtherNodeToTest = OtherNodeToTest->next;
            }
            if (AntiClock && !hasPointInside)
            {
                indices->push_back(p0->initial_index);
                indices->push_back(p1->initial_index);
                indices->push_back(p2->initial_index);
                PolygonVerticies.del(p1);
                firstRound = false;
            }
            else
            {
                firstRound = false;
            }
        }
    }
    return 0;
}

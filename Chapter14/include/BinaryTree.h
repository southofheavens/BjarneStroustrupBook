/*
    Определите класс Binary_tree, производный от класса Shape. Задайте параметр, задающий количество уровней
    (levels == 0 означает, что в дереве нет ни одного узла, levels == 1 означает, что в дереве есть один узел,
    levels == 2 означает, что дерево состоит из вершины и двух дочерних узлов, которые, в свою очередь, имеют
    по два дочерних узла, и т.д.). Пусть узел изображается маленьким кружочком. Соедините узлы линиями (как
    это принято).
    P.S. В компьютерных науках деревья изображаются растущими вниз от вершины (забавно, что ее часто называют
    корнем, хотя это и логично).
*/

#include "Graph.h"

unsigned int RADIUS_OF_NODE = 10;

using namespace Graph_lib;

class BinaryTree : public Shape
{
public:
    BinaryTree(unsigned int l) : levels{l} {}
    
    void draw_lines() const;
private:
    unsigned int levels;
};

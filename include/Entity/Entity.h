#ifndef _ENTITY_H_
#define _ENTITY_H_  

struct Position {
    int x;
    int y;
};
struct Size {
    int width;
    int height;
};
struct Properties {
    Position position;
    Size size;
    int weight;
};
class Entity{
public:
    virtual void init() = 0;
    virtual void render() = 0;
    virtual ~Entity() = default;
    Entity(Properties props) : properties(props), frameCount(0) {}
    void setPosition(Position pos) { properties.position = pos; }
    Position getPosition() const { return properties.position; }
    void setSize(Size size) { properties.size = size; }
    Size getSize() const { return properties.size; }
    void setWeight(int w) { properties.weight = w; }
    int getWeight() const { return properties.weight; }
protected:
    Properties properties;
    int frameCount; // Number of frames for animation
    int lastFrameTime; // Time of the last frame update
    
};

#endif // _ENTITY_H_
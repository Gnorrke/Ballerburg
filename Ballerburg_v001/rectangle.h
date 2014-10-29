#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:
    Rectangle(int x, int y, int width, int height) :
        posX(x),
        posY(y),
        width(width),
        height(height) {}

    int left() const { return posX; }
    int right() const { return posX + width; }
    int top() const { return posY; }
    int bottom() const { return posY + height; }

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    void reassign(int x, int y, int width, int height)
    {
        this->posX = x;
        this->posY = y;
        this->width = width;
        this->height = height;
    }

    bool collidesWith(const Rectangle& other) const
    {
        return right() >= other.left() &&
                left() <= other.right() &&
                top() <= other.bottom() &&
                bottom() >= other.top();
    }
private:
    int posX, posY, width, height;
};

#endif // RECTANGLE_H

#include <stdio.h>
#include <math.h>

class Point {
    public:
        float getX();
        float getY();
        void setX(float newX);
        void setY(float newY);
    private:
        float x;
        float y;
};

class Rectangle {
    public:
        int getFigureIndex();
        Point getLeftUpperPoint();
        Point getRightBottomPoint();
        void setLeftUpperPoint(Point point);
        void setRightBottonPoint(Point point);
        void setFigureIndex(int newIndex);
        bool inFigure(float pointX, float pointY);
    private:
        Point leftUpperPoint;
        Point rightBottomPoint;
        int index;
};

class Circle {
    public:
        int getFigureIndex();
        Point getCenterPoint();
        float getRadius();
        void setCenterPoint(Point point);
        void setRadius(float newRadius);
        void setFigureIndex(int newIndex);
        bool inFigure(float pointX, float pointY);
    private:
        Point centerPoint;
        float radius;
        int index;
};

void readRectangle(int, int, Rectangle*);
void readCircle(int, int, Circle*);
void checkInFigure(Rectangle*, int, Circle*, int, int, float, float);


int main(void) {
    char type;
    int countFigure = 0;
    int countRectangle = 0;
    int countCircle = 0;
    Rectangle* rectangles = new Rectangle[10];
    Circle* circles = new Circle[10];
    
    int countPoint = 1;
    float pointX;
    float pointY;
    
    while(scanf("%c", &type) == 1) {
        if (type == '*') {
            break;
        } else if (type == 'r') {
            readRectangle(countFigure, countRectangle, rectangles);
            countRectangle++;
            countFigure++;
        } else if (type == 'c') {
            readCircle(countFigure, countCircle, circles);
            countCircle++;
            countFigure++;
        } else {
            continue;
        }
    }
    
    while(scanf("%f %f\n", &pointX, &pointY) == 2) {
        if (pointX >= 9999 && pointY >= 9999) {
            break;
        } else {
            checkInFigure(rectangles, countRectangle, circles, countCircle,
                            countPoint, pointX, pointY);
            countPoint++;
        }
    }
    
    
    return 0;
}

void readRectangle(int figureIndex, int rectangleIndex, Rectangle* rectangles) {
    float leftUpperX;
    float leftUpperY;
    float rightBottomX;
    float rightBottomY;
    scanf("%f %f %f %f\n", &leftUpperX,
                            &leftUpperY,
                            &rightBottomX,
                            &rightBottomY);
    Point leftUpperPoint;
    leftUpperPoint.setX(leftUpperX);
    leftUpperPoint.setY(leftUpperY);
    
    Point rightBottomPoint;
    rightBottomPoint.setX(rightBottomX);
    rightBottomPoint.setY(rightBottomY);
    
    rectangles[rectangleIndex].setLeftUpperPoint(leftUpperPoint);
    rectangles[rectangleIndex].setRightBottonPoint(rightBottomPoint);
    rectangles[rectangleIndex].setFigureIndex(figureIndex);
}

void readCircle(int figureIndex, int circleIndex, Circle* circles) {
    float centerX;
    float centerY;
    float radius;
    scanf("%f %f %f\n", &centerX,
                        &centerY,
                        &radius);
   Point centerPoint;
   centerPoint.setX(centerX);
   centerPoint.setY(centerY);
   
   circles[circleIndex].setCenterPoint(centerPoint);
   circles[circleIndex].setRadius(radius);
   circles[circleIndex].setFigureIndex(figureIndex);
}

void checkInFigure(Rectangle* rectangles, int countRectangles,
                    Circle* circles, int countCircles, 
                    int index, float pointX, float pointY) {
    int belongSize = 0;                    
    for (int i = 0 ; i < countRectangles ; i++) {
        if (rectangles[i].inFigure(pointX, pointY)) {
            printf("Point %d is contained in figure %d\n",
                    index, rectangles[i].getFigureIndex() + 1);
            belongSize++;
        } else {
            continue;
        }
    }       
    
    for (int i = 0 ; i < countCircles ; i++) {
        if (circles[i].inFigure(pointX, pointY)) {
            printf("Point %d is contained in figure %d\n",
                    index, circles[i].getFigureIndex() + 1);
            belongSize++;
        } else {
            continue;
        }
    }    
        
    if (belongSize == 0) {
        printf("Point %d is not contained in any figure\n", index);
    }             
}



float Point::getX() {
    return x;
}

float Point::getY() {
    return y;
}

void Point::setX(float newX) {
    x = newX;
}

void Point::setY(float newY) {
    y = newY;
}

int Rectangle::getFigureIndex() {
    return index;
}


Point Rectangle::getLeftUpperPoint() {
    return leftUpperPoint;
}


Point Rectangle::getRightBottomPoint() {
    return rightBottomPoint;
}

void Rectangle::setLeftUpperPoint(Point point) {
    leftUpperPoint = point;
}

void Rectangle::setRightBottonPoint(Point point) {
    rightBottomPoint = point;
}

void Rectangle::setFigureIndex(int newIndex) {
    index = newIndex;
}

bool Rectangle::inFigure(float pointX, float pointY) {
    if (pointX > leftUpperPoint.getX() && pointX < rightBottomPoint.getX()
        && pointY > rightBottomPoint.getY() && pointY < leftUpperPoint.getY()) {
        return true;
    } else {
        return false;
    }
}

int Circle::getFigureIndex() {
    return index;
}

Point Circle::getCenterPoint() {
    return centerPoint;
}

float Circle::getRadius() {
    return radius;
}

void Circle::setCenterPoint(Point point) {
    centerPoint = point;    
}

void Circle::setRadius(float newRadius) {
    radius = newRadius;
}

void Circle::setFigureIndex(int newIndex) {
    index = newIndex;
}

bool Circle::inFigure(float pointX, float pointY) {
    double distance = sqrt(pow(pointX - centerPoint.getX(), 2) 
                        + pow(pointY - centerPoint.getY(), 2));
    
    if (distance < radius) {
        return true;
    } else {
        return false;
    }
}
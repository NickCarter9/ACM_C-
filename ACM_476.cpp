#include <stdio.h>

void checkInRectangle(int, float *, float *, float *, float *, int, float, float);

int main(void)
{
    char type;
    
    float* leftUpX = new float[10]();
    float* leftUpY = new float[10]();
    float* rightBottomX = new float[10]();
    float* rightBottomY = new float[10]();
    
    float pointX;
    float pointY;
    
    int rectangleIndex = 0;
    while(scanf("%c", &type) == 1) {
        if (type == 'r') {
            scanf("%f %f %f %f\n", &leftUpX[rectangleIndex],
                                    &leftUpY[rectangleIndex],
                                    &rightBottomX[rectangleIndex],
                                    &rightBottomY[rectangleIndex]);
        } else if (type == '*') {
            break;
        } else {
            continue;
        }
        rectangleIndex++;
    }
    
    int pointIndex = 1;
    while(scanf("%f %f\n", &pointX, &pointY) == 2) {
        if (pointX >= 9999 && pointY >= 9999) {
            break;
        } else {
            checkInRectangle(rectangleIndex, leftUpX, leftUpY, rightBottomX, rightBottomY,
                        pointIndex, pointX, pointY);
            pointIndex++;
        }
        // if ( pointX < 9999 && pointY < 9999) {
        //     checkInRectangle(rectangleIndex, leftUpX, leftUpY, rightBottomX, rightBottomY,
        //                 pointIndex, pointX, pointY);
        // } else {
        //     break;
        // }
    }
    return(0); 
}

void checkInRectangle(int rectangleSize, float* leftUpX, float* leftUpY, float* rightBottomX, float* rightBottomY,
                        int pointIndex, float pointX, float pointY) {
      int inRectangleTime = 0; 
      for (int i = 0; i <= rectangleSize ; i++) {
          if (pointX > leftUpX[i] && pointX < rightBottomX[i]
                && pointY > rightBottomY[i] && pointY < leftUpY[i]) {
                printf("Point %d is contained in figure %d\n", pointIndex, i+1);    
                inRectangleTime ++;    
           }
      }
      
      if (inRectangleTime == 0) {
          printf("Point %d is not contained in any figure\n", pointIndex);
      } 
}
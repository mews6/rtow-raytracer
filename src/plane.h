#indef PLANE_H
#define PLANE_H

#include 'hittable.h'

class plane : public hittable {
    plane(const point3& center, vec3 normal, double d) : center(center),  {}
}

#endif
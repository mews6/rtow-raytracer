#ifndef CUBE_H
#define CUBE_H

#include "hittable.h"
#include "vec3.h"
#include "interval.h"

class cube : public hittable {
    cube(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}
    
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        

        auto s1 = center+(radius/2) * vec3::vec3(-1,-1,-1); 
        auto s2 = center+(radius/2) * vec3::vec3(-1,1,-1); 
        auto s3 = center+(radius/2) * vec3::vec3(1,1,-1); 
        auto s4 = center+(radius/2) * vec3::vec3(1,-1,-1); 
        auto s5 = center+(radius/2) * vec3::vec3(-1,-1,1); 
        auto s6 = center+(radius/2) * vec3::vec3(-1,1,1); 
        auto s7 = center+(radius/2) * vec3::vec3(1,1,1); 
        auto s8 = center+(radius/2) * vec3::vec3(1,-1,1); 

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    };



    }

    private:
        point3 center;
        double radius;
};

#endif
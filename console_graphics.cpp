//
// Created by casper on 10/6/2021.
//

#include "console_graphics.h"

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

namespace vectorGraphics {

    /* Vec3D definitions */

    Vec3D::Vec3D(float x, float y, float z):
            x(x),y(y),z(z){}
    Vec3D::Vec3D(): x(0.),y(0.),z(0.){}

    void Vec3D::show(std::string const& label) const{std::cout << label << ":\t" << x << " " << y << ' ' << z << std::endl;}
    void Vec3D::show(std::string const& label, float scalar){std::cout << label << ":\t" << std::fixed << std::setprecision(3) << scalar << std::endl;}
    void Vec3D::show(){std::cout << std::endl;}
    std::ostream &operator<<(std::ostream &os, const Vec3D &d) {
        os << "x: " << d.x << " y: " << d.y << " z: " << d.z;
        return os;
    }

    Vec3D Vec3D::minus() const {return {-x,-y,-z};}
    Vec3D Vec3D::add(Vec3D const &other) const {return {x+other.x,y+other.y,z+other.z};}
    Vec3D Vec3D::sub(Vec3D const &other) const {return {x-other.x,y-other.y,z-other.z};}
    Vec3D Vec3D::mul(float scalar) const {return {x*scalar,y*scalar,z*scalar};}
    Vec3D Vec3D::div(float scalar) const {return {x/scalar,y/scalar,z/scalar};}
    float Vec3D::norm() const {return std::sqrt(x*x + y*y + z*z);}
    Vec3D Vec3D::unit() const {float n = 1/norm(); return {x*n, y*n, z*n};}
    float Vec3D::dot(Vec3D const &other) const {return x*other.x + y*other.y + z*other.z;}
    Vec3D Vec3D::cross(Vec3D const &other) const {return {y*other.z - z*other.y, -(x*other.z - z*other.x), x*other.y - y*other.x};}

    /* Override Vec3D operators */
    bool operator== (const Vec3D &self, const Vec3D &other) {
        if(self.x == other.x && self.y == other.y && self.z == other.z)
            return true;    return false;}
    Vec3D Vec3D::operator- () const {return minus();}
    Vec3D Vec3D::operator+ (const Vec3D &other) const {return add(other);}
    Vec3D Vec3D::operator- (const Vec3D &other) const {return sub(other);}
    Vec3D Vec3D::operator* (float scalar) const {return mul(scalar);}
    Vec3D Vec3D::operator/ (float scalar) const {return div(scalar);}

    /* Ray definitions */

    Ray::Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir):
            support(Vec3D(xSup,ySup,zSup)), direction(Vec3D(xDir,yDir,zDir)) {}
    Ray::Ray(const Vec3D &support, const Vec3D &direction) : support(support), direction(direction) {}

    std::ostream &operator<<(std::ostream &os, const Ray &ray) {
        os << "support: " << ray.support << " direction: " << ray.direction;
        return os;
    }


    /* Sphere definitions */

    Sphere::Sphere(float x, float y, float z, float radius):
            center(Vec3D(x,y,z)), radius(radius){}

    Sphere::Sphere(const Vec3D &center, float radius) : center(center), radius(radius) {}

    std::ostream &operator<<(std::ostream &os, const Sphere &sphere) {
        os << "center: " << sphere.center << " radius: " << sphere.radius;
        return os;
    }

    //calculate the point on the ray axis that is nearest to the circle.

    Vec3D Sphere::hitPoint(Ray const &ray) const{

        // if direction and support are the same coordinate, then that is the nearest point.
        //literature: https://stackoverflow.com/questions/31696533/c-get-point-on-3d-vector-with-shortest-distance-to-given-point
        if(ray.direction == ray.support){
            return ray.direction;
        }

        Vec3D x1x0 = ray.direction - center;
        Vec3D x1x2 = ray.direction - ray.support;

        float t;
        t = x1x0.dot(x1x2) / pow(x1x2.norm(), 2);

        if(t <= 0)
            return ray.direction;
        else if(t >= 1)
            return ray.support;
        else
            return ray.direction + x1x2 * t;
    }
    //find the distance between center of circle and closest point to ray. subtract from eachother and get the norm of that.
    float Sphere::distFromRay(Ray const &ray) const{return (hitPoint(ray) - center).norm();}

    bool Sphere::hit(Ray const &ray) const{
        if(distFromRay(ray) > radius){
            return false;
        }
        else if(ray.direction.norm() > radius || ray.support.norm() > radius)
            return true;
        return false;
    };

    float Sphere::getRadius() const {return radius;}

    /* Canvas definitions */

}

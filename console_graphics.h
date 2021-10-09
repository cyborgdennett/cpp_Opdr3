//
// Created by casper on 10/6/2021.
//

#ifndef CPP_OPDR3_CONSOLE_GRAPHICS_H
#define CPP_OPDR3_CONSOLE_GRAPHICS_H

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

namespace vectorGraphics {
    class Sphere;

    class Vec3D{
    public:
        Vec3D(float x, float y, float z);
        Vec3D();

        friend std::ostream &operator<<(std::ostream &os, const Vec3D &d);
        void show(std::string const& label) const;
        static void show(std::string const& label, float scalar);
        static void show();

        Vec3D minus() const;
        Vec3D add(Vec3D const &other) const;
        Vec3D sub(Vec3D const &other) const;
        Vec3D mul(float scalar) const;
        Vec3D div(float scalar) const;
        float norm() const;
        Vec3D unit() const;
        float dot(Vec3D const &other) const;
        Vec3D cross(Vec3D const &other) const;

        friend bool operator== (const Vec3D &self, const Vec3D &other);
        Vec3D operator- () const;
        Vec3D operator+ (const Vec3D &other) const;
        Vec3D operator- (const Vec3D &other) const;
        Vec3D operator* (float scalar) const;
        Vec3D operator/ (float scalar) const;

    protected:
        float x,y,z;
    };


//        RAY
    class Ray{
        friend class Sphere;
    public:
        Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir);

        Ray(const Vec3D &support, const Vec3D &direction);

        friend std::ostream &operator<<(std::ostream &os, const Ray &ray);

    protected:
        Vec3D support;
        Vec3D direction;
    };


//        SPHERE
    class Sphere{
    public:
        Sphere(float x, float y, float z, float radius);

        Sphere(const Vec3D &center, float radius);

        friend std::ostream &operator<<(std::ostream &os, const Sphere &sphere);

        float distFromRay(Ray const &ray) const;

        bool hit(Ray const &ray) const;

        Vec3D hitPoint(Ray const &ray) const;

        float getRadius() const;

    protected:
        Vec3D center;
        float radius;
    };
}


#endif //CPP_OPDR3_CONSOLE_GRAPHICS_H

//
// Created by casper on 10/6/2021.
//


#include <iostream>
#include <vector>
#include <iomanip>

#include "console_graphics.h"
namespace vg = vectorGraphics;

using namespace std;


/* Requirements:
 *  Deze code heeft een class Vec3D nodig met daarin de x,y en z waardes.
 *  Vec3D heeft een constructor nodig.
 *  De volgende functies moeten met een Vec3D worden uitgerekend:
 *      minus, add, sub, mul, div, norm(afstand vanaf origin), unit(norm van 1), dot(inproduct van twee vectors) en cross(uitproduct van twee vectors)
 *
 *  Deze code heeft een class Ray nodig die twee Vec3D's opslaat.
 *
 *  Deze code heeft een class Sphere nodig die uitrekent of(hit) de sphere een ray raakt, waar(hitPoint) de intersect is en de minimale waarde tussen sphere en ray(distFromRay)
 *
 *
 *
 * Testspecs:
 *  Om te testen of de functies werken, zal iedere functie een unit test krijgen met een vooraf uitgerekende uitkomst.
 *  Om de boundaries te checken zal ik een paar keer buiten de maxvalue van float raken om te zien wat er gebeurd.
 *
 *
 * Design:
 *  For the design of the code I would like to implement cpp operators(+-/*%) to calculate the Vec3D objects. for this I override the operators of this class.
 *  I would like to keep the classes to a minimum, so I only use 3.
 *  I like to use the classes in a namespace so that I can reuse it in other code.
 *  the Ray will have private objects so to use them I will need it to befriend the class Sphere.
 *  I declare everything in a header file so that I can lookup the functions and variables.
 *  I use matrix math to calculate the intersection of the ray and sphere.
 */


int main() {
    std::cout.precision(3);
    std::cout << std::setw(10);

    std::vector<vg::Sphere> spheres {
            vg::Sphere (-0.4, 0.23, -1, 0.4),
            vg::Sphere (0.4, 0.4, -1.2, 0.3),
            vg::Sphere (0.7, -0.15, -1.5, 0.2),
    };
    float far = -0.5;
    std::vector<vg::Ray> rays {
            vg::Ray (-far, 0.23, -1, far, 0, 0),
            vg::Ray (0.4, -far, -1.2, 0, far, 0),
            vg::Ray (0.7, -0.15, -far, 0, 0, far),
    };
    std::cout << "Start program" << std::endl;
    int rayNr = 0;
    for(const vg::Ray& r : rays){
        rayNr++;
        int sphereNr = 0;
        for(const vg::Sphere& s : spheres){
            sphereNr++;
            if(s.hit(r)){
                std::cout << "Ray " << rayNr << " HITS Sphere " << sphereNr << " detected!!! at: \n\t" << s.hitPoint(r) << std::endl;
                std::cout << "Ray: " << r << std::endl;
                std::cout << "Sphere: " << s << "\n\n";
                break;
            }
        }
    }
    return 0;
}

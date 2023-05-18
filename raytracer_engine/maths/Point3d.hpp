/*
** EPITECH PROJECT, 2022
** Test
** File description:
** point3d.hpp
*/

#pragma once
#include "Vector3d.hpp"

namespace Math
{
    class Point3d
    {
    public:
        Point3d()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        Point3d(double x, double y, double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Point3d(const Point3d &point)
        {
            this->x = point.x;
            this->y = point.y;
            this->z = point.z;
        }

        void operator=(const Point3d &point)
        {
            this->x = point.x;
            this->y = point.y;
            this->z = point.z;
        }

        Point3d(Point3d &point)
        {
            this->x = point.x;
            this->y = point.y;
            this->z = point.z;
        }

        void operator=(Point3d &point)
        {
            this->x = point.x;
            this->y = point.y;
            this->z = point.z;
        }

        Point3d operator-(Point3d &point)
        {
            Point3d newPoint;
            newPoint.x = this->x - point.x;
            newPoint.y = this->y - point.y;
            newPoint.z = this->z - point.z;
            return newPoint;
        }
        std::unique_ptr<Point3d> operator+(const Vector3d &vector) const
        {
            return (std::make_unique<Point3d>(this->x + vector.x, this->y + vector.y, this->z + vector.z));
        }
        double dot(Vector3d &vector)
        {
            return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
        }
        double dot(Point3d &point)
        {
            return (this->x * point.x + this->y * point.y + this->z * point.z);
        }
        double x;
        double y;
        double z;
    };
}

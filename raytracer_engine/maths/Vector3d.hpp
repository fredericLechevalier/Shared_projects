/*
** EPITECH PROJECT, 2022
** Test
** File description:
** vector3d.hpp
*/

#pragma once
#include <fstream>
#include <iostream>
#include <tgmath.h>
#include <memory>

namespace Math
{
    class Vector3d
    {
    public:
        Vector3d()
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

        Vector3d(double x, double y, double z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        
        Vector3d(const Vector3d &vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        void operator=(const Vector3d &vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        Vector3d(Vector3d &vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        void operator=(Vector3d &vector)
        {
            this->x = vector.x;
            this->y = vector.y;
            this->z = vector.z;
        }

        Vector3d operator+(const Vector3d &vector) const
        {
            Vector3d nw_vector;
            nw_vector.x = this->x + vector.x;
            nw_vector.y = this->y + vector.y;
            nw_vector.z = this->z + vector.z;
            return nw_vector;
        }

        void operator+=(const Vector3d &vector)
        {
            this->x += vector.x;
            this->y += vector.y;
            this->z += vector.z;
        }

        Vector3d operator-(const Vector3d &vector) const
        {
            Vector3d nw_vector(this->x - vector.x, this->y - vector.y, this->z - vector.z);
            return nw_vector;
        }

        void operator-=(const Vector3d &vector)
        {
            this->x -= vector.x;
            this->y -= vector.y;
            this->z -= vector.z;
        }

        Vector3d operator*(const Vector3d &vector) const
        {
            Vector3d nw_vector(this->x * vector.x, this->y * vector.y, this->z * vector.z);
            return nw_vector;
        }

        void operator*=(const Vector3d &vector)
        {
            this->x *= vector.x;
            this->y *= vector.y;
            this->z *= vector.z;
        }

        Vector3d operator/(const Vector3d &vector) const
        {
            Vector3d nw_vector(this->x / vector.x, this->y / vector.y, this->z / vector.z);
            return nw_vector;
        }

        void operator/=(const Vector3d &vector)
        {
            this->x /= vector.x;
            this->y /= vector.y;
            this->z /= vector.z;
        }

        Vector3d operator*(const double mul) const
        {
            Vector3d nw_vector(this->x * mul, this->y * mul, this->z * mul);
            return nw_vector;
        }

        Vector3d operator/(const double div) const
        {
            Vector3d nw_vector(this->x / div, this->y / div, this->z / div);
            return nw_vector;
        }

        void operator*=(const double mul)
        {
            this->x *= mul;
            this->y *= mul;
            this->z *= mul;
        }

        void operator/=(const double div)
        {
            this->x /= div;
            this->y /= div;
            this->z /= div;
        }

        double lenght(void)
        {
            return (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));
        }

        double dot(Vector3d &vector)
        {
            return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
        }

        double dot(const Vector3d &vector)
        {
            return (this->x * vector.x + this->y * vector.y + this->z * vector.z);
        }

        double x;
        double y;
        double z;
    };
}

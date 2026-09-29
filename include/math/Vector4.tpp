/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <cmath>
#include <vector>

#include <tbaricault/str.hpp>
#include <tbaricault/uniconvert.hpp>

#include "Vector4.hpp"


namespace tbaricault::math
{

    template<typename T>
    constexpr Vector4<T> Vector4<T>::zero() noexcept
    {
        return Vector4(0, 0, 0, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::one() noexcept
    {
        return Vector4(1, 1, 1, 1);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::left() noexcept
    {
        return Vector4(-1, 0, 0, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::right() noexcept
    {
        return Vector4(1, 0, 0, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::down() noexcept
    {
        return Vector4(0, -1, 0, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::up() noexcept
    {
        return Vector4(0, 1, 0, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::backward() noexcept
    {
        return Vector4(0, 0, -1, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::forward() noexcept
    {
        return Vector4(0, 0, 1, 0);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::kata() noexcept
    {
        return Vector4(0, 0, 0, -1);
    }

    template<typename T>
    constexpr Vector4<T> Vector4<T>::ana() noexcept
    {
        return Vector4(0, 0, 0, 1);
    }

    template<typename T>
    Vector4<T> Vector4<T>::hadamard(const Vector4& a, const Vector4& b) noexcept
    {
        return Vector4(
            a.x * b.x,
            a.y * b.y,
            a.z * b.z,
            a.w * b.w
        );
    }

    template<typename T>
    double Vector4<T>::distance(const Vector4& a, const Vector4& b) noexcept
    {
        return (std::sqrt(
            (a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y) +
            (a.z - b.z) * (a.z - b.z) +
            (a.w - b.w) * (a.w - b.w)
        ));
    }

    template<typename T>
    double Vector4<T>::angle(const Vector4& a, const Vector4& b) noexcept
    {
        return (std::acos(a * b / (a.magnitude() * b.magnitude())));
    }

    template<typename T>
    Vector4<T>::Vector4(T value) noexcept
        : x(value)
        , y(value)
        , z(value)
        , w(value)
    {
        return;
    }

    template<typename T>
    Vector4<T>::Vector4(T x, T y, T z, T w) noexcept
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
        return;
    }

    template<typename T>
    Vector4<T>::Vector4(const Vector2<T>& v, T z, T w) noexcept
        : x(v.x)
        , y(v.y)
        , z(z)
        , w(w)
    {
        return;
    }

    template<typename T>
    Vector4<T>::Vector4(const Vector3<T>& v, T w) noexcept
        : x(v.x)
        , y(v.y)
        , z(v.z)
        , w(w)
    {
        return;
    }

    template<typename T>
    template<typename U>
    Vector4<T>::Vector4(const Vector4<U>& other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
        , z(static_cast<T>(other.z))
        , w(static_cast<T>(other.w))
    {
        return;
    }

    template<typename T>
    Vector4<T>::Vector4(std::string_view str)
    {
        std::vector<std::string> args = tbaricault::str::split(str, " ", false);
        if (args.size() == 4)
        {
            this->x = tbaricault::uniconvert::convert<std::string, T>(args.at(0));
            this->y = tbaricault::uniconvert::convert<std::string, T>(args.at(1));
            this->z = tbaricault::uniconvert::convert<std::string, T>(args.at(2));
            this->w = tbaricault::uniconvert::convert<std::string, T>(args.at(3));
        }
        else
            throw std::invalid_argument("convertion failed");
        return;
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator+=(const Vector4& other) noexcept
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;
        return (*this);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator+=(T other) noexcept
    {
        this->x += other;
        this->y += other;
        this->z += other;
        this->w += other;
        return (*this);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator-=(const Vector4& other) noexcept
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;
        return (*this);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator-=(T other) noexcept
    {
        this->x -= other;
        this->y -= other;
        this->z -= other;
        this->w -= other;
        return (*this);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator*=(T other) noexcept
    {
        this->x *= other;
        this->y *= other;
        this->z *= other;
        this->w *= other;
        return (*this);
    }

    template<typename T>
    Vector4<T>& Vector4<T>::operator/=(T other) noexcept
    {
        this->x /= other;
        this->y /= other;
        this->z /= other;
        this->w /= other;
        return (*this);
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator+(const Vector4& other) const noexcept
    {
        return Vector4(
            this->x + other.x,
            this->y + other.y,
            this->z + other.z,
            this->w + other.w
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator+(T other) const noexcept
    {
        return Vector4(
            this->x + other,
            this->y + other,
            this->z + other,
            this->w + other
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator-(const Vector4& other) const noexcept
    {
        return Vector4(
            this->x - other.x,
            this->y - other.y,
            this->z - other.z,
            this->w - other.w
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator-(T other) const noexcept
    {
        return Vector4(
            this->x - other,
            this->y - other,
            this->z - other,
            this->w - other
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator-() const noexcept
    {
        return Vector4(
            -this->x,
            -this->y,
            -this->z,
            -this->w
        );
    }

    template<typename T>
    T Vector4<T>::operator*(const Vector4& other) const noexcept
    {
        return (
            this->x * other.x +
            this->y * other.y +
            this->z * other.z +
            this->w * other.w
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator*(T other) const noexcept
    {
        return Vector4(
            this->x * other,
            this->y * other,
            this->z * other,
            this->w * other
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::operator/(T other) const noexcept
    {
        return Vector4(
            this->x / other,
            this->y / other,
            this->z / other,
            this->w / other
        );
    }

    template<typename T>
    bool Vector4<T>::operator==(const Vector4& other) const noexcept
    {
        return (
            other.x == this->x &&
            other.y == this->y &&
            other.z == this->z &&
            other.w == this->w
        );
    }

    template<typename T>
    bool Vector4<T>::operator!=(const Vector4& other) const noexcept
    {
        return (
            other.x != this->x ||
            other.y != this->y ||
            other.z != this->z ||
            other.w != this->w
        );
    }

    template<typename T>
    Vector4<T>::operator std::string() const
    {
        return (
            tbaricault::uniconvert::convert<T, std::string>(this->x) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->y) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->z) + ' ' +
            tbaricault::uniconvert::convert<T, std::string>(this->w)
        );
    }

    template<typename T>
    bool Vector4<T>::isZero() const noexcept
    {
        return (
            this->x == 0 &&
            this->y == 0 &&
            this->z == 0 &&
            this->w == 0
        );
    }

    template<typename T>
    double Vector4<T>::magnitude() const noexcept
    {
        return std::sqrt(
            this->x * this->x +
            this->y * this->y +
            this->z * this->z +
            this->w * this->w
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::normalize() const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude == 0
            ? Vector4(1, 0, 0, 0)
            : Vector4(
                this->x / magnitude,
                this->y / magnitude,
                this->z / magnitude,
                this->w / magnitude
            )
        );
    }

    template<typename T>
    Vector4<T> Vector4<T>::limit(T limit) const noexcept
    {
        double magnitude = this->magnitude();
        return (
            magnitude > limit
            ? Vector4(
                this->x / magnitude * limit,
                this->y / magnitude * limit,
                this->z / magnitude * limit,
                this->w / magnitude * limit
            )
            : *this
        );
    }

}

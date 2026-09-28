/*
 * Copyright (c) 2026-present Thomas Baricault
 *
 * SPDX-License-Identifier: MIT
 */


#pragma once


#include <string>
#include <string_view>

#include "Vector2.hpp"
#include "Vector3.hpp"


namespace tbaricault::math
{

    /**
     * @brief Four-dimensional vector
     * 
     * @tparam T Component type
     */
    template<typename T>
    class Vector4 final
    {

        public:

            /**
             * @brief X component
             */
            T x = T{};

            /**
             * @brief Y component
             */
            T y = T{};

            /**
             * @brief Z component
             */
            T z = T{};

            /**
             * @brief W component
             */
            T w = T{};


            /**
             * @brief Returns the zero vector
             * 
             * @return (0, 0, 0, 0)
             */
            static constexpr Vector4 zero() noexcept;

            /**
             * @brief Returns a vector whose components are all equal to one
             * 
             * @return (1, 1, 1, 1)
             */
            static constexpr Vector4 one() noexcept;

            /**
             * @brief Returns the unit vector pointing left
             * 
             * @return (-1, 0, 0, 0)
             */
            static constexpr Vector4 left() noexcept;

            /**
             * @brief Returns the unit vector pointing right
             * 
             * @return (1, 0, 0, 0)
             */
            static constexpr Vector4 right() noexcept;

            /**
             * @brief Returns the unit vector pointing downward
             * 
             * @return (0, -1, 0, 0)
             */
            static constexpr Vector4 down() noexcept;

            /**
             * @brief Returns the unit vector pointing upward
             * 
             * @return (0, 1, 0, 0)
             */
            static constexpr Vector4 up() noexcept;

            /**
             * @brief Returns the unit vector pointing backwards
             * 
             * @return (0, 0, -1, 0)
             */
            static constexpr Vector4 backward() noexcept;

            /**
             * @brief Returns the unit vector pointing forward
             * 
             * @return (0, 0, 1, 0)
             */
            static constexpr Vector4 forward() noexcept;

            /**
             * @brief Returns the unit vector pointing kata
             * 
             * @return (0, 0, 0, -1)
             */
            static constexpr Vector4 kata() noexcept;

            /**
             * @brief Returns the unit vector pointing ana
             * 
             * @return (0, 0, 0, 1)
             */
            static constexpr Vector4 ana() noexcept;

            /**
             * @brief Computes the Hadamard (element-wise) product of two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Component-wise product
             */
            static Vector4 hadamard(const Vector4& a, const Vector4& b) noexcept;

            /**
             * @brief Computes the Euclidean distance between two points
             * 
             * @param a First point
             * @param b Second point
             * 
             * @return Distance
             */
            static double distance(const Vector4& a, const Vector4& b) noexcept;

            /**
             * @brief Computes the angle between two vectors
             * 
             * @param a First vector
             * @param b Second vector
             * 
             * @return Angle in radians
             */
            static double angle(const Vector4& a, const Vector4& b) noexcept;

            /**
             * @brief Constructs the zero vector
             */
            Vector4() noexcept = default;

            /**
             * @brief Copy constructor
             * 
             * @param other Vector to copy
             */
            Vector4(const Vector4& other) noexcept = default;

            /**
             * @brief Move constructor
             * 
             * @param other Vector to move
             */
            Vector4(Vector4&& other) noexcept = default;

            /**
             * @brief Constructs a vector with all components initialized to the same value
             * 
             * @param value Component value
             */
            Vector4(T value) noexcept;

            /**
             * @brief Constructs a vector from its components
             * 
             * @param x X component
             * @param y Y component
             * @param z Z component
             * @param w W component
             */
            Vector4(T x, T y, T z, T w) noexcept;

            /**
             * @brief Constructs a four-dimensional vector expanding a two-dimentional vector
             * 
             * @param v Vector to expand
             * @param z Z component
             * @param w W component
             */
            Vector4(const Vector2<T>& v, T z, T w) noexcept;

            /**
             * @brief Constructs a four-dimensional vector expanding a three-dimentional vector
             * 
             * @param v Vector to expand
             * @param w W component
             */
            Vector4(const Vector3<T>& v, T w) noexcept;

            /**
             * @brief Constructs a vector by converting another four-dimentional vector
             *
             * @tparam U Source component type
             * 
             * @param other Vector to convert
             */
            template<typename U>
            Vector4(const Vector4<U>& other);

            /**
             * @brief Constructs a vector from its string representation
             * 
             * @param str String representation
             * 
             * @throws std::invalid_argument If conversion failed
             */
            Vector4(std::string_view str);

            /**
             * @brief Destructor
             */
            ~Vector4() noexcept = default;

            /**
             * @brief Copy assignment operator
             * 
             * @param other Vector to copy
             * 
             * @return Reference to this vector
             */
            Vector4& operator=(const Vector4& other) noexcept = default;

            /**
             * @brief Move assignment operator
             * 
             * @param other Vector to move
             * 
             * @return Reference to this vector
             */
            Vector4& operator=(Vector4&& other) noexcept = default;

            /**
             * @brief Adds another vector component-wise
             * 
             * @param other Vector to add
             * 
             * @return Reference to this vector
             */
            Vector4& operator+=(const Vector4& other) noexcept;

            /**
             * @brief Adds a scalar value to each component
             * 
             * @param other Scalar to add
             * 
             * @return Reference to this vector
             */
            Vector4& operator+=(T other) noexcept;

            /**
             * @brief Subtracts another vector component-wise
             * 
             * @param other Vector to subtract
             * 
             * @return Reference to this vector
             */
            Vector4& operator-=(const Vector4& other) noexcept;

            /**
             * @brief Subtracts a scalar value to each component
             * 
             * @param other Scalar to subtract
             * 
             * @return Reference to this vector
             */
            Vector4& operator-=(T other) noexcept;

            /**
             * @brief Multiplies each component by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Reference to this vector
             */
            Vector4& operator*=(T other) noexcept;

            /**
             * @brief Divides each component by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Reference to this vector
             */
            Vector4& operator/=(T other) noexcept;

            /**
             * @brief Component-wise addition of two vectors
             * 
             * @param other Vector to add
             * 
             * @return Resulting vector
             */
            Vector4 operator+(const Vector4& other) const noexcept;

            /**
             * @brief Adds a scalar to each component of a vector
             * 
             * @param other Scalar to add
             * 
             * @return Resulting vector
             */
            Vector4 operator+(T other) const noexcept;

            /**
             * @brief Component-wise subtraction of two vectors
             * 
             * @param other Vector to subtract
             * 
             * @return Resulting vector
             */
            Vector4 operator-(const Vector4& other) const noexcept;

            /**
             * @brief Subtracts a scalar to each component of a vector
             * 
             * @param other Scalar to subtract
             * 
             * @return Resulting vector
             */
            Vector4 operator-(T other) const noexcept;

            /**
             * @brief Returns the negation of the vector
             * 
             * @return (-x, -y, -z, -w)
             */
            Vector4 operator-() const noexcept;

            /**
             * @brief Computes the dot product of two vectors
             * 
             * @param other Second vector
             * 
             * @return Dot product (ax * bx + ay * by + az * bz + aw * bw)
             */
            T operator*(const Vector4& other) const noexcept;

            /**
             * @brief Multiplies each component of a vector by a scalar
             * 
             * @param other Scalar multiplier
             * 
             * @return Resulting vector
             */
            Vector4 operator*(T other) const noexcept;

            /**
             * @brief Divides each component of a vector by a scalar
             * 
             * @param other Scalar divisor
             * 
             * @return Resulting vector
             */
            Vector4 operator/(T other) const noexcept;

            /**
             * @brief Checks whether two vectors are equal
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if both vector are equal, `false` otherwise
             */
            bool operator==(const Vector4& other) const noexcept;

            /**
             * @brief Checks whether two vectors are different
             * 
             * @param other Vector to compare with
             * 
             * @return `true` if vectors differ, `false` otherwise
             */
            bool operator!=(const Vector4& other) const noexcept;

            /**
             * @brief Converts the vector to its string representation
             */
            operator std::string() const;

            /**
             * @brief Checks whether this is the zero vector
             * 
             * @return `true` if all components are equal to zero, `false` otherwise
             */
            bool isZero() const noexcept;

            /**
             * @brief Computes the Euclidean norm of the vector
             * 
             * @return Euclidean norm (sqrt(x * x + y * y + z * z + w * w))
             */
            double magnitude() const noexcept;

            /**
             * @brief Returns the normalized vector
             * 
             * @return Unit vector
             */
            Vector4 normalize() const noexcept;

            /**
             * @brief Returns the magnitude limited vector
             * 
             * @param limit Maximum allowed magnitude
             * 
             * @return Limited vector
             */
            Vector4 limit(const T) const noexcept;

    };

}


#include "Vector3.tpp"

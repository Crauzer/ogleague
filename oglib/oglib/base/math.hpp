#pragma once
#include <algorithm>
#include <cmath>
#include <oglib/base/point2d.hpp>
#include <oglib/base/point3d.hpp>

namespace OG::Math {
  constexpr static const float PI = 3.1415926f;
  constexpr static const float EPSILON = 0.00001f;
  inline float invSqrt(float value) { return 1.0f / std::sqrt(value); }

  bool isNull(const Point2D& point) { return point.x == 0 && point.y == 0; }

  bool isNull(const Point3D& point)
  {
    return point.x == 0 && point.y == 0 && point.z == 0;
  }

  inline float dot(const Point2D& point, const Point2D& other)
  {
    return point.x * other.x + point.y * other.y;
  }

  inline float dot(const Point3D& point, const Point3D& other)
  {
    return point.x * other.x + point.y * other.y + point.z * other.z;
  }

  inline float lengthSq(const Point2D& point) { return dot(point, point); }

  inline float lengthSq(const Point3D& point) { return dot(point, point); }

  inline float length(const Point2D& point) { return sqrtf(lengthSq(point)); }

  inline float length(const Point3D& point) { return sqrtf(lengthSq(point)); }

  inline Point2D normalize(const Point2D& point)
  {
    float inv = invSqrt(lengthSq(point));
    return inv > 0 ? Point2D{ point.x * inv, point.y * inv } : point;
  }

  inline Point3D normalize(const Point3D& point)
  {
    float inv = invSqrt(lengthSq(point));
    return inv > 0 ? Point3D{ point.x * inv, point.y * inv, point.z * inv }
                   : point;
  }

  inline Point2D project(const Point2D& point,
                         const Point2D& pointOfLine,
                         const Point2D& normal)
  {
    auto norm = normalize(normal);
    auto diff = point - pointOfLine;
    auto diffLength = length(diff);
    if (diffLength < EPSILON)
      return point;
    return point + norm * diffLength * dot(norm, diff / diffLength);
  }

  // TODO: project for Point3D ???

  inline float minElement(const Point2D& point)
  {
    return std::min(point.x, point.y);
  }

  inline float minElement(const Point3D& point)
  {
    return std::min(std::min(point.x, point.y), point.z);
  }

  inline float maxElement(const Point2D& point)
  {
    return std::max(point.x, point.y);
  }

  inline float maxElement(const Point3D& point)
  {
    return std::min(std::max(point.x, point.y), point.z);
  }

  inline float angle(const Point2D& point, const Point2D& with)
  {
    return std::acos(std::clamp(dot(point, with), -1.0f, 1.0f));
  }

  inline float angle(const Point3D& point, const Point3D& with)
  {
    return std::acos(std::clamp(dot(point, with), -1.0f, 1.0f));
  }

  inline bool almostEqual(const Point2D& point,
                          const Point2D& other,
                          float delta = EPSILON)
  {
    return std::abs(point.x - other.x) <= delta &&
           std::abs(point.y - other.y) <= delta;
  }

  inline bool almostEqual(const Point3D& point,
                          const Point3D& other,
                          float delta = EPSILON)
  {
    return std::abs(point.x - other.x) <= delta &&
           std::abs(point.y - other.y) <= delta &&
           std::abs(point.z - other.z) <= delta;
  }

  // TODO: cross for Point2D

  inline Point3D cross(const Point3D& point, const Point3D& other)
  {
    return Point3D{ point.y * other.z - point.z * other.y,
                    point.z * other.x - point.x * other.z,
                    point.x * other.y - point.y * other.x };
  }

  // TODO: everything below for Point2D???

  inline float yaw(const Point3D& point)
  {
    auto yw = std::atan2(-point.x, point.z);
    if (yw < 0)
      yw += 2 * PI;
    return yw;
  }

  inline float pitch(const Point3D& point)
  {
    auto ptch =
      std::atan2(point.y, std::sqrt(point.x * point.x + point.z * point.z));
    if (ptch < 0)
      ptch += 2 * PI;
    return ptch;
  }

  inline float roll(const Point3D& point)
  {
    if (!point.x || !point.y)
      return 0.0f;
    auto rol =
      std::atan2(point.y, std::sqrt(point.x * point.x + point.z * point.z));
    if (rol < 0)
      rol += 2 * PI;
    return rol;
  }

  inline Point3D rotateX(const Point3D& point,
                         float angle,
                         const Point3D& about = {})
  {
    if (!angle)
      return point;
    auto y = point.y - about.y;
    auto z = point.z - about.z;
    if (!y && !z)
      return point;
    return Point3D{ point.x,
                    y * std::cos(angle) - z * std::sin(angle) + about.y,
                    z * std::cos(angle) + y * std::sin(angle) + about.z };
  }

  inline Point3D rotateY(const Point3D& point,
                         float angle,
                         const Point3D& about = {})
  {
    if (!angle)
      return point;
    auto x = point.x - about.x;
    auto z = point.z - about.z;
    if (!x && !z)
      return point;
    return Point3D{ x * std::cos(angle) + z * std::sin(angle) + about.x,
                    point.y,
                    z * std::cos(angle) - x * std::sin(angle) + about.z };
  }

  inline Point3D rotateZ(const Point3D& point,
                         float angle,
                         const Point3D& about = {})
  {
    if (!angle)
      return point;
    auto x = point.x - about.x;
    auto y = point.y - about.y;
    if (!x && !y)
      return point;
    return Point3D{ x * std::sin(angle) - y * std::cos(angle) + about.x,
                    y * std::sin(angle) + x * std::cos(angle) + about.y,
                    point.z };
  }
}
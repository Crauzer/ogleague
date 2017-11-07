#pragma once

namespace OG {
  struct Point2D
  {
    float x, y;
  };

  inline bool operator==(const Point2D& left, const Point2D& right)
  {
    return left.x == right.x && left.y == right.y;
  }

  inline bool operator!=(const Point2D& left, const Point2D& right)
  {
    return !(left == right);
  }

  inline Point2D operator+(const Point2D& left, const Point2D& right)
  {
    return Point2D{ left.x + right.x, left.y + right.y };
  }

  inline Point2D operator-(const Point2D& left, const Point2D& right)
  {
    return Point2D{ left.x - right.x, left.y - right.y };
  }

  inline Point2D operator*(const Point2D& left, const Point2D& right)
  {
    return Point2D{ left.x * right.x, left.y * right.y };
  }

  inline Point2D operator/(const Point2D& left, const Point2D& right)
  {
    return Point2D{ left.x / right.x, left.y / right.y };
  }

  inline Point2D operator+(const Point2D& left, float right)
  {
    return Point2D{ left.x + right, left.y + right };
  }

  inline Point2D operator-(const Point2D& left, float right)
  {
    return Point2D{ left.x - right, left.y - right };
  }

  inline Point2D operator*(const Point2D& left, float right)
  {
    return Point2D{ left.x * right, left.y * right };
  }

  inline Point2D operator/(const Point2D& left, float right)
  {
    return Point2D{ left.x / right, left.y / right };
  }

  inline Point2D operator+(float left, const Point2D& right)
  {
    return right + left;
  }

  inline Point2D operator*(float left, const Point2D& right)
  {
    return right * left;
  }

  inline Point2D operator+=(Point2D& left, const Point2D& right)
  {
    return left = left + right;
  }

  inline Point2D operator-=(Point2D& left, const Point2D& right)
  {
    return left = left - right;
  }

  inline Point2D operator*=(Point2D& left, const Point2D& right)
  {
    return left = left * right;
  }

  inline Point2D operator/=(Point2D& left, const Point2D& right)
  {
    return left = left / right;
  }

  inline Point2D operator+=(Point2D& left, float right)
  {
    return left = left + right;
  }

  inline Point2D operator-=(Point2D& left, float right)
  {
    return left = left - right;
  }

  inline Point2D operator*=(Point2D& left, float right)
  {
    return left = left * right;
  }

  inline Point2D operator/=(Point2D& left, float right)
  {
    return left = left / right;
  }
} // namespace OG
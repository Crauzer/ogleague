#pragma once
#include <array>
#include <sstream>
#include <string>

namespace OG
{
  inline void string_as(const std::string& value, std::string& to)
  {
    to = value;
  }

  inline void string_as(const std::string& value, float& to)
  {
    to = std::stof(value);
  }

  inline void string_as(const std::string& value, int& to)
  {
    to = std::stoi(value);
  }

  template <size_t SIZE>
  inline void string_as(const std::string& value, std::array<float, SIZE>& to)
  {
    std::stringstream ss(value);
    for (auto& v : to)
      ss >> v;
  }

  inline std::string as_string(const std::string& value)
  {
    return value;
  }

  inline std::string as_string(int value)
  {
    return std::to_string(value);
  }

  inline std::string as_string(float value)
  {
    return std::to_string(value);
  }

  template <size_t SIZE>
  inline std::string as_string(const std::array<float, SIZE>& value)
  {
    std::stringstream ss;
    for (auto&& v : value)
      ss << std::to_string(value) << ' ';
    return ss.str();
  }
} // namespace OG

#pragma once
#include <map>
#include <oglib/base/strings.hpp>
#include <oglib/base/types.hpp>
#include <optional>

namespace OG::File
{
  class Ini : public std::map<uint32, std::string>
  {
  private:
    using base = std::map<uint32, std::string>;
    using base::base;
    static uint32 hash(std::string_view section, std::string_view name)
    {
      uint32 h = 0;
      for (auto c : section)
        h = h * 65599 + tolower(c);
      h = h * 65599 + 42;
      for (auto c : name)
        h = h * 65599 + tolower(c);
      return h;
    }

  public:
    bool has(std::string_view section, std::string_view name)
    {
      return base::find(hash(section, name)) != base::end();
    }

    template <typename T>
    T get(std::string_view section, std::string_view name, T defaultValue = {})
    {
      auto it = base::find(hash(section, name));
      if (it == base::end())
        return defaultValue;
      return string_as(it->second, defaultValue);
    }
    void readText(std::istream& file);
    void readBin(std::istream& file);
  };
} // namespace OG::File

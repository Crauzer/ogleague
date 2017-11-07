#pragma once
#include <lsignal.hpp>

namespace OG {
  template<typename... Args>
  using Event = typename lsignal::signal<Args...>;
  using EventHandler = typename lsignal::slot;
  using EventConnection = typename lsignal::connection;
}

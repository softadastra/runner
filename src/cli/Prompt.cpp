/**
 *
 *  @file Prompt.cpp
 *  @author Gaspard Kirira
 *
 *  Copyright 2026, Gaspard Kirira.
 *  All rights reserved.
 *  https://github.com/softadastra/runner
 *
 *  Use of this source code is governed by a MIT license
 *  that can be found in the License file.
 *
 *  Softadastra Runner
 *
 */

#include <iostream>

#include <softadastra/runner/cli/Prompt.hpp>

namespace softadastra::runner::cli
{

  Prompt::Prompt() = default;

  Prompt::Prompt(std::string value)
      : value_(std::move(value))
  {
  }

  void Prompt::show() const
  {
    std::cout << value_ << std::flush;
  }

  void Prompt::set(std::string value)
  {
    value_ = std::move(value);
  }

  const std::string &Prompt::value() const noexcept
  {
    return value_;
  }

} // namespace softadastra::runner::cli

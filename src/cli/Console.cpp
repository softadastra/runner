/**
 *
 *  @file Console.cpp
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

#include <vix/input.hpp>
#include <vix/print.hpp>
#include <softadastra/runner/cli/Console.hpp>

namespace softadastra::runner::cli
{

  std::string Console::read_line() const
  {
    return vix::input();
  }

  void Console::write(const std::string &message) const
  {
    vix::print(vix::options{.end = ""}, message);
  }

  void Console::write_error(const std::string &message) const
  {
    vix::print(
        vix::options{.end = "", .file = &std::cerr},
        message);
  }

  void Console::display_result(const core::CommandResult &result) const
  {
    if (!result.stdout_text.empty())
    {
      vix::print(
          vix::options{.end = ""},
          result.stdout_text);

      if (result.stdout_text.back() != '\n')
      {
        vix::print();
      }
    }

    if (!result.stderr_text.empty())
    {
      vix::print(
          vix::options{.end = "", .file = &std::cerr},
          result.stderr_text);

      if (result.stderr_text.back() != '\n')
      {
        vix::print(vix::options{.file = &std::cerr});
      }
    }

    vix::print("[exit code:", result.exit_code, "]");
  }

} // namespace softadastra::runner::cli

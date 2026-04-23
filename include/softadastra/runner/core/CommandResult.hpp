/**
 *
 *  @file CommandResult.hpp
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
#ifndef SOFTADASTRA_RUNNER_CORE_COMMANDRESULT_HPP
#define SOFTADASTRA_RUNNER_CORE_COMMANDRESULT_HPP

#include <string>

namespace softadastra::runner::core
{
  /**
   * @struct CommandResult
   * @brief Represents the result of a command execution.
   *
   * This structure contains:
   * - the exit code
   * - captured standard output
   * - captured standard error
   *
   * Design goals:
   * - simple and explicit result representation
   * - independent from execution backend
   * - easy to display in CLI
   */
  struct CommandResult
  {
    /**
     * @brief Process exit code.
     *
     * A value of 0 usually means success.
     */
    int exit_code{0};

    /**
     * @brief Captured standard output.
     */
    std::string stdout_text{};

    /**
     * @brief Captured standard error.
     */
    std::string stderr_text{};

    /**
     * @brief Return true if execution succeeded.
     */
    [[nodiscard]] bool success() const noexcept
    {
      return exit_code == 0;
    }
  };

} // namespace softadastra::runner::core

#endif // SOFTADASTRA_RUNNER_CORE_COMMANDRESULT_HPP

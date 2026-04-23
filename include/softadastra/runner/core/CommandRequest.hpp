/**
 *
 *  @file CommandRequest.hpp
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
#ifndef SOFTADASTRA_RUNNER_CORE_COMMANDREQUEST_HPP
#define SOFTADASTRA_RUNNER_CORE_COMMANDREQUEST_HPP

#include <string>
#include <vector>

namespace softadastra::runner::core
{
  /**
   * @struct CommandRequest
   * @brief Represents a command to execute.
   *
   * This structure describes:
   * - the program to run
   * - the list of arguments
   *
   * Design goals:
   * - simple and explicit representation
   * - independent from execution backend
   * - reusable across CLI and services
   */
  struct CommandRequest
  {
    /**
     * @brief Program name or path.
     */
    std::string program{};

    /**
     * @brief Command arguments.
     */
    std::vector<std::string> arguments{};

    /**
     * @brief Return true if the request is valid.
     *
     * A command is valid if a program is provided.
     */
    [[nodiscard]] bool valid() const noexcept
    {
      return !program.empty();
    }
  };

} // namespace softadastra::runner::core

#endif // SOFTADASTRA_RUNNER_CORE_COMMANDREQUEST_HPP

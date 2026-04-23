/**
 *
 *  @file Console.hpp
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
#ifndef SOFTADASTRA_RUNNER_CLI_CONSOLE_HPP
#define SOFTADASTRA_RUNNER_CLI_CONSOLE_HPP

#include <string>

#include <softadastra/runner/core/CommandResult.hpp>

namespace softadastra::runner::cli
{
  /**
   * @class Console
   * @brief Handles console input and output.
   *
   * This class is responsible for:
   * - reading user input
   * - writing messages to the console
   * - displaying command results
   *
   * Design goals:
   * - isolate std::cin/std::cout usage
   * - keep CLI interaction simple and explicit
   */
  class Console
  {
  public:
    /**
     * @brief Read a line from standard input.
     *
     * @return User input line.
     */
    [[nodiscard]] std::string read_line() const;

    /**
     * @brief Write a message to standard output.
     *
     * @param message Text to display.
     */
    void write(const std::string &message) const;

    /**
     * @brief Write an error message to standard error.
     *
     * @param message Error text to display.
     */
    void write_error(const std::string &message) const;

    /**
     * @brief Display a command result.
     *
     * Expected behavior:
     * - print stdout if available
     * - print stderr if available
     * - optionally print exit code
     *
     * @param result Command execution result.
     */
    void display_result(const core::CommandResult &result) const;
  };

} // namespace softadastra::runner::cli

#endif // SOFTADASTRA_RUNNER_CLI_CONSOLE_HPP

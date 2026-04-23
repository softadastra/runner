/**
 *
 *  @file InputParser.hpp
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
#ifndef SOFTADASTRA_RUNNER_CLI_INPUTPARSER_HPP
#define SOFTADASTRA_RUNNER_CLI_INPUTPARSER_HPP

#include <string>

#include <softadastra/runner/core/CommandRequest.hpp>

namespace softadastra::runner::cli
{
  /**
   * @class InputParser
   * @brief Parses raw user input into a CommandRequest.
   *
   * This class is responsible for:
   * - splitting a raw input line
   * - extracting program and arguments
   *
   * Design goals:
   * - simple and predictable parsing
   * - no shell interpretation
   * - explicit transformation into CommandRequest
   */
  class InputParser
  {
  public:
    /**
     * @brief Parse a raw input line into a command request.
     *
     * Expected behavior:
     * - splits input by spaces
     * - first token becomes program
     * - remaining tokens become arguments
     *
     * @param input Raw user input.
     * @return CommandRequest representing the parsed command.
     */
    [[nodiscard]] core::CommandRequest parse(const std::string &input) const;
  };

} // namespace softadastra::runner::cli

#endif // SOFTADASTRA_RUNNER_CLI_INPUTPARSER_HPP

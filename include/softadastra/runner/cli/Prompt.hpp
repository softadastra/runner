/**
 *
 *  @file Prompt.hpp
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
#ifndef SOFTADASTRA_RUNNER_CLI_PROMPT_HPP
#define SOFTADASTRA_RUNNER_CLI_PROMPT_HPP

#include <string>

namespace softadastra::runner::cli
{
  /**
   * @class Prompt
   * @brief Handles prompt display in the console.
   *
   * This class is responsible for:
   * - rendering the prompt
   * - optionally customizing its appearance
   *
   * Design goals:
   * - isolate prompt logic from console
   * - keep rendering simple and explicit
   */
  class Prompt
  {
  public:
    /**
     * @brief Construct a prompt with a default value.
     */
    Prompt();

    /**
     * @brief Construct a prompt with a custom value.
     *
     * @param value Prompt text.
     */
    explicit Prompt(std::string value);

    /**
     * @brief Display the prompt.
     *
     * Expected behavior:
     * - prints the prompt
     * - flushes output for immediate visibility
     */
    void show() const;

    /**
     * @brief Set the prompt value.
     *
     * @param value New prompt text.
     */
    void set(std::string value);

    /**
     * @brief Get the current prompt value.
     */
    [[nodiscard]] const std::string &value() const noexcept;

  private:
    std::string value_{"> "};
  };

} // namespace softadastra::runner::cli

#endif // SOFTADASTRA_RUNNER_CLI_PROMPT_HPP

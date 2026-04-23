/**
 *
 *  @file StringUtils.hpp
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
#ifndef SOFTADASTRA_RUNNER_UTILS_STRINGUTILS_HPP
#define SOFTADASTRA_RUNNER_UTILS_STRINGUTILS_HPP

#include <string>
#include <vector>

namespace softadastra::runner::utils
{
  /**
   * @class StringUtils
   * @brief Utility functions for string manipulation.
   *
   * Design goals:
   * - simple reusable helpers
   * - no dependency on external libraries
   */
  class StringUtils
  {
  public:
    /**
     * @brief Trim leading and trailing whitespace.
     *
     * @param input Input string.
     * @return Trimmed string.
     */
    [[nodiscard]] static std::string trim(const std::string &input);

    /**
     * @brief Split a string by whitespace.
     *
     * @param input Input string.
     * @return Vector of tokens.
     */
    [[nodiscard]] static std::vector<std::string> split(const std::string &input);

    /**
     * @brief Return true if string is empty or only whitespace.
     *
     * @param input Input string.
     */
    [[nodiscard]] static bool is_blank(const std::string &input);
  };

} // namespace softadastra::runner::utils

#endif // SOFTADASTRA_RUNNER_UTILS_STRINGUTILS_HPP

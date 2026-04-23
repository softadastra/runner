/**
 *
 *  @file StringUtils.cpp
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

#include <cctype>
#include <sstream>

#include <softadastra/runner/utils/StringUtils.hpp>

namespace softadastra::runner::utils
{

  std::string StringUtils::trim(const std::string &input)
  {
    std::size_t start = 0;
    std::size_t end = input.size();

    while (start < end && std::isspace(static_cast<unsigned char>(input[start])))
    {
      ++start;
    }

    while (end > start && std::isspace(static_cast<unsigned char>(input[end - 1])))
    {
      --end;
    }

    return input.substr(start, end - start);
  }

  std::vector<std::string> StringUtils::split(const std::string &input)
  {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (stream >> token)
    {
      tokens.push_back(std::move(token));
    }

    return tokens;
  }

  bool StringUtils::is_blank(const std::string &input)
  {
    for (char c : input)
    {
      if (!std::isspace(static_cast<unsigned char>(c)))
      {
        return false;
      }
    }
    return true;
  }

} // namespace softadastra::runner::utils

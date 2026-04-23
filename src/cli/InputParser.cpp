/**
 *
 *  @file InputParser.cpp
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

#include <sstream>

#include <softadastra/runner/cli/InputParser.hpp>

namespace softadastra::runner::cli
{

  core::CommandRequest InputParser::parse(const std::string &input) const
  {
    core::CommandRequest request;

    std::istringstream stream(input);
    std::string token;

    if (stream >> token)
    {
      request.program = std::move(token);
    }

    while (stream >> token)
    {
      request.arguments.push_back(std::move(token));
    }

    return request;
  }

} // namespace softadastra::runner::cli

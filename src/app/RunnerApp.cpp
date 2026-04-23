/**
 *
 *  @file RunnerApp.cpp
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

#include <utility>

#include <softadastra/runner/app/RunnerApp.hpp>
#include <softadastra/runner/utils/StringUtils.hpp>

namespace softadastra::runner::app
{

  RunnerApp::RunnerApp()
      : executor_(std::make_shared<infrastructure::VixProcessExecutor>()),
        service_(executor_)
  {
  }

  int RunnerApp::run()
  {
    while (true)
    {
      prompt_.show();

      const std::string input = console_.read_line();
      if (!handle_input(input))
      {
        break;
      }
    }

    return 0;
  }

  bool RunnerApp::handle_input(const std::string &input)
  {
    if (utils::StringUtils::is_blank(input))
    {
      return true;
    }

    const std::string trimmed = utils::StringUtils::trim(input);

    if (trimmed == "exit")
    {
      return false;
    }

    const auto request = parser_.parse(trimmed);
    const auto result = service_.run(request);

    console_.display_result(result);
    return true;
  }

} // namespace softadastra::runner::app

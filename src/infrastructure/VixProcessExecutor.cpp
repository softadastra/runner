/**
 *
 *  @file VixProcessExecutor.cpp
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

#include <softadastra/runner/infrastructure/VixProcessExecutor.hpp>

#include <vix/process/Command.hpp>
#include <vix/process/Output.hpp>
#include <vix/process/PipeMode.hpp>

namespace softadastra::runner::infrastructure
{

  core::CommandResult VixProcessExecutor::execute(const core::CommandRequest &request) const
  {
    core::CommandResult result;

    if (!request.valid())
    {
      result.exit_code = 1;
      result.stderr_text = "invalid command: program is empty";
      return result;
    }

    vix::process::Command command(request.program);

    for (const auto &argument : request.arguments)
    {
      command.arg(argument);
    }

    command.stdout_mode(vix::process::PipeMode::Pipe);
    command.stderr_mode(vix::process::PipeMode::Pipe);

    auto output_result = vix::process::output(std::move(command));
    if (!output_result)
    {
      result.exit_code = 1;
      result.stderr_text = output_result.error().message();
      return result;
    }

    result.exit_code = output_result.value().exit_code;
    result.stdout_text = std::move(output_result.value().stdout_text);
    result.stderr_text = std::move(output_result.value().stderr_text);

    return result;
  }

} // namespace softadastra::runner::infrastructure
